#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <stdexcept>

struct LocalDate {
    int year, month, day;

    // Cộng ngày đúng lịch (qua tháng/năm) nhờ std::mktime chuẩn hoá các trường ngày tháng
    LocalDate plusDays(int days) const {
        std::tm t{};
        t.tm_year = year - 1900;
        t.tm_mon = month - 1;
        t.tm_mday = day + days;
        t.tm_hour = 12;            // tránh lệch ngày do giờ mùa hè
        t.tm_isdst = -1;
        std::mktime(&t);
        return {t.tm_year + 1900, t.tm_mon + 1, t.tm_mday};
    }

    friend std::ostream& operator<<(std::ostream& os, const LocalDate& d) {
        char old = os.fill('0');
        os << d.year << "-" << std::setw(2) << d.month << "-" << std::setw(2) << d.day;
        os.fill(old);
        return os;
    }
};

class SimpleLoanService {
public:
    struct Loan {
        std::string memberId;
        std::string isbn;
        LocalDate borrowedOn;
        LocalDate dueOn;
        friend std::ostream& operator<<(std::ostream& os, const Loan& r) {
            return os << "Loan(" << r.memberId << ", " << r.isbn << ", " << r.borrowedOn << ", " << r.dueOn << ")";
        }
    };

private:
    static constexpr int LOAN_DAYS = 14;
    std::vector<Loan> loans_list;

public:
    Loan borrow(const std::string& memberId, const std::string& isbn, LocalDate today) {
        if (memberId.empty()) throw std::invalid_argument("memberId");
        if (isbn.empty()) throw std::invalid_argument("isbn");
        Loan loan{memberId, isbn, today, today.plusDays(LOAN_DAYS)};
        loans_list.push_back(loan);
        return loan;
    }

    std::vector<Loan> loans() const { return loans_list; }
};

int main() {
    SimpleLoanService service;
    std::cout << service.borrow("M001", "978-0132350884", LocalDate{2026, 11, 8}) << "\n";
    return 0;
}
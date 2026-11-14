#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <vector>
#include <memory>
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

struct LoanDueDateStrategy { 
    virtual LocalDate dueDate(LocalDate borrowedOn) = 0; 
    virtual ~LoanDueDateStrategy() = default;
};

class StandardLoanDueDateStrategy : public LoanDueDateStrategy {
public:
    LocalDate dueDate(LocalDate borrowedOn) override { return borrowedOn.plusDays(14); }
};

class LoanDueDateCalculator {
    std::shared_ptr<LoanDueDateStrategy> strategy;
public:
    LoanDueDateCalculator(std::shared_ptr<LoanDueDateStrategy> strategy) : strategy(strategy) {}
    LocalDate calculate(LocalDate borrowedOn) { return strategy->dueDate(borrowedOn); }
};

class LoanRequestValidator {
public:
    void validate(const std::string& memberId, const std::string& isbn) {
        if (memberId.empty()) throw std::invalid_argument("memberId");
        if (isbn.empty()) throw std::invalid_argument("isbn");
    }
};

struct LoanRecord {
    std::string memberId, isbn; 
    LocalDate borrowedOn, dueOn;
    LoanRecord(std::string m, std::string i, LocalDate b, LocalDate d) 
        : memberId(m), isbn(i), borrowedOn(b), dueOn(d) {}
    friend std::ostream& operator<<(std::ostream& os, const LoanRecord& r) {
        return os << r.memberId << " borrowed " << r.isbn << " on " << r.borrowedOn << ", due " << r.dueOn;
    }
};

class LoanRecordFactory {
public:
    LoanRecord create(std::string m, std::string i, LocalDate b, LocalDate d) { 
        return LoanRecord(m, i, b, d); 
    }
};

struct LoanRepository { 
    virtual void save(const LoanRecord& r) = 0; 
    virtual std::vector<LoanRecord> all() = 0; 
    virtual ~LoanRepository() = default;
};

class InMemoryLoanRepository : public LoanRepository {
    std::vector<LoanRecord> data;
public:
    void save(const LoanRecord& r) override { data.push_back(r); }
    std::vector<LoanRecord> all() override { return data; }
};

class LoanProcessor {
    std::shared_ptr<LoanRequestValidator> validator; 
    std::shared_ptr<LoanDueDateCalculator> calculator;
    std::shared_ptr<LoanRecordFactory> factory; 
    std::shared_ptr<LoanRepository> repository;
public:
    LoanProcessor(std::shared_ptr<LoanRequestValidator> v, std::shared_ptr<LoanDueDateCalculator> c, 
                  std::shared_ptr<LoanRecordFactory> f, std::shared_ptr<LoanRepository> r) 
        : validator(v), calculator(c), factory(f), repository(r) {}
        
    LoanRecord process(std::string memberId, std::string isbn, LocalDate today) {
        validator->validate(memberId, isbn);
        LoanRecord rec = factory->create(memberId, isbn, today, calculator->calculate(today));
        repository->save(rec);
        return rec;
    }
};

class LoanService {
    std::shared_ptr<LoanProcessor> processor;
public:
    LoanService(std::shared_ptr<LoanProcessor> processor) : processor(processor) {}
    LoanRecord borrow(std::string memberId, std::string isbn, LocalDate today) { 
        return processor->process(memberId, isbn, today); 
    }
};

int main() {
    auto service = std::make_shared<LoanService>(
        std::make_shared<LoanProcessor>(
            std::make_shared<LoanRequestValidator>(),
            std::make_shared<LoanDueDateCalculator>(std::make_shared<StandardLoanDueDateStrategy>()),
            std::make_shared<LoanRecordFactory>(),
            std::make_shared<InMemoryLoanRepository>()
        )
    );
    std::cout << service->borrow("M001", "978-0132350884", LocalDate{2026, 11, 8}) << "\n";
    return 0;
}
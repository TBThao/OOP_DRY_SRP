#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <numeric>

class ShoppingCart {
public:
    struct Line {
        std::string sku;
        long unitPrice;
        int quantity;
        long amount() const { return unitPrice * quantity; }
    };

private:
    std::unordered_map<std::string, Line> lines;

public:
    void addItem(const std::string& sku, long unitPrice, int quantity) {
        if (quantity <= 0) throw std::invalid_argument("quantity must be positive");
        if (lines.find(sku) != lines.end()) {
            lines[sku].quantity += quantity;
        } else {
            lines[sku] = Line{sku, unitPrice, quantity};
        }
    }

    void changeQuantity(const std::string& sku, int quantity) {
        auto it = lines.find(sku);
        if (it == lines.end()) throw std::invalid_argument("unknown sku " + sku);
        if (quantity <= 0) {
            lines.erase(it);
        } else {
            it->second.quantity = quantity;
        }
    }

    void removeItem(const std::string& sku) { lines.erase(sku); }
    void clear() { lines.clear(); }
    bool isEmpty() const { return lines.empty(); }
    int distinctItems() const { return lines.size(); }
    int quantityOf(const std::string& sku) const {
        auto it = lines.find(sku);
        return it == lines.end() ? 0 : it->second.quantity;
    }
    long subtotal() const {
        long total = 0;
        for (const auto& pair : lines) {
            total += pair.second.amount();
        }
        return total;
    }
};

int main() {
    ShoppingCart cart;
    cart.addItem("PEN", 5000, 2);
    cart.addItem("BOOK", 80000, 1);
    cart.addItem("PEN", 5000, 3);
    cart.changeQuantity("BOOK", 2);
    std::cout << "distinct=" << cart.distinctItems() 
              << ", pens=" << cart.quantityOf("PEN")
              << ", subtotal=" << cart.subtotal() << "\n";
    return 0;
}
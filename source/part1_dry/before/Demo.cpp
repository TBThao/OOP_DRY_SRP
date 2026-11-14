#include <iostream>
#include <vector>
#include "CartService.h"
#include "InvoiceService.h"
#include "NotificationService.h"

int main() {
    std::vector<long> items = {300000, 300000};
    long cart = CartService().previewTotal(items, false);
    long invoice = InvoiceService().finalTotal(items, false);
    
    std::cout << "Cart preview   : " << cart << "\n";
    std::cout << "Invoice total  : " << invoice << "\n";
    std::cout << "Banner         : " << NotificationService().shippingBanner() << "\n";
    if (cart != invoice) {
        std::cout << ">>> BUG: customer sees " << cart << " in the cart but is charged " << invoice << "\n";
    }
    return 0;
}
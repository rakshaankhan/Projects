#include <iostream>
#include <vector>
#include <iomanip>

class Item {
private:
    std::string name;
    double price;
    int quantity;

public:
    Item(std::string name, double price, int quantity) : name(name), price(price), quantity(quantity) {}

    double getTotalPrice() const {
        return price * quantity;
    }

    void display() const {
        std::cout << std::left << std::setw(20) << name
                  << std::setw(10) << price
                  << std::setw(10) << quantity
                  << std::setw(10) << getTotalPrice() << std::endl;
    }
};

class BillingSystem {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item) {
        items.push_back(item);
    }

    void displayBill() {
        double total = 0.0;
        std::cout << std::left << std::setw(20) << "Item"
                  << std::setw(10) << "Price"
                  << std::setw(10) << "Quantity"
                  << std::setw(10) << "Total" << std::endl;
        std::cout << "-------------------------------------------------" << std::endl;

        for (const auto& item : items) {
            item.display();
            total += item.getTotalPrice();
        }

        std::cout << "-------------------------------------------------" << std::endl;
        std::cout << std::right << std::setw(50) << "Grand Total: " << total << std::endl;
    }
};

int main() {
    BillingSystem billingSystem;
    char choice;

    do {
        std::string itemName;
        double price;
        int quantity;

        std::cout << "Enter item name: ";
        std::cin >> itemName;
        std::cout << "Enter item price: ";
        std::cin >> price;
        std::cout << "Enter item quantity: ";
        std::cin >> quantity;

        Item item(itemName, price, quantity);
        billingSystem.addItem(item);

        std::cout << "Do you want to add another item? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    billingSystem.displayBill();

    return 0;
}

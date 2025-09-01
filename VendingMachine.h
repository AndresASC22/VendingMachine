#pragma once
#include<string>
#include<iostream>
#include<vector>

// Vending Machine class
class VendingMachineClass {
    static constexpr int MAX_CAPACITY = 5;
    static constexpr int CODE_START = 100;
    static constexpr int CODE_INCREMENT = 100;

    struct Item { // Struct to give items a name, value and quantity;
        std::string name;
        float price;
        int quantity;
        const int code;
    };

    std::vector<Item> VendingMachine; // Vector to keep count of Item
public:
    VendingMachineClass() {
        std::vector<std::pair<std::string, float>> defaults = {
            {"Chips", 1.0},
            {"Soda", 1.75},
            {"Cookies", 1.5},
            {"Water", 1.5},
            {"Jerky", 2.5},
            {"Candy Bar", 2.0}
        };

        for (size_t i = 0; i < defaults.size(); i++) {
            VendingMachine.push_back({
                defaults[i].first,   // name
                defaults[i].second,  // price
                MAX_CAPACITY,        // quantity
                CODE_START + (int)i * CODE_INCREMENT // auto code
            });
        }
    }

    bool itemRemove(int code) {
        int item = getIndexByCode(code);
        if (item != -1) {
            if (VendingMachine[item].quantity > 0) {
                VendingMachine[item].quantity -= 1;
                return true;
            }
        }
        return false;
    }

    // Check if code is valid
    bool isCodeValid(int code) {
        return getIndexByCode(code) != -1;
    }
    
    float manageMoney(float& money, int& code) {
        int index = getIndexByCode(code);
        if (index == -1) return money;
        return money -= VendingMachine[index].price;
    }

    // Check if item is sold out by code
    bool isSold(int code) const {
        int index = getIndexByCode(code);
        if (index == -1) return true;
        return VendingMachine[index].quantity == 0;
    }

    int getIndexByCode(int code) const {
        for (int i = 0; i < (int)VendingMachine.size(); i++) {
            if (VendingMachine[i].code == code) return i;
        }
        return -1;
    }

    void refillItem(int index, int amount) {
        if (index >= 0 && index < (int)VendingMachine.size() && amount > 0) {
            int& currentQuantity = VendingMachine[index].quantity;

            if (currentQuantity == 5) {
                std::cout << VendingMachine[index].name << " is already at max capacity (5).\n";
                return;
            }

            if (currentQuantity + amount > 5) {
                currentQuantity = 5;
                std::cout << VendingMachine[index].name 
                        << " refilled to max capacity (5).\n";
            } else {
                currentQuantity += amount;
                std::cout << VendingMachine[index].name 
                    << " refilled to " << currentQuantity << ".\n";
            }
        } else {
            std::cout << "Invalid refill request.\n";
        }
    }

    bool isEmpty() const {
        for (const auto& item : VendingMachine) {
            if (item.quantity > 0) return false;
        }
        return true;
    }

    // A lot of return functions
    int returnSize() const { return VendingMachine.size(); }

    std::string returnName(int i) const { return VendingMachine.at(i).name; }

    float returnPrice(int i) const { return VendingMachine.at(i).price; }

    int returnQuantity(int i) const { return VendingMachine.at(i).quantity; }

    int returnCode(int i) const { return VendingMachine.at(i).code; }
};

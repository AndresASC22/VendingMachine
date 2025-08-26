#pragma once
#include<string>
#include<iostream>
#include<vector>

// Vending Machine class
class VendingMachineClass {
    struct Item { // Struct to give items a name, value and quantity;
        std::string name;
        float price;
        int quantity;
        const int code;
    };
    std::vector<Item> VendingMachine; // Vector to keep count of Item
public:
    VendingMachineClass()
        : VendingMachine{ // Constructor here
            {"Chips", 1.0, 1, 100},
            {"Soda", 1.75, 0, 200},
            {"Cookies", 1.5, 0, 300},
            {"Water", 1.5, 0, 400},
            {"Jerky", 2.5, 0, 500},
            {"Candy Bar", 2.0, 0, 600}
        } {}

    // Item removal
    bool itemRemove(int code) {
        for (auto& item : VendingMachine) {
            if (item.code == code) {
                if (item.quantity > 0) {
                    item.quantity -= 1;
                    return true;
                } else {
                    return false;
                }
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
        if (money == VendingMachine[index].price) {
            itemRemove(code);
            return 0;  // Exact amount received
        } else if (money > VendingMachine[index].price) {
            money -= VendingMachine[index].price;
            return money;
        } else {
            return -1; // Insufficient funds
        }
    }

    // Check if item is sold out by code
    bool isSold(int code) const {
        for (const auto& item : VendingMachine) {
            if (item.code == code) {
                return item.quantity == 0; // true if sold out
            }
        }
        return true;
    }

    int getIndexByCode(int code) {
        for (int i = 0; i < (int)VendingMachine.size(); i++) {
            if (VendingMachine[i].code == code) {
                return i;
            }
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

    // Helper to see if the machine is empty
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

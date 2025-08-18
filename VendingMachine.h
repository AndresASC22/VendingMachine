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
            {"Chips", 1.0, 5, 100},
            {"Soda", 1.75, 5, 200},
            {"Cookies", 1.5, 5, 300},
            {"Water", 1.5, 5, 400},
            {"Jerky", 2.5, 5, 500},
            {"Candy Bar", 2.0, 5, 600}
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

    // Check if item is sold out by code
    bool isSold(int code) const {
        for (const auto& item : VendingMachine) {
            if (item.code == code) {
                return item.quantity == 0; // true if sold out
            }
        }
        return true;
    }

    // Optional: helper to see if the machine is empty
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

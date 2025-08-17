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
        for (size_t i = 0; i < VendingMachine.size(); i++) {
            if (VendingMachine[i].code == code) {
                if (VendingMachine[i].quantity > 0) {
                    VendingMachine[i].quantity -= 1;
                    return true;
                } else {
                    return false; // code is valid, but out of stock
                }
            }
        }
        return false; // code not found
    }

    // A lot of return functions
    int returnSize() const { return VendingMachine.size(); }

    std::string returnName(int i) const { return VendingMachine.at(i).name; }

    float returnPrice(int i) const { return VendingMachine.at(i).price; }

    int returnQuantity(int i) const { return VendingMachine.at(i).quantity; }

    int returnCode(int i) const { return VendingMachine.at(i).code; }
};

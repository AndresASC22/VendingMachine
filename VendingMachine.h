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
    bool itemRemove(int c){        
        int selected = 0;
        selected = c;
        for (int i = 0; i < VendingMachine.size(); i++) {
            if (selected == VendingMachine.at(i).code && VendingMachine.at(i).quantity > 0) {
                VendingMachine.at(i).quantity -= 1;
                return true;
            } 
        }
        return false;
    }
};

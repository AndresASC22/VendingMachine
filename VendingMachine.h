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
    };
    std::vector<Item> VendingMachine; // Vector to keep count of Item
public:
    VendingMachineClass()
        : VendingMachine{ // Constructor here
            {"Chips", 1.0, 5},
            {"Soda", 1.75, 5},
            {"Cookies", 1.5, 5},
            {"Water", 1.5, 5},
            {"Jerky", 2.5, 5},
            {"Candy Bar", 2.0, 5}
        } {}
    
    // Getters for single items
    void getItems() const {
        for (const auto& item : VendingMachine)
            std::cout << item.name << std::endl;
    }

    void getPrice() const {
        for (const auto& item : VendingMachine)
            std::cout << item.price << std::endl;
    }

    void getQuantity() const {
        for (const auto& item : VendingMachine)
            std::cout << item.quantity << std::endl;
    }

    // Display entire inventory
    void displayInventory() const {
        for (const auto& item : VendingMachine)
            std:: cout << "Name: " << item.name <<
            ", Price: $" << item.price << ", Quantity: " << item.quantity << std::endl;
    }

};

#include<string>
#include<iostream>
#include<unordered_map>
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
    VendingMachineClass() { // Constructor for the Vending Machine
        std::vector<Item> VendingMachine = {
            {"Chips", 1.0, 5},
            {"Soda", 1.75, 5},
            {"Cookies", 1.5, 5},
            {"Water", 1.5, 5},
            {"Jerky", 2.5, 5},
            {"Candy Bar", 2.0, 5}
        };
    }

    void getItems() {
        for (int i = 0; i < VendingMachine.size(); i++) 
            std::cout << VendingMachine[i].name << std::endl;    
    }
};

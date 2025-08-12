#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>

// Vending Machine class
class VendingMachineClass {
    // unordered hashmap to give items a name and value;
    std::unordered_map<std::string, float> VendingMachine;
    std::vector<int> ItemAmount; // vector to keep count of 
public:
    VendingMachineClass() {
        VendingMachine = { // constructor to set the items and their prices
            {"Chips", 1.0}, {"Soda", 1.75}, {"Cookies", 1.5},
            {"Water", 1.5}, {"Jerky", 2.5}, {"Candy Bar", 2.0}
        };

        // adding the amount of items for each set of items
        for(int i = 0; i < VendingMachine.size(); i++)
            ItemAmount.push_back(5);
        for(int i = 0; i < ItemAmount.size(); i++) 
            std::cout << ItemAmount.at(i) << std::endl;
    }
    
};
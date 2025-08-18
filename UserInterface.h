#include "VendingMachine.h"
#include<limits>

void displayInventory(const VendingMachineClass& vm) {
    for (int i = 0; i < vm.returnSize(); i++) {
        std::cout << "Name: " << vm.returnName(i) << ", Price: $" << vm.returnPrice(i) <<
        ", Quantity: " << vm.returnQuantity(i) << " left, " << "Code: " << vm.returnCode(i) << std::endl;
    }
}

void errorMessage(const std::string& msg) {
    std::cout << "Error: " << msg << std::endl;
}

// Calls all the functions
void selectItem(VendingMachineClass& vm) {
    while (true) {
        if (vm.isEmpty()) {
            std::cout << "The vending machine is sold out! Goodbye.\n";
            break; // Exit loop if everything is gone
        }

        displayInventory(vm);
        int choice;
        std::cout << "Enter the number of the item you want, enter 0 to exit: ";
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            errorMessage("Invalid input. Please enter a number.");
            continue;
        }

        if (choice == 0) break;

        if (vm.itemRemove(choice)) 
            std::cout << "Item dispensed!\n";
        else if (vm.isSold(choice)) 
            errorMessage("Item is sold out!");
        else 
            errorMessage(std::to_string(choice) + " is not a valid option.");   
    }
}

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

void refillMode(VendingMachineClass& vm) {
    while (true) {
        std::cout << "\n--- Refill Mode ---\n";
        for (int i = 0; i < vm.returnSize(); i++) {
            std::cout << i + 1 << ". " << vm.returnName(i) 
                      << " (Current: " << vm.returnQuantity(i) << ")\n";
        }
        std::cout << "Enter item number to refill (0 to exit): ";
        
        int choice;
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, try again.\n";
            continue;
        }

        if (choice == 0) break;

        if (choice < 1 || choice > vm.returnSize()) {
            std::cout << "Invalid item number.\n";
            continue;
        }

        int amount;
        std::cout << "Enter amount to add: ";
        std::cin >> amount;

        if (amount <= 0) {
            std::cout << "Amount must be positive.\n";
            continue;
        }

        vm.refillItem(choice - 1, amount);
        std::cout << "Refilled " << vm.returnName(choice - 1) 
                  << " by " << amount << " units.\n";
    }
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
        std::cout << "\nEnter the number of the item you want, enter 0 to exit: ";
        std::cin >> choice;

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            errorMessage("Invalid input. Please enter a number.");
            continue;
        }

        if (choice == 0) break;

        if (choice == -1) {
            refillMode(vm);
            continue; // return to normal menu after refill
        }
        if (vm.itemRemove(choice)) 
            std::cout << "Item dispensed!\n";
        else if (vm.isSold(choice)) 
            errorMessage("Item is sold out!");
        else 
            errorMessage(std::to_string(choice) + " is not a valid option.");   
    }
}

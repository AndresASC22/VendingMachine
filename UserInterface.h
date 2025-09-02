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

void handleInvalidInput() {
    std::cin.clear(); // Clear error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard bad input
    errorMessage("Invalid input. Please enter a number.");
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
            handleInvalidInput();
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

float insertCash(int index, const VendingMachineClass& vm) {
    float money;
    float price = vm.returnPrice(index);
    while (true) {
        std::cout << "Insert $" << price << ": ";
        std::cin >> money;

        if (std::cin.fail()) {
            handleInvalidInput();
        } else if (money <= 0) {
            std::cout << "Invalid input. Please enter a positive number.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return money;
        }
    }
}

// Calls all the functions
void selectItem(VendingMachineClass& vm) {
    while (true) {
        if (vm.isEmpty()) {
            std::cout << "The vending machine is sold out! Enter 'refill' to restock.\n";
            std::string command;
            std::cin >> command;
            if (command == "refill") {
                refillMode(vm);
                continue;
            }
            break; // Exit loop if everything is gone
        }

        displayInventory(vm);
        int choice;
        std::cout << "\nEnter the number of the item you want, enter 0 to exit: ";
        std::cin >> choice;

        if (!std::cin) {
            handleInvalidInput();
            continue;
        }

        if (choice == 0) break;
        
        if (choice == -1) {
            refillMode(vm);
            continue;
        }

        if (!vm.isCodeValid(choice)) {
            std::cout << "Invalid item code.\n";
        } else if (vm.isSold(choice)) {
            std::cout << "Item is sold out!\n";
        } else { // Valid and not sold out case 
            int index = vm.getIndexByCode(choice);
            float money = insertCash(index, vm);
            float change = vm.manageMoney(money, choice);

            if (change == 0) {
                vm.itemRemove(choice);
                std::cout << "Item dispensed!\n";
            } else if (change > 0) {
                vm.itemRemove(choice);
                std::cout << "Item dispensed! Your change is: $" << change << "\n"; 
            } else {
                std::cout << "Insufficient funds. Please insert more money.\n";
            }
        }
    }
}
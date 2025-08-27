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
            continue; // return to normal menu after refill
        }

        // Called when item is sold out
        if (vm.isSold(choice) && vm.isCodeValid(choice)) {
            std::cout << "Item is sold out!\n";
        }

        if (vm.isCodeValid(choice) && !vm.isSold(choice)) {
            // Proceed with item selection
            int index = vm.getIndexByCode(choice);
            while (true) { // Loop for inserting cash
                float money = insertCash(index, vm);
                if (money > 0) {
                    float change = vm.manageMoney(money, choice);
                    if (change == 0) {
                        vm.itemRemove(choice);
                        std::cout << "Item dispensed!\n";
                        break;
                    } else if (change > 0) {
                        vm.itemRemove(choice);
                        std::cout << "Item dispensed! Your change is: $" << change << "\n"; 
                        break;
                    }  else if (change < vm.returnPrice(index)) {
                        std::cout << "Insufficient funds. Please insert more money.\n";
                    }
                }
            }
        }
    }
}

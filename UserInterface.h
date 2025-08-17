#include "VendingMachine.h"

void displayInventory(const VendingMachineClass& vm) {
    for (int i = 0; i < vm.returnSize(); i++) {
        std::cout << "Name: " << vm.returnName(i) << ", Price: $" << vm.returnPrice(i) <<
        ", Quantity: " << vm.returnQuantity(i) << " left, " << "Code: " << vm.returnCode(i) << std::endl;
    }
}

void errorMessage(int c) {
    std::cout << "Error: " << c << " is not a valid option." << std::endl;
}

// Calls all the functions
void selectItem(VendingMachineClass& vm) {
    displayInventory(vm);
    int choice;
    std::cout << "Enter the number of the item you want: ";
    std::cin >> choice;

    if (vm.itemRemove(choice)) {
        displayInventory(vm);
    } else {
        errorMessage(choice);
    }
}

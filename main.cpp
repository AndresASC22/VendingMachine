#include"UserInterface.h"

int main() {
   VendingMachineClass Machine1;
   std::cout << Machine1.itemRemove(100) << std::endl;
   displayInventory(Machine1);

   return 0;
}

#include "./../include/pfm/Ledger.h"
#include "./../include/pfm/Income.h" 
#include "./../include/pfm/Expense.h"
#include "./../include/pfm/ConsoleUI.h"  





int main() { 
    std::cout << "Personal Finance Manager - Project Skeleton\n\n";

    Ledger myLedger;

    ConsoleUI ui(myLedger);

    ui.run();
    

    return 0; 
} 

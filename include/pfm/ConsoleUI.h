#ifndef PFM_CONSOLEUI_H 
#define PFM_CONSOLEUI_H 





#include <string>
#include "Ledger.h"





class ConsoleUI
{
    Ledger& ledger;

    void displayMenu() const;
    void handleAddIncome();
    void handleAddExpense();
    void handleViewBalance() const;
    void handleViewTransactions() const;

    public:
    ConsoleUI(Ledger& ledger);
    void run();
};
 
#endif // PFM_CONSOLEUI_H 

#ifndef PFM_LEDGER_H 
#define PFM_LEDGER_H 
 




#include "Transaction.h"




class Ledger
{
    double currentBalance;
    std::vector<std::unique_ptr<Transaction>> transactions;

    public:
    Ledger();
    double getCurrentBalance() const;
    void addTransaction(std::unique_ptr<Transaction> t);
    void displayAllTransactions() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

 
#endif // PFM_LEDGER_H 

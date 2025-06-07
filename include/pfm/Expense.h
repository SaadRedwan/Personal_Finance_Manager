#ifndef PFM_EXPENSE_H 
#define PFM_EXPENSE_H 
 




#include "Transaction.h"
 



class Expense: public Transaction
{
    public:
    Expense(double amount, const std::string& date, const std::string& description);
    std::string getType() const override;
    void display() const override;
};





#endif // PFM_EXPENSE_H 

#ifndef PFM_INCOME_H 
#define PFM_INCOME_H 





#include "Transaction.h"




class Income: public Transaction
{
    public:
    Income(double amount, const std::string& date, const std::string& description);
    std::string getType() const override;
    void display() const override;
};





#endif // PFM_INCOME_H 

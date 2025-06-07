#ifndef PFM_TRANSACTION_H 
#define PFM_TRANSACTION_H 
 




#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include <vector>
#include <cmath>




class Transaction
{
    double amount; 
    std::string date; 
    std::string description;

    public:
    Transaction(double amount, const std::string& date, const std::string& description);
    double getAmount() const;
    std::string getDate() const;
    std::string getDescription() const;

    virtual std::string getType() const = 0; 
    virtual void display() const;
    
    virtual ~Transaction() = default;
};





#endif // PFM_TRANSACTION_H 

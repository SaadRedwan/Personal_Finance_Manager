#include "./../include/pfm/Expense.h"





Expense::Expense(double amount, const std::string& date, const std::string& description):Transaction::Transaction(amount, date, description){}
std::string Expense::getType() const 
{
    return "EXPENSE";
}
void Expense::display() const 
{
    std::cout<<"[EXPENSE] ";
    Transaction::display();
    std::cout<<std::endl;
}
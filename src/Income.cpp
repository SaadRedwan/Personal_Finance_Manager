#include "./../include/pfm/Income.h"





Income::Income(double amount, const std::string& date, const std::string& description):Transaction::Transaction(amount, date, description){}
std::string Income::getType() const 
{
    return "INCOME";
}
void Income::display() const 
{
    std::cout<<"[INCOME]  ";
    Transaction::display();
    std::cout<<std::endl;
}
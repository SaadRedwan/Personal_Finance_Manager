#include "./../include/pfm/Transaction.h"





Transaction::Transaction(double amount, const std::string& date, const std::string& description): amount(amount), date(date), description(description){}
double Transaction::getAmount() const
{
    return amount;
}
std::string Transaction::getDate() const
{
    return date;
}
std::string Transaction::getDescription() const
{
    return description;
}
void Transaction::display() const
{
    std::cout<<std::setw(15)<<date;
    std::cout<<std::fixed<<std::setprecision(2)<<std::setw(15)<<amount;
    std::cout<<std::setw(28)<<description;
    // std::cout<<"Date: "<<date;
    // std::cout<<", Amount: "<<std::fixed<<std::setprecision(2)<<std::setw(15)<<amount;
    // std::cout<<", Description: "<<description;
    // std::cout <<
    //     "┌──────────┬────────────┬──────────────────────────┐\n"
    //     "│  Date    │   iomanip  │      representation      │\n"
    //     "├──────────┼────────────┼──────────────────────────┤\n";
    //     std::cout << std::left
    // << "│ " << std::setw(8) << text <<      " │ fixed      │ "
    // << std::setw(24) << std::fixed  << num <<            " │\n"
    // << "│ " << std::setw(8) << text <<      " │ scientific │ "
    // << std::setw(24) << std::scientific << num <<        " │\n"
    // << "│ " << std::setw(8) << text <<      " │ hexfloat   │ "
    // << std::setw(24) << std::hexfloat << num <<          " │\n"
    // << "│ " << std::setw(8) << text <<      " │ default    │ "
    // << std::setw(24) << std::defaultfloat << num <<      " │\n";
    // std::cout << (c != cap::end ?
    //     "├──────────┼────────────┼──────────────────────────┤\n" :
    //     "└──────────┴────────────┴──────────────────────────┘\n");
}

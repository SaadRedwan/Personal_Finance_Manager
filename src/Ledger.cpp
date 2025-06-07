#include <fstream>
#include <sstream> 
#include <stdexcept>
#include "./../include/pfm/Ledger.h"
#include "./../include/pfm/Income.h" 
#include "./../include/pfm/Expense.h" 





Ledger::Ledger(): currentBalance(0.0) {}
double Ledger::getCurrentBalance() const
{
    return currentBalance;
}

void Ledger::addTransaction(std::unique_ptr<Transaction> t)
{
    if(t != NULL) {
        std::string type = t->getType();
        if(type == "INCOME") {    
                currentBalance += t->getAmount();
                transactions.push_back(std::move(t));
            }
        if(type == "EXPENSE") {
            currentBalance -= t->getAmount();
            transactions.push_back(std::move(t));
        }
    }
}

void Ledger::displayAllTransactions() const
{
    if(!transactions.empty()) {
        
        std::cout<<"TYPE";
        std::cout<<std::setw(15)<<"Date";
        std::cout<<std::setw(20)<<"Amount";
        std::cout<<std::setw(28)<<"Description"<<std::endl;

        std::vector<std::unique_ptr<Transaction>>::const_iterator itr;

        itr = transactions.begin();

        for(; itr != transactions.end(); itr++) {
            (*itr)->display();
        }
    }
}

void Ledger::saveToFile(const std::string& filename) const
{
    std::ofstream outFile;

    outFile.open(filename);
    if (!outFile.is_open()) { 
        std::cout<<"Can not open the file: "<<filename<<" to save data"<<std::endl; 
        return;
    }
    outFile<<"Type"<<","
           <<"Date"<<","
           <<"Amount"<<","
           <<"Description"<<std::endl;
    
    std::vector<std::unique_ptr<Transaction>>::const_iterator itr;
    itr = transactions.begin();

    for(; itr != transactions.end(); itr++) {
        outFile << (*itr)->getType() << ","
                << (*itr)->getDate() << ","
                << std::fixed << std::setprecision(2) << (*itr)->getAmount() << ","
                << (*itr)->getDescription() << std::endl;
    }
    outFile.close();
    std::cout<<"Data saved in the: "<<filename<<" csv file."<<std::endl;
}

void Ledger::loadFromFile(const std::string& filename)
{
    std::ifstream inputFile;

    inputFile.open(filename);
    if (!inputFile.is_open()) { 
        std::cout<<"No existing data file found or could not open: "<<filename<<" to load data"<<std::endl; 
        return;
    }

    transactions.clear();
    currentBalance = 0.0;

    std::string line;
    //skip header
    std::getline(inputFile, line);
    while (std::getline(inputFile, line)) { 
        std::stringstream ss(line);
        std::string type;
        std::string date;
        std::string amountStr;
        std::string description;

        double amount;
        
        std::getline(ss, type, ',');
        std::getline(ss, date, ',');
        std::getline(ss, amountStr, ',');
        std::getline(ss, description, ',');

        try {
            amount = std::stod(amountStr); 
        } catch (const std::invalid_argument&) {
            std::cerr << "Warning: Invalid amount format in file. Skipping line: " << line << std::endl;
            continue;
        } catch (const std::out_of_range&) {
            std::cerr << "Warning: Amount out of range in file. Skipping line: " << line << std::endl;
            continue;
        }

        std::unique_ptr<Transaction> newTransaction;

        if(type == "INCOME") {
            newTransaction = std::make_unique<Income>(amount, date, description);
        } else if(type == "EXPENSE") {
            newTransaction = std::make_unique<Expense>(amount, date, description);
        } else {
            std::cerr << "Warning: Invalid type in file. Skipping line: " << line << std::endl;
            continue;
        }
        if(newTransaction != nullptr) {
            std::string type = newTransaction->getType();
            if(type == "INCOME") {    
                    currentBalance += newTransaction->getAmount();
                }
            if(type == "EXPENSE") {
                currentBalance -= newTransaction->getAmount();
            }
            transactions.push_back(std::move(newTransaction));
        }
    }
    if(!transactions.empty()) {
        std::cout<<"Data Loaded"<<std::endl;
    } else {
        std::cout<<"No existing data found... Starting fresh."<<std::endl;
    }
        
    inputFile.close();
}

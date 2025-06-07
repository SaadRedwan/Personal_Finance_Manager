#include <iostream> 
#include <sstream>
#include <memory> 
#include <iomanip>
#include <ctime>
#include <limits> 
#include "./../include/pfm/ConsoleUI.h"
#include "./../include/pfm/Income.h"
#include "./../include/pfm/Expense.h" 




ConsoleUI::ConsoleUI(Ledger& ledger): ledger(ledger) {}

void ConsoleUI::run()
{
    bool running = true; 
    int choice;

    ledger.loadFromFile("./../data/transactions.csv");

    while(running) {
        
        
        displayMenu();
        std::cout<<"Enter your choice: ";

        std::cin >> choice;
        while(choice > 5 || choice <= 0 || std::cin.fail()) {
            std::cin.clear();
            std::cout<<"\nThis is not a valid choice\n";
            displayMenu();
            std::cout<<"Please enter a valid choice: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cin>>choice;
        }

        switch (choice) {
            case 1: { 
                handleAddIncome();
                break;
            }
            case 2: {
                handleAddExpense(); 
                break;
            }
            case 3: { 
                handleViewBalance(); 
                break;
            }
            case 4: {
                 handleViewTransactions(); 
                 break; 
            }
            case 5: { 
                std::cout << "Exiting...."<< std::endl; 
                ledger.saveToFile("./../data/transactions.csv");
                running = false; 
                std::cout<<"Goodbye!"<<std::endl; 
                break;
            }
        }
    }
}

void ConsoleUI::displayMenu() const
{
    std::cout<<std::endl;
    std::cout<<"--- Personal Finance Manager ---"<<std::endl;
    
    std::cout<<"1. Add Income"<<std::endl;
    std::cout<<"2. Add Expense"<<std::endl;
    std::cout<<"3. View Balance"<<std::endl;
    std::cout<<"4. View All Transactions"<<std::endl;
    std::cout<<"5. Save & Exit"<<std::endl;
}

void ConsoleUI::handleAddIncome()
{
    double amount;
    std::string date;
    std::string description;

    std::cout<<std::endl;
    std::cout<<"Enter the amount of your income transaction: ";
    std::cin >> amount;

    while(amount < 0 || std::cin.fail()) {
        std::cin.clear();
        std::cout<<"\nThis is not a valid amount\n";
        std::cout<<"Please enter a valid amount: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cin>>amount;
    }

    std::cout<<std::endl;
    std::cout<<"The date of today will be set as the date of this transaction."<<std::endl;
    
    std::time_t t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);
    std::vector<char> buffer(11); 
    std::strftime(buffer.data(), buffer.size(), "%d.%m.%Y", &tm);
    date = buffer.data();
    std::cout<<"Date: "<<date;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Enter the description of your income transaction: ";
    std::getline(std::cin, description);

    std::cout<<std::endl;

    // std::unique_ptr<Transaction> income = std::make_unique<Income>(amount, date, description);
    
    ledger.addTransaction(std::make_unique<Income>(amount, date, description));
}
void ConsoleUI::handleAddExpense()
{
    double amount;
    std::string date;
    std::string description;

    std::cout<<std::endl;
    std::cout<<"Enter the amount of your expense transaction: ";
    std::cin >> amount;

    while(amount < 0 || std::cin.fail()) {
        std::cin.clear();
        std::cout<<"\nThis is not a valid amount\n";
        std::cout<<"Please enter a valid amount: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cin>>amount;
    }

    std::cout<<std::endl;
    std::cout<<"The date of today will be set as the date of this transaction."<<std::endl;
    std::time_t t = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &t);
    std::vector<char> buffer(11); 
    std::strftime(buffer.data(), buffer.size(), "%d.%m.%Y", &tm);
    date = buffer.data();
    std::cout<<"Date: "<<date;

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Enter the description of your expense transaction: ";
    std::getline(std::cin, description);

    std::cout<<std::endl;

    // Expense expense = std::make_unique<Expense>(amount, date, description);
    
    ledger.addTransaction(std::make_unique<Expense>(amount, date, description));
}
void ConsoleUI::handleViewBalance() const
{
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Your current balance is: ";
    std::cout<<std::fixed<<std::setprecision(2);
    std::cout<<ledger.getCurrentBalance();
    std::cout<<std::endl;
}
void ConsoleUI::handleViewTransactions() const
{
    std::cout<<std::endl;
    std::cout<<std::endl;
    ledger.displayAllTransactions();
    std::cout<<std::endl;
    std::cout<<std::endl;
}
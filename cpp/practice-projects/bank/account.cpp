#include "iostream"

class account {
    int balance;
    std::string username;

    public:
        account()
        {
            balance = 0;
            username = "";
        }
        account(std::string name, int bal)
        {
            username = name;
            balance = bal;
        }
        ~account()
        {
            std::cout << "account " << username << " has been destructed from " << this << std::endl;
        }
        int getBalance()
        {
            return balance;
        }
        std::string getUsername()
        {
            return username;
        }

};
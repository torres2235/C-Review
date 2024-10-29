#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account(name, balance, int_rate){
}

bool Trust_Account::deposit(double amount) {
    if(amount >= 5000) {
        amount += 50;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    if(withdraw_amt > 0 && amount <= balance * 0.2) {
        withdraw_amt--;
        return Account::withdraw(amount);
    }
    return false;
}


std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.withdraw_amt << "withdraws left]";
    return os;
}
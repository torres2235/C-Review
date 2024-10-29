#include "Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double transaction_rate)
    : Account {name, balance}, transaction_rate{transaction_rate} {
}

bool Checking_Account::withdraw(double amount) {
    amount += transaction_rate;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", $" << account.transaction_rate << "]";
    return os;
}

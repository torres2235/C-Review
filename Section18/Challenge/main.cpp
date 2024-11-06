#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "IllegalBalanceException.h"
#include "InsufficentFundsException.h"

using namespace std;

int main() {
    // test your code here
    try {
        std::unique_ptr<Account> moe = std::make_unique<Checking_Account>("Moe", 10.0);
        std::unique_ptr<Account> larry = std::make_unique<Savings_Account>("Larry", 10.0);
        std::unique_ptr<Account> currly = std::make_unique<Trust_Account>("Currly", 10.0);
        moe->withdraw(11);
    }
    catch (const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch(const InsufficentFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}


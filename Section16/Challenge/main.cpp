// Section 16 
// Challenge 
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
    
    // Savings 

    vector<Account *> sav_accounts;
    Account *s1 = new Savings_Account();
    Account *s2 = new Savings_Account("Superman");
    Account *s3 = new Savings_Account("Batman", 2000);
    Account *s4 = new Savings_Account("Wonderwoman", 5000, 5.0);
    sav_accounts.push_back(s1);
    sav_accounts.push_back(s2);
    sav_accounts.push_back(s3);
    sav_accounts.push_back(s4);
    
    Savings_Account frank {"frank", 5000, 5.0};
    
    std::cout << frank << endl;
    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    
    //Checking

    vector<Account *> chk_accounts;
    Account *c1 = new Checking_Account();
    Account *c2 = new Checking_Account("dude");
    Account *c3 = new Checking_Account("guy", 2000);
    chk_accounts.push_back(c1);
    chk_accounts.push_back(c2);
    chk_accounts.push_back(c3);
    
    display(chk_accounts);
    deposit(chk_accounts, 1000);
    withdraw(chk_accounts, 2000);

    
    //Checking

    vector<Account *> trust_accounts;
    Account *t1 = new Trust_Account();
    Account *t2 = new Trust_Account("man");
    Account *t3 = new Trust_Account("woman", 2000);
    Account *t4 = new Trust_Account("lady", 2000, 10.0);
    trust_accounts.push_back(t1);
    trust_accounts.push_back(t2);
    trust_accounts.push_back(t3);
    trust_accounts.push_back(t4);
    
    display(trust_accounts);
    deposit(trust_accounts, 1000);
    withdraw(trust_accounts, 2000);
    
    
    return 0;
}


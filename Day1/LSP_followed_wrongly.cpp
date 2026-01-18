#include <iostream>
#include<vector>
#include <typeinfo>
#include <stdexcept>


using namespace std;
class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};
class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount()
    {
        balance = 0;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited:" << amount << "in saving Account. new Balance:" << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn:" << amount << "in saving Account. new Balance:" << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in saving account";
        }
    }
};
class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount()
    {
        balance = 0;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited:" << amount << "in current Account. new Balance:" << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn:" << amount << "in current Account. new Balance:" << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in saving account";
        }
    }
};
class FixedTermAccount:public Account{
    private:
    double balance;
    public:
    FixedTermAccount(){
        balance=0;

    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited:" << amount << "in fixed term Account. new Balance:" << balance << endl;
    }
   void withdraw(double amount){
    throw logic_error("Withdrawal not allowed in fixed term account");
   }
};
class BankClient{
    private:
    vector<Account*>accounts;
public:
    BankClient(vector<Account*>accounts){
      this->accounts=accounts;
    }
    void processTransaction(){
      for(Account*acc:accounts){
        acc->deposit(1000);
      
     if(typeid(*acc)==typeid(FixedTermAccount)){
        cout<<"Skipping withdrawal for the fixed term account";
     }
     else{
        try{
            acc->withdraw(500);
        }
        catch(const logic_error &e){
            cout<<"Exception:"<<e.what()<<endl;
        }
     }
    }
    }
};
    


int main()
{
    vector<Account*>accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrentAccount());
    accounts.push_back(new FixedTermAccount());
    BankClient*client=new BankClient(accounts);
    client->processTransaction();
}
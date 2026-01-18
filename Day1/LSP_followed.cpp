#include <iostream>
#include <vector>
#include <typeinfo>
#include <stdexcept>

using namespace std;
class DepositOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
};
class WithdrawableAccount : public DepositOnlyAccount
{
public:
    virtual void withdraw(double amount) = 0;
};
class SavingAccount : public WithdrawableAccount
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
        cout << "Deposited:" << amount << "in fixed term Account. new Balance:" << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn:" << amount << "From saving account .New Balance" << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Saving Account" << endl;
        }
    }
};
class CurrentAccount : public WithdrawableAccount
{
private:
    double balance;
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit:" << amount << "From deposit account .New Balance" << balance << endl;
    }
    void withdraw(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawn:" << amount << "From current account .New Balance" << balance << endl;
        }
        else
        {
            cout << "Insufficient funds in Current Account" << endl;
        }
    }
};
class FixedTermAccount : public DepositOnlyAccount
{
private:
    double balance;

public:
    FixedTermAccount()
    {
        balance = 0;
    }
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit:" << amount << "in fixed term account .New Balance" << balance << endl;
    }
};
class BankClient
{
private:
    vector<WithdrawableAccount*> withdrawableAccounts;
    vector<DepositOnlyAccount*> depositOnlyAccounts;

public:
    BankClient(
        vector<WithdrawableAccount*> withdrawableAccounts,
        vector<DepositOnlyAccount*> depositOnlyAccounts
    ) {
        this->withdrawableAccounts = withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }
    void processTransactions(){
        for(WithdrawableAccount *acc:withdrawableAccounts){
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for(DepositOnlyAccount*acc:depositOnlyAccounts){
            acc->deposit(5000);
        }
    }
};


int main()
{
    vector<WithdrawableAccount*> WithdrawableAccount;
    WithdrawableAccount.push_back(new SavingAccount());
    WithdrawableAccount.push_back(new CurrentAccount());
    vector<DepositOnlyAccount*>DepositOnlyAccount;
    DepositOnlyAccount.push_back(new FixedTermAccount());
    BankClient*client=new BankClient(WithdrawableAccount,DepositOnlyAccount);
    client->processTransactions();
    return 0;
}
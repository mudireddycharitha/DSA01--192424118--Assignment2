
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount
{
private:

    struct Transaction
    {
        string type;
        double amount;
    };

    long long accountNumber;
    double balance;

    Transaction transactions[10];

    int count;
    int nextIndex;

    void addTransaction(const string& type, double amount)
    {
        transactions[nextIndex].type = type;
        transactions[nextIndex].amount = amount;

        nextIndex = (nextIndex + 1) % 10;

        if (count < 10)
        {
            count++;
        }
    }

public:

    SavingsAccount(long long accNo, double initialBalance)
        : accountNumber(accNo),
          balance(initialBalance),
          count(0),
          nextIndex(0)
    {
    }

    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount);

    void withdraw(double amount);

    void miniStatement() const;
};

void SavingsAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount.\n";
        return;
    }

    balance += amount;

    addTransaction("Deposit", amount);

    cout << "Deposited: Rs. " << amount << '\n';
}

void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        cout << "Withdrawal failed.\n";
        return;
    }

    balance -= amount;

    addTransaction("Withdrawal", amount);

    cout << "Withdrawn: Rs. " << amount << '\n';
}

void SavingsAccount::miniStatement() const
{
    cout << "\n====================================\n";
    cout << "          MINI STATEMENT\n";
    cout << "====================================\n";

    cout << "Account Number: " << accountNumber << '\n';
    cout << "Balance       : Rs. " << balance << '\n';

    cout << "\nRecent Transactions:\n";

    if (count == 0)
    {
        cout << "No transactions available.\n";
        return;
    }

    int start = (nextIndex - count + 10) % 10;

    for (int i = 0; i < count; i++)
    {
        int index = (start + i) % 10;

        cout << i + 1 << ". "
             << transactions[index].type
             << " : Rs. "
             << transactions[index].amount
             << '\n';
    }
}

int main()
{
    SavingsAccount account(10001, 5000);

    cout << "====================================\n";
    cout << "      SAVINGS ACCOUNT SYSTEM\n";
    cout << "====================================\n";

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.deposit(400);
    account.withdraw(100);
    account.deposit(600);
    account.withdraw(200);
    account.deposit(800);
    account.withdraw(150);
    account.deposit(900);

    account.miniStatement();

    return 0;
}

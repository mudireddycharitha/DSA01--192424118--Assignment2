
#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent)
{
    fee -= fee * percent / 100;
    cout << "Inside call by value: " << fee << '\n';
}

void applyByReference(long long& fee, int percent)
{
    fee -= fee * percent / 100;
}

void applyByPointer(long long* fee, int percent)
{
    if (fee != nullptr)
    {
        *fee -= *fee * percent / 100;
    }
}

void displayFee(const long long& fee)
{
    cout << "Current fee: Rs. " << fee << '\n';
}

long long returnConcession(long long fee, int percent)
{
    return fee - (fee * percent / 100);
}

void change(int a, int& b, int* c)
{
    a += 10;
    b += 10;
    *c += 10;
}

int& bigger(int& p, int& q)
{
    return p > q ? p : q;
}

void show(int x, int y = 5, int z = 10)
{
    cout << x + y + z << ' ';
}

int main()
{
    cout << "====================================\n";
    cout << "     HOSTEL FEE CONCESSION SYSTEM\n";
    cout << "====================================\n";

    long long fee1 = 45000;
    long long fee2 = 45000;
    long long fee3 = 45000;

    applyByValue(fee1, 10);
    cout << "After call by value     : " << fee1 << '\n';

    applyByReference(fee2, 10);
    cout << "After call by reference : " << fee2 << '\n';

    applyByPointer(&fee3, 10);
    cout << "After call by pointer   : " << fee3 << '\n';

    cout << "\n--- Const Reference ---\n";
    displayFee(fee2);

    cout << "\n--- Returning Updated Fee ---\n";

    long long updatedFee = 45000;

    updatedFee = returnConcession(updatedFee, 10);
    updatedFee = returnConcession(updatedFee, 15);

    cout << "Fee after two concessions: "
         << updatedFee << '\n';

    cout << "\n--- Given Prediction Program ---\n";

    int a = 1, b = 2, c = 3;

    change(a, b, &c);

    cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;

    cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);

    cout << '\n';

    return 0;
}

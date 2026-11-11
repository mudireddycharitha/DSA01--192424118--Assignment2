
#include <iostream>
using namespace std;

struct Parcel
{
    double weight;
    bool express;
    bool insured;
};

double charge(int grams)
{
    cout << "Selected: Integer overload\n";

    double kg = grams / 1000.0;

    return kg * 50;
}

double charge(double kg,
              bool express = false,
              bool insured = false)
{
    cout << "Selected: Double overload\n";

    double amount = kg * 50;

    if (express)
    {
        amount += 30;
    }

    if (insured)
    {
        amount += 20;
    }

    return amount;
}

double charge(const Parcel& p)
{
    cout << "Selected: Parcel overload\n";

    double amount = p.weight * 50;

    if (p.express)
    {
        amount += 30;
    }

    if (p.insured)
    {
        amount += 20;
    }

    return amount;
}

int main()
{
    cout << "====================================\n";
    cout << "      COURIER CHARGE CALCULATOR\n";
    cout << "====================================\n";

    cout << "\n1. charge(2)\n";
    cout << "Amount: Rs. " << charge(2) << '\n';

    cout << "\n2. charge(2.0)\n";
    cout << "Amount: Rs. " << charge(2.0) << '\n';

    cout << "\n3. charge(2.0f)\n";
    cout << "Amount: Rs. " << charge(2.0f) << '\n';

    cout << "\n4. charge(500)\n";
    cout << "Amount: Rs. " << charge(500) << '\n';

    cout << "\n5. charge(1.5)\n";
    cout << "Amount: Rs. " << charge(1.5) << '\n';

    Parcel p = {2.0, true, true};

    cout << "\n6. charge(parcel)\n";
    cout << "Amount: Rs. " << charge(p) << '\n';

    return 0;
}

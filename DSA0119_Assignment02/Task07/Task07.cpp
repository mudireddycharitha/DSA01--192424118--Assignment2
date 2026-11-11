
#include <iostream>
#include <string>
using namespace std;


class StaticTicket
{
private:

    static int issued;
    static const int CAPACITY = 3;

    string name;
    int seat;

public:

    StaticTicket(const string& n)
        : name(n), seat(0)
    {
        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
    }

    void print() const
    {
        cout << name << ": ";

        if (seat != 0)
            cout << "Seat " << seat << '\n';
        else
            cout << "Waiting\n";
    }
};

int StaticTicket::issued = 0;


class BusOffice
{
private:

    int issued;
    int capacity;

public:

    explicit BusOffice(int cap)
        : issued(0), capacity(cap)
    {
    }

    int allocateSeat()
    {
        if (issued < capacity)
        {
            issued++;
            return issued;
        }

        return 0;
    }

    int count() const
    {
        return issued;
    }
};


class BusTicket
{
private:

    string name;
    int seat;

public:

    BusTicket(const string& n, BusOffice& office)
        : name(n)
    {
        seat = office.allocateSeat();
    }

    void print() const
    {
        cout << name << ": ";

        if (seat != 0)
            cout << "Seat " << seat << '\n';
        else
            cout << "Waiting\n";
    }
};


int main()
{
    cout << "====================================\n";
    cout << "       BUS TICKET REDESIGN\n";
    cout << "====================================\n";

    cout << "\n--- ORIGINAL STATIC DESIGN ---\n";

    StaticTicket originalA[2] = {
        StaticTicket("Asha"),
        StaticTicket("Bala")
    };

    StaticTicket originalB[2] = {
        StaticTicket("Chitra"),
        StaticTicket("Dev")
    };

    cout << "\nBus A:\n";

    for (const StaticTicket& t : originalA)
        t.print();

    cout << "\nBus B:\n";

    for (const StaticTicket& t : originalB)
        t.print();


    cout << "\n--- REDESIGNED OFFICE SYSTEM ---\n";

    BusOffice officeA(3);
    BusOffice officeB(3);

    BusTicket busA[2] = {
        BusTicket("Asha", officeA),
        BusTicket("Bala", officeA)
    };

    BusTicket busB[2] = {
        BusTicket("Chitra", officeB),
        BusTicket("Dev", officeB)
    };

    cout << "\nBus A:\n";

    for (const BusTicket& t : busA)
        t.print();

    cout << "\nBus B:\n";

    for (const BusTicket& t : busB)
        t.print();

    cout << "\n--- ISSUED SEAT COUNTS ---\n";

    cout << "Bus A issued: "
         << officeA.count() << '\n';

    cout << "Bus B issued: "
         << officeB.count() << '\n';

    return 0;
}

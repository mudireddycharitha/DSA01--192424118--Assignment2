
#include <iostream>
#include <string>
using namespace std;

class BusTicket
{
private:

    static int issued;

    static const int CAPACITY = 3;

    int seat;
    string name;

public:

    explicit BusTicket(const string& n)
        : seat(0), name(n)
    {
        // TODO 1
        if (issued < CAPACITY)
        {
            issued++;
            seat = issued;
        }
        else
        {
            seat = 0;
        }
    }

    // TODO 2
    static int count()
    {
        return issued;
    }

    void print() const
    {
        cout << name << ": "
             << (seat
                 ? "Seat " + to_string(seat)
                 : string("Waiting"))
             << '\n';
    }
};

int BusTicket::issued = 0;

void createAdditionalTickets()
{
    cout << "\nCreating tickets inside function:\n";

    BusTicket a("Esha");
    BusTicket b("Farhan");

    a.print();
    b.print();

    cout << "Issued inside function: "
         << BusTicket::count() << '\n';
}

int main()
{
    cout << "====================================\n";
    cout << "       COLLEGE BUS TICKET SYSTEM\n";
    cout << "====================================\n";

    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    cout << "\n--- Ticket Allocation ---\n";

    for (const BusTicket& t : trip)
    {
        t.print();
    }

    cout << "Issued: " << BusTicket::count() << '\n';

    createAdditionalTickets();

    cout << "\nFinal issued count: "
         << BusTicket::count() << '\n';

    return 0;
}

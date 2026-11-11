
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

class Time
{
private:

    int h, m;

public:

    Time(int hh, int mm) : h(hh), m(mm)
    {
    }

    friend int minutesBetween(const Time& a, const Time& b);

    friend bool earlier(const Time& a, const Time& b);
};

// TODO 1
inline int minutesBetween(const Time& a, const Time& b)
{
    int timeA = a.h * 60 + a.m;

    int timeB = b.h * 60 + b.m;

    int difference = timeA - timeB;

    return difference < 0 ? -difference : difference;
}

// TODO 2
inline bool earlier(const Time& a, const Time& b)
{
    if (a.h < b.h)
        return true;

    if (a.h == b.h && a.m < b.m)
        return true;

    return false;
}

int regularCalculation(int a, int b)
{
    return (a * 60 + b * 60) % 1000;
}

inline int inlineCalculation(int a, int b)
{
    return (a * 60 + b * 60) % 1000;
}

int main()
{
    cout << "====================================\n";
    cout << "       TRAIN JOURNEY PLANNER\n";
    cout << "====================================\n";

    Time departure(9, 45);
    Time arrival(13, 10);

    cout << "\n--- Main Test ---\n";

    cout << minutesBetween(departure, arrival)
         << ' '
         << boolalpha
         << earlier(arrival, departure)
         << '\n';

    cout << "\n--- Additional Tests ---\n";

    Time morning(11, 55);
    Time noon(12, 5);
    Time same1(12, 0);
    Time same2(12, 0);

    cout << "Before noon difference: "
         << minutesBetween(morning, noon) << '\n';

    cout << "Earlier before noon: "
         << earlier(morning, noon) << '\n';

    cout << "Same time difference: "
         << minutesBetween(same1, same2) << '\n';

    cout << "Same time earlier: "
         << earlier(same1, same2) << '\n';

    cout << "\n--- Performance Measurement ---\n";

    const int ITERATIONS = 10000000;

    volatile long long result = 0;

    auto start1 = steady_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
        result = result + regularCalculation(i, 5);
    }

    auto end1 = steady_clock::now();

    auto regularTime =
        duration_cast<microseconds>(end1 - start1).count();

    auto start2 = steady_clock::now();

    for (int i = 0; i < ITERATIONS; i++)
    {
        result = result + inlineCalculation(i, 5);
    }

    auto end2 = steady_clock::now();

    auto inlineTime =
        duration_cast<microseconds>(end2 - start2).count();

    cout << "Regular function time: "
         << regularTime << " microseconds\n";

    cout << "Inline function time : "
         << inlineTime << " microseconds\n";

    cout << "Benchmark result: " << result << '\n';

    return 0;
}

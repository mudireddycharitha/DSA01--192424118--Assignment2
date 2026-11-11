
#include <iostream>
#include <vector>
using namespace std;

int& highestMark(int marks[], int size)
{
    int highestIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highestIndex])
        {
            highestIndex = i;
        }
    }

    return marks[highestIndex];
}

const int& highestMarkConst(const int marks[], int size)
{
    int highestIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[highestIndex])
        {
            highestIndex = i;
        }
    }

    return marks[highestIndex];
}

int highestMarkValue(const int marks[], int size)
{
    int highest = marks[0];

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

int highestIndex(const int marks[], int size)
{
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[index])
        {
            index = i;
        }
    }

    return index;
}

int* highestPointer(int marks[], int size)
{
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        if (marks[i] > marks[index])
        {
            index = i;
        }
    }

    return &marks[index];
}

int& dangerousReference()
{
    int local = 100;
    return local;
}

int main()
{
    cout << "====================================\n";
    cout << "     EXAMINATION MARKS REGISTER\n";
    cout << "====================================\n";

    int marks[5] = {78, 92, 85, 67, 88};

    cout << "Original marks: ";

    for (int mark : marks)
    {
        cout << mark << " ";
    }

    cout << "\n\n--- Return by Reference ---\n";

    cout << "Highest mark: " << highestMark(marks, 5) << '\n';

    highestMark(marks, 5) += 2;

    cout << "After moderation: "
         << highestMark(marks, 5) << '\n';

    cout << "\n--- Return by Const Reference ---\n";

    const int& readOnly = highestMarkConst(marks, 5);

    cout << "Highest mark: " << readOnly << '\n';

    cout << "\n--- Return by Value ---\n";

    int copiedMark = highestMarkValue(marks, 5);

    cout << "Copied highest mark: " << copiedMark << '\n';

    copiedMark += 10;

    cout << "Modified copy: " << copiedMark << '\n';
    cout << "Original highest mark: "
         << highestMark(marks, 5) << '\n';

    cout << "\n--- Return by Index ---\n";

    int index = highestIndex(marks, 5);

    cout << "Highest mark index: " << index << '\n';
    cout << "Highest mark: " << marks[index] << '\n';

    cout << "\n--- Return by Pointer ---\n";

    int* ptr = highestPointer(marks, 5);

    cout << "Highest mark using pointer: " << *ptr << '\n';

    cout << "\n--- Growing Vector ---\n";

    vector<int> studentMarks = {78, 92, 85};

    int savedIndex = 1;

    cout << "Before adding: "
         << studentMarks[savedIndex] << '\n';

    studentMarks.push_back(95);

    cout << "After adding: "
         << studentMarks[savedIndex] << '\n';

    cout << "\nNote: Old references may become invalid "
         << "if vector reallocates.\n";

    return 0;
}

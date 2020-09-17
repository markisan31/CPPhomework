#include <iostream>
using namespace std;

void check_temp(double temp)
{
    if (temp > 25)
        cout << "hot" << endl;
    else if (temp > 10 && temp <= 25)
    {
        cout << "warm" << endl;
    }
    else
    {
        cout << "cold" << endl;
    }
}

void third_task()
{
    double temp;
    cout << "Sisesta temperatuur: " << endl;
    cin >> temp;
    check_temp(temp);
}

int main()
{
    third_task();
    return (0);
}
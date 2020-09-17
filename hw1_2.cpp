#include <iostream>
using namespace std;

void change_salaries(double salaries[], int arrayLength)
{
    
    
    for (unsigned int i = 0; i < arrayLength; i++)
    {
        if (salaries[i] < 500)
        {
            salaries[i] = salaries[i] * 1.05;
            cout << "Salary of " << i + 1 << "st person after changing is: " << salaries[i] << endl;
        }
        else
        {
            cout << "Salary of " << i + 1 << "st person didn't changed" << endl;
        }
        cout << endl;
    }
}


void second_task()
{
    cout << "Type 5 different salaries" << endl;
    double salaries[5];
    unsigned int salaries_length = sizeof(salaries) / sizeof(double);

    for (unsigned int i = 0; i < salaries_length; i++)
    {
        cout << "Please insert salary no. " << i + 1 << endl;
        cin >> salaries[i];
        cout << endl;
    }
    
    change_salaries(salaries, salaries_length);
}


int main()
{
    second_task();
    return(0);
}


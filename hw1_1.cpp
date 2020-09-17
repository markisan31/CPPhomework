#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>


using namespace std;


double circle_area(int radius)
{
    return pow(radius, 2) * M_PI;
}

double circle_perimetr(int radius)
{
    return 2 * M_PI * radius;
}

double square_perimeter(int radius) {
    return 2 * radius * 4;
}
double square_area(int radius) {
    return pow(radius * 2, 2);
}
void first_task()
{
    cout << "Enter circle radius: " << endl;

    unsigned int radius;

    cin >> radius;

    if (radius < 1)
    {
        cout << "Can't handle numbers less than 1";
    }
    else
    {
        cout << "Circle are: " << circle_area(radius) << ", Circle perimetr: " << circle_perimetr(radius) << endl;
        cout << "Square are: " << square_area(radius) << ", Square perimetr: " << square_perimeter(radius) << endl;
    }

}

int main()
{
    first_task();
    return(0);
}
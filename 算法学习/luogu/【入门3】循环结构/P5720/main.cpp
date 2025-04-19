#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a;
    cin >> a;

    int days = 1;
    while (a!=1)
    {
        days++;
        a/=2;
    }

    cout<< days;
    return 0;
}
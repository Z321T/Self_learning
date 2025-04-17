#include <iostream>
using namespace std;

int main()
{
    int a,b;
    int ans=0;
    int unhappy=0;
    for (int i=0; i<7; i++)
    {
        cin>> a >> b;
        if ( a+b > 8  && a+b > unhappy)
        {
            unhappy = a+b;
            ans = i+1;
        }
    }
    cout<< ans;

    return 0;
}
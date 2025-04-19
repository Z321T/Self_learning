#include <iostream>
using namespace std;

int a,b;

int main()
{
    int i,j,k;
    cin>>a;
    b=a;
    a=a*(a+1)/2;
    j=1;
    i=1;
    while(i<=a)
    {
        if(i<10)
        {
            cout<<0<<i;
        }
        else
        {
            cout<<i;
        }
        i++;
        j++;
        if(j>b)
        {
            b--;
            j=1;
            cout<<endl;
        }
    }
    return 0;
}
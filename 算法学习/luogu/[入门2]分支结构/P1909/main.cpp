#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int a,b;
    int c = INT_MAX;
    for (int i=0; i<3;i++)
    {
        cin >> a >> b;
        int m=ceil((double)num/(double)a)*b;
        if ( c>m )
            c = m;
    }
    cout << c;

    return 0;
}
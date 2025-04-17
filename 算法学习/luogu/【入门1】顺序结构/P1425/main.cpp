#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d;
    int start = a*60 + b;
    int end = c*60 + d;
    int cost = end - start;

    e = cost / 60;
    f = cost % 60;

    cout << e << " " << f;

    return 0;
}
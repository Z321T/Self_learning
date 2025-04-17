#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a,b,c;
    cin>>a>>b>>c;
    float p = 0.5*(a+b+c);
    float ans = sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<fixed<<setprecision(1)<<ans;

    return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float t;
    int n;
    cin >> t >> n;
    float ans = t/n;
    int cup = n*2;
    cout<< fixed << setprecision(3) << ans << endl;
    cout<< cup;

    return 0;
}
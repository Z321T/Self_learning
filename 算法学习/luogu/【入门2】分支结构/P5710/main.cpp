#include <iostream>
using namespace std;

int main()
{
    bool factor1 = false;
    bool factor2 = false;

    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        factor1 = true;
    }
    if (4<n && n<=12)
    {
        factor2 = true;
    }

    int ans[4]={0};
    if (factor1 && factor2)
    {
        ans[0] = 1;
    }
    if (factor1 || factor2)
    {
        ans[1] = 1;
    }
    if ( (factor1 && !factor2) || (!factor1 && factor2))
    {
        ans[2] = 1;
    }
    if (!factor1 && !factor2)
    {
        ans[3] = 1;
    }

    for (int i = 0; i < 4; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
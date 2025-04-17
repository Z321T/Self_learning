#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int ans[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> ans[i];
    }
    sort(ans, ans + 3);
    for (int i = 0; i < 3; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
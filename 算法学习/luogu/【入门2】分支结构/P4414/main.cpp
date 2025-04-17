#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int a[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 3);
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            cout << a[0] << " ";
        }
        else if (s[i] == 'B')
        {
            cout << a[1] << " ";
        }
        else
        {
            cout << a[2] << " ";
        }
    }

    return 0;
}
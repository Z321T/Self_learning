#include <iostream>
using namespace std;

int main()
{
    int k, sum;
    sum = 0;
    cin >> k;

    int corn = 1;//当前应收到几个金币
    int i = corn;//当前是第n天中的第几个
    while (k > 0)
    {
        while (i > 0)
        {
            i--;
            sum += corn;
            k--;
            if (k == 0)
                break;
        }
        corn++;
        i = corn;
    }
    cout << sum;

    return 0;
}
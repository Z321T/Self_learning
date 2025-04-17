#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float pi = 3.14;
    int h,r;
    cin >> h >> r;
    int water = 20*1000;// 20L
    float volume = pi * r * r * h;

    float ans = water / volume;
    cout<<ceil(ans);

    return 0;
}
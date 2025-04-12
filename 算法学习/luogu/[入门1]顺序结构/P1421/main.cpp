#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    float pen = 1.9;
    float a,b;
    cin >> a >> b;
    float c = a + b/10;

    cout << floor(c/pen);

    return 0;
}
#include <iostream>
using namespace std;
const int N = 1e7;
int a[N];
int main()
{
    int n;
    cin >> n;
    a[1] = 1;
    int cnt = 1;
    for(int i = 2; i <= n; i++){
        if(a[i])continue;
        a[i] = 1;
        cnt++;
        for(int j = i * 2; j <= n; j += i){
            a[j] = ~a[j];
        }
    }
    cout << cnt;
    return 0;
}
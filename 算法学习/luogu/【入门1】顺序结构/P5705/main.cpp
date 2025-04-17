#include<iostream>
#include<string>
using namespace std;

int main(){
    float a;
    cin>>a;
    a = a*10;
    int b=a;
    string s = to_string(b);
    reverse(s.begin(), s.end());
    a = stoi(s);
    a = a/1000;
    cout<<a;

    return 0;
}
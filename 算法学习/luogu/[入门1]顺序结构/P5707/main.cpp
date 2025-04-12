#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int s,v;
    cin>>s>>v;
    //计算时间花费，向上取整
    int t = s/v;//路程上花费的时间--分钟
    if (s%v != 0)
        t++;
    t+=10;//垃圾分类的时间

    int ans_h, ans_m;
    //计算最晚出发时间
    int cos_h = t/60;
    int cos_m = t%60;

    if (cos_h < 8) {
        //当天之内出发
        if (cos_m == 0) {
            ans_h = 8 - cos_h;
            ans_m = 0;
        }
        else {
            ans_h = 8 - cos_h - 1;
            ans_m = 60 - cos_m;
        }
    }
    if (cos_h == 8) {
        if (cos_m == 0) {
            ans_h = 8 - cos_h;
            ans_m = 0;
        }
        else {
            ans_h = 23;
            ans_m = 60 - cos_m;
        }
    }
    if (8 < cos_h && cos_h < 24) {
        //提前一天之内出发
        if (cos_m == 0) {
            ans_h = 24 - cos_h + 8;
        }
        else {
            ans_h = 24 - cos_h - 1 + 8;
            ans_m = 60 - cos_m;
        }
    }

    //输出符合要求的格式化结果
    cout << setw(2) << setfill('0') << ans_h << ":"
         << setw(2) << setfill('0') << ans_m << endl;

    return 0;
}
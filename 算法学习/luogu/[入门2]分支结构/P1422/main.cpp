#include <cstdio>
int main(){
    double a;//计算开double
    scanf("%lf",&a);//输入不解释了
    if (a<=150){//判断即可
        printf("%.1lf",a*0.4463);
    }
    else if (a>=151 && a<=400){
        printf("%.1lf",150*0.4463+(a-150)*0.4663);
    }
    else {
        printf("%.1lf",150*0.4463+250*0.4663+(a-400)*0.5663);
    }
    return 0;
}
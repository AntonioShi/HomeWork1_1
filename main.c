/**
 * 编写程序计算x^n，要求:
 * 1输入整数x和n
 * 2输出x^n的值
 * 3思考算法是否可以进一步提升效率，如何提升?
 * 4改进并实现算法，分析时间复杂度
 * @param x
 * @param n
 * @return
 */

#include <stdio.h>
#include <stdlib.h>
#include <spandsp.h>


//普通的算法O(n)
int Operate1(int x, int n){

    double sum = 1.0 ;

    if(n == 0){
        printf("%.4lf\n", sum) ;//O(1)
        return 0;
    }
    else if(n < 0){
        int m = -1 * n ;
        for (int i = 0; i < m; ++i) {//O(n)
            sum *= x ;
        }
        sum = 1.0 / sum ;
        printf("%.4lf\n", sum) ;
        exit(0) ;

    }
    else{
        for (int i = 0; i < n; ++i) {//O(n)
            sum *= x ;
        }
    }

    printf("%.2lf\n", sum) ;
}

//改进后的方法
int Operate2(int x, int n){
    double sum = 1.0 ;

    if(n == 0){
        printf("%.4lf\n", sum) ;//O(1)
        return 0;
    }
    else if(n < 0){
      int m = -1 * n ;
        while(m % 2 == 0){
            m = m / 2 ;
            x *= x ;
        }
        while (m != 0) {
            m -- ;
            sum *= x ;
        }
        sum = 1 / sum ;
        printf("\nx^n的值:%.4lf\n", sum) ;
        exit(0) ;

    }
    else{
        while(n % 2 == 0){
            n = n / 2 ;
            x *= x ;
        }
        while (n != 0) {
            n -- ;
            sum *= x ;
        }
    }



//    else if( (n + 1) % 2 == 0){
//        int m = (n + 1) / 2 ;
//        for (int i = 0; i < m - 1; i++) {
//            x *= x ;
//        }
//    }

    printf("\nx^n的值:%.4lf\n", sum) ;

    return 1 ;

}



int main() {
    int x, n ;
    double sum ;
    printf("请输入两个整数x n: ") ;
    scanf("%d %d", &x, &n) ;

   //Operate1(x, n) ;//方法一
     Operate2(x, n) ;//方法二


    return 0;
}
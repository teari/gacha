#include <stdio.h>
#include <stdlib.h> //rand(),srand()
#include <time.h> //time()

#define NTRY 10000000 //試行回数

int main(void)
{
    char    cd[5][9]={"A","B","C","D","E"}; //カードの種類
    int     h[5]={0}; //カード別排出実現回数
    int     p[5]={60,30,7,2,1}; //確率分布
    int     s[5];
    int     np=5; //n.prob:分布サイズ
    int     ip; //分布表カウンタ
    int     nt; //n.trial:全試行回数
    int     it; //施行カウンタ
    int     rn; //乱数:0<=rn<100

    nt = NTRY;
    srand((unsigned)time(NULL));
    //累積確率表を作る
    s[0] = p[0];
    for (ip = 1; ip < np; ip++) {
        s[ip] = s[ip-1] + p[ip];
    }
    //確率表を表示
//    printf("確率表:\n種別 確率 累積確率\n");
//    for (ip = 0; ip < np; ip++) {
//        printf("%4s %4dd %8d\n", cd[ip],p[ip],s[ip]);
//    }
    //施行ループ
    printf("\n試行経歴:\n実行通番   実現    回数\n");
    for (it = 0; it < nt; it++) {
        rn = rand()%100;
        //確率的排出カード選択
        for (ip = 0; ip < np; ip++) {
            if (s[ip]>rn) break;
        }
        //排出実現回数カウント、報告
        h[ip]++;
//        printf("trial No.%3d: card[%s] %4d\n", it+1,cd[ip],h[ip]);
    }
    //総排出実現回数表示
    printf("\n排出実現統計:\n実現種別 回数 相対確率\n");
    for (ip = 0; ip < np; ip++) {
        printf("%8s %4d %f\n", cd[ip],h[ip],(double)h[ip]/nt);
    }
    printf("\nn-normal end-\n");
    return 0;
}

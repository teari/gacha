#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NTRY 10000000
#define FIRST 60
#define SECOND 30
#define THIRD 7
#define FOURTH 2
#define FIFTH 1

int gacha(void) {
  // カードの種類
  char card[5][9] = {"A", "B", "C", "D", "E"};
  // カード別排出実現回数
  int hcount[5] = {0};
  // 確率分布
  int rank[5] = {FIRST, SECOND, THIRD, FOURTH, FIFTH};
  int s[5];
  // n.prob:分布サイズ
  int np = 5;
  // 分布カウンタ
  int ip;
  // n.trial:全試行回数
  int nt;
  // 試行カウンタ
  int drow;
  // 乱数:0<=rn<100
  int rondom;

    nt = NTRY;
    srand((unsigned)time(NULL));
    // 累積確率表を作る
    s[0] = rank[0];
    for (ip = 1; ip < np; ip++) {
        s[ip] = s[ip-1] + rank[ip];
    }
    // 確率表を表示
    printf("確率表:\n種別 確率 累積確率\n");
    for (ip = 0; ip < np; ip++) {
        printf("%4s %4d %8d\n", card[ip], rank[ip], s[ip]);
    }
    // 試行ループ
//    printf("\n試行経歴:\n実行通番   実現    回数\n");
    for (drow = 0; drow < nt; drow++) {
        rondom = rand()%100;
        // 確率的排出カード選択
        for (ip = 0; ip < np; ip++) {
            if (s[ip] > rondom) break;
        }
        // 排出実現回数カウント、報告
        hcount[ip]++;
//        printf("trial No.%3d: card[%s] %4d\n", it+1, cd[ip], h[ip]);
    }
    // 総排出実現回数表示
    printf("\n排出実現統計:\n実現種別 回数 相対確率\n");
    for (ip = 0; ip < np; ip++) {
        printf("%8s %4d %f\n", card[ip], hcount[ip], (double)hcount[ip]/nt);
    }
    printf("\nn-normal end-\n");
    return 0;
}

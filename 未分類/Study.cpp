//作成者 川﨑 裕貴
//作成日 2018/5/2
//学習用ソフトウェア①

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
    int x, y, ans;
    int correct_answers;
    int n, i;
    int a;
    double persent;
    time_t start_time, end_time;
    int second_time, minute_time = 0;
    
    srand((unsigned)time(NULL));
    
    printf("掛け算演習を行います\n\n");
    printf("何問演習しますか？(10 ~ 100)\n");
    printf("範囲以外の数値、または文字等を入力した場合は10問とする\n");
    scanf("%d",&n);
    if(n<10||n>100)
        n = 10;
    printf("\n全%d問\n\n",n);
    
    //掛け算演習開始
    printf("はじめ!!\n");
    start_time = time(NULL);
    for(i=1; i<=n; i++){
        x = rand()%90+10; //10~99の整数の乱数を返す
        y = rand()%90+10; //10~99の整数の乱数を返す
        ans = x * y;
        printf("%d × %d = ", x, y);
        scanf("%d", &a);
        if(a == ans)
            correct_answers++;
    }
    end_time = time(NULL);
    printf("おわり!!\n");
    
    //正答率の計算
    persent = double(correct_answers) / double(n) * 100.0;
    
    //時間の計算
    second_time = (int)(end_time - start_time);
    minute_time = second_time / 60;
    second_time %= 60;
    
    //結果の出力
    printf("\n正解数 %d / %d (%.1f%%)\n",correct_answers, n, persent);
    if(minute_time == 0)
        printf("時間 %d秒\n\n", second_time);
    else
        printf("時間 %d分%d秒\n\n", minute_time, second_time);
    
    
    return 0;
}

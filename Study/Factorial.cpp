/*
 Information
     Name: Kawasaki Hiroki
     Data: 9/9/2018
 contents: Program to make factorial.
 */

#include <stdio.h>

#define MAX 10000 //30000桁まで扱える

//Function to handle carry forward. //繰り上がりの処理をする関数
void Advance(int BigNumber[]){
    //Declaring variables. //変数の宣言
    int n = 0;
    
    while(n <= MAX){
        if(BigNumber[n] >= 1000){
            BigNumber[n] -= 1000;
            BigNumber[n+1] ++;
        }else{
            n++;
        }
    }
    return;
}

//A function that outputs a large number. //大きい数を出力する関数
void Output(int BigNumber[]){
    //Declaring variables. //変数の宣言
    int i;
    
    for(i = MAX; i >= 0; i--){
        if(BigNumber[i] > 0){
            printf("%d", BigNumber[i]);
            break;
        }
    }
    while(i > 0){
        i--;
        if(BigNumber[i] >= 100)           printf("%d", BigNumber[i]);
        else if(BigNumber[i] >= 10)     printf("0%d", BigNumber[i]);
        else                                         printf("00%d", BigNumber[i]);
    }
    printf("\n");
    return;
}

//Function to multiply large numbers. //大きい数の掛け算を行う関数
void multiplication(int BigNumber[], int num){
    //Declaring variables. //変数の宣言
    int i, n, c = -1, BigNumber_copy[MAX + 1];
    char marker[10000];
    
    //Preprocessing. //開始処理
    for(i = 0; i < MAX; i++)
        BigNumber_copy[i] = BigNumber[i];
    
    //Processing of multiplication. //掛け算の処理
    n = num;
    while(n > 1){
        c++;
        if(n % 2 == 0){
            marker[c] = '*';
            n /= 2;
        }else{
            marker[c] = '+';
            n--;
        }
    }
    while(c >= 0){
        switch(marker[c]){
            case '+':
                for(i = 0; i < MAX; i++)    BigNumber[i] += BigNumber_copy[i];
                break;
            case '*':
                for(i = 0; i < MAX; i++)    BigNumber[i] *= 2;
                break;
            default:
                break;
        }
        Advance(BigNumber);
        c--;
    }
    return;
}

int main(void){
    //Declaring variables. //変数の宣言
    int BigNumber1[MAX + 1], i, num;
    
    //Preprocessing. //開始処理
    for(i = 0; i < MAX; i++)        BigNumber1[i] = 0;
    BigNumber1[0] = 1;
    
    printf("階乗の計算をします\n0以上の整数を入力してください\n");
    
    //数値の入力
    do{
        printf("Number = ");
        scanf("%d", &num);
    }while(num < 0);
    
    //Factorial processing. //階乗の処理
    for(i = 1; i <= num; i++)       multiplication(BigNumber1, i);
    
    printf("%d!(%dの階乗) = ", num, num);
    Output(BigNumber1);
    
    return 0;
}

/*
　山本先生へ
 
　山本先生、通算1年間(2年次後期「プログラミング技術」、3年次前期「プログラミング応用」)ありがとうございました。
 
　先生は階乗が好きなようなので（笑）これをプレゼントします。
授業中に、C言語では12の階乗以降は扱えなーい。と嘆きましたが、どうにかして扱いたかったので作ってみました。
 
　アルゴリズムの演習は初めての試みと言っていたのを思い出し、どのような授業が楽しいのか考えた結果、やはりインターネットでは簡単に調べることのできない内容が少しでもあるといいなと思いました。私の場合、今回の授業の問題は全てノーヒントで考え、作成しました。この授業は「プログラミング応用」なのでもう少し、深くアルゴリズム的な電子的な思考を付けれるような問題が好ましいと思いました。
　もし、来年度以降もこの演習を行うなら、もう少し問題を難しくして、1問に授業を二回分（200分）確保し、十分に思考する時間を生徒に与え、また、考え方の一部を説明し（ヒントを出し）ながら、やってもいいかもしれません。一生徒の意見なので、参考程度に聞き流してください。

　また、来年以降の授業で私が作ったプログラミングコード、およびその実行結果を生徒に公開し、参考としてに使ってもらって大丈夫です。自分では言いたくはありませんが、模範としてわかりやすく書いたつもりで、実行結果も親切設定になっていると思います。だから、プログラムを作る時に一番考えないといけないこと「利便性」を追求した形になっていると思います。よろしければ、活用していただけると幸いです。
また、ぜひこのプログラミングコードも学校のパソコンに打ち込み、活用してください。自分のコードを他生徒に見せる場合は、個人名は控えて、「ある生意気の先輩」が作ったものだよと後輩たちにお伝えてください（笑）
　本当に、1年間ありがとうございました。
 
　2018年度　3年次3組8番　川﨑裕貴
*/


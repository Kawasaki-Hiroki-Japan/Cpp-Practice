//作成者：川﨑裕貴
//作成日：2018/3/16
//名　称：素数出力プログラム(CSV出力)_vol.1


#include<stdio.h>
#include<math.h>

int sqrt_intf(int x);
int pndf(int x[], int z);
void pne_csvf(int x[]);
void confirmation(int x[]);


//メインプログラム(素数を格納する配列の管理)
int main(void){
    int prime_numbers[50000] = {2,3};
    int num, pn_bool, i = 2;
    for(num = 5; i < 50000; num += 2){
        pn_bool = pndf(prime_numbers, num);
        if(pn_bool == 1){
            prime_numbers[i] = num;
            i++;
        }
    }
    confirmation(prime_numbers);
    printf("素数出力プログラムを終了します\n");
    printf("ありがとうございました\n");
    getchar();
    return 0;
}

//int型の平方根を求める関数
int sqrt_intf(int x){
    double y;
    int z;
    y = sqrt(x);
    z = (int)y;
    return z;
}

//素数を判別する関数
int pndf(int x[], int z){
    int sqrt_int, i = 1;
    sqrt_int = sqrt_intf(z);
    while(1){
        if(x[i] > sqrt_int)
            return 1;
        if(z % x[i] == 0)
            return 0;
        i++;
    }
}

//素数をCSV形式で出力する関数
void pne_csvf(int x[]){
    int i;
    FILE *fp;
    fp = fopen("prime_numbers_50000.csv", "w");
    if( fp == NULL ){
        printf( "Error:ファイルが開けません\n");
        return;
    }
    for(i = 0; i < 50000; i++){
        fprintf(fp, "%d", x[i]);
        if((i+1)%50!=0)
            fprintf(fp, ", ");
        else
            fprintf(fp, "\n");
    }
    fclose(fp);
    printf("ファイルへの出力が完了しました\n");
    getchar();
    return;
}

//確認画面
void confirmation(int x[]){
    int select;
    printf("素数の出力を行いますか？\n\n");
    printf("1, Yes\n");
    printf("2, No\n\n");
    scanf("%d", &select);
    printf("\n");
    getchar();
    switch(select){
        case 1:
            printf("Yes\n\n");
            printf("2 から 611,953 までの素数(50,000番目まで)を\"CSV形式\"で出力します\n");
            getchar();
            pne_csvf(x);
            break;
        case 2:
            printf("No\n");
            getchar();
            break;
        default:
            printf("Error:入力値が間違っています\n");
            getchar();
            break;
    }
    return;
}

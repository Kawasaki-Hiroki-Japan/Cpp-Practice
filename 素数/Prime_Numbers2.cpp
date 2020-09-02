//作成者：川﨑裕貴
//作成日：2018/3/14
//名　称：素数検索プログラム


#include<stdio.h>
#include<math.h>

void n();
int sqrt_intf(int x);
int pndf(int x[50000], int y[50000], int z);
void pnrf(int x[50000], int y[50000], int z);
void pnef(int x[50000], int y[50000]);
void pne_csvf(int x[50000]);
void pne_csv2f(int x[50000], int y[50000]);
int pnd_optionf(int x[50000], int y[50000], int z);
void option(int x[50000], int y[50000]);


//メインプログラム
int main(void){
    int prime_numbers1[50000] = {2,3};
    int prime_numbers2[50000] = {0};
    int num = 3;
    int pn_bool = 0;
    int i = 2;
	while(i<100000){
        num += 2;
        pn_bool = pndf(prime_numbers1, prime_numbers2, num);
        if(i < 50000 && pn_bool == 1){
            prime_numbers1[i] = num;
            i++;
        }else if(i >= 50000 && pn_bool == 1){
            prime_numbers2[i-50000] = num;
            i++;
        }
	}
    option(prime_numbers1, prime_numbers2);
    printf("素数検索プログラムを終了します。\n");
    return 0;
}

//行間を空ける関数
void n(){
    printf("\n");
    return;
}

//int型の平方根を求める関数
int sqrt_intf(int x){
    double y;
    int z;
    y = sqrt(x);
    z = (int)y;
    return z;
}

//素数を判別する関数(素数配列作成時に使用)
int pndf(int x[50000], int y[50000], int z){
    int i = 1;
    int sqrt_int;
    sqrt_int = sqrt_intf(z);
    while(1){
        if(i < 50000 && x[i] > sqrt_int)
            return 1;
        else if(i >= 50000 && y[i-50000] > sqrt_int)
            return 1;
        if(i < 50000 && z % x[i] == 0)
            return 0;
        else if(i >= 50000 && z % y[i-50000] == 0)
            return 0;
        i++;
    }
    return 0;
}

//素数を検索する関数
void pnrf(int x[50000], int y[50000],int z){
    if(z<1||z>100000)
        printf("Error:0000\n");
    else if(z <= 50000)
        printf("%d番目の素数は%dです。\n",z, x[z-1]);
    else{
        z -= 50000;
        printf("%d番目の素数は%dです。\n", z+50000, y[z-1]);
    }
    return;
}

//素数を出力する関数
void pnef(int x[50000],int y[50000]){
    int i;
    for(i = 0;i < 50000;i++){
        printf("%d",x[i]);
        if((i+1)%10!=0)
            printf(", ");
        else
            n();
    }
    for(i = 0;i < 50000;i++){
        printf("%d",y[i]);
        if((i+1)%10!=0)
            printf(", ");
        else
            n();
    }
    return;
}

//素数をCSV形式で出力する関数
void pne_csvf(int x[50000]){
    int y;
    FILE *fp;
    fp = fopen("prime_numbers.csv", "w");
    if( fp == NULL ){
        printf( "ファイルが開けません\n");
        return;
    }
    for(y = 0;y < 50000;y++){
        fprintf(fp, "%d", x[y]);
        if((y+1)%50!=0)
            fprintf(fp, ", ");
        else
            fprintf(fp, "\n");
    }
    fclose(fp);
    printf("ファイルへの出力が完了しました。\n");
    return;
}

//素数をCSV形式で出力する関数 拡張①
void pne_csv2f(int x[50000], int y[50000]){
    int i;
    FILE *fp;
    fp = fopen("prime_numbers.csv", "w");
    if( fp == NULL ){
        printf( "ファイルが開けません\n");
        return;
    }
    for(i = 0;i < 50000;i++){
        fprintf(fp, "%d", x[i]);
        if((i+1)%100!=0)
            fprintf(fp, ", ");
        else
            fprintf(fp, "\n");
    }
    for(i = 0;i < 50000;i++){
        fprintf(fp, "%d", y[i]);
        if((i+1)%100!=0)
            fprintf(fp, ", ");
        else
            fprintf(fp, "\n");
    }
    fclose(fp);
    printf("ファイルへの出力が完了しました。\n");
    return;
}

//素数かどうか判別する関数
int pnd_optionf(int x[50000],int y[50000],int z){
    int i;
    if(z<1||z>1299710){
        printf("Error:0000\n");
        return 2;
    }
    for(i = 0;i < 50000;i++){
        if(z == x[i]){
            return 1;
        }
    }
    for(i = 0;i < 50000;i++){
        if(z == y[i]){
            return 1;
        }
    }
    return 0;
}

//オプション
void option(int x[50000],int y[50000]){
    int select, num, pn_bool;
    printf("オプションを選んでください。\n");
    printf("*****************************\n");
    printf("* No.1：素数検索            *\n");
    printf("* No.2：素数出力            *\n");
    printf("* No.3：素数出力(CSV)       *\n");
    printf("* No.4：素因数分解          *\n");
    printf("* No.5：素数判別            *\n");
    printf("* No.6：素数出力(CSV)拡張①  *\n");
    printf("*****************************\n");
    n();
    printf("No.");
    scanf("%d", &select);
    n();
    switch(select){
        case 1:
            printf("何番目の素数を知りたいですか？\n");
            printf("(No.1 ~ No.100000)\n");
            n();
            printf("No.");
            scanf("%d", &num);
            n();
            pnrf(x, y, num);
            getchar();
            break;
        case 2:
            printf("「2」から100000番目の素数「1299709」までの素数を出力します。\n");
            getchar();
            getchar();
            pnef(x, y);
            break;
        case 3:
            printf("「2」から50000番目の素数「611953」までの素数を\"CSV形式\"で出力します。\n");
            getchar();
            getchar();
            pne_csvf(x);
            break;
        case 4:
            printf("未実装です。\n");
            break;
        case 5:
            printf("判別したい数を入力して下さい。\n");
            printf("(1 ~ 1299710)\n");
            n();
            scanf("%d", &num);
            pn_bool = pnd_optionf(x, y,num);
            n();
            if(pn_bool == 1)
                printf("%dは素数です。\n", num);
            else if(pn_bool == 0)
                printf("%dは素数ではありません。\n", num);
            break;
        case 6:
            printf("「2」から100000番目の素数「1299709」までの素数を\"CSV形式\"で出力します。\n");
            getchar();
            getchar();
            pne_csv2f(x,y);
            break;
        default:
            printf("Error:0000\n");
            break;
    }
    getchar();
    n();
    return;
}

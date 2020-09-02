//作成者：川﨑裕貴
//作成日：2018/3/17
//名　称：素因数分解プログラム_vol.1


#include<stdio.h>
#include<math.h>

int sqrt_intf(int x);
int pndf(int x[], int z);
void factoringf(int x[],int y[]);
void resultf(int x[]);
void confirmation(int x[]);



//メインプログラム(素数を格納する配列の管理等)
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
    printf("素因数分解プログラムを終了します\n");
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

//素因数分解を行う関数
void factoringf(int x[],int y[]){
    int num, i = 1, j = 0;
    printf("素因数分解したい数を入力して下さい(1 ~ 611954)\n\n");
    printf("Number = ");
    scanf("%d", &num);
    printf("\n");
    if(num < 1 || num > 611954){
        printf("Error:入力値が間違っています\n");
        return;
    }
    y[0] = num;
    while(1){
        if(num % x[j] == 0){
            y[i] = x[j];
            while(num % x[j] == 0){
                y[i+1] += 1;
                num /= x[j];
            }
            i += 2;
        }
        j++;
        if(num == 1)
            break;
    }
    return;
}

//素因数分解の結果を表示する関数
void resultf(int x[]){
    int i;
    if(x[0] == 0)
        return;
    printf("結果を表示します\n");
    getchar();
    if(x[0] == 1)
        printf("1は1です。素因数はありません");
    else if(x[2] == 1 && x[3] == 0){
        printf("%dは素数です", x[0]);
    }
    else{
        printf("%d = %d ^ %d", x[0], x[1], x[2]);
        for(i = 3; x[i]>0; i += 2)
            printf(" × %d ^ %d", x[i], x[i+1]);
    }
    printf("\n\n");
    return;
}

//確認画面
void confirmation(int x[]){
    int select;
    int prime_factor_list[10000];
    printf("素因数分解を行いますか？\n\n");
    printf("1, Yes\n");
    printf("2, No\n\n");
    scanf("%d", &select);
    printf("\n");
    getchar();
    switch(select){
        case 1:
            printf("Yes\n\n");
            printf("素因数分解を行います\n");
            factoringf(x, prime_factor_list);
            printf("\n");
            resultf(prime_factor_list);
            getchar();
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

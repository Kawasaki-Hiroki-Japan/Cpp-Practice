//作成者　川﨑裕貴
//作成日　2018/4/16
//内　容　クイックソート＆2分探索

#include <stdio.h>
#include <stdlib.h>
#define KOSU 15

void QSort(int x[], int left, int right);
void swap(int x[], int a, int b);

int main(void){
    int data[KOSU];
    int i;
    int left = 0, right = KOSU -1;
    int key;
    int cent, lower = 0, upper = KOSU -1;
    
    printf("整数データを%d個入力して下さい\n",KOSU);
    for(i = 0; i < KOSU; i++)
        scanf("%d",&data[i]);
    for (i = 0; i < KOSU ; i++)
        printf("%d,  ", data[i]);
    printf("\n");
    QSort(data,left,right);
    for (i = 0; i < KOSU ; i++)
        printf("%d,  ", data[i]);
    printf("\n");
//    printf("探索データを入力して下さい\n");
//    scanf("%d", &key);
//
//    while(lower <= upper){
//        cent = (upper + lower) / 2;
//
//    }
    return 0;
}

//クイックソート
void QSort(int x[], int left , int right){
    
    int pivot, a, b;
    
    a = left;
    b = right;
    
    pivot = x[(left + right) / 2];
    
    while (1) {
        while (x[a] < pivot)
            a++;
        while (pivot < x[b])
            b--;
        if (a >= b)
            break;
        swap(x, a, b);
        a++;
        b--;
    }
    
    if (left < a - 1)
        QSort(x, left, a - 1);
    if (b + 1 <  right)
        QSort(x, b + 1, right);
    
    return;
}

//要素の取り換え
void swop(int x[], int a, int b){
    int work;
    work = x[a];
    x[a] = x[b];
    x[b] = work;
    return;
}

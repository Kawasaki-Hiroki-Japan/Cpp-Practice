/*
    Information
        Name: Kawasaki Hiroki
        Data: 9/6/2018
 contents: Arithmetic -> No.1: Addition.
        rule: [++],[--],[*=2],[+1],[-1]
    Function: DNtoBN(), BNtoDN(), BN_Output(), MAX(), scanf_DN()
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_bit 20
#define TN 5

//Global Variable
int binary_number[TN+1][MAX_bit+1];
int MAX_number = 1;

//Function 01~02: DNtoBN(), BNtoDN()
void DNtoBN(int decimal_number, int x){
    int n, i, j;
    for(i = 1; i <= MAX_bit; i++){
        for(j = 0, n = 1; j < i; j++)  n *= 2;
        if(decimal_number % n == (n/2)){
            binary_number[x][i-1] = 1;
            decimal_number -= n/2;
        }
    }
    return;
}
int BNtoDN(int x){
    int y = 0, n = 1, i;
    for(i = 0; i <= MAX_bit; i++){
        if(binary_number[x][i] == 1)
            y += n;
        n *= 2;
    }
    return y;
}

//Function 03: BN_Output()
void BN_Output(int x){
    int i;
    printf(" Binary Number_%d = (", x+1);
    for(i = MAX_bit - 1; i >= 0; i--)
        printf("%d", binary_number[x][i]);
    printf(")2\n\n");
}

//Funciton 04: MAX()
void MAX(void){
    int i;
    for(i = 0; i < MAX_bit; i++)  MAX_number *= 2;
}

//Function 05: scanf_DN()
int scanf_DN(int x){
    int y;
    printf("Decimal Number_%d = ", x+1);
    scanf("%d", &y);
    return y;
}

//Start
int main(void){
    //Preprocessing.
    MAX();  printf("\n");
    
    int decimal_number[TN+1];
    int i, j;
    
    //Input on left side.
    for(i = 0; i < TN; i++){
        while(((decimal_number[i] = scanf_DN(i)) > MAX_number) || (decimal_number[i] < 0))
            printf("0 ~ %d\n\n", MAX_number);
        DNtoBN(decimal_number[i], i);
    }
    
    //Addition processing.
    for(i = 0; i < MAX_bit; i++){
        for(j = 0; j < TN; j++){
            if(binary_number[j][i] == 1)
                binary_number[TN][i] ++;
        }
    }
    for(i = 0; i < MAX_bit; i++){
        while(binary_number[TN][i] > 1){
            binary_number[TN][i+1] ++;
            binary_number[TN][i] --;
            binary_number[TN][i] --;
        }
    }
    
    printf("\n");
    
    //Output of result.
    if(binary_number[TN][MAX_bit] > 1){
        printf("Error: Overflow.\n\n");
    }else{
        decimal_number[TN] = BNtoDN(TN);
        printf("%d", decimal_number[0]);
        for(i = 1; i < TN; i++)
            printf(" + %d", decimal_number[i]);
        printf(" = %d\n\n", decimal_number[TN]);
        printf("Decimal Number_%d = %d\n\n", TN+1, decimal_number[TN]);
    }
    
    //Thank You!!
    printf("Thank You!\n\n");
    
    return 0;
}
//End

/*
    Information
        Name: Kawasaki Hiroki
        Data: 9/9/2018
 contents: Big Numbers.
        rule:
    Function:
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

//Global Variable

//Function 01:
void Advance(int BigNumber[]){
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

//Function 02:
void Output(int BigNumber[]){
    int i;
    for(i = MAX; i >= 0; i--){
        if(BigNumber[i] > 0){
            printf("%d", BigNumber[i]);
            break;
        }
    }
    while(i > 0){
        i--;
        if(BigNumber[i] >= 100)
            printf("%d", BigNumber[i]);
        else if(BigNumber[i] >= 10)
            printf("0%d", BigNumber[i]);
        else
            printf("00%d", BigNumber[i]);
    }
    printf("\n");
    return;
}

//Function 03:
void multiplication(int BigNumber[], int num){
    //Declaring variables.
    int i, n, c = -1;
    char marker[10000];
    int BigNumber_copy[MAX + 1];
    
    //Preprocessing.
    for(i = 0; i < MAX; i++)
        BigNumber_copy[i] = BigNumber[i];
    
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
                for(i = 0; i < MAX; i++){
                    BigNumber[i] += BigNumber_copy[i];
                }
                break;
            case '*':
                for(i = 0; i < MAX; i++)
                    BigNumber[i] *= 2;
                break;
            default:
                break;
        }
        Advance(BigNumber);
        c--;
    }
    return;
}

//Start
int main(void){
    //Declaring variables.
    int BigNumber1[MAX + 1];
    int i, num;
    
    //Preprocessing.
    for(i = 0; i < MAX; i++)
        BigNumber1[i] = 0;
    BigNumber1[0] = 1;
    
    printf("Number = ");
    scanf("%d", &num);
    
    for(i = 1; i <= num; i++)
        multiplication(BigNumber1, i);
    
    printf("%d!(%dの階乗) = ", num, num);
    Output(BigNumber1);
    
    return 0;
}
//End

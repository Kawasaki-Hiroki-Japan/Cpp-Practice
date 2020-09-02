/*
    Information
        Name: Kawasaki Hiroki
        Data: 9/8/2018
 contents: Big Numbers.
        rule:
    Function:
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
            printf(",%d", BigNumber[i]);
        else if(BigNumber[i] >= 10)
            printf(",0%d", BigNumber[i]);
        else
            printf(",00%d", BigNumber[i]);
    }
    printf("\n");
    return;
}

//Start
int main(void){
    //Declaring variables.
    int BigNumber1[MAX + 1];
    int num1, num2, i, n, c = -1;
    char marker[10000];
    
     //Preprocessing.
    for(i = 0; i < MAX; i++)
        BigNumber1[i] = 0;
    
    printf("Number1 = ");
    scanf("%d", &num1);
    printf("Number2 = ");
    scanf("%d", &num2);
    
    n = num2;
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
    BigNumber1[0] = num1;
    Advance(BigNumber1);
    while(c >= 0){
        switch(marker[c]){
            case '+':
                BigNumber1[0] += num1;
                break;
            case '*':
                for(i = 0; i < MAX; i++)
                    BigNumber1[i] *= 2;
                break;
            default:
                break;
        }
        Advance(BigNumber1);
        c--;
    }
    
    printf("\n%d * %d = ", num1, num2);
    Output(BigNumber1);
    
    //Thank You!!
    printf("\nThank You!\n\n");
    
    return 0;
}
//End

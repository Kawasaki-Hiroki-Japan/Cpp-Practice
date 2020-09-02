/*
 Information
 Name: Kawasaki Hiroki
 Data: 9/19/2018 - 9/21/2018
 contents: Study Math
 
 Function M0001: scan_Number()
 Function M0002: print_polynomial()
 Function M0003: advance()
 Function M0004: print_BigNumber()
 Function M0005: multiplication()
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>

int scan_Number(char char_1, int int_1, int int_2, int int_3){
    //char_1 -> Information of variable.
    //int_1,int_2 -> Range of the variable.
    //int_3 -> 0 :(int_1 <= int_5 <= int_2), 1 :(int_1 < int_5 < int_2)
    int int_4 = -1, int_5 = 0;
    if((int_3 != 0) && (int_3 != 1)){
        printf("Error: s001\n\n");
        exit(0);
    }
    while(int_3 != int_4){
        if(char_1 == '0')       printf("Number = ");
        else if(char_1 == '1')  printf("No.");
        else                    printf("%c = ", char_1);
        scanf("%d",&int_5);
        if((int_5 >= int_1) && (int_5 <= int_2))
            int_4 = 0;
        else if((int_5 > int_1) && (int_5 < int_2))
            int_4 = 1;
    }
    return int_5;
}

void print_polynomial(int a, int b, int c){
    //[ax^2 + bx + c]
    if(a == 1){
        if(b > 1){
            if(c > 0)        printf("x^2 + %dx + %d", b, c);
            else if(c == 0)  printf("x^2 + %dx", b);
            else             printf("x^2 + %dx - %d", b, -c);
        }else if(b == 1){
            if(c > 0)        printf("x^2 + x + %d", c);
            else if(c == 0)  printf("x^2 + x");
            else             printf("x^2 + x - %d", -c);
        }else if(b == 0){
            if(c > 0)        printf("x^2 + %d", c);
            else if(c == 0)  printf("x^2");
            else             printf("x^2 - %d", -c);
        }else if(b == -1){
            if(c > 0)        printf("x^2 - x + %d", c);
            else if(c == 0)  printf("x^2 - x");
            else             printf("x^2 - x - %d", -c);
        }else{
            if(c > 0)        printf("x^2 - %dx + %d", -b, c);
            else if(c == 0)  printf("x^2 - %dx", -b);
            else             printf("x^2 - %dx - %d", -b, -c);
        }
    }else if(a == 0){
        if(b > 1){
            if(c > 0)        printf("%dx + %d", b, c);
            else if(c == 0)  printf("%dx", b);
            else             printf("%dx - %d", b, -c);
        }else if(b == 1){
            if(c > 0)        printf("x + %d", c);
            else if(c == 0)  printf("x");
            else             printf("x - %d", -c);
        }else if(b == 0){
                             printf("%d", c);
        }else if(b == -1){
            if(c > 0)        printf("-x + %d", c);
            else if(c == 0)  printf("-x");
            else             printf("-x - %d", -c);
        }else{
            if(c == 0)       printf("%dx", b);
            else             printf("%dx + %d", b, c);
        }
    }else if(a == -1){
        if(b > 1){
            if(c > 0)        printf("-x^2 + %dx + %d", b, c);
            else if(c == 0)  printf("-x^2 + %dx", b);
            else             printf("-x^2 + %dx - %d", b, -c);
        }else if(b == 1){
            if(c > 0)        printf("-x^2 + x + %d", c);
            else if(c == 0)  printf("-x^2 + x");
            else             printf("-x^2 + x - %d", -c);
        }else if(b == 0){
            if(c > 0)        printf("-x^2 + %d", c);
            else if(c == 0)  printf("-x^2");
            else             printf("-x^2 - %d", -c);
        }else if(b == -1){
            if(c > 0)        printf("-x^2 - x + %d", c);
            else if(c == 0)  printf("-x^2 - x");
            else             printf("-x^2 - x - %d", -c);
        }else{
            if(c > 0)        printf("-x^2 - %dx + %d", -b, c);
            else if(c == 0)  printf("-x^2 - %dx", -b);
            else             printf("-x^2 - %dx - %d", -b, -c);
        }
    }else{
        if(b > 1){
            if(c > 0)        printf("%dx^2 + %dx + %d", a, b, c);
            else if(c == 0)  printf("%dx^2 + %dx", a, b);
            else             printf("%dx^2 + %dx - %d", a, b, -c);
        }else if(b == 1){
            if(c > 0)        printf("%dx^2 + x + %d", a, c);
            else if(c == 0)  printf("%dx^2 + x", a);
            else             printf("%dx^2 + x - %d", a, -c);
        }else if(b == 0){
            if(c > 0)        printf("%dx^2 + %d", a, c);
            else if(c == 0)  printf("%dx^2", a);
            else             printf("%dx^2 - %d", a, -c);
        }else if(b == -1){
            if(c > 0)        printf("%dx^2 - x + %d", a, c);
            else if(c == 0)  printf("%dx^2 - x", a);
            else             printf("%dx^2 - x - %d", a, -c);
        }else{
            if(c > 0)        printf("%dx^2 - %dx + %d", a, -b, c);
            else if(c == 0)  printf("%dx^2 - %dx", a, -b);
            else             printf("%dx^2 - %dx - %d", a, -b, -c);
        }
    }
    return;
}

void advance(int BigNumber[]){
    int n = 0;
    while(n <= 100000){
        if(BigNumber[n] >= 1000){
            BigNumber[n] -= 1000;
            BigNumber[n+1] ++;
        }else   n++;
    }
    return;
}

void print_BigNumber(int BigNumber[]){
    int i;
    for(i = 100000; i >= 0; i--){
        if(BigNumber[i] > 0){
            printf("%d", BigNumber[i]);
            break;
        }
    }
    while(i > 0){
        i--;
        if(BigNumber[i] >= 100)        printf("%d", BigNumber[i]);
        else if(BigNumber[i] >= 10)    printf("0%d", BigNumber[i]);
        else                           printf("00%d", BigNumber[i]);
    }
    printf("\n");
    return;
}

void multiplication(int BigNumber[], int num){
    int i, n, c = -1, BigNumber_copy[100000];
    char marker[10000];
    for(i = 0; i < 100000; i++)
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
                for(i = 0; i < 100000; i++)    BigNumber[i] += BigNumber_copy[i];
                break;
            case '*':
                for(i = 0; i < 100000; i++)    BigNumber[i] *= 2;
                break;
            default:
                break;
        }
        advance(BigNumber);
        c--;
    }
    return;
}

// (c) 2018 Kawasaki Hiroki

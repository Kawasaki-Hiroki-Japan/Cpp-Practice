/*
 Information
 Name: Kawasaki Hiroki
 Data: 3/14/2018, 9/23/2018
 contents: Prime Number Edition.
 
 Function M0301: sqrt_intf()
 Function M0302: pndf()
 Function M0303: pnrf()
 Function M0304: pnef()
 Function M0305: pnd_optionf()
 Function M0306: option()
 Function M0307: Prime_Number_Edition()
 */


#pragma once

#include<stdio.h>
#include<math.h>
#include "Math_000.hpp"


int sqrt_intf(int x){
    double y;
    int z;
    y = sqrt(x);    z = (int)y;
    return z;
}

int pndf(int x[50000], int y[50000], int z){
    int i = 1;
    int sqrt_int;
    sqrt_int = sqrt_intf(z);
    while(1){
        if(i < 50000 && x[i] > sqrt_int)                return 1;
        else if(i >= 50000 && y[i-50000] > sqrt_int)    return 1;
        if(i < 50000 && z % x[i] == 0)                  return 0;
        else if(i >= 50000 && z % y[i-50000] == 0)      return 0;
        i++;
    }
    return 0;
}

void pnrf(int x[50000], int y[50000], int z){
    if(z <= 50000)  printf("\nPrime Number (No.%d): %d\n",z, x[z-1]);
    else            printf("\nPrime Number (No.%d): %d\n", z, y[z-50001]);
    return;
}

void pnef(int x[50000], int y[50000]){
    int i;
    for(i = 0; i < 50000; i++){
        printf("%7d",x[i]);
        if((i+1) % 10 != 0)     printf(", ");
        else                    printf("\n");
    }
    for(i = 0;i < 50000;i++){
        printf("%7d",y[i]);
        if((i+1) % 10 != 0)     printf(", ");
        else                    printf("\n");
    }
    return;
}

int pnd_optionf(int x[50000], int y[50000], int z){
    int i;
    for(i = 0; i < 50000; i++){
        if(z == x[i])   return 1;
    }
    for(i = 0; i < 50000; i++){
        if(z == y[i])   return 1;
    }
    return 0;
}

void option(int x[50000], int y[50000]){
    int select, num, pn_bool;
    printf("\nPlease choose the option.\n\n");
    printf(" 1: Search for a prime number.\n");
    printf(" 2: Output prime numbers.\n");
    printf(" 3: Factorization in prime numbers.\n");
    printf(" 4: Distinguish a prime number.\n\n");
    printf("select: ");
    scanf("%d", &select);
    printf("\n");
    switch(select){
        case 1:
            printf("What number prime number do you want to know?\n");
            printf("(No.1 ~ No.100000)\n\n");
            num = scan_Number('1', 1, 100000, 0);
            pnrf(x, y, num);
            break;
        case 2:
            printf("Output prime numbers from 1st(2) to 100000th(1299710).\n");
            pnef(x, y);
            break;
        case 3:
            printf("No content.\n");
            break;
        case 4:
            printf("Please input number that wants to distinguish.\n");
            printf("(1 ~ 1299710)\n\n");
            num = scan_Number('0', 1, 1299710, 0);
            pn_bool = pnd_optionf(x, y,num);
            printf("\n");
            if(pn_bool == 1)        printf("{%d} ∈ Prime Number\n", num);
            else if(pn_bool == 0)   printf("{%d} ∉ Prime Number\n", num);
            break;
        default:
            printf("Error: y005\n");
            break;
    }
    return;
}

void Prime_Number_Edition(){
    int prime_numbers1[50000] = {2,3};
    int prime_numbers2[50000] = {0};
    int num = 3, pn_bool = 0, i = 2;
    while(i < 100000){
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
    printf("\n");
    return;
}


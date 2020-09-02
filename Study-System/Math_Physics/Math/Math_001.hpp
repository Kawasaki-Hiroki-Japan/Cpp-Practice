/*
 Information
 Name: Kawasaki Hiroki
 Data: 9/19/2018
 contents: Study Math No.1: Factorization
 
 Function M0101: scan_Number()
 Function M0102: Factorization()
 */

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Math_000.hpp"

void print_Factorization(int k, int n1, int n2, int n3, int n4){
    if(n1 == 1 && n2 == 0){
        if(n3 == 1 && n4 == 0)    printf("%dx^2", k);
        else                      printf("%dx", k);
    }else if(n3 == 1 && n4 == 0)  printf("%dx", k);
    else{
        if(n1 == 0)    k *= n2;
        if(n3 == 0)    k *= n4;
        if(k != 1 && k != 0)     printf("%d", k);
    }
    if(n1 == 1){
        if (n2 > 0)         printf("( x + %d )", n2);
        else if(n2 < 0)     printf("( x - %d )", -n2);
    }else if(n1 != 0){
        if (n2 > 0)         printf("( %dx + %d )", n1, n2);
        else if(n2 < 0)     printf("( %dx - %d )", n1, -n2);
    }
    if(n1 == n3 && n2 == n4){
        printf(" ^ 2");
    }else if(n3 == 1){
        if (n4 > 0)         printf("( x + %d )", n4);
        else if(n4 < 0)     printf("( x - %d )", -n4);
    }else if(n3 != 0){
        if (n4 > 0)         printf("( %dx + %d )", n3, n4);
        else if(n4 < 0)     printf("( %dx - %d )", n3, -n4);
    }
    return;
}

void Factorization(){
    int num_Basic[3], num[3], a_Abs ,b_Abs, c_Abs, k = 1, a1 = 0, a2 = 0, c1 = 0, c2 = 0;
    int kye, i, j;
    printf("Resolve a polynomial into factors.\n");
    printf("[ax^2+bx+c]\n\n");
    
    num_Basic[0] = scan_Number('a', -99, 99, 0);
    num_Basic[1] = scan_Number('b', -99, 99, 0);
    num_Basic[2] = scan_Number('c', -99, 99, 0);
    
    num[0] = num_Basic[0];
    num[1] = num_Basic[1];
    num[2] = num_Basic[2];
    
    printf("\n[");   print_polynomial(num_Basic[0], num_Basic[1], num_Basic[2]);   printf("]\n");

    a_Abs = (int)fabs(num[0]);    b_Abs = (int)fabs(num[1]);    c_Abs = (int)fabs(num[2]);
    
    if(num[0] < 0)  k *= -1;
    for(i = 1; i <= a_Abs; i++){
        if((a_Abs % i == 0) && (b_Abs % i == 0) && (c_Abs % i == 0))    k *= i;
    }
    num[0] /= k;    num[1] /= k;    num[2] /= k;
    
    for(i = 1; i <= a_Abs; i++){
        if(a_Abs % i == 0){
            a1 = i;    a2 = num[0] / i;
            for(j = 1; j <= c_Abs; j++){
                if(c_Abs % j == 0){
                    c1 = j;    c2 = num[2] / j;
                    if(a1*c2+a2*c1 == num[1])   goto end;
                    c1 *= -1;   c2 *= -1;
                    if(a1*c2+a2*c1 == num[1])   goto end;
                }
            }
            a1 *= -1;   a2 *= -1;
            for(j = 1; j <= c_Abs; j++){
                if(c_Abs % j == 0){
                    c1 = j;    c2 = num[2] / j;
                    if(a1*c2+a2*c1 == num[1])   goto end;
                }
            }
        }
        
    }
    printf("\n");   print_polynomial(num_Basic[0], num_Basic[1], num_Basic[2]);
    if(k != 1){
        printf(" = %d( ", k);
        print_polynomial(num_Basic[0]/k, num_Basic[1]/k, num_Basic[2]/k);
        printf(" )\n\n");
    }else{
        printf("\n\n");
    }
    return;
    end:
    printf("\n");   print_polynomial(num_Basic[0], num_Basic[1], num_Basic[2]);   printf(" = ");
    print_Factorization(k, a1, c1, a2, c2);    printf("\n\n");
    return;
}

// (c) 2018 Kawasaki Hiroki

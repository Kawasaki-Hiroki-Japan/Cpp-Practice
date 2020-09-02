/*
 Information
 Name: Kawasaki Hiroki
 Data: 9/9/2018, 9/22/2018 - 9/23/2018
 contents: Program to make factorial.
 
 Function M0201: Factorial()
 */

#pragma once

#include <stdio.h>
#include "Math_000.hpp"

int Factorial(){
    int BigNumber1[100000 + 1], i, num;
    for(i = 0; i < 100000; i++)        BigNumber1[i] = 0;
    BigNumber1[0] = 1;
    printf("Calculate the factorial.\nPlease input integers more than 0(zero).\n\n");
    num = scan_Number('0', 0, 999999, 0);
    for(i = 1; i <= num; i++)       multiplication(BigNumber1, i);
    printf("\n");
    printf("%d!(Factorial[%d]) = ", num, num);
    print_BigNumber(BigNumber1);
    printf("\n");
    
    return 0;
}

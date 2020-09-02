/*
 Information
    Name: Kawasaki Hiroki
    Data: 8/30/2018
*/

#include <stdio.h>

//Function 01~02: year(), month()
int year(void){
    int y;
    printf(" year: ");    scanf("%d", &y);
    return y;
}
int month(void){
    int m;
    printf("month: ");    scanf("%d", &m);
    return m;
}

//Start
int main(void){
    int y, m, d, sn = 1, n;
    
    printf("\n");
    while((y = year()) < 1)
        printf("\nyear = Natural Nunber\n\n");
    while(((m = month()) < 1) || (m > 12)){
        printf("\n1 <= Month <= 12\n\n");
        printf(" year: %d\n", y);
    }
    
    if((m == 2) && (((y % 4 != 0) && (y % 100 == 0)) || (y % 400 != 0)))    d = 28;
    else if(m == 2)                                                         d = 29;
    else if(((m <= 7) && (m % 2 != 1)) || ((m >= 8) && (m % 2 == 1)))       d = 30;
    else                                                                    d = 31;
    
    for(n = 1; n < y; n++){
        if(((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))    sn += 366;
        else                                                      sn += 365;
    }
    for(n = 1; n < m; n++){
        if((n == 2) && (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)))    sn += 29;
        else if(n == 2)                                                         sn += 28;
        else if(((n <= 7) && (n % 2 != 1)) || ((n >= 8) && (n % 2 == 1)))       sn += 30;
        else                                                                    sn += 31;
    }
    
    printf("\nSerial Nunber = %d <- %d/1/%d\n\n", sn, m, y);
    
    printf("                 %2d/%4d\n", m, y);
    printf("  Sun.  Mon.  Tue.  Wed.  Thu.  Fri.  Sta.\n");
    for(n = 1; n - sn % 7 <= d; n++){
        if(n <= sn % 7)    printf("      ");
        else               printf("   %2d ", n - sn % 7);
        if(n % 7 == 0)     printf("\n");
    }
    printf("\n\n");
    return 0;
}

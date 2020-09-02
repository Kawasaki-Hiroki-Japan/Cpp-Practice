//作成者 川﨑 裕貴
//作成日 2018/7/14
//連立方程式（二元一次方程式）の解を求める

#include<stdio.h>
#include<math.h>

int houteisiki(int a, int b, int c, int n){
    
    if(a == 0){
        if(b == 0){         printf("入力ミスです\n\n");   return 1;   }
        else if(b == 1)     printf("y = %d", c);
        else if(b == -1)    printf("-y = %d", c);
        else                printf("%dy = %d", b, c);
    }else if(a == 1){
        if(b == 0)          printf("x = %d", c);
        else if(b == 1)     printf("x + y = %d", c);
        else if(b == -1)    printf("x - y = %d", c);
        else if(b > 0)      printf("x + %dy = %d", b, c);
        else                printf("x - %dy = %d", -b, c);
    }else if(a == -1){
        if(b == 0)          printf("-x = %d", c);
        else if(b == 1)     printf("-x + y = %d", c);
        else if(b == -1)    printf("-x - y = %d", c);
        else if(b > 0)      printf("-x + %dy = %d", b, c);
        else                printf("-x - %dy = %d", -b, c);
    }else{
        if(b == 0)          printf("%dx = %d", a, c);
        else if(b == 1)     printf("%dx + y = %d", a, c);
        else if(b == -1)    printf("%dx - y = %d", a, c);
        else if(b > 0)      printf("%dx + %dy = %d", a, b, c);
        else                printf("%dx - %dy = %d", a, -b, c);
    }
    
    if(n == 1)          printf(" ・・・ ①\n");
    else if(n == 2)     printf(" ・・・ ②\n");
    else                printf("\n");
    
    return 0;
}

double dou(int n){
    return (double)n;
}

int main(void){
    
    int a, b, c, d, e, f;
    double af, cd, ae, bd, x, y, decimal[100];
    
    printf("\n");
    printf("ax + by = c ・・・ ①\n");
    printf("dx + ey = f ・・・ ②\n");
    printf("ただし、a,b,c,d,e,fは整数\n\n");
    
    do{
        printf("a, b, cを入力してください\n\n");
        printf("a = ");    scanf("%d", &a);
        printf("b = ");    scanf("%d", &b);
        printf("c = ");    scanf("%d", &c);
        printf("\n");
    }while(houteisiki(a, b, c, 0) != 0);
    printf("\n");
    
    do{
        printf("d, e, fを入力してください\n\n");
        printf("d = ");    scanf("%d", &d);
        printf("e = ");    scanf("%d", &e);
        printf("f = ");    scanf("%d", &f);
        printf("\n");
    }while(houteisiki(d, e, f, 0) != 0);
    printf("\n");
    
    houteisiki(a, b, c, 1);
    houteisiki(d, e, f, 2);
    printf("\n");
    
    printf("代入法\n\n");
    /*
     if(a == 0){
        y = dou(c) / dou(b);
        x = (dou(f) - dou(e) * y) / dou(d);
    }else if(b == 0){
        x = dou(c) / dou(a);
        y = (dou(f) - dou(d) * x) / dou(e);
    }else if(d == 0){
        y = dou(f) / dou(e);
        x = (dou(c) - dou(b) * y) / dou(a);
    }else if(e == 0){
        x = dou(f) / dou(d);
        y = (dou(c) - dou(a) * x) / dou(b);
     }
     printf("x = %.3f, y = %.3f\n\n", x, y);
     */
    
    af = a * f;   cd = c * d;   ae = a * e;   bd = b * d;
    y = (af - cd)/(ae - bd);
    x = (dou(c) - dou(b) * y) / dou(a);
    
    printf("① を変形\n");
    houteisiki(a, b, c, 1);
    if(a == 1){
        if(b == 1)          printf("x = %d - y", c);
        else if(b == -1)    printf("x = %d + y", c);
        else if(b > 0)      printf("x = %d - %dy", c, b);
        else                printf("x = %d + %dy", c, -b);
    }else if(a == -1){
        if(b == 1)          printf("-x = %d - y\n", c);
        else if(b == -1)    printf("-x = %d + y\n", c);
        else if(b > 0)      printf("-x = %d - %dy\n", c, b);
        else                printf("-x = %d + %dy\n", c, -b);
    }else{
        if(b == 1)          printf("%dx = %d - y\n", a, c);
        else if(b == -1)    printf("%dx = %d + y\n", a, c);
        else if(b > 0)      printf("%dx = %d - %dy\n", a, c, b);
        else                printf("%dx = %d + %dy\n", a, c, -b);
    }
    decimal[0] = dou(c) / dou(a);   decimal[1] = dou(b) / dou(a);
    if(a != 1){
        if(decimal[1] > 0)  printf("x = %.3f - %.3fy", decimal[0], decimal[1]);
        else                printf("x = %.3f + %.3fy", decimal[0], -decimal[1]);
    }
    printf(" ・・・ ③\n\n");
    
    printf("② に③ を代入\n");
    houteisiki(d, e, f, 2);
    if(decimal[1] > 0)  printf("%d × ( %.3f - %.3fy ) + %dy = %d\n", d, decimal[0], decimal[1], e, f);
    else                printf("%d × ( %.3f + %.3fy ) + %dy = %d\n", d, decimal[0], -decimal[1], e, f);
    decimal[2] = decimal[0] * dou(d);   decimal[3] = decimal[1] * dou(d);
    if(decimal[3] > 0)  printf("%.3f - %.3fy + %dy = %d\n", decimal[2], decimal[3], e, f);
    else                printf("%.3f + %.3fy + %dy = %d\n", decimal[2], -decimal[3], e, f);
    decimal[4] = -decimal[3] + dou(e);
    if(decimal[4] > 0)  printf("%.3f + %.3fy = %d\n", decimal[2], decimal[4], f);
    else                printf("%.3f - %.3fy = %d\n", decimal[2], -decimal[4], f);
    decimal[5] = dou(f) - decimal[2];
    printf("%.3fy = %.3f\n", decimal[4], decimal[5]);
    decimal[6] = decimal[5] / decimal[4];
    printf("y = %.3f ・・・ ④\n\n", decimal[6]);
    
    printf("③ に④ を代入\n");
    if(decimal[1] > 0)  printf("x = %.3f - %.3fy ・・・ ③\n", decimal[0], decimal[1]);
    else                printf("x = %.3f + %.3fy ・・・ ③\n", decimal[0], -decimal[1]);
    decimal[7] = decimal[1] * decimal[6];
    if(decimal[7] > 0)  printf("x = %.3f - %.3f\n", decimal[0], decimal[7]);
    else                printf("x = %.3f + %.3f\n", decimal[0], -decimal[7]);
    decimal[8] = decimal[0] - decimal[7];
    printf("x = %.3f ・・・ ⑤\n\n", decimal[8]);
    
    printf("したがって\n");
    printf("x = %.3f, y = %.3f\n\n", x, y);
    
    
    return 0;
}

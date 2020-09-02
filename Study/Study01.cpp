//作成者 川﨑 裕貴
//作成日 2018/7/12
//二次方程式の解を求める

#include<stdio.h>
#include<math.h>

int main(void){
    int a, b, c;
    double ad, bd, cd, x1, x2, d;
    
    printf("ax^2 + bx + c = 0\n\n");
    printf("a, b, cを入力してください。\n");
    printf("ただし、a,b,cは整数\n\n");
    
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);
    printf("\n");
    
    ad = a;
    bd = b;
    cd = c;
    
    if(a == 0){
        if(b == 0){
            printf("方程式ではありません\n\n");
            return 0;
        }
        printf("一次方程式\n");
        if(b == 1){
            if(c > 0)   printf("x + %d = 0\n", c);
            else if(c < 0)   printf("x - %d = 0\n", -c);
            else             printf("x = 0\n");
        }else{
            if(c > 0)   printf("%dx + %d = 0\n", b, c);
            else if(c < 0)   printf("%dx - %d = 0\n", b, -c);
            else             printf("%dx = 0\n", b);
        }
        x1 = -cd / bd;
        printf("x = %.3f\n\n", x1);
        return 0;
    }else if(a == 1){
        if(b == 1){
            if(c > 0)        printf("x^2 + x + %d = 0\n", c);
            else if(c < 0)   printf("x^2 + x - %d = 0\n", -c);
            else             printf("x^2 + x = 0\n");
        }else if(b > 0){
            if(c > 0)        printf("x^2 + %dx + %d = 0\n", b, c);
            else if(c < 0)   printf("x^2 + %dx - %d = 0\n", b, -c);
            else             printf("x^2 + %dx = 0\n", b);
        }else if(b < 0){
            if(c > 0)        printf("x^2 - %dx + %d = 0\n", -b, c);
            else if(c < 0)   printf("x^2 - %dx - %d = 0\n", -b, -c);
            else             printf("x^2 - %dx = 0\n", -b);
        }else{
            if(c > 0)        printf("x^2 + %d = 0\n", c);
            else if(c < 0)   printf("x^2 - %d = 0\n", -c);
            else             printf("x^2 = 0\n");
        }
    }else{
        if(b == 1){
            if(c > 0)        printf("%dx^2 + x + %d = 0\n", a, c);
            else if(c < 0)   printf("%dx^2 + x - %d = 0\n", a, -c);
            else             printf("%dx^2 + x = 0\n", a);
        }else if(b > 0){
            if(c > 0)        printf("%dx^2 + %dx + %d = 0\n", a, b, c);
            else if(c < 0)   printf("%dx^2 + %dx - %d = 0\n", a, b, -c);
            else             printf("%dx^2 + %dx = 0\n", a, b);
        }else if(b < 0){
            if(c > 0)        printf("%dx^2 - %dx + %d = 0\n", a, -b, c);
            else if(c < 0)   printf("%dx^2 - %dx - %d = 0\n", a, -b, -c);
            else             printf("%dx^2 - %dx = 0\n", a, -b);
        }else{
            if(c > 0)        printf("%dx^2 + %d = 0\n", a, c);
            else if(c < 0)   printf("%dx^2 - %d = 0\n", a, -c);
            else             printf("%dx^2 = 0\n", a);
        }
    }
    
    d = bd * bd - 4 * ad * cd;
    
    if(d < 0){
        printf("実数解なし（虚数解）\n\n");
        return 0;
    }
    
    x1 = (-bd + sqrt(d)) / (2 * ad);
    x2 = (-bd - sqrt(d)) / (2 * ad);
    
    printf("x = %.3f", x1);
    
    if(d == 0)   printf("\n\n");
    else         printf(", %.3f\n\n", x2);
    
    return 0;
}

//作成者 川﨑 裕貴
//作成日 2018/7/30
//剰余計算(modのアルゴリズム)

#include<stdio.h>
#include<math.h>
    
int main(void){
    
    int n1 = 1, n2, i, d;
    
    printf("\n(n ^ i)(mod d)\n\n");
    
    printf("n, i, dを入力してください\n");
    printf("n = ");    scanf("%d", &n2);
    printf("i = ");    scanf("%d", &i);
    printf("d = ");    scanf("%d", &d);
    printf("\n");
    
    printf("  (%d ^ %d)(mod %d)\n\n", n2, i, d);
    printf("  %d ^ %d\n", n2, i);
    
    while(1){
        if(n1 >= d){
            n1 %= d;
            printf("≡ %d * %d ^ %d\n", n1, n2, i);
        }
        if(n2 >= d){
            n2 %= d;
            if(n1 == 1)    printf("≡ %d ^ %d\n", n2, i);
            else           printf("≡ %d * %d ^ %d\n", n1, n2, i);
        }
        if(i % 2 != 0){
            n1 *= n2;
            i -= 1;
        }else{
            i /= 2;
            n2 = n2 * n2;
        }
        
        if(i == 1)              break;
        if(n1 == 1 || n2 == 1)  break;
        
        if(n1 == 1)    printf("= %d ^ %d\n", n2, i);
        else           printf("= %d * %d ^ %d\n", n1, n2, i);
    }
    
    if(n1 != 1){
        printf("= %d * %d\n", n1, n2);
        
        if(n1 >= d || n2 >= d){
            n1 %= d;    n2 %= d;
            printf("≡ %d * %d\n", n1, n2);
        }
    }
    
    n1 *= n2;
    printf("= %d\n", n1);
    
    if(n1 >= d){
        n1 %= d;
        printf("≡ %d\n", n1);
    }
    printf("\n");
    return 0;
}

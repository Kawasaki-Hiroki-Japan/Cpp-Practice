// 作成者 川﨑 裕貴

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void ruruOn();
void char_desicion(char a[]);
struct Numerical_Formula struct_a(char a[], struct Numerical_Formula nf);
int Numerical_Formula_desicion_all(struct Numerical_Formula nf);
void Numerical_Formula_desicion_NoAns(struct Numerical_Formula nf);
void Candidata(struct Numerical_Formula nf);

struct Numerical_Formula{
    int x;
    char symbol;
    int y;
    char equal;
    int ans;
};


int main(void){
    char numerical_formula[MAX_LEN];
    int len;
    int numerical_formula_bool = 0;
    
    Numerical_Formula nf = {0, ' ', 0 , ' ', 0};
    
    printf("\n\n数式を半角で入力して下さい\n");
    printf("ルールを表示したい場合は, [r] を入力してください\n\n");
    while(1){
        fgets(numerical_formula, MAX_LEN, stdin);
        if(numerical_formula[0] != 'r')
            break;
        ruruOn();
        printf("数式を入力して下さい\n\n");
    }
    
    len = strlen(numerical_formula);
    numerical_formula[len - 1] = '\0';
    
    char_desicion(numerical_formula);
    
    printf("\n");
    
    nf = struct_a(numerical_formula, nf);
    
    if((nf.x != 0) && (nf.symbol != ' ') && (nf.y != 0) && (nf.equal != ' '))
        numerical_formula_bool = Numerical_Formula_desicion_all(nf);
    else
        Numerical_Formula_desicion_NoAns(nf);
        
    if(numerical_formula_bool == 1)
        Candidata(nf);
    
    return 0;
}

//ルールの表示
void ruruOn(){
    printf("\n******************************************************************\n");
    printf("*                             ルール                             *\n");
    printf("******************************************************************\n");
    printf("* ・ 自然数の等式                                                *\n");
    printf("* ・ 項数は２つ                                                  *\n");
    printf("* ・ 四則演算のみ                                                *\n");
    printf("* ・ スペースを入れない                                          *\n");
    printf("* ・ 全て半角で入力（掛け算は「*」、割り算は「/」で入力すること）*\n");
    printf("* ・ 割り算の場合、あまりは0                                     *\n");
    printf("* ・ ○○+○○=○○ の形で入力                                         *\n");
    printf("******************************************************************\n\n");
}

//文字列の正誤判定
void char_desicion(char a[]){
    int i = 0;
    while(a[i] != '\0'){
        switch (a[i]) {
            case '1':
                break;
            case '2':
                break;
            case '3':
                break;
            case '4':
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case '0':
                break;
            case '+':
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
            case ':':
                break;
            case '=':
                break;
            default:
                printf("\n扱うことのできない文字が含まれています\n\n");
                exit(1);
                break;
        }
        i++;
    }
}

// 構造体に代入
Numerical_Formula struct_a(char a[],Numerical_Formula nf){
    int i = 0;
    int add = 0;
    while(a[i] != '\0'){
        switch (add) {
            case 0:
                switch (a[i]) {
                    case '1':
                        nf.x *= 10;
                        nf.x += 1;
                        break;
                    case '2':
                        nf.x *= 10;
                        nf.x += 2;
                        break;
                    case '3':
                        nf.x *= 10;
                        nf.x += 3;
                        break;
                    case '4':
                        nf.x *= 10;
                        nf.x += 4;
                        break;
                    case '5':
                        nf.x *= 10;
                        nf.x += 5;
                        break;
                    case '6':
                        nf.x *= 10;
                        nf.x += 6;
                        break;
                    case '7':
                        nf.x *= 10;
                        nf.x += 7;
                        break;
                    case '8':
                        nf.x *= 10;
                        nf.x += 8;
                        break;
                    case '9':
                        nf.x *= 10;
                        nf.x += 9;
                        break;
                    case '0':
                        nf.x *= 10;
                        break;
                    default:
                        add++;
                        i--;
                        break;
                }
                i++;
                break;
            case 1:
                switch(a[i]){
                    case '+':
                        nf.symbol = '+';
                        break;
                    case '-':
                        nf.symbol = '-';
                        break;
                    case '*':
                        nf.symbol = '*';
                        break;
                    case '/':
                        nf.symbol = '/';
                        break;
                    case ':':
                        nf.symbol = '/';
                        break;
                    case '=':
                        nf.equal = '=';
                        add = 3;
                        break;
                    default:
                        printf("この数式を分析することができませんでした\n\n");
                        exit(1);
                        break;
                }
                add++;
                i++;
                break;
            case 2:
                switch (a[i]) {
                    case '1':
                        nf.y *= 10;
                        nf.y += 1;
                        break;
                    case '2':
                        nf.y *= 10;
                        nf.y += 2;
                        break;
                    case '3':
                        nf.y *= 10;
                        nf.y += 3;
                        break;
                    case '4':
                        nf.y *= 10;
                        nf.y += 4;
                        break;
                    case '5':
                        nf.y *= 10;
                        nf.y += 5;
                        break;
                    case '6':
                        nf.y *= 10;
                        nf.y += 6;
                        break;
                    case '7':
                        nf.y *= 10;
                        nf.y += 7;
                        break;
                    case '8':
                        nf.y *= 10;
                        nf.y += 8;
                        break;
                    case '9':
                        nf.y *= 10;
                        nf.y += 9;
                        break;
                    case '0':
                        nf.y *= 10;
                        break;
                    default:
                        add++;
                        i--;
                        break;
                }
                i++;
                break;
            case 3:
                switch(a[i]){
                    case '=':
                        nf.equal = '=';
                        break;
                    default:
                        printf("この数式を分析することができませんでした\n\n");
                        exit(1);
                        break;
                }
                add++;
                i++;
                break;
            case 4:
                switch(a[i]){
                    case '1':
                        nf.ans *= 10;
                        nf.ans += 1;
                        break;
                    case '2':
                        nf.ans *= 10;
                        nf.ans += 2;
                        break;
                    case '3':
                        nf.ans *= 10;
                        nf.ans += 3;
                        break;
                    case '4':
                        nf.ans *= 10;
                        nf.ans += 4;
                        break;
                    case '5':
                        nf.ans *= 10;
                        nf.ans += 5;
                        break;
                    case '6':
                        nf.ans *= 10;
                        nf.ans += 6;
                        break;
                    case '7':
                        nf.ans *= 10;
                        nf.ans += 7;
                        break;
                    case '8':
                        nf.ans *= 10;
                        nf.ans += 8;
                        break;
                    case '9':
                        nf.ans *= 10;
                        nf.ans += 9;
                        break;
                    case '0':
                        nf.ans *= 10;
                        break;
                    default:
                        add++;
                        i--;
                        break;
                }
                i++;
                break;
            default:
                return nf;
                break;
        }
    }
    return nf;
}

//全情報が揃っているときの分析
int Numerical_Formula_desicion_all(Numerical_Formula nf){
    switch(nf.symbol){
        case '+':
            if(nf.x + nf.y == nf.ans){
                printf("%d %c %d %c %d は正しいです\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
                return 0;
            }else{
                printf("%d %c %d %c %d は誤ってます\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
                return 1;
            }
            break;
        case '-':
            if(nf.x - nf.y == nf.ans){
                printf("%d %c %d %c %d は正しいです\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
                return 0;
            }else{
                printf("%d %c %d %c %d は誤ってます\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
                return 1;
            }
            break;
        case '*':
            if(nf.x * nf.y == nf.ans){
                printf("%d %c %c %c %d は正しいです\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
                return 0;
            }else{
                printf("%d %c %d %c %d は誤ってます\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
                return 1;
            }
            break;
        case '/':
            if((nf.x / nf.y == nf.ans) && (nf.ans * nf.y == nf.x)){
                printf("%d %c %d %c %d は正しいです\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
                return 0;
            }else{
                printf("%d %c %d %c %d は誤ってます\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
                return 1;
            }
            break;
        default:
            exit(1);
            break;
    }
}

//答えが抜けているときの分析
void Numerical_Formula_desicion_NoAns(Numerical_Formula nf){
    nf.equal = '=';
    
    if(nf.symbol == ' '){
    }else
        printf("%d %c %d の計算をします\n\n",nf.x, nf.symbol, nf.y);
    
    switch(nf.symbol){
        case '+':
            nf.ans = nf.x + nf.y;
            break;
        case '-':
            nf.ans = nf.x - nf.y;
            break;
        case '*':
            nf.ans = nf.x * nf.y;
            break;
        case '/':
            if(nf.y != 0)
                nf.ans = nf.x / nf.y;
            else{
                printf("この数式は数学的にありえません\n\n");
                exit(1);
            }
            break;
        case ' ':
            printf("%d %c %d\n\n",nf.x, nf.equal, nf.x);
            return;
            break;
        default:
            exit(1);
            break;
    }
    if((nf.symbol == '/') && (nf.y * nf.ans != nf.x))
        printf("%d %c %d %c %d...%d\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans, nf.x % nf.y);
    else
        printf("%d %c %d %c %d\n\n",nf.x, nf.symbol, nf.y, nf.equal, nf.ans);
}

//正しい数式の候補を出力
void Candidata(Numerical_Formula nf){
    int x, y ,ans;
    
    switch(nf.symbol){
        case '+':
            x = nf.ans - nf.y;
            y = nf.ans - nf.x;
            ans = nf.x + nf.y;
            break;
        case '-':
            x = nf.ans + nf.y;
            y = nf.x - nf.ans;
            ans = nf.x - nf.y;
            break;
        case '*':
            if(nf.y != 0)
                x = nf.ans / nf.y;
            if(nf.x != 0)
                y = nf.ans / nf.x;
            ans = nf.x * nf.y;
            break;
        case '/':
            x = nf.ans * nf.y;
            if(nf.ans != 0)
            y = nf.x / nf.ans;
            if(nf.y != 0)
                ans = nf.x / nf.y;
            break;
        case ' ':
            printf("%d %c %d\n\n",nf.x, nf.equal, nf.x);
            return;
            break;
        default:
            exit(1);
            break;
    }
    
    printf("訂正候補を出力します\n\n");
    if((nf.symbol == '/') && (nf.y * ans != nf.x))
        printf("%d %c %d %c %d...%d\n",nf.x, nf.symbol, nf.y, nf.equal, ans, nf.x % nf.y);
    else
        printf("%d %c %d %c %d\n",nf.x, nf.symbol, nf.y, nf.equal, ans);
    if((nf.symbol == '/') && (y * nf.ans != nf.x)){
    }else if(y >= 0)
        printf("%d %c %d %c %d\n",nf.x, nf.symbol, y, nf.equal, nf.ans);
    else
        printf("%d %c (%d) %c %d\n",nf.x, nf.symbol, y, nf.equal, nf.ans);
    printf("%d %c %d %c %d\n",x, nf.symbol, nf.y, nf.equal, nf.ans);
    if(ans > nf.ans)
        printf("%d %c %d > %d\n",nf.x, nf.symbol, nf.y, nf.ans);
    else
        printf("%d %c %d < %d\n",nf.x, nf.symbol, nf.y, nf.ans);
    if((nf.symbol != '+') && (nf.x + nf.y == nf.ans))
        printf("%d + %d = %d\n",nf.x, nf.y, nf.ans);
    else if((nf.symbol != '-') && (nf.x - nf.y == nf.ans))
        printf("%d - %d = %d\n",nf.x, nf.y, nf.ans);
    else if((nf.symbol != '*') && (nf.x * nf.y == nf.ans))
        printf("%d * %d = %d\n",nf.x, nf.y, nf.ans);
    else if((nf.symbol != '/') && (nf.x / nf.y == nf.ans) && (nf.x % nf.y == 0))
        printf("%d / %d = %d\n",nf.x, nf.y, nf.ans);
    printf("\n");
}

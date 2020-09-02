//作成者: 川﨑裕貴
//作成日: 2018/3/17
//内　容: oxGAME(ver.1)

#include<stdio.h>

void mass(char a[], char b[], char c[], char d[]);
void mass_num();
void massNum(char b[], char c[], char d[]);
int massNum_bool(char b[], char c[], char d[], int x);
void changeo(char b[], char c[], char d[], int x);
void changex(char b[], char c[], char d[], int x);
void battle_mode_select(char a[], char b[], char c[], char d[]);
void battle_modeAI(char a[], char b[], char c[], char d[]);
void win_lose(int x);

int main(void){
    char a[15] = "+---+---+---+\n";
    char b[15] = "|   |   |   |\n";
    char c[15] = "|   |   |   |\n";
    char d[15] = "|   |   |   |\n";
    battle_mode_select(a, b, c, d);
    return 0;
}

//現在のマスを表示する関数
void mass(char a[], char b[], char c[], char d[]){
    int i, j;
    for(i = 1; i < 8; i++){
        if(i == 2){
            for(j = 0; j < 14; j++)
                printf("%c",b[j]);
        }else if(i == 4){
            for(j = 0; j < 14; j++)
                printf("%c",c[j]);
        }else if(i == 6){
            for(j = 0; j < 14; j++)
                printf("%c",d[j]);
        }else{
            for(j = 0; j < 14; j++)
                printf("%c",a[j]);
        }
    }
     printf("\n");
    return;
}

//マス番号を確認する関数
void mass_num(){
    int i, j;
    char a[15] = "+---+---+---+\n";
    char b[15]= "| 1 | 2 | 3 |\n";
    char c[15]= "| 4 | 5 | 6 |\n";
    char d[15]= "| 7 | 8 | 9 |\n";
    for(i = 1; i < 8; i++){
        if(i == 2){
            for(j = 0; j < 14; j++)
                printf("%c",b[j]);
        }else if(i == 4){
            for(j = 0; j < 14; j++)
                printf("%c",c[j]);
        }else if(i == 6){
            for(j = 0; j < 14; j++)
                printf("%c",d[j]);
        }else{
            for(j = 0; j < 14; j++)
                printf("%c",a[j]);
        }
    }
    return;
}

//マス番号の入力と置き換えの実施
void massNum(char b[], char c[], char d[]){
    int x, y = 0;
    while (1){
        do{
            printf("マス番号を入力して下さい\n");
            printf("マス番号の確認をしたい場合は10を入力して下さい\n\n");
            scanf("%d", &x);
            printf("\n");
            if(x == 10){
                mass_num();
                printf("\n");
            }
        }while(x == 10);
        y = massNum_bool(b, c, d, x);
        if(y == 1){
            printf("このマス番号は有効です\n");
            printf("マス番号%dに\"x\"をおきます\n\n",x);
            changex(b, c, d, x);
            y = 0;
            break;
        }
        else{
            printf("このマス番号は無効です\n\n");
        }
    }
    return;
}

//マス番号の有効性を確認
int massNum_bool(char b[], char c[], char d[], int x){
    char space[2] = " ";
    switch(x){
        case 1:
            if(b[2] == space[0])
                return 1;
            break;
        case 2:
            if(b[6] == space[0])
                return 1;
            break;
        case 3:
            if(b[10] == space[0])
                return 1;
            break;
        case 4:
            if(c[2] == space[0])
                return 1;
            break;
        case 5:
            if(c[6] == space[0])
                return 1;
            break;
        case 6:
            if(c[10] == space[0])
                return 1;
            break;
        case 7:
            if(d[2] == space[0])
                return 1;
            break;
        case 8:
            if(d[6] == space[0])
                return 1;
            break;
        case 9:
            if(d[10] == space[0])
                return 1;
            break;
        default:
            break;
    }
    return 0;
}

//マスの書き換えo
void changeo(char b[], char c[], char d[], int x){
    char maru[2] = "o";
    switch(x){
        case 1:
            b[2] = maru[0];
            break;
        case 2:
            b[6] = maru[0];
            break;
        case 3:
            b[10] = maru[0];
            break;
        case 4:
            c[2] = maru[0];
            break;
        case 5:
            c[6] = maru[0];
            break;
        case 6:
            c[10] = maru[0];
            break;
        case 7:
            d[2] = maru[0];
            break;
        case 8:
            d[6] = maru[0];
            break;
        case 9:
            d[10] = maru[0];
            break;
        default:
            break;
    }
    return;
}

//マスの書き換えx
void changex(char b[], char c[], char d[], int x){
    char batu[2] = "x";
    switch(x){
        case 1:
            b[2] = batu[0];
            break;
        case 2:
            b[6] = batu[0];
            break;
        case 3:
            b[10] = batu[0];
            break;
        case 4:
            c[2] = batu[0];
            break;
        case 5:
            c[6] = batu[0];
            break;
        case 6:
            c[10] = batu[0];
            break;
        case 7:
            d[2] = batu[0];
            break;
        case 8:
            d[6] = batu[0];
            break;
        case 9:
            d[10] = batu[0];
            break;
        default:
            break;
    }
    return;
}

//対戦モードの選択
void battle_mode_select(char a[], char b[], char c[], char d[]){
    int x;
    do{
        printf("対戦モードの選択をして下さい\n\n");
        printf("**********************\n");
        printf("* 1: AIと対戦（最強）*\n");
        printf("* 2: 友人と対戦      *\n");
        printf("**********************\n\n");
        scanf("%d", &x);
        printf("\n");
    }while(x != 1 && x != 2);
        switch (x) {
            case 1:
                printf("AIとの対戦を開始します。\n\n");
                battle_modeAI(a, b, c, d);
                break;
            case 2:
                printf("未実装です\n\n");
                break;
            default:
                break;
        }
    return;
}

//対戦モードAI
void battle_modeAI(char a[], char b[], char c[], char d[]){
    char maru[2] = "o";
    char batu[2] = "x";
    int win_flag = 1, lose_flag = 0, root = 0;
    printf("あなたは後攻です\n\n");
    mass(a, b, c, d);
    getchar();
    printf("AIのターンです\n\n");
    changeo(b,c,d,1);
    mass(a, b, c, d);
    getchar();
    printf("あなたのターンです\n\n");
    massNum(b, c, d);
    mass(a, b, c, d);
    getchar();
    if(c[6] != batu[0] && win_flag == 1){
        printf("あなたの負けが確定しました\n\n");
        win_flag = 0;
    }
    getchar();
    printf("AIのターンです\n\n");
    if(b[6] == batu[0]){
        root = 1;
        changeo(b,c,d,7);
    }else if(b[10] == batu[0]){
        root = 2;
        changeo(b,c,d,9);
    }else if(c[2] == batu[0]){
        root = 3;
        changeo(b,c,d,3);
    }else if(c[6] == batu[0]){
        changeo(b,c,d,9);
    }else if(c[10] == batu[0]){
        root = 4;
        changeo(b,c,d,7);
    }else if(d[2] == batu[0]){
        root = 5;
        changeo(b,c,d,9);
    }else if(d[6] == batu[0]){
        root = 6;
        changeo(b,c,d,3);
    }else if(d[10] == batu[0]){
        root = 7;
        changeo(b,c,d,3);
    }
    mass(a, b, c, d);
    getchar();
    printf("あなたのターンです\n\n");
    massNum(b, c, d);
    mass(a, b, c, d);
    getchar();
    printf("AIのターンです\n\n");
    switch(root){
        case 0:
            printf("開発中!!\nあなたはここから勝つことができるのか？\n\n");
            goto end;
            break;
        case 1:
            if(c[2] == batu[0])
                changeo(b,c,d,9);
            else{
                changeo(b,c,d,4);
                lose_flag = 1;
            }
            break;
        case 2:
            if(c[6] == batu[0])
                changeo(b,c,d,7);
            else{
                changeo(b,c,d,5);
                lose_flag = 1;
            }
            break;
        case 3:
            if(b[6] == batu[0])
                changeo(b,c,d,9);
            else{
                changeo(b,c,d,2);
                lose_flag = 1;
            }
            break;
        case 4:
            if(c[2] == batu[0])
                changeo(b,c,d,5);
            else{
                changeo(b,c,d,4);
                lose_flag = 1;
            }
            break;
        case 5:
            if(c[6] == batu[0])
                changeo(b,c,d,3);
            else{
                changeo(b,c,d,5);
                lose_flag = 1;
            }
            break;
        case 6:
            if(b[6] == batu[0])
                changeo(b,c,d,5);
            else{
                changeo(b,c,d,2);
                lose_flag = 1;
            }
            break;
        case 7:
            if(b[6] == batu[0])
                changeo(b,c,d,7);
            else{
                changeo(b,c,d,2);
                lose_flag = 1;
            }
            break;
        default:
            break;
    }
    mass(a, b, c, d);
    getchar();
    win_lose(lose_flag);
    if(lose_flag == 1)
        goto end;
    printf("あなたのターンです\n\n");
    massNum(b, c, d);
    mass(a,b,c,d);
    getchar();
    printf("AIのターンです\n\n");
    switch(root){
        case 0:
            printf("開発中!!\nあなたはここから勝つことができるのか？\n\n");
            goto end;
            break;
        case 1:
            if(c[6] == batu[0])
                changeo(b,c,d,8);
            else
                changeo(b,c,d,5);
            lose_flag = 1;
            break;
        case 2:
            if(c[2] == batu[0])
                changeo(b,c,d,8);
            else
                changeo(b,c,d,4);
            lose_flag = 1;
            break;
        case 3:
            if(b[6] == batu[0])
                changeo(b,c,d,6);
            else
                changeo(b,c,d,5);
            lose_flag = 1;
            break;
        case 4:
            if(b[10] == batu[0])
                changeo(b,c,d,9);
            else
                changeo(b,c,d,3);
            lose_flag = 1;
            break;
        case 5:
            if(b[6] == batu[0])
                changeo(b,c,d,6);
            else
                changeo(b,c,d,2);
            lose_flag = 1;
            break;
        case 6:
            if(d[2] == batu[0])
                changeo(b,c,d,9);
            else
                changeo(b,c,d,7);
            lose_flag = 1;
            break;
        case 7:
            if(c[2] == batu[0])
                changeo(b,c,d,5);
            else
                changeo(b,c,d,4);
            lose_flag = 1;
            break;
        default:
            break;
    }
    mass(a, b, c, d);
    getchar();
    win_lose(lose_flag);

end:
    return;
}

//勝敗判定
void win_lose(int x){
    if(x == 1){
        printf("あなたの負けです\n\n");
    }
    return;
}

//作成者: 川﨑裕貴
//作成日: 2018/4/3
//内　容: oxGAME(ver.4)

#include<stdio.h>

void mass(char a[], char b[], char c[], char d[]);
void mass_num();
int massNum_bool(char b[], char c[], char d[], int x);
void changeo(char b[], char c[], char d[], int x);
void changex(char b[], char c[], char d[], int x);
void battle_mode_select(char a[], char b[], char c[], char d[]);
//新規関数
void mass_o(char b[], char c[], char d[]);
void mass_x(char b[], char c[], char d[]);
void battle_mode_Friend(char a[], char b[], char c[], char d[]);
void o_ture(char a[], char b[], char c[], char d[]);
void x_ture(char a[], char b[], char c[], char d[]);
int win_lose(char b[], char c[], char d[]);


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

//マス番号の入力と置き換えの実施(先攻)
void mass_o(char b[], char c[], char d[]){
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
            printf("マス番号%dに\"o\"をおきます\n\n",x);
            changeo(b, c, d, x);
            y = 0;
            break;
        }
        else{
            printf("このマス番号は無効です\n\n");
        }
    }
    return;
}

//マス番号の入力と置き換えの実施(後攻)
void mass_x(char b[], char c[], char d[]){
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
            return 2;
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
            return;
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
            return;
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
                printf("未実装です\n\n");
                break;
            case 2:
                printf("友人との対戦を始めます\n\n");
                battle_mode_Friend(a,b,c,d);
                break;
            default:
                return;
        }
    return;
}

//友人との対戦
void battle_mode_Friend(char a[], char b[], char c[], char d[]){
    int i;
    int end = 0;
    mass(a,b,c,d);
    for(i = 1; i <= 9; i++){
        if(i%2!=0){
            o_ture(a,b,c,d);
        }else{
            x_ture(a,b,c,d);
        }
        end = win_lose(b,c,d);
        if(end == 1)
            i = 10;
    }
    if(i == 9)
        printf("引き分けです。\n\n");
    return;
}

//先攻のターン
void o_ture(char a[], char b[], char c[], char d[]){
    printf("先攻のターンです\n\n");
    mass_o(b, c, d);
    mass(a, b, c, d);
    return;
}

//後攻のターン
void x_ture(char a[], char b[], char c[], char d[]){
    printf("後攻のターンです\n\n");
    mass_x(b, c, d);
    mass(a, b, c, d);
    return;
}

//勝敗判定
int win_lose(char b[], char c[], char d[]){
    char maru[2] = "o";
    char batu[2] = "x";
    if(b[2] == b[6] && b[2] == b[10]){
        if(maru[0] == b[2]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == b[2]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(c[2] == c[6] && c[2] == c[10]){
        if(maru[0] == c[2]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == c[2]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(d[2] == d[6] && d[2] == d[10]){
        if(maru[0] == d[2]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == d[2]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(b[2] == c[2] && b[2] == d[2]){
        if(maru[0] == b[2]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == b[2]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(b[6] == c[6] && b[6] == d[6]){
        if(maru[0] == b[6]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == b[6]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(b[10] == c[10] && b[10] == d[10]){
        if(maru[0] == b[10]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == b[10]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(b[2] == c[6] && b[2] == d[10]){
        if(maru[0] == b[2]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == b[2]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(b[10] == c[6] && b[10] == d[2]){
        if(maru[0] == b[10]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == b[10]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    return 0;
}

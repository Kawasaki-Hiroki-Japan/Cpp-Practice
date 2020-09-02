//作成者: 川﨑裕貴
//作成日: 2018/6/1
//内　容: oxGAME(ver.6)
//更　新: 戦歴の保存機能追加
//       その他、細かい修正

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//盤面表示関数
void mass(char a[], char b[], char c[]); //現在の盤面
void mass_num(); //マス番号確認用

//マス番号チェック関数
int massNum(char a[], char b[], char c[]); //AI戦
void mass_o(char a[], char b[], char c[]); //フレンド戦(先攻)
void mass_x(char a[], char b[], char c[]); //フレンド戦(後攻)
int massNum_bool(char a[], char b[], char c[], int x); //有効性の確認

//盤面置換関数
void changeo(char a[], char b[], char c[], int x); //先攻
void changex(char a[], char b[], char c[], int x); //後攻

//選択画面表示関数
void battle_mode_select(char a[], char b[], char c[]); //モード選択

//AI戦関数
void battle_modeAI(char a[], char b[], char c[]);
void root1(char a[], char b[], char c[]);
void root2(char a[], char b[], char c[]);
void root3(char a[], char b[], char c[]);
void root4(char a[], char b[], char c[]);
void root5(char a[], char b[], char c[]);
void root6(char a[], char b[], char c[]);
void root7(char a[], char b[], char c[]);
int root8(char a[], char b[], char c[]);
int your_ture(char a[], char b[], char c[]);

//フレンド戦関数
void battle_mode_Friend(char a[], char b[], char c[]);
void o_ture(char a[], char b[], char c[]);
void x_ture(char a[], char b[], char c[]);
int win_lose(char a[], char b[], char c[]);

//戦歴保存関数(NEW)
void txt_save(char a[], char b[], char c[]);
void assignment_fname(void);

//グローバル関数
char mass_line[15] = "+---+---+---+\n";
char mass_enpty[15] = "|   |   |   |\n";
int turn_num; //ターン数の記録変数(NEW)
int select_mode; //対戦モード記録変数
char fname[30]; //ファイル名変数

//メイン関数
int main(void){
    char mass_A[15], mass_B[15], mass_C[15];
    int i, x;
    while(1){
        for(i = 0; i<14; i++){
            mass_A[i] = mass_enpty[i];
            mass_B[i] = mass_enpty[i];
            mass_C[i] = mass_enpty[i];
        }
        battle_mode_select(mass_A, mass_B, mass_C);
        do{
            printf("continue?\n\n");
            printf("**********************\n");
            printf("* 1: YES             *\n");
            printf("* 2: NO              *\n");
            printf("**********************\n\n");
            scanf("%d", &x);
            printf("\n");
            if(x == 2){
                printf("Thank You!\n\n");
                return 0;
            }
        }while(x != 1);
    }
    return 0;
}

//現在のマスを表示する関数
void mass(char a[], char b[], char c[]){
    int i, j;
    for(i = 1; i < 8; i++){
        if(i == 2){
            for(j = 0; j < 14; j++)
                printf("%c",a[j]);
        }else if(i == 4){
            for(j = 0; j < 14; j++)
                printf("%c",b[j]);
        }else if(i == 6){
            for(j = 0; j < 14; j++)
                printf("%c",c[j]);
        }else{
            for(j = 0; j < 14; j++)
                printf("%c",mass_line[j]);
        }
    }
     printf("\n");
     txt_save(a, b, c);
    return;
}

//マス番号を確認する関数
void mass_num(){
    int i, j;
    char a[15]= "| 1 | 2 | 3 |\n";
    char b[15]= "| 4 | 5 | 6 |\n";
    char c[15]= "| 7 | 8 | 9 |\n";
    for(i = 1; i < 8; i++){
        if(i == 2){
            for(j = 0; j < 14; j++)
                printf("%c",a[j]);
        }else if(i == 4){
            for(j = 0; j < 14; j++)
                printf("%c",b[j]);
        }else if(i == 6){
            for(j = 0; j < 14; j++)
                printf("%c",c[j]);
        }else{
            for(j = 0; j < 14; j++)
                printf("%c",mass_line[j]);
        }
    }
    return;
}

//マス番号の入力と置き換えの実施(AI戦)
int massNum(char a[], char b[], char c[]){
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
        y = massNum_bool(a, b, c, x);
        if(y == 1){
            printf("このマス番号は有効です\n");
            printf("マス番号%dに\"x\"をおきます\n\n",x);
            changex(a, b, c, x);
            y = 0;
            break;
        }
        else{
            printf("このマス番号は無効です\n\n");
        }
    }
    return x;
}

//マス番号の入力と置き換えの実施(先攻)
void mass_o(char a[], char b[], char c[]){
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
        y = massNum_bool(a, b, c, x);
        if(y == 1){
            printf("このマス番号は有効です\n");
            printf("マス番号%dに\"o\"をおきます\n\n",x);
            changeo(a, b, c, x);
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
void mass_x(char a[], char b[], char c[]){
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
        y = massNum_bool(a, b, c, x);
        if(y == 1){
            printf("このマス番号は有効です\n");
            printf("マス番号%dに\"x\"をおきます\n\n",x);
            changex(a, b, c, x);
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
int massNum_bool(char a[], char b[], char c[], int x){
    char space[2] = " ";
    switch(x){
        case 1:
            if(a[2] == space[0])
                return 1;
            break;
        case 2:
            if(a[6] == space[0])
                return 1;
            break;
        case 3:
            if(a[10] == space[0])
                return 1;
            break;
        case 4:
            if(b[2] == space[0])
                return 1;
            break;
        case 5:
            if(b[6] == space[0])
                return 1;
            break;
        case 6:
            if(b[10] == space[0])
                return 1;
            break;
        case 7:
            if(c[2] == space[0])
                return 1;
            break;
        case 8:
            if(c[6] == space[0])
                return 1;
            break;
        case 9:
            if(c[10] == space[0])
                return 1;
            break;
        default:
            return 2;
    }
    return 0;
}

//マスの書き換えo
void changeo(char a[], char b[], char c[], int x){
    char maru[2] = "o";
    switch(x){
        case 1:
            a[2] = maru[0];
            break;
        case 2:
            a[6] = maru[0];
            break;
        case 3:
            a[10] = maru[0];
            break;
        case 4:
            b[2] = maru[0];
            break;
        case 5:
            b[6] = maru[0];
            break;
        case 6:
            b[10] = maru[0];
            break;
        case 7:
            c[2] = maru[0];
            break;
        case 8:
            c[6] = maru[0];
            break;
        case 9:
            c[10] = maru[0];
            break;
        default:
            return;
    }
    return;
}

//マスの書き換えx
void changex(char a[], char b[], char c[], int x){
    char batu[2] = "x";
    switch(x){
        case 1:
            a[2] = batu[0];
            break;
        case 2:
            a[6] = batu[0];
            break;
        case 3:
            a[10] = batu[0];
            break;
        case 4:
            b[2] = batu[0];
            break;
        case 5:
            b[6] = batu[0];
            break;
        case 6:
            b[10] = batu[0];
            break;
        case 7:
            c[2] = batu[0];
            break;
        case 8:
            c[6] = batu[0];
            break;
        case 9:
            c[10] = batu[0];
            break;
        default:
            return;
    }
    return;
}

//対戦モードの選択
void battle_mode_select(char a[], char b[], char c[]){
    turn_num = 0;
    do{
        printf("対戦モードの選択をして下さい\n\n");
        printf("**********************\n");
        printf("* 1: AIと対戦（最強）*\n");
        printf("* 2: 友人と対戦      *\n");
        printf("**********************\n\n");
        scanf("%d", &select_mode);
        printf("\n");
    }while(select_mode != 1 && select_mode != 2);
        switch (select_mode) {
            case 1:
                printf("AIとの対戦を開始します。\n\n");
                assignment_fname();
                battle_modeAI(a, b, c);
                break;
            case 2:
                printf("友人との対戦を始めます\n\n");
                assignment_fname();
                battle_mode_Friend(a,b,c);
                break;
            default:
                return;
        }
    return;
}

//対戦モードAI
void battle_modeAI(char a[], char b[], char c[]){
    int lose_flag = 1;
    int x = 0;
    printf("あなたは後攻です\n\n");
    mass(a, b, c);
    getchar();
    printf("AIのターンです\n\n");
    changeo(a, b, c, 1);
    mass(a, b, c);
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    switch(x){
        case 2:
            root1(a, b, c);
            break;
        case 3:
            root2(a, b, c);
            break;
        case 4:
            root3(a, b, c);
            break;
        case 5:
            lose_flag = root8(a, b, c);
            break;
        case 6:
            root4(a, b, c);
            break;
        case 7:
            root5(a, b, c);
            break;
        case 8:
            root6(a, b, c);
            break;
        case 9:
            root7(a, b, c);
            break;
        default:
            return;
    }
    if(lose_flag == 1){
        printf("あなたの負けです\n\n");
    }else{
        printf("引き分けです\n\n");
    }
    return;
}

//ルート1
void root1(char a[], char b[], char c[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(a, b, c, 7);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x != 4){
        changeo(a, b, c, 4);
        mass(a, b, c);
        return;
    }
    changeo(a, b, c, 9);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x == 5){
        changeo(a, b, c, 8);
        mass(a, b, c);
        getchar();
    }else{
        changeo(a, b, c, 5);
        mass(a, b, c);
        getchar();
    }
    return;
}

//ルート2
void root2(char a[], char b[], char c[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(a, b, c, 9);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x != 5){
        changeo(a, b, c, 5);
        mass(a, b, c);
        return;
    }
    changeo(a, b, c, 7);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x == 4){
        changeo(a, b, c, 8);
        mass(a, b, c);
        getchar();
    }else{
        changeo(a, b, c, 4);
        mass(a, b, c);
        getchar();
    }
    return;
}

//ルート3
void root3(char a[], char b[], char c[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(a, b, c, 3);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x != 2){
        changeo(a, b, c, 2);
        mass(a, b, c);
        return;
    }
    changeo(a, b, c, 9);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x == 5){
        changeo(a, b, c, 6);
        mass(a, b, c);
        getchar();
    }else{
        changeo(a, b, c, 5);
        mass(a, b, c);
        getchar();
    }
    return;
}

//ルート4
void root4(char a[], char b[], char c[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(a, b, c, 3);
    mass(a, b, c);
    getchar();
    x = your_ture(a,b,c);
    printf("AIのターンです\n\n");
    if(x != 2){
        changeo(a, b, c, 2);
        mass(a, b, c);
        return;
    }
    changeo(a, b, c, 7);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x == 4){
        changeo(a, b, c, 5);
        mass(a, b, c);
        getchar();
    }else{
        changeo(a, b, c, 4);
        mass(a, b, c);
        getchar();
    }
    return;
}

//ルート5
void root5(char a[], char b[], char c[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(a, b, c, 9);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x != 5){
        changeo(a, b, c, 5);
        mass(a, b, c);
        return;
    }
    changeo(a, b, c, 3);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x == 2){
        changeo(a, b, c, 6);
        mass(a, b, c);
        getchar();
    }else{
        changeo(a, b, c, 2);
        mass(a, b, c);
        getchar();
    }
    return;
}

//ルート6
void root6(char a[], char b[], char c[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(a, b, c, 7);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x != 4){
        changeo(a, b, c, 4);
        mass(a, b, c);
        return;
    }
    changeo(a, b, c, 3);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x == 2){
        changeo(a, b, c, 5);
        mass(a, b, c);
        getchar();
    }else{
        changeo(a, b, c, 2);
        mass(a, b, c);
        getchar();
    }
    return;
}

//ルート7
void root7(char a[], char b[], char c[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(a, b, c, 3);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x != 2){
        changeo(a, b, c, 2);
        mass(a, b, c);
        return;
    }
    changeo(a, b, c, 7);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    if(x == 4){
        changeo(a, b, c, 5);
        mass(a, b, c);
        getchar();
    }else{
        changeo(a, b, c, 4);
        mass(a, b, c);
        getchar();
    }
    return;
}

//ルート8
int root8(char a[], char b[], char c[]){
    int x;
    changeo(a, b, c, 9);
    mass(a, b, c);
    getchar();
    x = your_ture(a, b, c);
    printf("AIのターンです\n\n");
    switch(x){
        case 3:
            changeo(a, b, c, 7);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x == 4){
                changeo(a, b, c, 8);
                mass(a, b, c);
                getchar();
            }else{
                changeo(a, b, c, 4);
                mass(a, b, c);
                getchar();
            }
            return 1;
        case 7:
            changeo(a, b, c, 3);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x == 2){
                changeo(a, b, c, 6);
                mass(a, b, c);
                getchar();
            }else{
                changeo(a, b, c, 2);
                mass(a, b, c);
                getchar();
            }
            return 1;
            default:
                break;
    }
    switch(x){
        case 2:
            changeo(a, b, c, 8);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x != 7){
                changeo(a, b, c, 7);
                mass(a, b, c);
                return 1;
            }
            changeo(a, b, c, 3);
            mass(a,b,c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x != 6){
                changeo(a, b, c, 6);
                mass(a,b,c);
                return 1;
            }
            changeo(a, b, c, 4);
            mass(a, b, c);
            getchar();
            return 0;
        case 4:
            changeo(a, b, c, 6);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x != 3){
                changeo(a, b, c, 3);
                mass(a, b, c);
                return 1;
            }
            changeo(a, b, c, 7);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x != 8){
                changeo(a, b, c, 8);
                mass(a, b, c);
                return 1;
            }
            changeo(a, b, c, 2);
            mass(a, b, c);
            getchar();
            return 0;
        case 6:
            changeo(a, b, c, 4);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x != 7){
                changeo(a, b, c, 7);
                mass(a, b, c);
                return 1;
            }
            changeo(a, b, c, 3);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x != 2){
                changeo(a, b, c, 2);
                mass(a, b, c);
                return 1;
            }
            changeo(a, b, c, 8);
            mass(a, b, c);
            getchar();
            return 0;
        case 8:
            changeo(a, b, c, 2);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x != 3){
                changeo(a, b, c, 3);
                mass(a, b, c);
                return 1;
            }
            changeo(a, b, c, 7);
            mass(a, b, c);
            getchar();
            x = your_ture(a, b, c);
            printf("AIのターンです\n\n");
            if(x != 4){
                changeo(a, b, c, 4);
                mass(a, b, c);
                return 1;
            }
            changeo(a, b, c, 6);
            mass(a, b, c);
            getchar();
            return 0;
        default:
            return 1;
    }
    return 1;
}

//あなたのターン
int your_ture(char a[], char b[], char c[]){
    int x;
    printf("あなたのターンです\n\n");
    x = massNum(a, b, c);
    mass(a, b, c);
    return x;
}

//友人との対戦
void battle_mode_Friend(char a[], char b[], char c[]){
    int i;
    int end = 0;
    mass(a, b, c);
    for(i = 1; i <= 9; i++){
        if(i%2!=0){
            o_ture(a, b, c);
        }else{
            x_ture(a, b, c);
        }
        end = win_lose(a, b, c);
        if(end == 1)
            return;
    }
    printf("引き分けです。\n\n");
    return;
}

//先攻のターン
void o_ture(char a[], char b[], char c[]){
    printf("先攻のターンです\n\n");
    mass_o(a, b, c);
    mass(a, b, c);
    return;
}

//後攻のターン
void x_ture(char a[], char b[], char c[]){
    printf("後攻のターンです\n\n");
    mass_x(a, b, c);
    mass(a, b, c);
    return;
}

//勝敗判定
int win_lose(char a[], char b[], char c[]){
    char maru[2] = "o";
    char batu[2] = "x";
    if(a[2] == a[6] && a[2] == a[10]){
        if(maru[0] == a[2]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == a[2]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
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
    if(a[2] == b[2] && a[2] == c[2]){
        if(maru[0] == a[2]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == a[2]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(a[6] == b[6] && a[6] == c[6]){
        if(maru[0] == a[6]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == a[6]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(a[10] == b[10] && a[10] == c[10]){
        if(maru[0] == a[10]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == a[10]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(a[2] == b[6] && a[2] == c[10]){
        if(maru[0] == a[2]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == a[2]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    if(a[10] == b[6] && a[10] == c[2]){
        if(maru[0] == a[10]){
            printf("先攻の勝ちです。\n\n");
            return 1;
        }else if(batu[0] == a[10]){
            printf("後攻の勝ちです。\n\n");
            return 1;
        }
    }
    return 0;
}

//txt形式のファイルに書き込み
void txt_save(char a[], char b[], char c[]){
    FILE *fp;

    fp = fopen(fname, "a");
    if(fp == NULL){
      printf("ファイル処理ができませんでした\n\n");
      exit(1);
    }
    if(turn_num == 0)
      fprintf(fp, "GAME STRAT!!\n\n");
    else{
      if((select_mode == 1) && (turn_num % 2 == 1))
        fprintf(fp, "%dターン目(AI)\n", turn_num);
      else if(select_mode == 1)
        fprintf(fp, "%dターン目(YOU)\n", turn_num);
      else if((select_mode == 2) && (turn_num % 2 == 1))
        fprintf(fp, "%dターン目(先攻)\n", turn_num);
      else
        fprintf(fp, "%dターン目(後攻)\n", turn_num);
      fprintf(fp, "%s", mass_line);
      fprintf(fp, "%s", a);
      fprintf(fp, "%s", mass_line);
      fprintf(fp, "%s", b);
      fprintf(fp, "%s", mass_line);
      fprintf(fp, "%s", c);
      fprintf(fp, "%s\n", mass_line);
    }
    turn_num += 1;
    fclose(fp);
}

void assignment_fname(void){
    FILE *fp;
    int fname_num;

    fp = fopen("fname.txt", "r");
    if(fp == NULL){
      printf("ファイル処理ができませんでした\n\n");
      exit(1);
    }
    fscanf(fp, "%d\n", &fname_num);
    fscanf(fp, "%s\n", fname);
    fclose(fp);

    fname_num += 1;

    fp = fopen("fname.txt", "w");
    if(fp == NULL){
      printf("ファイル処理ができませんでした\n\n");
      exit(1);
    }
    fprintf(fp, "%d\n", fname_num);
    fprintf(fp, "oxGAME-Result/oxGAME-Result-%d.txt\n", fname_num);
    fclose(fp);
}

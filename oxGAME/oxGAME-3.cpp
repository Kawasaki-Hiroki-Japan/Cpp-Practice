//作成者: 川﨑裕貴
//作成日: 2018/4/3
//内　容: oxGAME(ver.3)

#include<stdio.h>

void mass(char a[], char b[], char c[], char d[]);
void mass_num();
int massNum(char b[], char c[], char d[]);
int massNum_bool(char b[], char c[], char d[], int x);
void changeo(char b[], char c[], char d[], int x);
void changex(char b[], char c[], char d[], int x);
void battle_mode_select(char a[], char b[], char c[], char d[]);
void battle_modeAI(char a[], char b[], char c[], char d[]);
void root1(char a[], char b[], char c[], char d[]);
void root2(char a[], char b[], char c[], char d[]);
void root3(char a[], char b[], char c[], char d[]);
void root4(char a[], char b[], char c[], char d[]);
void root5(char a[], char b[], char c[], char d[]);
void root6(char a[], char b[], char c[], char d[]);
void root7(char a[], char b[], char c[], char d[]);
int root8(char a[], char b[], char c[], char d[]);
int your_ture(char a[], char b[], char c[], char d[]);

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
int massNum(char b[], char c[], char d[]){
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
    return x;
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
                printf("AIとの対戦を開始します。\n\n");
                battle_modeAI(a, b, c, d);
                break;
            case 2:
                printf("未実装です\n\n");
                break;
            default:
                return;
        }
    return;
}

//対戦モードAI
void battle_modeAI(char a[], char b[], char c[], char d[]){
    int lose_flag = 1;
    int x = 0;
    printf("あなたは後攻です\n\n");
    mass(a, b, c, d);
    getchar();
    printf("AIのターンです\n\n");
    changeo(b,c,d,1);
    mass(a, b, c, d);
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    switch(x){
        case 2:
            root1(a,b,c,d);
            break;
        case 3:
            root2(a,b,c,d);
            break;
        case 4:
            root3(a,b,c,d);
            break;
        case 5:
            lose_flag = root8(a,b,c,d);
            break;
        case 6:
            root4(a,b,c,d);
            break;
        case 7:
            root5(a,b,c,d);
            break;
        case 8:
            root6(a,b,c,d);
            break;
        case 9:
            root7(a,b,c,d);
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
void root1(char a[], char b[], char c[], char d[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(b,c,d,7);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x != 4){
        changeo(b,c,d,4);
        mass(a, b, c, d);
        return;
    }
    changeo(b,c,d,9);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x == 5){
        changeo(b,c,d,8);
        mass(a, b, c, d);
        getchar();
    }else{
        changeo(b,c,d,5);
        mass(a, b, c, d);
        getchar();
    }
    return;
}

//ルート2
void root2(char a[], char b[], char c[], char d[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(b,c,d,9);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x != 5){
        changeo(b,c,d,5);
        mass(a, b, c, d);
        return;
    }
    changeo(b,c,d,7);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x == 4){
        changeo(b,c,d,8);
        mass(a, b, c, d);
        getchar();
    }else{
        changeo(b,c,d,4);
        mass(a, b, c, d);
        getchar();
    }
    return;
}

//ルート3
void root3(char a[], char b[], char c[], char d[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(b,c,d,3);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x != 2){
        changeo(b,c,d,2);
        mass(a, b, c, d);
        return;
    }
    changeo(b,c,d,9);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x == 5){
        changeo(b,c,d,6);
        mass(a, b, c, d);
        getchar();
    }else{
        changeo(b,c,d,5);
        mass(a, b, c, d);
        getchar();
    }
    return;
}

//ルート4
void root4(char a[], char b[], char c[], char d[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(b,c,d,3);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x != 2){
        changeo(b,c,d,2);
        mass(a, b, c, d);
        return;
    }
    changeo(b,c,d,7);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x == 4){
        changeo(b,c,d,5);
        mass(a, b, c, d);
        getchar();
    }else{
        changeo(b,c,d,4);
        mass(a, b, c, d);
        getchar();
    }
    return;
}

//ルート5
void root5(char a[], char b[], char c[], char d[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(b,c,d,9);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x != 5){
        changeo(b,c,d,5);
        mass(a, b, c, d);
        return;
    }
    changeo(b,c,d,3);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x == 2){
        changeo(b,c,d,6);
        mass(a, b, c, d);
        getchar();
    }else{
        changeo(b,c,d,2);
        mass(a, b, c, d);
        getchar();
    }
    return;
}

//ルート6
void root6(char a[], char b[], char c[], char d[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(b,c,d,7);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x != 4){
        changeo(b,c,d,4);
        mass(a, b, c, d);
        return;
    }
    changeo(b,c,d,3);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x == 2){
        changeo(b,c,d,5);
        mass(a, b, c, d);
        getchar();
    }else{
        changeo(b,c,d,2);
        mass(a, b, c, d);
        getchar();
    }
    return;
}

//ルート7
void root7(char a[], char b[], char c[], char d[]){
    int x;
    printf("AIのターンです\n\n");
    changeo(b,c,d,3);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x != 2){
        changeo(b,c,d,2);
        mass(a, b, c, d);
        return;
    }
    changeo(b,c,d,7);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    if(x == 4){
        changeo(b,c,d,5);
        mass(a, b, c, d);
        getchar();
    }else{
        changeo(b,c,d,4);
        mass(a, b, c, d);
        getchar();
    }
    return;
}

//ルート8
int root8(char a[], char b[], char c[], char d[]){
    int x;
    changeo(b,c,d,9);
    mass(a, b, c, d);
    getchar();
    x = your_ture(a,b,c,d);
    printf("AIのターンです\n\n");
    switch(x){
        case 3:
            changeo(b,c,d,7);
            mass(a, b, c, d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x == 4){
                changeo(b,c,d,8);
                mass(a, b, c, d);
                getchar();
            }else{
                changeo(b,c,d,4);
                mass(a, b, c, d);
                getchar();
            }
            return 1;
        case 7:
            changeo(b,c,d,3);
            mass(a, b, c, d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x == 2){
                changeo(b,c,d,6);
                mass(a, b, c, d);
                getchar();
            }else{
                changeo(b,c,d,2);
                mass(a, b, c, d);
                getchar();
            }
            return 1;
            default:
                break;
    }
    switch(x){
        case 2:
            changeo(b,c,d,8);
            mass(a,b,c,d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x != 7){
                changeo(b,c,d,7);
                mass(a,b,c,d);
                return 1;
            }
            changeo(b,c,d,3);
            mass(a,b,c,d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x != 6){
                changeo(b,c,d,6);
                mass(a,b,c,d);
                return 1;
            }
            changeo(b,c,d,4);
            mass(a,b,c,d);
            getchar();
            return 0;
        case 4:
            changeo(b,c,d,6);
            mass(a, b, c, d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x != 3){
                changeo(b,c,d,3);
                mass(a,b,c,d);
                return 1;
            }
            changeo(b,c,d,7);
            mass(a,b,c,d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x != 8){
                changeo(b,c,d,8);
                mass(a,b,c,d);
                return 1;
            }
            changeo(b,c,d,2);
            mass(a,b,c,d);
            getchar();
            return 0;
        case 6:
            changeo(b,c,d,4);
            mass(a, b, c, d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x != 7){
                changeo(b,c,d,7);
                mass(a,b,c,d);
                return 1;
            }
            changeo(b,c,d,3);
            mass(a,b,c,d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x != 2){
                changeo(b,c,d,2);
                mass(a,b,c,d);
                return 1;
            }
            changeo(b,c,d,8);
            mass(a,b,c,d);
            getchar();
            return 0;
        case 8:
            changeo(b,c,d,2);
            mass(a, b, c, d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x != 3){
                changeo(b,c,d,3);
                mass(a,b,c,d);
                return 1;
            }
            changeo(b,c,d,7);
            mass(a,b,c,d);
            getchar();
            x = your_ture(a,b,c,d);
            printf("AIのターンです\n\n");
            if(x != 4){
                changeo(b,c,d,4);
                mass(a,b,c,d);
                return 1;
            }
            changeo(b,c,d,6);
            mass(a,b,c,d);
            getchar();
            return 0;
        default:
            return 1;
    }
    return 1;
}

//あなたのターン
int your_ture(char a[], char b[], char c[], char d[]){
    int x;
    printf("あなたのターンです\n\n");
    x = massNum(b, c, d);
    mass(a, b, c, d);
    return x;
}

//作成者: 川﨑裕貴
//作成日: 2018/6/15
//内　容: oxGAME(ver.8) ディープランニング用


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct oxGAME_data{
    int turn_num; //経過ターン数
    char mass_A[15]; //マス1列目
    char mass_B[15]; //マス2列目
    char mass_C[15]; //マス3列目
};


void mass_Out(struct oxGAME_data data);
int rand_up(struct oxGAME_data data);
int reach_Get(struct oxGAME_data data, char symbol);
int reach_Cut(struct oxGAME_data data, char symbol);
struct oxGAME_data mass_Change(struct oxGAME_data data, int num, char symbol);
int winORlose(struct oxGAME_data data, char symbol);


int main(void){
    struct oxGAME_data data;
    char mass_enpty[15] = "|   |   |   |\n";
    char mass_line[15]  = "+---+---+---+\n";
    char symbol;
    int n, i, j, num, judge;
    int win_o = 0, win_x = 0, draw = 0;
    int win_turn[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("\n**************************************\n");
    printf("*   ディープランニング用ソフトです   *\n");
    printf("*     学習回数を入力してください     *\n");
    printf("**************************************\n\n");
    printf("学習回数：");
    scanf("%d", &n);
    printf("\n%d回学習を行います\n\n", n);

    for(j = 0; j < n; j++){
        data.turn_num = 1;
        judge = 0;
        for(i = 0; i < 15; i++){
            data.mass_A[i] = mass_enpty[i];
            data.mass_B[i] = mass_enpty[i];
            data.mass_C[i] = mass_enpty[i];
        }
        //mass_Out(data);
        do{
            num = 0;
            if(data.turn_num % 2 == 1)    symbol = 'o';
            else                          symbol = 'x';

            num = reach_Get(data, symbol);
            if(num == 10)   num = reach_Cut(data, symbol);
            if(num == 10)   num = rand_up(data);

            data = mass_Change(data, num, symbol);
            //mass_Out(data);
            judge = winORlose(data, symbol);
            data.turn_num += 1;
        }while(judge != 1 && data.turn_num <= 9);
        if(judge != 1){
            //printf("draw\n");
            draw++;
        }else{
            //printf("winner %c\n", symbol);
            if(symbol == 'o')   win_o++;
            else               win_x++;
        }
        win_turn[data.turn_num - 2]++;
    }

    printf("\n先攻:　%d勝 %d敗 %d分\n", win_o, win_x, draw);
    printf("後攻:　%d勝 %d敗 %d分\n", win_x, win_o, draw);
    for(i = 5; i <= 9; i++)    printf("%dターン目: %8d\n", i, win_turn[i]);
    printf("\n");

    return 0;
}

//現在のマスの表示
void mass_Out(struct oxGAME_data data){
    int i;
    char mass_line[15] = "+---+---+---+\n";
    for(i = 0; i < 7; i++){
        if(i == 1)        printf("%s", data.mass_A);
        else if(i == 3)   printf("%s", data.mass_B);
        else if(i == 5)   printf("%s", data.mass_C);
        else              printf("%s", mass_line);
    }
    printf("\n");
    return;
}

//ランダムにマスを置く
int rand_up(struct oxGAME_data data){
    int x;
    srand((unsigned)time(NULL));
    do{
        srand(rand());
        x = rand()%9+1;
        switch(x){
            case 1:
                if(data.mass_A[2] != ' ')     x = 0;    break;
            case 2:
                if(data.mass_A[6] != ' ')     x = 0;    break;
            case 3:
                if(data.mass_A[10] != ' ')    x = 0;    break;
            case 4:
                if(data.mass_B[2] != ' ')     x = 0;    break;
            case 5:
                if(data.mass_B[6] != ' ')     x = 0;    break;
            case 6:
                if(data.mass_B[10] != ' ')    x = 0;    break;
            case 7:
                if(data.mass_C[2] != ' ')     x = 0;    break;
            case 8:
                if(data.mass_C[6] != ' ')     x = 0;    break;
            case 9:
                if(data.mass_C[10] != ' ')    x = 0;    break;
            default:
                exit(1);
        }
    }while(x == 0);
    return x;
}

//自リーチをとる
int reach_Get(struct oxGAME_data data, char symbol){
    unsigned long int k = 1;
    int x;

    if(data.mass_A[2] == symbol)   k *= 8;
    if(data.mass_A[6] == symbol)   k *= 9;
    if(data.mass_A[10] == symbol)  k *= 125;
    if(data.mass_B[2] == symbol)   k *= 49;
    if(data.mass_B[6] == symbol)   k *= 121;
    if(data.mass_B[10] == symbol)  k *= 169;
    if(data.mass_C[2] == symbol)   k *= 289;
    if(data.mass_C[6] == symbol)   k *= 361;
    if(data.mass_C[10] == symbol)  k *= 529;

    do{
        if(k % 15 == 0){
            k /= 15;
            x = 1;
        }else if(k % 139 == 0){
            k /= 139;
            x = 1;
        }else if(k % 253 == 0){
            k /= 253;
            x = 1;
        }else if(k % 10 == 0){
            k /= 10;
            x = 2;
        }else if(k % 209 == 0){
            k /= 209;
            x = 2;
        }else if(k % 6 == 0){
            k /= 6;
            x = 3;
        }else if(k % 187 == 0){
            k /= 187;
            x = 3;
        }else if(k % 299 == 0){
            k /= 299;
            x = 3;
        }else if(k % 34 == 0){
            k /= 34;
            x = 4;
        }else if(k % 143 == 0){
            k /= 143;
            x = 4;
        }else if(k % 46 == 0){
            k /= 46;
            x = 5;
        }else if(k % 57 == 0){
            k /= 57;
            x = 5;
        }else if(k % 85 == 0){
            k /= 85;
            x = 5;
        }else if(k % 91 == 0){
            k /= 91;
            x = 5;
        }else if(k % 77 == 0){
            k /= 77;
            x = 6;
        }else if(k % 115 == 0){
            k /= 115;
            x = 6;
        }else if(k % 14 == 0){
            k /= 14;
            x = 7;
        }else if(k % 55 == 0){
            k /= 55;
            x = 7;
        }else if(k % 437 == 0){
            k /= 437;
            x = 7;
        }else if(k % 33 == 0){
            k /= 33;
            x = 8;
        }else if(k % 391 == 0){
            k /= 391;
            x = 8;
        }else if(k % 22 == 0){
            k /= 22;
            x = 9;
        }else if(k % 65 == 0){
            k /= 65;
            x = 9;
        }else if(k % 323 == 0){
            k /= 323;
            x = 9;
        }else{
            x = 10;
        }

        switch(x){
            case 1:
                if(data.mass_A[2] != ' ')   x = 0;  break;
            case 2:
                if(data.mass_A[6] != ' ')   x = 0;  break;
            case 3:
                if(data.mass_A[10] != ' ')  x = 0;  break;
            case 4:
                if(data.mass_B[2] != ' ')   x = 0;  break;
            case 5:
                if(data.mass_B[6] != ' ')   x = 0;  break;
            case 6:
                if(data.mass_B[10] != ' ')  x = 0;  break;
            case 7:
                if(data.mass_C[2] != ' ')   x = 0;  break;
            case 8:
                if(data.mass_C[6] != ' ')   x = 0;  break;
            case 9:
                if(data.mass_C[10] != ' ')  x = 0;  break;
            default:
                break;
        }
    }while(x == 0);

    return x;
}

//敵リーチを妨げる
int reach_Cut(struct oxGAME_data data, char symbol){
    unsigned long int k = 1;
    int x;

    if(symbol == 'o')  symbol = 'x';
    else               symbol = 'o';

    if(data.mass_A[2] == symbol)   k *= 8;
    if(data.mass_A[6] == symbol)   k *= 9;
    if(data.mass_A[10] == symbol)  k *= 125;
    if(data.mass_B[2] == symbol)   k *= 49;
    if(data.mass_B[6] == symbol)   k *= 121;
    if(data.mass_B[10] == symbol)  k *= 169;
    if(data.mass_C[2] == symbol)   k *= 289;
    if(data.mass_C[6] == symbol)   k *= 361;
    if(data.mass_C[10] == symbol)  k *= 529;

    do{
        if(k % 15 == 0){
            k /= 15;
            x = 1;
        }else if(k % 139 == 0){
            k /= 139;
            x = 1;
        }else if(k % 253 == 0){
            k /= 253;
            x = 1;
        }else if(k % 10 == 0){
            k /= 10;
            x = 2;
        }else if(k % 209 == 0){
            k /= 209;
            x = 2;
        }else if(k % 6 == 0){
            k /= 6;
            x = 3;
        }else if(k % 187 == 0){
            k /= 187;
            x = 3;
        }else if(k % 299 == 0){
            k /= 299;
            x = 3;
        }else if(k % 34 == 0){
            k /= 34;
            x = 4;
        }else if(k % 143 == 0){
            k /= 143;
            x = 4;
        }else if(k % 46 == 0){
            k /= 46;
            x = 5;
        }else if(k % 57 == 0){
            k /= 57;
            x = 5;
        }else if(k % 85 == 0){
            k /= 85;
            x = 5;
        }else if(k % 91 == 0){
            k /= 91;
            x = 5;
        }else if(k % 77 == 0){
            k /= 77;
            x = 6;
        }else if(k % 115 == 0){
            k /= 115;
            x = 6;
        }else if(k % 14 == 0){
            k /= 14;
            x = 7;
        }else if(k % 55 == 0){
            k /= 55;
            x = 7;
        }else if(k % 437 == 0){
            k /= 437;
            x = 7;
        }else if(k % 33 == 0){
            k /= 33;
            x = 8;
        }else if(k % 391 == 0){
            k /= 391;
            x = 8;
        }else if(k % 22 == 0){
            k /= 22;
            x = 9;
        }else if(k % 65 == 0){
            k /= 65;
            x = 9;
        }else if(k % 323 == 0){
            k /= 323;
            x = 9;
        }else{
            x = 10;
        }

        switch(x){
            case 1:
                if(data.mass_A[2] != ' ')   x = 0;  break;
            case 2:
                if(data.mass_A[6] != ' ')   x = 0;  break;
            case 3:
                if(data.mass_A[10] != ' ')  x = 0;  break;
            case 4:
                if(data.mass_B[2] != ' ')   x = 0;  break;
            case 5:
                if(data.mass_B[6] != ' ')   x = 0;  break;
            case 6:
                if(data.mass_B[10] != ' ')  x = 0;  break;
            case 7:
                if(data.mass_C[2] != ' ')   x = 0;  break;
            case 8:
                if(data.mass_C[6] != ' ')   x = 0;  break;
            case 9:
                if(data.mass_C[10] != ' ')  x = 0;  break;
            default:
                break;
        }
    }while(x == 0);
    return x;
}

//マスの置き換え
struct oxGAME_data mass_Change(struct oxGAME_data data, int num, char symbol){
    switch(num){
        case 1:
            data.mass_A[2] = symbol;    break;
        case 2:
            data.mass_A[6] = symbol;    break;
        case 3:
            data.mass_A[10] = symbol;   break;
        case 4:
            data.mass_B[2] = symbol;    break;
        case 5:
            data.mass_B[6] = symbol;    break;
        case 6:
            data.mass_B[10] = symbol;   break;
        case 7:
            data.mass_C[2] = symbol;    break;
        case 8:
            data.mass_C[6] = symbol;    break;
        case 9:
            data.mass_C[10] = symbol;   break;
        default:
            exit(1);
    }
    return data;
}

//勝敗判定
int winORlose(struct oxGAME_data data, char symbol){
    int k = 1;

    if(data.mass_A[2] == symbol)  k *= 2;
    if(data.mass_A[6] == symbol)  k *= 3;
    if(data.mass_A[10] == symbol) k *= 5;
    if(data.mass_B[2] == symbol)  k *= 7;
    if(data.mass_B[6] == symbol)  k *= 11;
    if(data.mass_B[10] == symbol) k *= 13;
    if(data.mass_C[2] == symbol)  k *= 17;
    if(data.mass_C[6] == symbol)  k *= 19;
    if(data.mass_C[10] == symbol) k *= 23;

    if(k % 30 == 0)  return 1; //横１列目（１、２、３）
    else if(k % 238 == 0)  return 1; //縦１列目（１、４、７）
    else if(k % 506 == 0)  return 1; //右斜め（１、５、９）
    else if(k % 627 == 0)  return 1; //縦２列目（２、５、８）
    else if(k % 935 == 0)  return 1; //左斜め（３、５、７）
    else if(k % 1001 == 0)  return 1; //横２列目（４、５、６）
    else if(k % 1495 == 0)  return 1; //縦３列目（３、６、９）
    else if(k % 7429 == 0)  return 1; //横３列目（７、８、９）
    else  return 0;
}

//作成者: 川﨑裕貴
//作成日: 2018/6/15
//内　容: oxGAME(ver.8)
//更　新:


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//構造体 ~oxGAME~
struct oxGAME_data{
    int fname_num; //ファイル番号
    char fname[100]; //ファイル名
    int mode_num; //対戦モード
    int turn_num; //経過ターン数
    char mass_A[15]; //マス1列目
    char mass_B[15]; //マス2列目
    char mass_C[15]; //マス3列目
    char name_A[30]; //プレイヤー名（先攻）
    char name_B[30]; //プレイヤー名（後攻）
};


//関数のプロトコル宣言開始

struct oxGAME_data reset_Data(struct oxGAME_data data); //構造体の初期化
struct oxGAME_data battle_Menu(struct oxGAME_data data); //対戦メニュー画面の表示
struct oxGAME_data fname_Get(struct oxGAME_data data); //ファイル名の取得
struct oxGAME_data name_Get(struct oxGAME_data data);
void mass_Out(struct oxGAME_data data); //現在のマスの表示
int mass_Number(void); //マス番号の入力
int mass_Number_checker(struct oxGAME_data data, int num); //マス番号の照合
struct oxGAME_data mass_Change(struct oxGAME_data data, int num, char symbol); ////マスの置き換え
int winORlose(struct oxGAME_data data, char symbol); //プレイヤー名の取得

void mode_Friend(struct oxGAME_data data); //「友人と対戦」モード(上位階層)

void mode_AI(struct oxGAME_data data); //「AIと対戦」モード（上位階層）
int mode_AI_level1(struct oxGAME_data data); //AI Level1
int mode_AI_level2_1(struct oxGAME_data data, char symbol); //AI Level2(自リーチをとる)
int mode_AI_level2_2(struct oxGAME_data data, char symbol); //AI Level2(他リーチを妨げる)

void txt_save(struct oxGAME_data data); //txt形式のファイルに対戦状況の書き込み
void txt_winORlose(struct oxGAME_data data, char symbol, char symbol_AI, int judge); //txt形式のファイルに対戦状況の書き込み(勝敗情報)

void saveData_Input(struct oxGAME_data data); //中断データの書き込み
struct oxGAME_data saveData_Output(struct oxGAME_data data); //中断デートの読み込み

//関数のプロトコル宣言終了


//プログラム開始

//処理の誘導および、関数の処理
int main(void){
    struct oxGAME_data data;
    int n;
    data = reset_Data(data);
    printf("中断データがある場合、再開しますか？\n");
    printf("再開する場合は「0」を入力してください\n\n");
    scanf("%d", &n);
    if(n == 0){
        data = saveData_Output(data);
    }else{
        data = battle_Menu(data);
        if(data.mode_num != 3){
            data = fname_Get(data);
            printf("セーブファイルを取得に成功しました\n\n");
            data = name_Get(data);
        }
    }
    switch (data.mode_num){
        case 1:
            mode_AI(data);
            break;
        case 2:
            mode_Friend(data);
            break;
        case 3:
            printf("ゲームを終了します\n\n");
            printf("ありがとうございました\n\n");
            return 0;
        default:
            exit(1);
    }
    return 0;
}

//構造体の初期化
struct oxGAME_data reset_Data(struct oxGAME_data data){
    int i;
    char mass_enpty[15] = "|   |   |   |\n";

    data.mode_num = 0;
    data.turn_num = 1;

    for(i = 0; i < 15; i++){
        data.mass_A[i] = mass_enpty[i];
        data.mass_B[i] = mass_enpty[i];
        data.mass_C[i] = mass_enpty[i];
    }

    return data;
}

//対戦メニュー画面の表示
struct oxGAME_data battle_Menu(struct oxGAME_data data){
    printf("対戦モードの選択をして下さい\n\n");
    printf("**********************\n");
    printf("* 1: ＡIと対戦　　　 *\n");
    printf("* 2: 友人と対戦      *\n");
    printf("* 3: 終了　　　      *\n");
    printf("**********************\n\n");
    do{
        scanf("%d", &data.mode_num);
        printf("\n");
    }while(data.mode_num < 1 || data.mode_num > 3);
    return data;
}

//ファイル名の取得
struct oxGAME_data fname_Get(struct oxGAME_data data){
    FILE *fp;
    fp = fopen("oxGAME-Data/fname.txt", "r");
    if(fp == NULL){
        printf("ファイル処理ができませんでした\n");
        exit(1);
    }
    fscanf(fp, "%d\n", &data.fname_num);
    fscanf(fp, "%s\n", data.fname);
    fclose(fp); //読み込み終了
    data.fname_num += 1;
    fp = fopen("oxGAME-Data/fname.txt", "w");
    if(fp == NULL){
        printf("ファイル処理ができませんでした\n");
        exit(1);
    }
    fprintf(fp, "%d\n", data.fname_num);
    fprintf(fp, "oxGAME-Result/Result-%d.txt\n", data.fname_num);
    fclose(fp); //書き込み終了
    return data;
}

//プレイヤー名の取得
struct oxGAME_data name_Get(struct oxGAME_data data){
    char you[4] = "YOU";
    char player1[8] = "Player1";
    char player2[8] = "Player2";
    int i, x = 0;
    if(data.mode_num == 1){
        srand((unsigned)time(NULL));
        x = rand()%2+1;
    }
    if(x == 1){
        do{
            printf("プレイヤー名を入力してください\n");
            printf("無名の場合、[0]を入力してください\n");
            scanf("%s", data.name_A);
        }while (data.name_A[0] == 'A' && data.name_A[1] == 'I');
        data.name_B[0] = 'A';
        data.name_B[1] = 'I';
    }else if(x == 2){
        do{
            printf("プレイヤー名を入力してください\n");
            printf("無名の場合、[0]を入力してください\n");
            scanf("%s", data.name_B);
        }while (data.name_B[0] == 'A' && data.name_B[1] == 'I');
        data.name_A[0] = 'A';
        data.name_A[1] = 'I';
    }else{
        printf("プレイヤー名（先攻）を入力してください\n");
        printf("無名の場合、[0]を入力してください\n");
        scanf("%s", data.name_A);
        printf("プレイヤー名（後攻）を入力してください\n");
        printf("無名の場合、[0]を入力してください\n");
        scanf("%s", data.name_B);
    }
    if(data.name_A[0] == '0' && data.name_A[1] == '\0' && data.mode_num == 1){
        for(i = 0; i < 3; i++)
            data.name_A[i] = you[i];
    }
    if(data.name_A[0] == '0' && data.name_A[1] == '\0' && data.mode_num == 2){
        for(i = 0; i < 3; i++)
            data.name_A[i] = player1[i];
    }
    if(data.name_B[0] == '0' && data.name_B[1] == '\0' && data.mode_num == 2){
        for(i = 0; i < 3; i++)
            data.name_B[i] = player2[i];
    }
    printf("\n");
    return data;
}

//現在のマスの表示
void mass_Out(struct oxGAME_data data){
    int i;
    char mass_line[15] = "+---+---+---+\n";
    for(i = 0; i < 7; i++){
        if(i == 1)
            printf("%s", data.mass_A);
        else if(i == 3)
            printf("%s", data.mass_B);
        else if(i == 5)
            printf("%s", data.mass_C);
        else
            printf("%s", mass_line);
    }
    printf("\n");
    return;
}

//マス番号の入力
int mass_Number(void){
    int x, i;
    char mass_line[15] = "+---+---+---+\n";
    char a[15]= "| 1 | 2 | 3 |\n";
    char b[15]= "| 4 | 5 | 6 |\n";
    char c[15]= "| 7 | 8 | 9 |\n";
    do{
        printf("マス番号を入力して下さい\n");
        printf("マス番号の確認をしたい場合は10を入力して下さい\n");
        printf("ゲームを中断したい場合は0を入力して下さい\n\n");
        scanf("%d", &x);
        printf("\n");
        if(x == 10){
            for(i = 0; i < 7; i++){
                if(i == 1)        printf("%s", a);
                else if(i == 3)   printf("%s", b);
                else if(i == 5)   printf("%s", c);
                else              printf("%s", mass_line);
            }
            printf("\n");
        }
    }while(x < 0 || x > 9);
    return x;
}

//マス番号の照合
int mass_Number_checker(struct oxGAME_data data, int num){
    switch(num){
        case 1:
            if(data.mass_A[2] == ' ')
                return num;
            break;
        case 2:
            if(data.mass_A[6] == ' ')
                return num;
            break;
        case 3:
            if(data.mass_A[10] == ' ')
                return num;
            break;
        case 4:
            if(data.mass_B[2] == ' ')
                return num;
            break;
        case 5:
            if(data.mass_B[6] == ' ')
                return num;
            break;
        case 6:
            if(data.mass_B[10] == ' ')
                return num;
            break;
        case 7:
            if(data.mass_C[2] == ' ')
                return num;
            break;
        case 8:
            if(data.mass_C[6] == ' ')
                return num;
            break;
        case 9:
            if(data.mass_C[10] == ' ')
                return num;
            break;
        default:
            exit(1);
    }
    printf("もう一度入力してください\n\n");
    return 0;
}

//マスの置き換え
struct oxGAME_data mass_Change(struct oxGAME_data data, int num, char symbol){
    switch(num){
        case 1:
            data.mass_A[2] = symbol;
            break;
        case 2:
            data.mass_A[6] = symbol;
            break;
        case 3:
            data.mass_A[10] = symbol;
            break;
        case 4:
            data.mass_B[2] = symbol;
            break;
        case 5:
            data.mass_B[6] = symbol;
            break;
        case 6:
            data.mass_B[10] = symbol;
            break;
        case 7:
            data.mass_C[2] = symbol;
            break;
        case 8:
            data.mass_C[6] = symbol;
            break;
        case 9:
            data.mass_C[10] = symbol;
            break;
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

//「友人と対戦」モード
void mode_Friend(struct oxGAME_data data){
    int judge = 0, num;
    char symbol;
    printf("%s VS %s\n\n", data.name_A, data.name_B);
    printf("GAME START!!\n\n");
    mass_Out(data);
    do{
        num = 0;
        if(data.turn_num % 2 == 1){
            symbol = 'o';
            printf("%s(先攻)の番です\n\n", data.name_A);
        }else{
            symbol = 'x';
            printf("%s(後攻)の番です\n\n", data.name_B);
        }
        do{
            num = mass_Number();
            if(num == 0){
                saveData_Input(data);
                printf("ゲームを中断します\n");
                printf("ありがとうございました\n\n");
                exit(0);
            }
            num = mass_Number_checker(data, num);
        }while(num == 0);
        data = mass_Change(data, num, symbol);
        mass_Out(data);
        judge = winORlose(data, symbol);
        txt_save(data);
        data.turn_num += 1;
      }while(judge != 1 && data.turn_num <= 9);
      if(judge != 1){
          printf("引き分けです\n");
      }else{
          switch (symbol){
              case 'o':
                  printf("%s(先攻)の勝ちです\n", data.name_A);
                  break;
              case 'x':
                  printf("%s(後攻)の勝ちです\n", data.name_B);
                  break;
              default:
                  exit(1);
          }
      }
      txt_winORlose(data, symbol, ' ', judge);
      return;
}

//「AIと対戦」モード
void mode_AI(struct oxGAME_data data){
    int judge = 0, num, lebel;
    char symbol, symbol_AI;
    if(data.name_A[0] == 'A' && data.name_A[1] == 'I')
        symbol_AI = 'o';
    else
        symbol_AI = 'x';
    printf("AIの強さの選択をして下さい\n\n");
    printf("**********************\n");
    printf("* 1: レベル１　  　　*\n");
    printf("* 2: レベル２　　  　*\n");
    printf("* 3: レベル３　　  　*\n");
    printf("**********************\n\n");
    do{
        scanf("%d", &lebel);
        printf("\n");
    }while(lebel < 1 || lebel > 3);
    if(symbol_AI != 'o'){
        printf("%sは先攻です\n\n", data.name_A);
        printf("%s VS AI(Lv.%d)\n\n", data.name_A, lebel);
    }else{
        printf("%sは後攻です\n\n", data.name_B);
        printf("%s VS AI(Lv.%d)\n\n", data.name_B, lebel);
    }
    printf("GAME STRAT!!\n\n");
    mass_Out(data);
    do{
        num = 0;
        if(data.turn_num % 2 == 1){
            symbol = 'o';
        }else{
            symbol = 'x';
        }
        if(symbol_AI == symbol){
            printf("AIの番です\n\n");
            switch (lebel) {
              case 1:
                  num = mode_AI_level1(data);
                  break;
              case 2:
                  num = mode_AI_level2_1(data, symbol);
                  if(num == 10)
                      num = mode_AI_level2_2(data, symbol);
                  if(num == 10)
                      num = mode_AI_level1(data);
                  break;
              case 3:
                  exit(1);//未実装のため
                  break;
              default:
                  exit(1);
            }
        }else{
            printf("%sの番です\n\n", data.name_A);
            do{
                num = mass_Number();
                if(num == 0){
                    saveData_Input(data);
                    printf("ゲームを中断します\n");
                    printf("ありがとうございました\n\n");
                    exit(0);
                }
                num = mass_Number_checker(data, num);
            }while(num == 0);
        }
        data = mass_Change(data, num, symbol);
        mass_Out(data);
        judge = winORlose(data, symbol);
        txt_save(data);
        data.turn_num += 1;
      }while(judge != 1 && data.turn_num <= 9);
      if(judge != 1){
          printf("引き分けです\n");
      }else if(symbol_AI == symbol)
          printf("AIの勝ちです\n");
      else
          printf("%sの勝ちです\n", data.name_A);
      txt_winORlose(data, symbol, symbol_AI, judge);
      return;
}

//AI Level1
int mode_AI_level1(struct oxGAME_data data){
    int x;
    do{
        x = rand()%9+1;
        switch(x){
            case 1:
                if(data.mass_A[2] != ' ')
                    x = 0;
                break;
            case 2:
                if(data.mass_A[6] != ' ')
                    x = 0;
                break;
            case 3:
                if(data.mass_A[10] != ' ')
                    x = 0;
                break;
            case 4:
                if(data.mass_B[2] != ' ')
                    x = 0;
                break;
            case 5:
                if(data.mass_B[6] != ' ')
                    x = 0;
                break;
            case 6:
                if(data.mass_B[10] != ' ')
                    x = 0;
                break;
            case 7:
                if(data.mass_C[2] != ' ')
                    x = 0;
                break;
            case 8:
                if(data.mass_C[6] != ' ')
                    x = 0;
                break;
            case 9:
                if(data.mass_C[10] != ' ')
                    x = 0;
                break;
            default:
                exit(1);
        }
    }while(x == 0);
    return x;
}

//AI Level2(自リーチをとる)
int mode_AI_level2_1(struct oxGAME_data data, char symbol){
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

//AI Level2(敵リーチを妨げる)
int mode_AI_level2_2(struct oxGAME_data data, char symbol){
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

//txt形式のファイルに対戦状況の書き込み
void txt_save(struct oxGAME_data data){
    FILE *fp;
    char mass_line[15] = "+---+---+---+\n";
    int i;

    fp = fopen(data.fname, "a");

    if(fp == NULL){
      printf("ファイル処理ができませんでした\n\n");
      exit(1);
    }

    if(data.turn_num == 1)
      fprintf(fp, "GAME STRAT!!\n");

    if(data.turn_num % 2 == 1)
        fprintf(fp, "\n%dターン目(%s)\n", data.turn_num, data.name_A);
    else
        fprintf(fp, "\n%dターン目(%s)\n", data.turn_num, data.name_B);

    for(i = 0; i < 7; i++){
        if(i == 1)
            fprintf(fp, "%s", data.mass_A);
        else if(i == 3)
            fprintf(fp, "%s", data.mass_B);
        else if(i == 5)
            fprintf(fp, "%s", data.mass_C);
        else
            fprintf(fp, "%s", mass_line);
    }

    fclose(fp);
    return;
}

//txt形式のファイルに対戦状況の書き込み(勝敗情報)
void txt_winORlose(struct oxGAME_data data, char symbol, char symbol_AI, int judge){
    FILE *fp;

    fp = fopen(data.fname, "a");

    if(fp == NULL){
        printf("ファイル処理ができませんでした\n\n");
        exit(1);
    }
    if(data.mode_num == 1){
        if(judge == 1 && symbol == symbol_AI)
            fprintf(fp, "\nYour Lose！\n");
        else if(judge == 1)
            fprintf(fp, "\nYour Win！\n");
        else
            fprintf(fp, "\nDraw！\n");
    }else{
        if(judge == 1 && symbol == 'o')
            fprintf(fp, "\nA winner is %s！\n", data.name_A);
        else if(judge == 1)
            fprintf(fp, "\nA winner is %s！\n", data.name_B);
        else
            fprintf(fp, "\nDraw！\n");
    }

    return;
}

//中断データの書き込み
void saveData_Input(struct oxGAME_data data){
    FILE *fp;
    int o_num = 1, x_num = 1;

    if(data.mass_A[2] == 'o')   o_num *= 2;
    if(data.mass_A[6] == 'o')   o_num *= 3;
    if(data.mass_A[10] == 'o')  o_num *= 5;
    if(data.mass_B[2] == 'o')   o_num *= 7;
    if(data.mass_B[6] == 'o')   o_num *= 11;
    if(data.mass_B[10] == 'o')  o_num *= 13;
    if(data.mass_C[2] == 'o')   o_num *= 17;
    if(data.mass_C[6] == 'o')   o_num *= 19;
    if(data.mass_C[10] == 'o')  o_num *= 23;

    if(data.mass_A[2] == 'x')   x_num *= 2;
    if(data.mass_A[6] == 'x')   x_num *= 3;
    if(data.mass_A[10] == 'x')  x_num *= 5;
    if(data.mass_B[2] == 'x')   x_num *= 7;
    if(data.mass_B[6] == 'x')   x_num *= 11;
    if(data.mass_B[10] == 'x')  x_num *= 13;
    if(data.mass_C[2] == 'x')   x_num *= 17;
    if(data.mass_C[6] == 'x')   x_num *= 19;
    if(data.mass_C[10] == 'x')  x_num *= 23;

    fp = fopen("oxGAME-Data/save.txt", "w");
    if(fp == NULL){
        printf("ファイル処理ができませんでした\n\n");
        exit(1);
    }

    fprintf(fp, "%d,%d,%d,%d\n", data.mode_num, data.turn_num, o_num, x_num);
    fprintf(fp, "%s\n%s\n%s\n", data.fname, data.name_A, data.name_B);

    fclose(fp);

    return;
}

//中断デートの読み込み
struct oxGAME_data saveData_Output(struct oxGAME_data data){
    FILE *fp;
    int o_num, x_num;

    fp = fopen("oxGAME-Data/save.txt", "r");
    if(fp == NULL){
        printf("ファイル処理ができませんでした\n\n");
        exit(1);
    }

    fscanf(fp, "%d,%d,%d,%d\n", &data.mode_num, &data.turn_num, &o_num, &x_num);
    fscanf(fp, "%s\n", data.fname);
    fscanf(fp, "%s\n",data.name_A);
    fscanf(fp, "%s\n",data.name_B);

    if(o_num % 2 == 0)   data.mass_A[2] = 'o';
    if(o_num % 3 == 0)   data.mass_A[6] = 'o';
    if(o_num % 5 == 0)   data.mass_A[10] = 'o';
    if(o_num % 7 == 0)   data.mass_B[2] = 'o';
    if(o_num % 11 == 0)  data.mass_B[6] = 'o';
    if(o_num % 13 == 0)  data.mass_B[10] = 'o';
    if(o_num % 17 == 0)  data.mass_C[2] = 'o';
    if(o_num % 19 == 0)  data.mass_C[6] = 'o';
    if(o_num % 23 == 0)  data.mass_C[10] = 'o';

    if(x_num % 2 == 0)   data.mass_A[2] = 'x';
    if(x_num % 3 == 0)   data.mass_A[6] = 'x';
    if(x_num % 5 == 0)   data.mass_A[10] = 'x';
    if(x_num % 7 == 0)   data.mass_B[2] = 'x';
    if(x_num % 11 == 0)  data.mass_B[6] = 'x';
    if(x_num % 13 == 0)  data.mass_B[10] = 'x';
    if(x_num % 17 == 0)  data.mass_C[2] = 'x';
    if(x_num % 19 == 0)  data.mass_C[6] = 'x';
    if(x_num % 23 == 0)  data.mass_C[10] = 'x';

    fclose(fp);

    return data;
}

//プログラム終了

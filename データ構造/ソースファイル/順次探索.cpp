//作成者　川﨑裕貴
//作成日　2018/4/16
//内　容　原子番号1~20までの原素名を当てるクイズ

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *table[] = {"水素","ヘリウム","リチウム","ベリリウム","ホウ素","炭素","窒素","酸素","フッ素","ネオン","ナトリウム","マグネシウム","アルミニウム","ケイ素","リン","硫黄","塩素","アルゴン","カリウム","カルシウム"};
    char str[20];
    int n;
    printf("原子番号1~20までの原素名を入力して下さい！\n");
    gets(str);
    for(n = 0; n < 20; n++){
        if(! strcmp(str, table[n])){
            printf("正解です！\n");
            exit(0);
        }
    }
    printf("%sは原子番号1~20に含まれていません\n",str);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define KAZU 10
#define RETU 5

int main(void){
    
    FILE *fp;
    int i = 0;
    int numbers[KAZU];
    
    fp = fopen("numbers.csv", "r");
    
    if(fp == NULL){
        printf("ファイルが開けませんでした\n");
        exit(1);
    }
    
    while(fscanf(fp, "%d,%d,%d,%d,%d", &numbers[i], &numbers[i+1], &numbers[i+2], &numbers[i+3], &numbers[i+4]) != EOF){
        i += RETU;
        if(i > KAZU)
            break;
    }
    
    fclose(fp);
    
    fp = fopen("numbers.csv", "w");
    
    if(fp == NULL){
        printf("ファイルが開けませんでした\n");
        exit(1);
    }
    
    for(i = 0; i < KAZU; i++){
        numbers[i] *= 2;
        fprintf(fp, "%d", numbers[i]);
        if((i + 1) % RETU == 0)
            fprintf(fp, "\n");
        else
            fprintf(fp, ",");
    }
    
    fclose(fp);
    
}

/*
 Information
 Name: Kawasaki Hiroki
 Data: 9/19/2018
 contents: Study Math_Physics Main
 */

#include <stdio.h>
#include <stdlib.h>
#include "Math/Math_001.hpp" //-> Math_2
#include "Math/Math_002.hpp" //-> Math_1
#include "Math/Math_003.hpp" //-> Math_1

int main(){
    int select_1, select_2;
    
    printf("\nWhich study do you make?\n\n");
    printf("1: Math\n");
    printf("2: Physics\n");
    printf("3: Error search\n\n");
    printf("select: ");
    scanf("%d", &select_1);
    printf("\n");
    if(select_1 == 1){
        printf("1: Math\n");
        printf("    1: Factorial\n");
        printf("    2: Factorization\n");
        printf("    3: Prime Number Edition\n");
    }else if(select_1 == 2){
        printf("2: Physics\n");
        printf("    No content.\n\n");
        return 0;
    }else if(select_1 == 3){
        printf("3: Error search\n");
        printf("  1: s001~999\n");
        printf("  2: y001~005\n");
    }
    printf("\nselect: ");
    scanf("%d", &select_2);
    printf("\n");
    if(select_1 == 1){
        switch (select_2){
            case 1:
                Factorial();
                break;
            case 2:
                Factorization();
                break;
            case 3:
                Prime_Number_Edition();
                break;
            default:
                printf("Error: y002\n\n");
                exit(0);
        }
    }else if(select_1 == 2){
        switch (select_2){
            default:
                printf("Error: y003\n\n");
                exit(0);
        }
    }else if(select_1 == 3){
        switch (select_2){
            case 1:
                printf("System error. Please refer.\n\n");
                break;
            case 2:
                printf("You selected a wrong choice. Please input again.\n\n");
                break;
            default:
                printf("Error: y004\n\n");
                exit(0);
        }
    }else{
        printf("Error: y001\n\n");
        exit(0);
    }
    printf("Thank you.\nSee you again.\n\n");
    return 0;
}

// (c) 2018 Kawasaki Hiroki

#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    int counter = 0;

    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
    if(fscanf(fin,"%d",&a) == 1){
        int ap = a; //previous a 
        n++;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a < ap){
            printf("ERROR: YOU'RE NOT COOKING");
            return 1;
        }
        if (a > ap){
            counter++;
        }
        ap = a;
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        printf("Amount ogf unique numbers: %d\n", counter);
    }
    
    fclose(fin);
    return 0;

}
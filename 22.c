#include <stdio.h>



int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел
    int counter = 1;
    int ap = 0;
    int max = -1;
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }

    if(fscanf(fin,"%d",&a) == 1){
        ap = a; 
        n++;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a > ap){ 
            counter++;
        }
        if (a <= ap){
            if (counter > max){
                max = counter;
            }
            counter = 1;
        }
        ap = a; 
    } 
    if (counter > max){
        max  = counter;
    }

    if (n == 0){ 
        printf("No numbers in the file\n");
    }
    else{
        printf("MAX Length of growing sequence: %d\n", max);
    }
    
    fclose(fin);
    return 0;

}
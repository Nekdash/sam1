#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    int counter = 0;
    int k = 0;
    int res = 0;
    int ap = 0;
    printf("Input k:\n");
    scanf("%d",&k);
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
    if(fscanf(fin,"%d",&a) == 1){
        ap = a; //previous a 
        n++;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if(a > ap){
            printf("ERROR: SEQUENCE INCONSISTENT\n");
            return -1;
        }
        if(a == ap){
            counter++;
        }
        if(counter == k){
            printf("%d\n", a);
            res++;
        }
        if(a < ap){
            counter = 0;
        }
        ap = a;
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        printf("Amount of numbers found more than %d times: %d\n",k, res);
    }
    
    fclose(fin);
    return 0;

}
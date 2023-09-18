#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    int min = 2147483647;
    int min_last = 0;
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        sum+=a;
        n++;
        if (a < min){
            min = a;
        }
        if(a == min){
            min_last = n;
        }
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        printf("Last min number found at %d place\n",  min_last);
    }

    
    fclose(fin);
    return 0;

}
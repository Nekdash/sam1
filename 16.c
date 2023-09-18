#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    int min = 2147483647;
    int min_first = 0;
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        
        sum+=a;
        n++;
        if (a < min){
            min = a;
            min_first = n;
        }
        
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        printf("First min number found at %d place\n",  min_first);
    }
    

    //printf("sum=%d\nn =%d\n", sum, n);
    //printf("a1 = %d,a2 = %d,a = %d\n", a1, a2,a);
    
    fclose(fin);
    return 0;

}
#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    int positive_nums, negative_nums, zero_nums = 0;
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
 
    
    while(fscanf(fin,"%d",&a) == 1){
        
        sum+=a;
        n++;

        if (a > 0) positive_nums++;
        else if(a == 0)zero_nums++;
        else negative_nums++;
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        printf("Positive numbers:%d\n", positive_nums);
        printf("Zeros:%d\n", zero_nums);
        printf("Negative numbers:%d\n", negative_nums);
    }
    

    
    fclose(fin);
    return 0;

}
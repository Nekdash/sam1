#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    int insert_num = 0;
    int res = 0;
    

    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
       
    while(fscanf(fin,"%d",&a) == 1){
        sum+=a;
        res += a*(insert_num**n);
        n++;

    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        printf("Result:%d", res);
    }
    

    //printf("sum=%d\nn =%d\n", sum, n);
    //printf("a1 = %d,a2 = %d,a = %d\n", a1, a2,a);
    
    fclose(fin);
    return 0;

}
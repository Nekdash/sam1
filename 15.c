#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; // счетчик чисел в файле
    int max = -2147483648;
    int max_first = 0; // индекс первого максимального числа в файле
   
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){  
        
        n++;
        if (a > max){ // нынешнее а больше максимума - это новый максимум ( а значит и первое его появление )
            max = a;
            max_first = n;
        }
        
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file \n");
    }
    else{
        printf("First max number found at %d place\n", max_first);
    }
    
    //файл закройте , 0 верните, вам то сложно что ли
    fclose(fin);
    return 0;

}
#include <stdio.h>

//смотрите решение номера 9 : здесь просто вычитаем найденное значение из общего кол-ва чисел

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел в файле
    int max = -2147483648;
    int max_c = 0;
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        
        
        n++;
        if (a > max){
            max = a;
            max_c = 1;
        }
        else if(a == max){
            max_c++;
        }
    } 

    if (n == 0){ // может не стоило вводить пустой файл?
        printf("No numbers in the file \n");
    }
    else{
        printf("Amount of  non-max numbers:%d\n", n - max_c);
    }
    

    fclose(fin);
    return 0;

}
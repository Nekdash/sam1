#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел в файле
    int min = 2147483647; //это самое большое возможное значение для типа int
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a < min){
            min = a; //число меньше минимума - это новый минимум
        }
    } 

    if (n == 0){ // чисел в файле не было, о каком ответе может идти речь?!
        printf("No numbers in the file\n");
    }
    else{
        printf("Min number:%d\n", min);
    }
    
    //последнее правило бойцовского клуба - закрыть файл и вернуть 0
    fclose(fin);
    return 0;

}
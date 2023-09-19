#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик файлов в числе
    int min = 2147483647;
    int min_first = 0; // индекс первого минимума
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a < min){ //нынешнее число меньше минимума - это новый минимум (а значит и первое его вхождение)
            min = a;
            min_first = n;
        }
        
    } 

    if (n == 0){ // какой долбаеб додумался подавать путсые файлы
        printf("No numbers in the file \n");
    }
    else{
        printf("First min number found at %d place\n",  min_first);
    }
    //не забываем закрыть файл и вернуть 0
    fclose(fin);
    return 0;

}
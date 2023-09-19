#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //количество чисел в файле - счетчик
    int min = 2147483647; // самое большое возможное значение int
    int min_c = 0; //счетчик 
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a < min){ // ичсло меньше минимума - оно новый минимум и счетчик сбрасывается до 1
            min = a;
            min_c = 1;
        }
        else if(a == min){ // число просто равно минимуму - прибавляем единичку
            min_c++;
        }
    } 

    if (n == 0){ // и конечно в случае если в файле пусто - сообщаем об этом
        printf("No numbers in the file \n");
    }
    else{
        printf("Amount of min numbers:%d\n", min_c);
    }
    //не забываем закрыть файл и вернуть 0
    fclose(fin);
    return 0;

}
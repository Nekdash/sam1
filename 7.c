#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик количества  чисел
    int max = -2147483648; // это минимальное значение для типа int
   
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }

    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a > max){
            max = a; //если число больше максимума - то это новый максимум
        }
    } 
    if (n == 0){ // о боже мой, чисел в файле не было - какая жалость, давайте обязательно сообщим об этом пользователю
        printf("No numbers in the file \n");
    }
    else{
        printf("Max number:%d\n", max);
    }
    //закрыть файл. вернуть 0.
    fclose(fin);
    return 0;

}
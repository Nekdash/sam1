#include <stdio.h>

//более точное описание алгоритма чистать в задаче номер 4 - тут изменены пара строк

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел в файле
    
    int insert_num;
    int index_last_found = -1;
    
    printf("Input a number:\n");
    if (scanf("%d", &insert_num) != 1){
        printf("INCORRECT INPUT");
        return -1;
    }

    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    
    while(fscanf(fin,"%d",&a) == 1){
        
        n++; // следим за номером нашего числа
        if (a == insert_num){
            index_last_found = n;
        }
    } 

    if (n == 0){ // чисел нет - сообщаем что пользователя вероятно черт попутал
        printf("No numbers in the file \n");
    }
    else{
        if(index_last_found != -1) { //число было найдено
            printf("Your number was last found on the %d place\n\n", index_last_found);
        }
        else printf("Your number was not found once! :(\n\n");
    }
    
    //умоляю вас закрывайте файл до выхода, и возвращайте 0
    fclose(fin);
    return 0;

}
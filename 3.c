#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //количество чисел в файле - счетчик
    
    /*
    ОБЪЯСНЕНИЕ ПЕРЕМЕННЫХ
    insert_num - переменная в которую я потом положу введенное значение
    count_insert = счетчик, сколько раз мы встретили введенное значение
    */

    int insert_num = 0, count_insert = 0;
    
    //Просим пользователя ввести число и считываем ввод (просить ввести число это этикет)
    printf("Input a number:\n");

    //считываем число и проверяем что считали именно число что все хорошо и что пользователь не долбаеб
    if (scanf("%d", &insert_num) != 1){
        printf("INCORRECT INPUT");
        return -1;
    }

    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a == insert_num){ //если нынешний элемент равен нужному числу - прибавляем один к счетчику
            count_insert += 1; 
        }
    } 

    if (n == 0){ // чисел нет - выводим сообщение об этом казусе
        printf("No numbers in the file \n");
    }
    else{
        
        if(count_insert != 0) {
            printf("Your number was found %d time(s)\n", count_insert); //число было
        }
        else printf("Your number was not found once! \n\n"); //числа не нашли
    }
    //закрыть файл и вернуть 0 - обязательно
    fclose(fin);
    return 0;

}
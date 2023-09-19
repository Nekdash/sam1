#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел в файле
    
    /*
    insert_num - переменная для введенного числа
    index_insert - сюда вы положим номер места где впервые нашли наше число (если не найдем там будет -1)
    */
    int insert_num;
    int index_insert= -1;
    
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
        n++; // следим за номером числа

        if (a == insert_num){
            if (index_insert == -1){
                index_insert = n;
            }
        }
    } 

    if (n == 0){ // если чисел в файле не было - сообщаем о таком недоразумении
        printf("No numbers in the file \n");
    }
    else{
        if(index_insert != -1) { //число находили
            printf("Your number was first found on the %d place\n", index_insert);
        }
        else printf("Your number was not found once! :(\n\n"); // ну не было числа в файле, ну что вы пристали
    }
    
    //если вы хоть что-то напишете вообще - так это закрытие файла и возврат нуля - обязательно
    fclose(fin);
    return 0;

}
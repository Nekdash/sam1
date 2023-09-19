#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел в файлееее
    int max = -2147483648; //самое маленькое возможное значение int
    int max_c = 0; //счетчик максимальных чисел
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED\n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a > max){ //число больше максимума - новый максимум и счетчик сбрасываем до 1
            max = a;
            max_c = 1;
        }
        else if(a == max){ //очередной старый максимум ( который мы уже встрчали) - добавляем один к счетчику
            max_c++;
        }
    } 

    if (n == 0){ // как же так, в файле пусто - сообщаем об этом
        printf("No numbers in the file\n");
    }
    else{
        printf("Amount of max numbers:%d\n", max_c);
    }

    //кто файл закрыл и вернул 0 - тот молодец
    fclose(fin);
    return 0;

}
#include <stdio.h>

//смотрите решение номера 12 : здесь просто вычитаем найденное значение из общего кол-ва чисел

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //считаем количество чисел в файле
    int min = 2147483647;
    int min_c = 0;
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        
        
        n++;
        if (a < min){
            min = a;
            min_c = 1;
        }
        else if(a == min){
            min_c++;
        }
    } 

    if (n == 0){ // мало ли кто-то додумался создать пустой файл
        printf("No numbers in the file \n");
    }
    else{
        printf("Min number:%d\nAmount of non-min numbers:%d\n", min, n - min_c);
    }
    //файлик закрываем
    //ноль возвращаем
    fclose(fin);
    return 0;

}
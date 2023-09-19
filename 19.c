#include <stdio.h>

//вот тут начались сложные задачи

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел
    int counter = 0;
    int ap = 0;
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }

    if(fscanf(fin,"%d",&a) == 1){
        ap = a; //первое число - наше предыдущее
        n++;
        counter++; //первое число уже уникальное
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a < ap){ // если следующий элемент меньше предыдущего - последовательность не неубывающая - ошибка
            printf("ERROR: sequence inconsistent\n");
            return 1;
        }
        if (a > ap){ // число сменилось - прибавили единичку
            counter++;
        }
        ap = a; // запоминаем предыдущее число для сравнения со следующим
    } 

    if (n == 0){ // в файле пусто как в моей голове
        printf("No numbers in the file \n");
    }
    else{
        printf("Amount of unique numbers: %d\n", counter);
    }
    // файл закрыли и вернули системе что все хорошо - нолик
    fclose(fin);
    return 0;

}
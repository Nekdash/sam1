#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел в файле
    int min = 2147483647;
    int min_last = 0;
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
    while(fscanf(fin,"%d",&a) == 1){
        sum+=a;
        n++;
        if (a < min){
            min = a;
        }
        if(a == min){
            min_last = n; // каждое число равное минимуму может оказаться последним - запоминаем его
        }
    } 

    if (n == 0){ // в случае если файл пустой:
        printf("No numbers in the file \n");
    }
    else{
        printf("Last min number found at %d place\n",  min_last);
    }

    // файл закрыли и вернули системе нулик (что вам жалко что ли)
    fclose(fin);
    return 0;

}
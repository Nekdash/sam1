#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел в файле
    int max = -2147483648;
    int max_last = 0;
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }

    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a > max){
            max = a;
        }
        if (a == max){
            max_last = n; // каждое число равное максимуму может оказаться последним - его и запоминаем
        }
    } 

    if (n == 0){ // последовательность оказалась пустой как моя душа
        printf("No numbers in the file \n");
    }
    else{
        printf("Last max number found at %d place\n", max_last);
    }
    // файл закрыли и вернули 0
    fclose(fin);
    return 0;

}
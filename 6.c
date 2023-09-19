#include <stdio.h>

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чисел в файле
    int positive_nums = 0, negative_nums = 0, zero_nums = 0; // переменные для кол-ва положительных, отрицательных и нулей (изначально равны нулю)
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
 
    
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        //смотрим на число - добавляем единичку в нужную категорию
        if (a > 0)positive_nums++;
        else if(a == 0)zero_nums++;
        else negative_nums++;
    } 

    if (n == 0){ // чисел в файле не обнаружено - выводим сообщение об оплошности ввода 
        printf("No numbers in the file \n");
    }
    else{
        printf("Positive numbers:%d\n", positive_nums);
        printf("Zeros:%d\n", zero_nums);
        printf("Negative numbers:%d\n", negative_nums);
    }
    

    //перед выходом из программы закройте все что открыли и верните 0 пожалуйста
    fclose(fin);
    return 0;

}
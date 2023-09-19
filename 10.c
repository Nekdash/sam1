#include <stdio.h>
#include <math.h>
/*
степени многочлена убывают, а мы не знаем даже сколько слагаемых в многочлене :(
поэтому мы будем начинать со степени 0 и для следующего слагаемого понижать ее.
в конце - когда мы будем знать кол-во чисел в файле
домножаем весь многочлен на нужную степень х

важно: здесь я сделала так что последний коэффициент - свободный (степень х = 0)
*/

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //количество чисел в файле - счетчик
    float insert_num = 0;
    float res = 0; // здесь храним результаты вычислений
    float temp = 1; // временная переменная - пригодится в цикле
    printf("Insert number:\n");
    if (scanf("%d", &insert_num) != 1){
        printf("INCORRECT INPUT");
        return -1;
    }
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED\n");
        return -1;
    }
       
    while(fscanf(fin,"%d",&a) == 1){
        temp = 1;
        for(int i = 0; i < n; i++){
            temp = temp / insert_num;
        }
        res += a*temp;
        n++;
    } 
    temp = 1;
    for(int i = 0; i < (n-1); i++){
        temp *= insert_num;
    }
    res = res*temp; // последнее домножение
    
    if (n == 0){ // мы бы хотели чтобы файл был не пустым, но так уж и быть - сообщаем что файл оказался все же пустым.
        printf("No numbers in the file\n");
    }
    else{
        printf("Result:%f", res);
    }
    

    //файл закрыл, ноль вернул
    fclose(fin);
    return 0;

}
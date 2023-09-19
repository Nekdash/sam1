#include <stdio.h>
#include <math.h>

//на простых примерах работает - проверьте на сложных

int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //счетчик чсиел в файле
    int insert_num = 0;
    int res = 0;
    int derivative = 0; //производная
    printf("Input number:\n");
    if (scanf("%d", &insert_num) != 1){
        printf("INCORRECT INPUT");
        return -1;
    }

    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }
       
    while(fscanf(fin,"%d",&a) == 1){
        res += a*pow(insert_num,n);
        if (n != 0){
        derivative += a*n*pow(insert_num,n-1);
        }else{
            derivative += 0;
        }
        n++;
    } 

    if (n == 0){ // может лучше будет если в файле будут числа
        printf("No numbers in the file \n");
    }
    else{
        printf("Result:%d\nDerivative:%d\n", res, derivative);
    }
    //файлик закрываааем, нолик на место возвращаем
    fclose(fin);
    return 0;

}
#include <stdio.h>

/*
объяснять этот пиздец лучше лично
*/



int main(void){
    int a = 0;
    FILE *fin = NULL;
    int n = 0; //считаем числа в файле
    int counter = 0; 
    int checker = 0; 
    int monot = 0;
    int fuck = 0;
    int ap = 0;

    

    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED\n");
        return -1;
    }
    if(fscanf(fin,"%d",&a) == 1){
        ap = a; //previous a 
        n++;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a != ap && checker == 0){  
            if(a > ap)monot = 1; // возрастает
            else monot = -1; // убывает
            checker = 1;
            counter++;
        }
        if (monot == 1){ //возрастающая функция
            if (a < ap){
                printf("ERROR: SEQENCE NOT CONSISTENT");
                return -1;
            }
            if (a > ap ){
                counter++;
                fuck = 0;
            }
        }
        else if (monot == -1){ //убывающая функция
            if (a > ap){
                printf("ERROR: SEQENCE NOT CONSISTENT");
                return -1;
            }
            if (a < ap){
                counter++;
                fuck = 0;
            }
        }
        if(a == ap && fuck == 0){
            fuck = 1;
            counter -= 1;
        }
        ap = a;
    } 

    if (n == 0){ // заебали путсые файлы делать бляди
        printf("No numbers in the file\n");
    }
    else{
        printf("Amount of unique numbers: %d\n", counter);
    }
    //файл закрой и ноль верни
    fclose(fin);
    return 0;

}
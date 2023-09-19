#include <stdio.h>

int main(void){
    int a = 0; //переменная для нынешнего значения а
    FILE *fin = NULL;
    int n = 0; //количество чисел в файле - счетчик
    
    /*
    ОБЪЯСЕНИЕ ПЕРЕМЕННЫХ:
    а1 и а2 - переменные для первых двух чисел - по ним я рассчитываю а1 и d
    previous_a - переменная для предыдущего значения а (сохраняю для проверки разности с нынешней а)
    difference - это и есть d (разность)

    checker_ap - с  помощью нее я слежу за тем, что это ариф. прогрессия
                = 0 - прогрессия не арифметическая
                = 1 - прогрессия арифметичсекая (все хорошо) 
    */

    int a1 , a2, previous_a  = 0;
    int difference = 1, checker_ap = 1;
    
    //открываем файл и проверяем что он открылся
    if ((fin = fopen("input.txt","r")) == NULL){

        //если файл не открылся - пишем ошибку и ПИШЕМ RETURN ОБЯЗАТЕЛЬНО ИНАЧЕ ПИЗДЕЦ
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }


     //считываю первые два числа ; сохраняю их в переменных а1 и а2 ; добавляю к счетчику чисел по единичке
    if(fscanf(fin,"%d", &a) == 1){a1 = a; n++;} 
    if(fscanf(fin,"%d", &a) == 1){a2 = a; n++;}

    //расчитываю разность арифметической прогрессии
    difference = a2 - a1;

    //теперь "предыдущее а" это наше а2 (мы его уже считали и обработали)
    previous_a = a2;
    







    //цикл  - в каждой итерации цикла мы считываем следующее значение в файле и кладем его в переменную а
    while(fscanf(fin,"%d",&a) == 1){
        
        n++; //слежу за количеством чисел
        /*
        если вдруг разность соседних чисел не равна разности ариф. прогрессии то мы понимаем что это не ариф. прогрессия
        */
        if (a - previous_a != difference) checker_ap = 0;
        
        
        //меняем предыдущее а
        previous_a = a;
    } 

    if (n == 0){ // если чисел в файле не было - пишу что их не было
        printf("ERROR: No numbers in the file\n");
    }
    else{
        if(n == 1)printf("ERROR: One number is not a progression.\n"); // если число было одно, то это тоже не очень прогрессия - вывожу сообщение
        else{
            if(checker_ap == 0) printf("It's not an arithmetic progression! \n");  // если наш checker равен 0 - это не ариф. прогрессия
            else printf("It's an arithmetic progression! a1 = %d, d = %d\n\n", a1, difference); //иначе выводим первое число в файле и разность
        }
    }
    //Закрываем файл ОБЯЗАТЕЛЬНО
    fclose(fin);

    //ВОЗВРАЩАЕМ НОЛЬ ТОЖЕ ОБЯЗАТЕЛЬНО
    return 0;

}
#include <stdio.h>

int main(void){
    int a = 0; //переменная для нынешнего значения а
    FILE *fin = NULL;
    int n = 0; //количество чисел в файле - счетчик
    
    /*
    ОБЪЯСЕНИЕ ПЕРЕМЕННЫХ:
    а1 и а2 - переменные для первых двух чисел - по ним я рассчитываю а1 и q
    previous_a - переменная для предыдущего значения а (сохраняю для проверки частного с нынешней а)
    ratio - это и есть q (частное)

    checker_gp - с  помощью нее я слежу за тем, что это геом. прогрессия
                = 0 - прогрессия не геометрическая
                = 1 - прогрессия геометричсекая (все хорошо) 
    
    */

    int a1 = 0, a2, previous_a = 0;
    int ratio, checker_gp= 1;
    
    //открываем файл и проверяем что он открылся
    if ((fin = fopen("input.txt","r")) == NULL){

        //если файл не открылся - пишем ошибку и ПИШЕМ RETURN ОБЯЗАТЕЛЬНО ИНАЧЕ ПИЗДЕЦ
        printf("ERROR: FILE CANNOT BE OPENED \n");
        return -1;
    }

    //считываю первые два числа ; сохраняю их в переменных а1 и а2 ; добавляю к счетчику чисел по единичке
    if(fscanf(fin,"%d", &a) == 1){a1 = a; n++;} 
    if(fscanf(fin,"%d", &a) == 1){a2 = a; n++;}

    
    //в википедии написано что элементы геометричесмкой прогрессии не могут быть равны нулю - проверяем это
    if (a1 == 0 || a2 == 0){checker_gp = 0;}
    else{ratio = a2 / a1;} // если все хорошо то считаем частное
    
    previous_a = a2; //теперь "предыдущее а" это а2
    
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a == 0 ) {checker_gp = 0;} //если число ноль - прогрессия не геометрическая
        else if (a / previous_a != ratio) checker_gp = 0; // или если частное двух соседних чисел другое
        
        previous_a = a; //обновляем "предыдущее а"
    } 

    if (n == 0){ // если чисел нет - сообщаем об этом
        printf("No numbers in the file \n");
    }
    else{
        if(n == 1)printf("One number is not a progression.\n"); //число одно - так себе прогресиия - сообщаем об этом
        else{
            //если наш checker равен 0 - то прогрессия не геометрическая
            if(checker_gp == 0) printf("It's not a geometric progression! \n\n");
            else printf("It's a geometric progression! b1 = %d, q = %d\n\n", a1, ratio);
        }
    }
    

    //закрыть файл и вернуть 0 - обязательно
    fclose(fin);
    return 0;

}
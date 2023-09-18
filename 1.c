#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    
    int a1 = 0, a2, previous_a, error_gp  = 0;
    int difference = 1, ratio, checker_ap, checker_gp= 1;
    
    
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
     //read first two numbers
    if(fscanf(fin,"%d", &a) == 1){a1 = a; n++;sum+=a;} 
    if(fscanf(fin,"%d", &a) == 1){a2 = a; n++;sum+=a;}

    difference = a2 - a1;

    if (a1 == 0 || a2 == 0){error_gp = 1; checker_gp = 0;}
    else{ratio = a2 / a1;}
    
    previous_a = a2;
    
    while(fscanf(fin,"%d",&a) == 1){
        sum+=a;
        n++;

        if (a - previous_a != difference) checker_ap = 0;
        if (a == 0 || error_gp == 1) {error_gp = 1; checker_gp = 0;}
        else if (a / previous_a != ratio) checker_gp = 0;
        

        previous_a = a;
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        if(n == 1)printf("One number is not a progression.\n");
        else{
            if(checker_ap == 0) printf("It's not an arithmetic progression! :(\n\n");
            else printf("It's an arithmetic progression! a1 = %d, d = %d\n\n", a1, difference);
            //if(checker_gp == 0 || error_gp == 1) printf("It's not a geometric progression! :(\n\n");
            //else printf("It's a geometric progression! b1 = %d, q = %d\n\n", a1, ratio);
        }
    }
    

    //printf("sum=%d\nn =%d\n", sum, n);
    //printf("a1 = %d,a2 = %d,a = %d\n", a1, a2,a);
    
    fclose(fin);
    return 0;

}
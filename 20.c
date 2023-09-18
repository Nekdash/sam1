#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    int counter = 0;
    int checker = 0;
    int monot = 0;
    int fuck = 0;
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
    if(fscanf(fin,"%d",&a) == 1){
        int ap = a; //previous a 
        n++;
    }
    while(fscanf(fin,"%d",&a) == 1){
        n++;
        if (a != ap){
            if (checker == 0){
                if(a > ap)monot = 1; // growing
                else monot = -1; // decreasing
                checker = 1;
            }
        }
        if (monot == 1){ //growing
            if (a < ap){
                printf("ERROR: SEQENCE NOT CONSISTENT");
                return -1;
            }
            if (a > ap && fuck == 0){
                counter++;
            }else if(a > ap){
                fuck = 0;
            }
            

        }
        else if (monot == -1){ //decreasing
            if (a > ap){
                printf("ERROR: SEQENCE NOT CONSISTENT");
                return -1;
            }
            if (a < ap && fuck == 0){
                counter++;
            }else if(a < ap){
                fuck = 0;
            }

        }
        if(a == ap && fuck == 0){
            fuck = 1;
            counter -= 1;
        }
        ap = a;
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        printf("Amount of unique numbers: %d\n", counter);
    }
    
    fclose(fin);
    return 0;

}
#include <stdio.h>

int main(void){
    int a,sum = 0;
    FILE *fin = NULL;
    int n = 0; //number of numbers
    int cur_a = 0;
    
    int insert_num = 0, count_insert = 0, index_insert = 0, index_found = 0, index_last_found = 0;
    
    printf("Input a number:\n");
    scanf("%d", &insert_num);
    if ((fin = fopen("input.txt","r")) == NULL){
        printf("ERROR: FILE CANNOT BE OPENED :(\n");
        return -1;
    }
    
    while(fscanf(fin,"%d",&a) == 1){
        
        sum+=a;
        n++;

        
        if (a == insert_num){
            count_insert += 1;
            
            if (index_found == 0){
                index_insert = n;
                index_found = 1;
            }
            index_last_found = n;
        }
    } 

    if (n == 0){ // zero numbers situation
        printf("No numbers in the file :(\n");
    }
    else{
        if(count_insert != 0) {
            
            printf("Your number was first found on the %d place\n", index_found);
            
        }
        else printf("Your number was not found once! :(\n\n");
    }
    
    fclose(fin);
    return 0;

}
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE*file;
    file = fopen("A_l.txt", "r");
    if(file == NULL){
        printf("Arquivo invalido");
        return 0;
        fclose(file);
    }else{
        
        float dados[30][3];
        float x,y,z;
        while(!feof(file)){
            fscanf(file,"%f;%f;%f", &x, &y, &z);
            printf("%1.f;%1.f;%1.f\n",x,y,z);
        fclose(file);     
        }   
    }
    return 0;
}
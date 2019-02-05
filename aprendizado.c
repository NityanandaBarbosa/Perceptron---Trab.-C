#include <stdio.h>

int main(void)
{
    char linha[100]; /* ou maior se vc precisar */
    
    float x1[30],x2[30],y[30];
    float w1 = 1;
    float w2 = 1;
    float taxa = 0.01;

    FILE *arquivo;
    
    arquivo = fopen("A_l.txt", "r");
    
    if(arquivo == NULL) {
        printf("arquivo desconhecido - nome_do_arquivo.txt\n");
        return 0;
    }
    
    int i = 0;
    
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        fscanf(arquivo,"%f %f %f", &x1[i], &x2[i], &y[i]);
        i++;
    }
    
    for(i=0; i<29; i++){
        printf("%.2f %.2f %.2f\n", x1[i],x2[i],y[i]);
    }
    
    fclose(arquivo);
    
    int c = 0;
    float yr =0;
    
    while(c!=30){
        yr = (w1*x1[i])+(w2*x2[i]);
        if(y >=0){
            yr=1;
        }else{
            yr=0;
        }
    }

    return 0;

}
 

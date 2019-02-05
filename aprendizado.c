#include <stdio.h>

float definirW1deVetor();
float definirW2deVetor();

int main(void){
    char linha[100];

    float x1[30],x2[30],y[30];
    float taxa = 0.01;

    FILE *arquivo;
        
    arquivo = fopen("A_l.txt", "r");
    
    if(arquivo == NULL) {
        printf("Arquivo informado não está correto.\n");
        return 0;
    }

    float w1 = definirW1deVetor();
    float w2 = definirW2deVetor();
    
    int i = 0;
    
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        fscanf(arquivo,"%f %f %f", &x1[i], &x2[i], &y[i]);
        i++;
    }
    
    for(i=0; i<30; i++){
    printf("c=%d %.2f %.2f %.2f\n", i,x1[i],x2[i],y[i]);
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

float  definirW1deVetor(){
    float w1;

    printf("Informe o valor para a primeira coordenada do vetor inicial: ");
    scanf("%f", &w1);

    return w1;
}

float definirW2deVetor(){
    float w2;

    printf("Informe o valor da segunda coordenada do vetor inicial: ");
    scanf("%f", &w2);

    return w2;
}
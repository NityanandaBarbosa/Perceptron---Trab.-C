#include <stdio.h>

float definirW1deVetor();
float definirW2deVetor();

int main(void){

    char linha[100];

    float x1[30], x2[30], y[30];
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
    
    for(i = 0; i < 30; i++){
    printf("c=%d %.2f %.2f %.2f\n", i, x1[i], x2[i], y[i]);
    }
    
    fclose(arquivo);
    
    int c = 0;
    float yr = 0;
    
    while(c < 30){
        yr = (w1*x1[c]) + (w2*x2[c]);
        
        if(yr >= 0){
            yr = 1;
        } else if(yr < 0){
            yr = 0;
        }

        float d = y[c] - yr;
        
        if(d == 0){
            c++;
        } else if (d != 0){
            w1 = (taxa*d*x1[c]) + w1;
            w2 = (taxa*d*x2[c]) + w2;      
            c = 0;
        }

        yr = 0;
        printf("%d  w1: %.2f w2: %.2f d:%.2f\n",c,w1,w2,d);
    }
    printf("Vetor W descoberto!\nw1:%.2f  w2:%.2f.",w1,w2);
      
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
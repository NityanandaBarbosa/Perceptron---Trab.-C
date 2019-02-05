#include <stdio.h>

int main(void){
    char linha[10000];
    FILE *arquivo;
    float x1[30],x2[30],y[30];
    float w1 = 0.43;
    float w2 = 0.69;


    arquivo = fopen("B_t.txt", "r");
    if(arquivo == NULL) {
        printf("arquivo desconhecido - nome_do_arquivo.txt\n");
        return 0;
    }
    int i=0;
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        fscanf(arquivo,"%f %f %f", &x1[i], &x2[i], &y[i]);
        i++;
    }   
    fclose(arquivo);
    i=0;
    int d = 0;
    int acerto=0;
    for(i=0;i<29;i++){
        float yr=0.0;
        d = 0;
        yr = (w1*x1[i])+(w2*x2[i]);
        printf("Yr é %.2f  e Y[i] : %0.2f\n",yr,y[i]);
        if(yr >=0){
            yr=1;
        }
        else if(yr<0){
            yr=0;
        }
        d = y[i] - yr;
        printf("C = %d e D = %d\n", i,d);
        if(d==0){
            acerto++;
        }else
            printf("ta errado\n");
    }
    float porcAcerto;
    porcAcerto = acerto*100/i;
    printf("Taxa de acerto foi : %.2f", porcAcerto);

}
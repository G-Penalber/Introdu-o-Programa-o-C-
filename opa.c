#include <stdio.h>
#include <stdbool.h>

int main(){
    int media, temperatura;
    int duracao = 10;
    int leituras = 0;
    bool falha = false;
    int quant_frio = 0;
    int quant_quente = 0;
    int quant_estavel = 0;
    printf("\033[0;32m===========================================\n");
    printf("Iniciando a análise de temperatura da caldeira.\n Tempo de duração: 10 minutos.\n");
    printf("===========================================\033[0m\n");
    for (int i = 1; i <= duracao; i++){
        printf("\033[0;32mInsira a temperatura da caldeira no minuto %d: \n", i);
        printf("===========================================\033[0m\n");
        scanf("%d", &temperatura);
        leituras=leituras+1;
        if (temperatura < 80){
            quant_frio = quant_frio + 1;
        }
        else if (temperatura >= 80 && temperatura <= 100){
            quant_estavel = quant_estavel + 1;
        }
        else if (temperatura > 100){
            quant_quente = quant_quente + 1;
        }
        if (temperatura < 80 ){
            printf("\033[0;36m===========================================\n");
            printf("A CALDEIRA ESTÁ FRIA.\n");
            printf("===========================================\n");
            printf("Aumente a temperatura para acima ou igual a 80 graus. \n");
            printf("===========================================\033[0m \n");            
        }
        if (temperatura > 100){
            printf("\033[0;33m===========================================\n");            
            printf("A CALDEIRA ESTÁ ACIMA DA TEMPERATURA SEGURA.\n");
            printf("===========================================\n");
            printf("Diminua a temperatura para abaixo ou igual a 100 graus.\n");
            printf("===========================================\033[0m \n");            
        }
        if (temperatura > 120){
            printf("\033[0;31m===========================================\n");            
            printf("A CALDEIRA SUPERAQUECEU.\n");
            printf("===========================================\n");
            printf("Iniciando procedimento de desligamento da caldeira.\n");
            printf("===========================================\033[0m \n");            
            falha = true;
            break;
        }
        if (i==1){
            media = temperatura;
        }
        else{
            media = (media + temperatura) / 2;
        }
    }
    printf("\033[0;32mANÁLISE CONCLUÍDA \n");
    printf("INICIANDO RELATÓRIO DE ANÁLISE \n");
    printf("===========================================\033[0m\n");
    if (falha){
        printf("\033[0;31mCaldeira desligada em procedimento de emergência devido ao superaquecimento\033[0m \n");
        printf("\033[0;32m===========================================\033[0m\n");  
        printf("\033[0;32mQuantidade de leituras realizadas antes do desligamento: %d \n", leituras);
        printf("\033[0;32mTempo médio com temperatura abaixo de 80 graus: %.1f%% \n", ((float)quant_frio / leituras) * 100);
        printf("Tempo médio com temperatura entre 80 e 100 graus: %.1f%% \n", ((float)quant_estavel / leituras) * 100);
        printf("Tempo médio com temperatura acima de 100 graus: %.1f%% \n", ((float)quant_quente / leituras) * 100);
        printf("===========================================\033[0m\n");
    }   
    else{
        printf("\033[0;32mQuantidade de leituras realizadas: %d \n", leituras);
        printf("Tempo médio com temperatura abaixo de 80 graus: %.1f%% \n", ((float)quant_frio / leituras) * 100);
        printf("Tempo médio com temperatura entre 80 e 100 graus: %.1f%% \n", ((float)quant_estavel / leituras) * 100);
        printf("Tempo médio com temperatura acima de 100 graus: %.1f%% \n", ((float)quant_quente / leituras) * 100);
        printf("===========================================\033[0m\n");
    }
    printf("\033[0;32mFIM DA ANÁLISE DA CALDEIRA \n");
    printf("===========================================\033[0m\n");
    return 0;
}
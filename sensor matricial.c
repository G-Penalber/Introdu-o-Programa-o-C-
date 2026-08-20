#include <stdio.h>
#include <stdbool.h>

int main(){
    float malha[5][5];
    float malha_reserva[5][5];
    int j, i;
    int reduzidax, reduziday;
    float malha_reduzida[3][3];
    float maior;
    float soma;
    float media;

    printf("\n S: Este algoritmo analisa a temperatura 25 sensores posicionados em formato de uma matriz 5x5 de uma malha férrica. \n");
    
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf("\n S: Insira a temperatura do sensor da linha [%d] da coluna [%d] posicionado na malha: \n", i, j);
            scanf("%f", &malha[i][j]);
            printf("\n ================================================================== \n");
        }    
    }
    i=0, j=0;
    printf("\n R: Segue a malha não filtrada em formato de matriz: \n");
    
    
    for (i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%7.2f\t", malha[i][j]);
        }
        printf("\n");
    }

    printf("\n ================================================================== \n");

    for (i=0; i<5; i++){
        for (j=0; j<5; j++){
            malha_reserva[i][j] = malha[i][j];
        }
    }

    for (reduzidax = 1; reduzidax<=3; reduzidax++){
        for (reduziday = 1; reduziday <=3; reduziday++){
            soma = 0.00;
            for (i = reduzidax - 1; i <= reduzidax + 1; i++){
                for(j = reduziday - 1; j <= reduziday + 1; j++){
                    soma += malha_reserva[i][j];   
                }
            }
            media = soma/9.0;
            
            malha[reduzidax][reduziday] = media;

            malha_reduzida[reduzidax - 1][reduziday - 1] = media;
        }
    }
    printf ("\n R: Segue a temperatura filtrada em formato de matriz dos sensores: \n");

    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%7.2f\t", malha_reduzida[i][j]);
        }
        printf("\n");
    }

    maior = malha_reduzida[0][0];
    
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (malha_reduzida[i][j] > maior){
                maior = malha_reduzida[i][j];
            }
        
        }
    }
    printf("\n ================================================================== \n");
    
    printf("R: Segue o maior valor da malha reduzida: [%7.2f] \n", maior);

    return 0;
}

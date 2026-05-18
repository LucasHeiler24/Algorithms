#include <stdio.h>
#include <stdlib.h>

void main(){

    int matrix[1][2] = 
    {
        {0, 30},
        {0, 30},
        {0, 30},
    };
    int qtd = 1;

    for(int i=0; i<qtd; i++){
        for(int j=i+1; j<qtd; j++){
            if(matrix[i][0] > matrix[j][0]){
                int aux1 = matrix[i][0];
                int aux2 = matrix[i][1];
                matrix[i][0] = matrix[j][0];
                matrix[i][1] = matrix[j][1];
                matrix[j][0] = aux1;
                matrix[j][1] = aux2;
            }
        }
    }

    int cont=qtd;
    int line = 0;
    for(int i=1; i<qtd; i++){
        if(matrix[line][1] < matrix[i][0]){
            cont--;
        }
        if(matrix[line][1] >= matrix[i][0]){
            line = i;
        }
    }
    printf("%d", cont);

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/*
    Esse algoritmo serve para ordenar uma palavra escrita
    pelo usuário de A-Z
*/

//Faço o meu alfabeto
void buildAlfabeto(char *alfabeto){
    int cont=0;
    for(int i=97; i<=122; i++){
        *(alfabeto + cont) = i;
        cont++;
    }
}

void main()
{
    char *alfabeto = malloc(26 * sizeof(char));
    char palavra[100];
    buildAlfabeto(alfabeto);

    printf("Informe uma palavra:...");
    fgets(palavra, 100, stdin);

    //Aqui faço uma validação que percorre para não haver letras repetidas
    int cont=0;
    char letrasExistentesNaPalvra[cont];
    for(int i=0; i<strlen(palavra); i++){
        bool exist = false;
        for(int z=0; z<26; z++){
            if(palavra[i] == *(alfabeto + z)){
                for(int j=0; j<cont; j++){
                    if(tolower(palavra[i]) == letrasExistentesNaPalvra[j])
                        exist = true;
                }
                if(!exist)
                    letrasExistentesNaPalvra[cont++] = tolower(palavra[i]);
            }
        }
    }

    //Ordeno meu vetor para saber a posição que devo colocar na sequência
    for(int i=0; i<cont; i++){
        for(int j=i+1; j<cont; j++){
            if(letrasExistentesNaPalvra[i] > letrasExistentesNaPalvra[j]){
                char letra = letrasExistentesNaPalvra[j];
                letrasExistentesNaPalvra[j] = letrasExistentesNaPalvra[i];
                letrasExistentesNaPalvra[i] = letra;
            }
        }
    }

    //Aqui eu monto a palavra ordenada de A-Z
    char palavraOrdenada[100];
    int existLetraIgual = 0;
    for(int i=0; i<cont; i++){
        for(int j=0; j<strlen(palavra); j++){
            if(tolower(palavra[j]) == letrasExistentesNaPalvra[i]){
                for(int n=0; n<strlen(palavraOrdenada); n++){
                    if(tolower(palavra[j]) == palavraOrdenada[n])
                        existLetraIgual++;
                }
                palavraOrdenada[i+existLetraIgual] = letrasExistentesNaPalvra[i];
            }
        }
    }

    printf("%s", palavraOrdenada);


}


#include <stdio.h>
#include <time.h>

// Desafio Xadrez - Nível Novato - Movimentação de Peças

/*
    Curso ADS - Introdução à Programação de Computadores
    Tema 3 - Movimentação de Peças de Xadrez
    Exercício: Desafio Nível Novato - Movimentando as Peças do xadrez
    Data: 21 de Março de 2025
    Aluno: Ednilson Graciano dos Santos
    Matrícula: 202503249997 
    Versão: 0.1.0v
*/

int main() {

    int i;
        
    printf("### Bem-vindo ao jogo de xadrez! ###\n\n");
    printf("Movimentando as peças Torre, Bispo, Rainha\n \n");
    
    printf("Movimentando a Torre 5 casas na horizontal à direita\n");
    // Movimento da Torre (5 casas para a direita) usando for
    for (i = 1; i <= 5; i++) { // Inicialização, condição e incremento
        printf("Torre: %d Direita\n", i);
    }

    printf("\n");

    printf("Movimentando o Bispo 5 casa na diagonal para cima e à direita\n");
    // Movimento do Bispo (5 casas na diagonal para cima e à direita) usando while
    i = 1; // Inicialização, resetando o contador
    while (i <= 5){ // Condição, enquanto i for menor ou igual a 5
        printf("Bispo: %d Cima e à direita\n", i);
        i++; // Incremento, incrementando o contador em 1
    }

    printf("\n");

    printf("Movimentando a Rainha 8 casa na horizontal para à esquerda\n");
    // Movimento da Rainha (8 casas para a esquerda) usando do-while
    i = 1;
    do { // Inicialização, executa pelo menos uma vez
        printf("Rainha: %d Esquerda\n", i);
        i++; 
    } while (i <= 8); // Condição, enquanto i for menor ou igual a 8

    printf("\n");
    printf("### Fim do jogo de xadrez! ###\n");
    return 0;
}
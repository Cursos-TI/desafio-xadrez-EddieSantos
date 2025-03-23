#include <stdio.h>

// Desafio Xadrez - Movimentação de Peças

/*
    Curso ADS - Introdução à Programação de Computadores
    Tema 3 - Movimentação de Peças de Xadrez
    Exercício: Desafio Nível Aventureiro - Movimentando a Peça Cavalo do xadrez
    Data: 23 de Março de 2025
    Aluno: Ednilson Graciano dos Santos
    Matrícula: 202503249997 
    Versão: 0.2.0v
*/

void regrasmovimentacao() {
    printf("\nRegras de movimentação do Xadrez para cada peça:\n\n");
    
    printf("* Peão:\n");
    printf("  - Move-se para frente, uma casa de cada vez\n");
    printf("  - No primeiro movimento, pode mover-se duas casas\n");
    printf("  - Não pode mover-se para a frente se houver outra peça na frente\n");
    printf("  - Captura na diagonal, lateralmente ao seu avanço\n");
    printf("  - Quando um peão chega à última fileira do tabuleiro, ele deve ser promovido a outra peça (geralmente rainha)\n");
    printf("  - O peão não pode mover-se para trás\n");
    printf("  - São 8 peças brancas e 8 peças pretas no tabuleiro\n\n");
    
    printf("* Torre:\n");
    printf("  - Move-se na horizontal e vertical, não pode pular outra peça\n");
    printf("  - São 2 peças brancas e 2 peças pretas no tabuleiro\n\n");
    
    printf("* Bispo:\n");
    printf("  - Move-se nas diagonais, não pode pular outra peça\n");
    printf("  - São 2 peças brancas e 2 peças pretas no tabuleiro\n\n");
    
    printf("* Cavalo:\n");
    printf("  - Move-se em um formato de 'L'\n");
    printf("  - Anda duas casas em qualquer direção e depois mais uma em sentido perpendicular\n");
    printf("  - Pode saltar sobre outras peças\n");
    printf("  - São 2 peças brancas e 2 peças pretas no tabuleiro\n\n");
    
    printf("* Dama (Rainha):\n");
    printf("  - É a peça mais poderosa, movendo-se em todas as direções\n");
    printf("  - Pode mover-se na horizontal, vertical e diagonal\n");
    printf("  - São 1 peça branca e 1 peça preta no tabuleiro\n\n");
    
    printf("* Rei:\n");
    printf("  - É a peça mais importante do tabuleiro\n");
    printf("  - Pode mover-se em qualquer direção, mas apenas uma casa por vez\n");
    printf("  - Não pode mover-se para uma posição que o coloque em xeque\n");
    printf("  - São 1 peça branca e 1 peça preta no tabuleiro\n\n");
    
    printf("** Regras adicionais:\n");
    printf("  - As peças não podem mover-se através de outras peças, exceto o cavalo.\n");
    printf("  - Também não podem avançar para uma casa ocupada por uma das suas próprias peças.\n");
    printf("  - Se um rei está em xeque, ele deve ser movido para evitar o xeque.\n");
    printf("  - Xeque-mate ocorre quando o rei está em xeque e não há movimento que o tire do xeque, encerrando o jogo.\n");
}

void regrastabuleiro() {
    printf("O tabuleiro de xadrez é composto por 64 casas alternadamente coloridas em preto e branco.\n");
    printf("Cada jogador começa com 16 peças, sendo 8 peças brancas e 8 peças pretas.\n");
    printf("As peças são posicionadas nas primeiras duas fileiras do tabuleiro, com as peças brancas nas fileiras inferiores e as peças pretas nas fileiras superiores.\n");
    printf("O objetivo do jogo é capturar a peça adversária ou colocar o rei adversário em xeque-mate, o que encerra o jogo.\n\n");

    printf("Representação do tabuleiro:\n");
    printf("\033[4m"); // Sublinhado 

    printf("  | A | B | C | D | E | F | G | H |\n");
    printf("8 | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ |\n");
    printf("7 | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ |\n");
    printf("6 | . | . | . | . | . | . | . | . |\n");
    printf("5 | . | . | . | . | . | . | . | . |\n");
    printf("4 | . | . | . | . | . | . | . | . |\n");
    printf("3 | . | . | . | . | . | . | . | . |\n");
    printf("2 | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ |\n");
    printf("1 | ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ |\n");

    printf("\033[0m"); // Retira o sublinhado

}

int main() {
    int i, move, direcao, continuar, regras ;

    printf("### Bem-vindo ao jogo de xadrez! ###\n");

    do { // Menu de opções inicio do programa
        printf("\nDeseja ver as regras do jogo de xadrez ou continuar?\n");
        printf("1 - Regras\n");
        printf("2 - Continuar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &continuar);
        while (continuar != 1 && continuar != 2) // Validação de entrada, verifica se o usuário digitou uma opção válida
        {
            printf("\nOpção inválida. Por favor, escolha 1 ou 2: ");
            scanf("%d", &continuar);
        }  
        // Se o usuário escolher 1, o programa exibe as regras do jogo de xadrez.
        if (continuar == 1) {
            printf("\nQual Regra deseja ver!\n");
            printf("1 - Regras do Tabuleiro?\n");
            printf("2 - Regras de Movimentação das Peças?\n");
            printf("Escolha uma opção: ");
            scanf("%d", &regras);
            if (regras == 1) {
                regrastabuleiro();
            } else  if (regras == 2) {
                regrasmovimentacao();
            } else {
                printf("\nOpção inválida. Por favor, escolha 1 ou 2.\n");
            }            
        }
    } while (continuar == 1); // Se escolher 2 volta para o menu de opções
    
    printf("\nOk, vamos começar!\n");

    // Aqui o programa simula o movimento de peças de xadrez Nível Novato.
    printf("\nMovimentando as peças Torre, Bispo, Rainha\n");
    
    printf("\nMovimentando a Torre 5 casas à direita\n");
    // Movimento da Torre (5 casas para a direita) usando for
    for (i = 1; i <= 5; i++) { // Inicialização, condição e incremento
        printf("Torre: %d Direita\n", i);
    }

    printf("\nMovimentando o Bispo 5 casa na diagonal para cima e à direita\n");
    // Movimento do Bispo (5 casas na diagonal para cima e à direita) usando while
    i = 1; // Inicialização, resetando o contador
    while (i <= 5){ // Condição, enquanto i for menor ou igual a 5
        printf("Bispo: %d Cima e à direita\n", i);
        i++; // Incremento, incrementando o contador em 1
    }

    printf("\nMovimentando a Rainha 8 casa na horizontal para a esquerda\n");
    // Movimento da Rainha (8 casas para a esquerda) usando do-while
    i = 1;
    do { // Inicialização, executa pelo menos uma vez
        printf("Rainha: %d Esquerda\n", i);
        i++; 
    } while (i <= 8); // Condição, enquanto i for menor ou igual a 8
 
    // Aqui o programa simula o movimento de peças de xadrez Nível Aventureiro.
    printf("\nMovimentando o Cavalo em L\n"); 
    printf("Qual direção você deseja mover o cavalo?\n"); // O cavalo se move em L em 8 direções diferentes
    printf("1 - Para Cima e para Direita\n");
    printf("2 - Para Cima e para Esquerda\n");
    printf("3 - Para Baixo e para Direita\n");
    printf("4 - Para Baixo e para Esquerda\n");
    printf("5 - Para Direita e para Baixo\n");
    printf("6 - Para Direita e para Cima\n");
    printf("7 - Para Esquerda e para Baixo\n");
    printf("8 - Para Esquerda e para Cima\n");
    printf("9 - Regras de Movimentação\n");
    printf("10 - Sair\n");
    printf("\nDigite o número da opção desejada: ");
    scanf("%d", &direcao);

    while (direcao != 10) //  O programa deve continuar executando até que o usuário digite 10
    {
        switch (direcao)
        {
        case 1:
            move = 1;
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            { 
                printf("\nMovendo o cavalo para cima e para a direita\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Cima\n"); // Movimento do cavalo para cima duas vezes
                }
                printf("Cavalo: Para Direita\n"); //  Movimento do cavalo para a direita uma ves               
            }
            break;
        case 2:
            move = 1;
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            { 
                printf("\nMovendo o cavalo para cima e para a esquerda\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Cima\n"); // Movimento do cavalo para cima duas vezes
                }
                printf("Cavalo: Para Esquerda\n"); //  Movimento do cavalo para a esquerda uma vez
            }
            break;
        case 3:
            move = 1;
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            { 
                printf("\nMovendo o cavalo para baixo e para a direita\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Baixo\n"); // Movimento do cavalo para baixo duas vezes
                }
                printf("Cavalo: Para Direita\n"); //  Movimento do cavalo para a direita uma vez
            }
            break;
        case 4:
            move = 1;
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            {
                printf("\nMovendo o cavalo para baixo e para a esquerda\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Baixo\n"); // Movimento do cavalo para baixo duas vezes
                }
                printf("Cavalo: Para Esquerda\n"); //  Movimento do cavalo para a esquerda uma vez
            }
            break;
        case 5:
            move = 1; 
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            {
                printf("\nMovendo o cavalo para a direita e para baixo\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Direita\n"); // Movimento do cavalo para a direita duas vezes
                }
                printf("Cavalo: Para Baixo\n"); //  Movimento do cavalo para baixo uma vez
            }
            break;
        case 6:
            move = 1; 
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            {
                printf("\nMovendo o cavalo para a direita e para cima\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Direita\n"); // Movimento do cavalo para a direita duas vezes
                }
                printf("Cavalo: Para Cima\n"); //  Movimento do cavalo para cima uma vez
            }
            break;
        case 7:
            move = 1;
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            {             
                printf("\nMovendo o cavalo para a esquerda e para baixo\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Esquerda\n"); // Movimento do cavalo para a esquerda duas vezes
                }
                printf("Cavalo: Para Baixo\n"); // Movimento do cavalo para baixo uma vez
            }
            break;
        case 8:
            move = 1; 
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            {                 
                printf("\nMovendo o cavalo para a esquerda e para cima\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Esquerda\n"); // Movimento do cavalo para a esquerda duas vezes
                }
                printf("Cavalo: Para Cima\n"); // Movimento do cavalo para cima uma vez
            }
            break;
        case 9:
            regrasmovimentacao();
            break;
        case 10:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpção inválida. Tente novamente.\n");
        }
        printf("\nDigite o número da opção desejada: ");
        scanf("%d", &direcao);
    }
    
    printf("\n");

    printf("### Fim do jogo de xadrez! Até a próxima etapa... ###\n");

    return 0;
}
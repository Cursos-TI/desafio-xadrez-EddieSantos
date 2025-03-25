#include <stdio.h>

// Desafio Nível Mestre - Criando Movimentos Complexos

/*
    Curso ADS - Introdução à Programação de Computadores
    Tema 3 - Movimentação de Peças de Xadrez
    Exercício: Desafio Nível Mestre - Criando Movimentos Complexos
    Data: 24 de Março de 2025
    Aluno: Ednilson Graciano dos Santos
    Matrícula: 202503249997 
    Versão: 0.3.1v
*/
// Só uma observação as movimentações são feitas com o limite maximo de 8 casa do tabuleiro no caso não esta sendo conciderado os obstaculos 
// Declarando as funções
void regrastabuleiro();
void regrasmovimentacao();
void recursivarPeao(int casas);
void recursivarTorre(int casas, int direcao);
void recursivarBispo(int casas, int direcao);
void moveCavalo(int direcao, int move);
void recursivarRainha(int casas, int direcao);
void recursivarRei(int casas, int direcao);

// Declarando os menus
void MenuPrincipal();
void MenuRegras();
void MenuMovimentacao();
void movimentarPeca(int mover);

int main() {
    int continuar;

    printf("### Bem-vindo ao jogo de xadrez! ###\n");
    do {
        // Inicia com o menu principal
        MenuPrincipal(); // Chama a função MenuPrincipal() para mostrar o menu principal
        scanf("%d", &continuar);
        while (continuar < 1 || continuar > 3) {
            printf("\nOpção inválida. Por favor, escolha 1, 2 ou 3: ");
            scanf("%d", &continuar);
        }
        // switch para escolher a opção do menu principal
        switch (continuar) {
            case 1:
                MenuRegras(); // Chama a função MenuRegras() para mostrar as regras do jogo
                break;
            case 2:
                printf("\nOk, vamos iniciar uma partida!\n");
                MenuMovimentacao(); // Chama a função MenuMovimentacao() para mostrar qual peça movimentar
                break;
            case 3:
                printf("### Fim do jogo de xadrez! Até a próxima. ###\n");
                break;
        }
    } while (continuar != 3);

    return 0;
}
void MenuPrincipal() { // Menu principal do jogo
    printf("\nDeseja ver as regras do jogo de xadrez ou iniciar partida?\n");
    printf("1 - Regras\n");
    printf("2 - Iniciar Partida\n");
    printf("3 - Sair\n");
    printf("Escolha uma opção: ");
}

void MenuRegras() { // Menu de regras do jogo
    int regras;
    printf("\nQual regra deseja ver?\n");
    printf("1 - Regras do Tabuleiro\n");
    printf("2 - Regras de Movimentação das Peças\n");
    printf("Escolha uma opção: ");
    scanf("%d", &regras);

    if (regras == 1) {
        regrastabuleiro();
    } else if (regras == 2) {
        regrasmovimentacao();
    } else {
        printf("\nOpção inválida. Escolha 1 ou 2.\n");
    }
}

void MenuMovimentacao() { // Menu para escolher qual peça mover
    int mover;
    do {
        printf("\nEscolha qual peça deseja mover.\n");
        printf("1 - Peão\n");
        printf("2 - Torre\n");
        printf("3 - Bispo\n");
        printf("4 - Cavalo\n");
        printf("5 - Rainha\n");
        printf("6 - Rei\n");
        printf("7 - Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &mover);

        if (mover >= 1 && mover <= 6) {
            movimentarPeca(mover);
        } else if (mover != 7) {
            printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (mover != 7);
}

void movimentarPeca(int mover) { // Função para movimentar a peça escolhida pelo usuário
    int casas, direcao;
    switch (mover) {
        case 1: // Aqui acontece a escolha de mover peão
            printf("\nVocê escolheu mover o Peão!\n");
            // Aqui é o menu de movimentação do peão em que o usuário escolhe a direção e quantas casas quer mover
            printf("Digite quantas casas deseja mover (1 ou 2 se for o primeiro movimento): ");
            scanf("%d", &casas);

            // Validação de entrada, verifica se o usuário digitou uma opção válida
            while (casas < 1 || casas > 2) {
                printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                printf("Digite quantas casas deseja mover 1 ou (2 se for o primeiro movimento): ");
                scanf("%d", &casas);
            }
            printf("\nMovendo o Peão...\n");
            recursivarPeao(casas);                
            break;
        case 2: // Aqui acontece a escolha de mover torre
            // Aqui é o menu de movimentação da torre em que o usuário escolhe a direção e quantas casas quer mover
            printf("\nVocê escolheu mover a Torre!\n");      
            printf("1 - Para Cima\n");
            printf("2 - Para Baixo\n");
            printf("3 - Para Esquerda\n");
            printf("4 - Para Direita\n");
            printf("Digite a direção que deseja mover: ");
            scanf("%d", &direcao);

            // Validação de entrada verifica se o usuário digitou uma opção válida
            while (direcao < 1  || direcao > 4)
            {
                printf("\nOpção inválida. Por favor, escolha 1 a 4: ");
                scanf("%d", &direcao);
            }
            
            // Aqui solicita ao usuário quantas casas deseja mover
            printf("\nQuantas casas (1 a 8) que deseja mover: ");
            scanf("%d", &casas);
            while (casas < 1 || casas > 8){
                printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                printf("\nQuantas casas (1 a 8) que deseja mover: ");
                scanf("%d", &casas);
            }

            // Aqui chama a função recursiva para mover a torre
            printf("\nMovendo a Torre...\n");
            recursivarTorre(casas, direcao);
            break;                
        case 3: // Aqui acontece a escolha de mover bispo
            // Aqui é o menu de movimentação do bispo em que o usuário escolhe a direção e quantas casas quer mover perpendicular
            printf("\nVocê escolheu mover o Bispo!\n");
            printf("1 - Para Diagonal Superior à Direita\n");
            printf("2 - Para Diagonal Superior à Esquerda\n");
            printf("3 - Para Diagonal Inferior à Direita\n");
            printf("4 - Para Diagonal Inferior à Esquerda\n");
            printf("Digite a direção que deseja mover: ");
            scanf("%d", &direcao);

            // Validação de entrada verifica se o usuário digitou uma opção válida
            while (direcao < 1  || direcao > 4)
            {
                printf("\nOpção inválida. Por favor, escolha 1 a 4: ");
                scanf("%d", &direcao);
            }

            // Aqui solicita ao usuário quantas casas deseja mover
            printf("\nQuantas casas (1 a 8) que deseja mover: ");
            scanf("%d", &casas);

            // Validação de entrada verifica se o usuário digitou uma opção válida
            while (casas < 1 || casas > 8){
                printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                printf("\nQuantas casas (1 a 8) que deseja mover: ");
                scanf("%d", &casas);
            }
            // Aqui chama a função recursiva para mover o bispo
            printf("\nMovendo o Bispo...\n");
            recursivarBispo(casas, direcao);
            break;
        case 4: // Aqui acontece a escolha de mover cavalo
            do {
                printf("\nVocê escolheu mover o Cavalo!\n");
                // Aqui é o menu de movimentação do cavalo em que o usuário escolhe a direção e quantas casas quer mover
                printf("1 - Para Cima e para Direita\n");
                printf("2 - Para Cima e para Esquerda\n");
                printf("3 - Para Baixo e para Direita\n");
                printf("4 - Para Baixo e para Esquerda\n");
                printf("5 - Para Direita e para Baixo\n");
                printf("6 - Para Direita e para Cima\n");
                printf("7 - Para Esquerda e para Baixo\n");
                printf("8 - Para Esquerda e para Cima\n");
                printf("9 - Regras de Movimentação\n");
                printf("10 - Voltar ao Menu Principal\n");
                printf("Digite o número da opção desejada: "); // O cavalo se move em L em 8 direções diferentes da possição atual caso esteja no centro do tabuleiro
                scanf("%d", &direcao);
                
                if (direcao >=1 && direcao <= 8) {
                    printf("\nMovendo o Cavalo..."); 
                    moveCavalo(direcao, 1);
                    break; // move o cavalo e sai do loop voltando para o menu principal
                } else if (direcao == 9) {
                    regrasmovimentacao();
                } else if (direcao != 10) {   
                    printf("\nOpção inválida. Tente novamente.\n");
                }
            } while (direcao != 10);
            break; // Se o usuário escolher 10 voltar ao menu principal, o loop é interrompido e o programa retorna ao menu principal
        case 5: // Aqui acontece a escolha de mover rainha
            printf("\nVocê escolheu mover a Rainha!\n");
            // Aqui é o menu de movimentação da rainha em que o usuário escolhe a direção e quantas casas quer mover
            printf("1 - Para Cima\n");
            printf("2 - Para Baixo\n");
            printf("3 - Para Esquerda\n");
            printf("4 - Para Direita\n");
            printf("5 - Para Diagonal Superior à Direita\n");
            printf("6 - Para Diagonal Superior à Esquerda\n");
            printf("7 - Para Diagonal Inferior à Direita\n");
            printf("8 - Para Diagonal Inferior à Esquerda\n");
            printf("Digite a direção que deseja mover: ");
            scanf("%d", &direcao);

            // Validação de entrada verifica se o usuário digitou uma opção válida
            while (direcao < 1  || direcao > 8)
            {
                printf("\nOpção inválida. Por favor, escolha 1 a 8: ");
                scanf("%d", &direcao);
            }
            // Aqui solicita ao usuário quantas casas deseja mover
            printf("\nQuantas casas (1 a 8) que deseja mover: ");
            scanf("%d", &casas);
            // Validação de entrada verifica se o usuário digitou uma opção válida
            while (casas < 1 || casas > 8){
                printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                printf("\nQuantas casas (1 a 8) que deseja mover: ");
                scanf("%d", &casas);
            }
            // Aqui chama a função recursiva para mover a rainha
            printf("\nMovendo a Rainha...\n");
            recursivarRainha(casas, direcao);
            break;
        case 6: // Aqui acontece a escolha de mover rei
            // Aqui é o menu de movimentação do rei em que o usuário escolhe a direção e quantas casas quer mover
            printf("\nVocê escolheu mover o Rei!\n");
            printf("1 - Para Cima\n");
            printf("2 - Para Baixo\n");
            printf("3 - Para Esquerda\n");
            printf("4 - Para Direita\n");
            printf("5 - Para Diagonal Superior à Direita\n");
            printf("6 - Para Diagonal Superior à Esquerda\n");
            printf("7 - Para Diagonal Inferior à Direita\n");
            printf("8 - Para Diagonal Inferior à Esquerda\n");
            printf("Digite a direção que deseja mover: ");
            scanf("%d", &direcao);
            // Validação de entrada verifica se o usuário digitou uma opção válida
            while (direcao < 1  || direcao > 8)
            {
                printf("\nOpção inválida. Por favor, escolha 1, 2, 3, 4, 5, 6, 7 ou 8: ");
                scanf("%d", &direcao);
            }
            // Aqui o Rei só pode mover 1 casa por vez não precisa solicitar ao usuário quantas casas quer mover
            printf("Quantas casas (1 a 1): ");
            scanf("%d", &casas);
            while (casas != 1) {
                printf("\nOpção inválida. O Rei só pode mover 1 casa por vez. Digite 1: ");
                scanf("%d", &casas);
            }
            printf("\nMovendo o Rei...\n");
            recursivarRei(casas, direcao);
            break;
        case 7: // Aqui acontece a escolha de voltar ao menu anterior
            printf("\nVoltando ao Menu Principal!\n");
            break;
        default: // Caso o usuário digite uma opção inválida
            printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
            break;
    }
}

void regrastabuleiro() { // Aqui é a função que mostra as regras do jogo de xadrez
    printf("\nO tabuleiro de xadrez é composto por 64 casas alternadamente coloridas em preto e branco.\n");
    printf("Cada jogador começa com 16 peças, sendo 8 peças brancas e 8 peças pretas.\n");
    printf("As peças são posicionadas nas primeiras duas fileiras do tabuleiro, com as peças brancas nas fileiras inferiores e as peças pretas nas fileiras superiores.\n");
    printf("O objetivo do jogo é capturar a peça adversária ou colocar o rei adversário em xeque-mate, o que encerra o jogo.\n\n");

    printf("Representação do tabuleiro:\n");
    printf("\033[4m"); // Sublinhado 

    printf("  | A | B | C | D | E | F | G | H |\n");
    printf("1 | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ |\n");
    printf("2 | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ | ♟ |\n");
    printf("3 | . | . | . | . | . | . | . | . |\n");
    printf("4 | . | . | . | . | . | . | . | . |\n");
    printf("5 | . | . | . | . | . | . | . | . |\n");
    printf("6 | . | . | . | . | . | . | . | . |\n");
    printf("7 | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ |\n");
    printf("8 | ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ |\n");

    printf("\033[0m"); // Retira o sublinhado

}
    
void regrasmovimentacao() { // Aqui é a função que mostra as regras de movimentação do jogo de xadrez
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
    

void recursivarPeao(int casas) { // Aqui é a função que mostra as regras de movimentação do peão
    if (casas > 0){ // Aqui a condição de parada quando casasPeao chegar a 0, a função para
        printf("Peão: Para Frente\n"); // movesse somente uma casa para frente
        recursivarPeao(casas - 1); // Aqui usei uma recursividade para mover o peão reduzindo as casas e repetindo o processo até chegar em 0
    }
}

void recursivarTorre(int casas, int direcao) { // Aqui é a função que mostra as regras de movimentação da torre
    if (casas > 0){ // Aqui a condição de parada quando casasTorre chegar a 0, a função para
        switch (direcao) // Aqui usei uma estrutura de decisão para mostrar a direção da torre escolhida
        {
        case 1:
            printf("Torre: Para Cima\n");
            break;
        case 2:
            printf("Torre: Para Baixo\n");
            break;
        case 3:
            printf("Torre: Para Esquerda\n");
            break;
        case 4:
            printf("Torre: Para Direita\n");
            break;  
        }
        recursivarTorre(casas - 1, direcao); // Aqui usei uma recursividade para mover a torre reduzindo as casas e repetindo o processo até chegar em 0 e a direção
    }    
}

void recursivarBispo(int casas, int direcao) { // Aqui é a função que mostra as regras de movimentação do bispo
    if (casas > 0){ // Aqui a condição de parada quando casasBispo chegar a 0, a função para
        switch (direcao) // Aqui usei uma estrutura de decisão para mostrar a direção do bispo escolhido
        {
        case 1:
            printf("Bispo: Para Diagonal Superior à Direita\n"); // movesse perpendicularmente para cima na diagonal direita
            break;
        case 2:
            printf("Bispo: Para Diagonal Superior à Esquerda\n"); // movesse perpendicularmente para cima na diagonal esquerda
            break;
        case 3:
            printf("Bispo: Para Diagonal Inferior à Direita\n"); // movesse perpendicularmente para diagonal inferior à direita
            break;
        case 4:
            printf("Bispo: Para Diagonal Inferior à Esquerda\n"); // movesse perpendicularmente para diagonal inferior à esquerda
            break;
        }
        recursivarBispo(casas - 1, direcao); // Aqui usei uma recursividade para mover o bispo reduzindo as casas e repetindo o processo até chegar em 0
    }
}

void moveCavalo(int direcao, int move) { // Aqui é a função que mostra as regras de movimentação do cavalo
    move = 1;
    switch (direcao) // Aqui usei uma estrutura de decisão para mostrar a direção do cavalo escolhido
    {
        case 1:
            move = 1;
            while (move--) // O cavalo pode executar o movimento apenas uma vez
            { 
                printf("\nMovendo o cavalo para cima e para a direita em (L)\n");
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
                printf("\nMovendo o cavalo para cima e para a esquerda em (L)\n");
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
                printf("\nMovendo o cavalo para baixo e para a direita em (L)\n");
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
                printf("\nMovendo o cavalo para baixo e para a esquerda em (L)\n");
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
                printf("\nMovendo o cavalo para a direita e para baixo em (L)\n");
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
                printf("\nMovendo o cavalo para a direita e para cima em (L)\n");
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
                printf("\nMovendo o cavalo para a esquerda e para baixo em (L)\n");
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
                printf("\nMovendo o cavalo para a esquerda e para cima em (L)\n");
                for (int i = 0; i < 2; i++)
                {
                    printf("Cavalo: Para Esquerda\n"); // Movimento do cavalo para a esquerda duas vezes
                }
                printf("Cavalo: Para Cima\n"); // Movimento do cavalo para cima uma vez
            }
            break;
    }
}

void recursivarRainha(int casas, int direcao) { /// Aqui criei uma função recursiva para mostrar a movimentação da rainha
    if (casas > 0){ // Aqui a condição de parada quando casasRainha chegar a 0, a função para
        switch (direcao) // Aqui usei uma estrutura de decisão para mostrar a direção da rainha escolhida em 8 direções
        {
            case 1:
                printf("Rainha: Para Cima\n"); // movesse horizontalmente
                break;
            case 2:
                printf("Rainha: Para Baixo\n"); // movesse horizontalmente
                break;
            case 3:
                printf("Rainha: Para Esquerda\n"); // movesse verticalmente
                break;
            case 4:
                printf("Rainha: Para Direita\n"); // movesse verticalmente
                break;
            case 5:
                printf("Rainha: Para Diagonal Superior e à Direita\n"); // movesse perpendicularmente para diagonal superior à direita
                break;
            case 6:
                printf("Rainha: Para Diagonal Superior e à Esquerda\n"); // movesse perpendicularmente para diagonal superior à esquerda
                break;
            case 7:
                printf("Rainha: Para Diagonal Inferior e à Direita\n"); // movesse perpendicularmente para diagonal inferior à direita
                break;
            case 8:
                printf("Rainha: Para Diagonal Inferior e à Esquerda\n"); // movesse perpendicularmente para diagonal inferior à esquerda
                break;
        }
        recursivarRainha(casas - 1, direcao); // Aqui usei uma recursividade para mover a rainha reduzindo as casas e repetindo o processo até chegar em 0 e a direção
    }
}

void recursivarRei(int casas, int direcao) { // Aqui criei uma função recursiva para mostrar a movimentação do rei
    if (casas > 0){ // Aqui a condição de parada quando casasRei chegar a 0, a função para
        switch (direcao) // Aqui usei uma estrutura de decisão para mostrar a direção do rei escolhido em 8 direções uma casa por vez
        {
            case 1:
                printf("Rei: Para Cima\n"); // movesse horizontalmente
                break;
            case 2:
                printf("Rei: Para Baixo\n"); // movesse horizontalmente
                break;
            case 3:
                printf("Rei: Para Esquerda\n"); // movesse verticalmente
                break;
            case 4:
                printf("Rei: Para Direita\n"); // movesse verticalmente
                break;
            case 5:
                printf("Rei: Para Diagonal Superior à Direita\n"); // movesse perpendicularmente para cima na diagonal direita
                break;
            case 6:
                printf("Rei: Para Diagonal Superior à Esquerda\n"); // movesse perpendicularmente para cima na diagonal esquerda
                break;
            case 7:
                printf("Rei: Para Diagonal Inferior à Direita\n"); // movesse perpendicularmente para diagonal inferior à direita
                break;
            case 8:
                printf("Rei: Para Diagonal Inferior à Esquerda\n"); // movesse perpendicularmente para diagonal inferior à esquerda
                break;
        }
        recursivarRei(casas - 1, direcao); // Aqui usei uma recursividade para mover o rei reduzindo as casas e repetindo o processo até chegar em 0 e a direção
    }
}
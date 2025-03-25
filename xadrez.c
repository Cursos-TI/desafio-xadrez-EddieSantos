#include <stdio.h>

// Desafio Nível Metre - Criando Movimentos Complexos

/*
    Curso ADS - Introdução à Programação de Computadores
    Tema 3 - Movimentação de Peças de Xadrez
    Exercício: Desafio Nível Metre - Criando Movimentos Complexos
    Data: 24 de Março de 2025
    Aluno: Ednilson Graciano dos Santos
    Matrícula: 202503249997 
    Versão: 0.3.0v
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
void recursivarPeao(int casasPeao){
    if (casasPeao > 0){ // Aqui a condição de parada quando casasPeao chegar a 0, a função para
        printf("Peão: Para Frente\n"); // movesse somente uma casa para frente
        recursivarPeao(casasPeao - 1); // Aqui usei uma recursividade para mover o peão reduzindo as casas e repetindo o processo até chegar em 0
    }
}
void recursivarBispo(int casasBispo, int direcaoBispo){ // Aqui usei duas variáveis, uma para a direção e outra para a quantidade de casas
    if (casasBispo > 0){ // Aqui a condição de parada quando casasBispo chegar a 0, a função para
        switch (direcaoBispo) // Aqui usei uma estrutura de decisão para mostrar a direção do bispo escolhido
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
        recursivarBispo(casasBispo - 1, direcaoBispo); // Aqui usei uma recursividade para mover o bispo reduzindo as casas e repetindo o processo até chegar em 0
    }
}
void recursivarTorre(int casasTorre, int direcaoTorre){ // Aqui usei duas variáveis, uma para a direção e outra para a quantidade de casas
    if (casasTorre > 0){ // Aqui a condição de parada quando casasTorre chegar a 0, a função para
        switch (direcaoTorre) // Aqui usei uma estrutura de decisão para mostrar a direção da torre escolhida
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
        recursivarTorre(casasTorre - 1, direcaoTorre); // Aqui usei uma recursividade para mover a torre reduzindo as casas e repetindo o processo até chegar em 0 e a direção
    }
    
}
void moveCavalo(int direcaoCavalo, int move){
    switch (direcaoCavalo) // Aqui usei uma estrutura de decisão para mostrar a direção do cavalo escolhido
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
    }
}
void recursivarRainha(int casasRainha, int direcaoRainha){
    if (casasRainha > 0){ // Aqui a condição de parada quando casasRainha chegar a 0, a função para
        switch (direcaoRainha) // Aqui usei uma estrutura de decisão para mostrar a direção da rainha escolhida em 8 direções
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
        recursivarRainha(casasRainha - 1, direcaoRainha); // Aqui usei uma recursividade para mover a rainha reduzindo as casas e repetindo o processo até chegar em 0 e a direção
    }
}
void recursivarRei(int casasRei, int direcaoRei){
    if (casasRei > 0){ // Aqui a condição de parada quando casasRei chegar a 0, a função para
        switch (direcaoRei) // Aqui usei uma estrutura de decisão para mostrar a direção do rei escolhido em 8 direções uma casa por vez
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
        recursivarRei(casasRei - 1, direcaoRei); // Aqui usei uma recursividade para mover o rei reduzindo as casas e repetindo o processo até chegar em 0 e a direção
    }
}

int main() {
    int i, mover, move, direcao, 
           continuar, regras,
           direcaoPeao, casasPeao,
           direcaoTorre, casasTorre,
           direcaoBispo, casasBispo,
           direcaoCavalo,
           direcaoRei, casasRei,
           direcaoRainha, casasRainha
        ;

    printf("### Bem-vindo ao jogo de xadrez! ###\n");

    do { // Menu Principal de opções inicio do programa
        printf("\nDeseja ver as regras do jogo de xadrez, ou Iniciar partida?\n");
        printf("1 - Regras\n");
        printf("2 - Iniciar Partida\n");
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
    
    printf("\nOk, vamos iniciar uma partida!\n");

    // Menu para escolhe qual peça mover
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
        while (mover < 1 || mover > 7) { // Validação de entrada, verifica se o usuário digitou uma opção válida
            printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
            printf("Escolha uma opção: ");
            scanf("%d", &mover);
        }
        switch (mover) {
            case 1: // Aqui acontece a escolha de mover peão
                printf("\nVocê escolheu mover o Peão!\n");
                // Aqui é o menu de movimentação do peão em que o usuário escolhe a direção e quantas casas quer mover
                printf("Digite quantas casas deseja mover (1 ou 2 se for o primeiro movimento): ");
                scanf("%d", &casasPeao);

                // Validação de entrada, verifica se o usuário digitou uma opção válida
                while (casasPeao < 1 || casasPeao > 2) {
                    printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                    printf("Digite quantas casas deseja mover 1 ou (2 se for o primeiro movimento): ");
                    scanf("%d", &casasPeao);
                }
                printf("\nMovendo o Peão...\n");
                recursivarPeao(casasPeao);                
                break;
            case 2: // Aqui acontece a escolha de mover torre
                // Aqui é o menu de movimentação da torre em que o usuário escolhe a direção e quantas casas quer mover
                printf("\nVocê escolheu mover a Torre!\n");      
                printf("1 - Para Cima\n");
                printf("2 - Para Baixo\n");
                printf("3 - Para Esquerda\n");
                printf("4 - Para Direita\n");
                printf("Digite a direção que deseja mover: ");
                scanf("%d", &direcaoTorre);

                 // Validação de entrada verifica se o usuário digitou uma opção válida
                while (direcaoTorre < 1  || direcaoTorre > 4)
                {
                    printf("\nOpção inválida. Por favor, escolha 1, 2, 3 ou 4: ");
                    scanf("%d", &direcaoTorre);
                }
                
                // Aqui solicita ao usuário quantas casas deseja mover
                printf("\nQuantas casas (1 a 8) que deseja mover: ");
                scanf("%d", &casasTorre);
                while (casasTorre < 1 || casasTorre > 8){
                    printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                    printf("\nQuantas casas (1 a 8) que deseja mover: ");
                    scanf("%d", &casasTorre);
                }

                // Aqui chama a função recursiva para mover a torre
                printf("\nMovendo a Torre...\n");
                recursivarTorre(casasTorre, direcaoTorre);
                break;                
            case 3: // Aqui acontece a escolha de mover bispo
                // Aqui é o menu de movimentação do bispo em que o usuário escolhe a direção e quantas casas quer mover perpendicular
                printf("\nVocê escolheu mover o Bispo!\n");
                printf("1 - Para Diagonal Superior à Direita\n");
                printf("2 - Para Diagonal Superior à Esquerda\n");
                printf("3 - Para Diagonal Inferior à Direita\n");
                printf("4 - Para Diagonal Inferior à Esquerda\n");
                printf("Digite a direção que deseja mover: ");
                scanf("%d", &direcaoBispo);

                // Validação de entrada verifica se o usuário digitou uma opção válida
                while (direcaoBispo < 1  || direcaoBispo > 4)
                {
                    printf("\nOpção inválida. Por favor, escolha 1, 2, 3 ou 4: ");
                    scanf("%d", &direcaoBispo);
                }

                // Aqui solicita ao usuário quantas casas deseja mover
                printf("\nQuantas casas (1 a 8) que deseja mover: ");
                scanf("%d", &casasBispo);

                // Validação de entrada verifica se o usuário digitou uma opção válida
                while (casasBispo < 1 || casasBispo > 8){
                    printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                    printf("\nQuantas casas (1 a 8) que deseja mover: ");
                    scanf("%d", &casasBispo);
                }
                // Aqui chama a função recursiva para mover o bispo
                printf("\nMovendo o Bispo...\n");
                recursivarBispo(casasBispo, direcaoBispo);
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
                    scanf("%d", &direcaoCavalo);
                    
                    if (direcaoCavalo >=1 && direcaoCavalo <= 8) {
                        printf("\nMovendo o Cavalo...");
                        int move = 1; 
                        moveCavalo(direcaoCavalo, move);
                        break; // move o cavalo e sai do loop voltando para o menu principal
                    } else if (direcaoCavalo == 9) {
                        regrasmovimentacao();
                    } else if (direcaoCavalo != 10) {   
                        printf("\nOpção inválida. Tente novamente.\n");
                    }
                } while (direcaoCavalo != 10);
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
                scanf("%d", &direcaoRainha);

                // Validação de entrada verifica se o usuário digitou uma opção válida
                while (direcaoRainha < 1  || direcaoRainha > 8)
                {
                    printf("\nOpção inválida. Por favor, escolha 1, 2, 3, 4, 5, 6, 7 ou 8: ");
                    scanf("%d", &direcaoRainha);
                }
                // Aqui solicita ao usuário quantas casas deseja mover
                printf("\nQuantas casas (1 a 8) que deseja mover: ");
                scanf("%d", &casasRainha);
                // Validação de entrada verifica se o usuário digitou uma opção válida
                while (casasRainha < 1 || casasRainha > 8){
                    printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                    printf("\nQuantas casas (1 a 8) que deseja mover: ");
                    scanf("%d", &casasRainha);
                }
                // Aqui chama a função recursiva para mover a rainha
                printf("\nMovendo a Rainha...\n");
                recursivarRainha(casasRainha, direcaoRainha);
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
                scanf("%d", &direcaoRei);
                // Validação de entrada verifica se o usuário digitou uma opção válida
                while (direcaoRei < 1  || direcaoRei > 8)
                {
                    printf("\nOpção inválida. Por favor, escolha 1, 2, 3, 4, 5, 6, 7 ou 8: ");
                    scanf("%d", &direcaoRei);
                }
                // Aqui o Rei só pode mover 1 casa por vez não precisa solicitar ao usuário quantas casas quer mover
                casasRei = 1;
                // Aqui chama a função recursiva para mover o rei
                printf("\nMovendo o Rei...\n");
                recursivarRei(casasRei, direcaoRei);
                break;
            case 7: // Aqui acontece a escolha de voltar ao menu anterior
                printf("\nVoltando ao Menu Principal!\n");
                return main(); // Volta para o menu principal no inicio do programa
            default: // Caso o usuário digite uma opção inválida
                printf("\nOpção inválida. Por favor, escolha uma opção válida.\n");
                break;
        }
    }   while (mover != 7); // Se escolher 7 volta para o menu inicial do jogo 
    printf("\n");

    printf("### Fim do jogo de xadrez! Até a próxima etapa... ###\n");

    return 0;
}
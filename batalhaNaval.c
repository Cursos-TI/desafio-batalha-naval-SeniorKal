#include <stdio.h>

char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Letras que representam as linhas no tabuleiro
int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Números que representam as colunas no tabuleiro
char tabuleiro[10][10]; // Matriz 10x10 que representa o tabuleiro. Usamos 'char' para armazenar símbolos como '~' (água) e 'B' (navio)
int escolha; // Variável para armazenar escolha do usuário entre navio horizontal ou vertical
int c, l, opcao = 0; // Variáveis para linha, coluna e opção do menu principal

void mostrar_tabuleiro() {
    printf("Tabuleiro de batalha naval:\n  ");
    for (int i = 0; i < 10; i++) {
        printf("%c ", linha[i]); // Imprime as letras do topo do tabuleiro
    }
    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", coluna[i]); // Imprime os números à esquerda do tabuleiro
        for (int j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]); // Imprime os símbolos de cada célula
        }
        printf("\n"); // Quebra de linha para formar o tabuleiro
    }
}


void adicionar_navio() {
    printf("Onde gostaria de posicionar o navio [1]vertical, [2]horizontal ou [3]diagonal?\n");
    scanf("%d", &escolha);

    printf("Digite a linha (0 a 9) onde deseja posicionar o navio: \n");
    scanf("%d", &l);

    printf("Digite a coluna (0 a 9) onde deseja posicionar o navio: \n");
    scanf("%d", &c);

    if (l >= 0 && l < 10 && c >= 0 && c < 10) { // Verifica se as coordenadas são válidas
        if (escolha == 1) {
            // Adiciona navio verticalmente (verifica os limites)
            if (l + 2 < 10) { // Exemplo: navio de tamanho 3
                tabuleiro[l][c] = 'B';
                tabuleiro[l + 1][c] = 'B';
                tabuleiro[l + 2][c] = 'B';
                printf("Navio adicionado verticalmente!\n");
            } else {
                printf("Não há espaço suficiente para o navio nessa posição!\n");
            }
        } else if (escolha == 2) {
            // Adiciona navio horizontalmente (verifica os limites)
            if (c + 2 < 10) { // Exemplo: navio de tamanho 3
                tabuleiro[l][c] = 'B';
                tabuleiro[l][c + 1] = 'B';
                tabuleiro[l][c + 2] = 'B';
                printf("Navio adicionado horizontalmente!\n");
            } else {
                printf("Não há espaço suficiente para o navio nessa posição!\n");
            }
        } else if (escolha == 3) {
            // Adiciona navio diagonalmente (verifica os limites)
            if (l + 2 < 10 && c + 2 < 10) { // Exemplo: navio de tamanho 3
                tabuleiro[l][c] = 'B';
                tabuleiro[l + 1][c + 1] = 'B';
                tabuleiro[l + 2][c + 2] = 'B';
                printf("Navio adicionado diagonalmente!\n");
            } else {
                printf("Não há espaço suficiente para o navio nessa posição!\n");
            }
        } else {
            printf("Opção inválida! Escolha entre [1], [2] ou [3].\n");
        }
    } else {
        printf("Coordenadas inválidas! Tente novamente.\n");
    }
}

int main() {
    // Inicializa o tabuleiro com água ('~')
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '~';
        }
    }

    printf("Batalha naval!\n");
    do {
        printf("\n[1] Mostrar tabuleiro\n");
        printf("[2] Adicionar navio\n");
        printf("[3] Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                mostrar_tabuleiro();
                break;
            case 2:
                adicionar_navio();
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}

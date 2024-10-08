#include <stdio.h>

char tabuleiro[3][3];
char jogadorAtual = 'X';

void inicializarTabuleiro()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2)
                printf("|");
        }
        if (i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n");
}

int verificarVitoria()
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == jogadorAtual && tabuleiro[i][1] == jogadorAtual && tabuleiro[i][2] == jogadorAtual)
        {
            return 1;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[0][i] == jogadorAtual && tabuleiro[1][i] == jogadorAtual && tabuleiro[2][i] == jogadorAtual)
        {
            return 1;
        }
    }
    if (tabuleiro[0][0] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][2] == jogadorAtual)
    {
        return 1;
    }
    if (tabuleiro[0][2] == jogadorAtual && tabuleiro[1][1] == jogadorAtual && tabuleiro[2][0] == jogadorAtual)
    {
        return 1;
    }
    return 0;
}

int verificarEmpate()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}

void alternarJogador()
{
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

int main()
{
    int linha, coluna;
    inicializarTabuleiro();

    while (1)
    {
        exibirTabuleiro();
        printf("Jogador %c, insira a linha e a coluna (1-3): ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;

        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ')
        {
            printf("Movimento invalido. Tente novamente.\n");
            continue;
        }

        tabuleiro[linha][coluna] = jogadorAtual;

        if (verificarVitoria())
        {
            exibirTabuleiro();
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        if (verificarEmpate())
        {
            exibirTabuleiro();
            printf("O jogo terminou em empate!\n");
            break;
        }

        alternarJogador();
    }

    return 0
}

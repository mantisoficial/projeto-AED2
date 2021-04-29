#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Rena
{
    char nome[100];
    int peso;
    int idade;
    double altura;

} Rena;

void criaHeap(Rena *vet, int i, int f)
{
    Rena aux;
    aux.peso = vet[i].peso;
    aux.idade = vet[i].idade;
    aux.altura = vet[i].altura;
    strcpy(aux.nome, vet[i].nome);

    int j = i * 2 + 1;
    while (j <= f)
    {
        if (j < f)
        {
            if (vet[j].peso < vet[j + 1].peso)
            {
                j = j + 1;
            }

            else if (vet[j].peso == vet[j + 1].peso && vet[j].idade != vet[j + 1].idade)
            {
                if (vet[j].idade > vet[j + 1].idade)
                {
                    j = j + 1;
                }
            }

            else if (vet[j].peso == vet[j + 1].peso && vet[j].idade == vet[j + 1].idade && vet[j].altura != vet[j + 1].altura)
            {
                if (vet[j].altura > vet[j + 1].altura)
                {
                    j = j + 1;
                }
            }

            else if (vet[j].peso == vet[j + 1].peso && vet[j].idade == vet[j + 1].idade && vet[j].altura == vet[j + 1].altura)
            {
                if (vet[j].nome > vet[j + 1].nome)
                {
                    j = j + 1;
                }
            }
        }

        if (aux.peso < vet[j].peso)
        {
            vet[i].peso = vet[j].peso;
            vet[i].idade = vet[j].idade;
            vet[i].altura = vet[j].altura;
            strcpy(vet[i].nome, vet[j].nome);

            i = j;
            j = 2 * i + 1;
        }

        else if (aux.peso == vet[j].peso && aux.idade > vet[j].idade)
        {
            vet[i].peso = vet[j].peso;
            vet[i].idade = vet[j].idade;
            vet[i].altura = vet[j].altura;
            strcpy(vet[i].nome, vet[j].nome);

            i = j;
            j = 2 * i + 1;
        }

        else if (aux.peso == vet[j].peso && aux.idade == vet[j].idade && aux.altura > vet[j].altura)
        {
            vet[i].peso = vet[j].peso;
            vet[i].idade = vet[j].idade;
            vet[i].altura = vet[j].altura;
            strcpy(vet[i].nome, vet[j].nome);

            i = j;
            j = 2 * i + 1;
        }

        else if (aux.peso == vet[j].peso && aux.idade == vet[j].idade && aux.altura == vet[j].altura && aux.nome > vet[j].nome)
        {
            vet[i].peso = vet[j].peso;
            vet[i].idade = vet[j].idade;
            vet[i].altura = vet[j].altura;
            strcpy(vet[i].nome, vet[j].nome);

            i = j;
            j = 2 * i + 1;
        }

        else
        {
            j = f + 1;
        }
    }
    vet[i].peso = aux.peso;
    vet[i].idade = aux.idade;
    vet[i].altura = aux.altura;
    strcpy(vet[i].nome, aux.nome);
}

void heapSort(Rena *vet, int n)
{
    Rena aux;
    int i;
    for (i = (n - 1) / 2; i >= 0; i--)
    {
        criaHeap(vet, i, n - 1);
    }

    for (i = n - 1; i >= 1; i--)
    {
        aux.peso = vet[0].peso;
        aux.idade = vet[0].idade;
        aux.altura = vet[0].altura;
        strcpy(aux.nome, vet[0].nome);

        vet[0].peso = vet[i].peso;
        vet[0].idade = vet[i].idade;
        vet[0].altura = vet[i].altura;
        strcpy(vet[0].nome, vet[i].nome);

        vet[i].peso = aux.peso;
        vet[i].idade = aux.idade;
        vet[i].altura = aux.altura;
        strcpy(vet[i].nome, aux.nome);

        criaHeap(vet, 0, i - 1);
    }
}

int main(void)
{

    int nt, cc = 1;
    scanf("%d", &nt);

    for (nt = nt; nt > 0; nt--)
    {
        int tr, trt, a, b, dif, cr = 1;
        scanf("%d %d", &tr, &trt);
        dif = tr - trt;

        Rena renas[tr];

        for (a = 0; a < tr; a++)
        {
            scanf("%s %d %d %lf", &renas[a].nome, &renas[a].peso, &renas[a].idade, &renas[a].altura);
        }

        heapSort(renas, tr);

        printf("CENARIO {%d}\n", cc);
        for (b = tr - 1; b >= dif; b--)
        {
            printf("%d - %s\n", cr, renas[b].nome);
            cr++;
        }
        cc++;
    }
}

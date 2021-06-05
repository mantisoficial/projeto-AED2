//1195 - Árvore Binária de Busca
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct node
{
    struct node *esq;
    int data;
    struct node *dir;
};
typedef struct node Node;

int tipo;

Node *AchaRaiz(Node *r, int v)
{
    if (r == NULL)
        return NULL;
    else if (v <= r->data)
        if (r->esq == NULL)
            return r;
        else
            return AchaRaiz(r->esq, v);
    else
        if (r->dir == NULL)
        return r;
    else
        return AchaRaiz(r->dir, v);
}

int ImprimeNode(Node *r)
{
    if (r != NULL)
    {
        if (tipo == 1)
        {
            printf(" %d", r->data);
            ImprimeNode(r->esq);
            ImprimeNode(r->dir);
        }
        if (tipo == 2)
        {
            ImprimeNode(r->esq);
            printf(" %d", r->data);
            ImprimeNode(r->dir);
        }
        if (tipo == 3)
        {
            ImprimeNode(r->esq);
            ImprimeNode(r->dir);
            printf(" %d", r->data);
        }
    }

    return 0;
}

int main()
{
    Node *raiz, *pai, *aux;
    int tam, n_casos, c, d, noh;

    raiz = NULL;
    scanf("%d", &n_casos);

    for (c = 1; c <= n_casos; c++)
    {
        raiz = NULL;

        scanf("%d", &tam);
        for (d = 0; d < tam; d++)
        {
            scanf("%d", &noh);

            aux = (Node *)malloc(sizeof(Node));
            aux->data = noh;
            aux->esq = NULL;
            aux->dir = NULL;

            pai = AchaRaiz(raiz, noh);
            if (pai == NULL)
                raiz = aux;
            else if (noh <= pai->data)
                pai->esq = aux;
            else
                pai->dir = aux;
        }

        printf("Case %d:", c);

        printf("\nPre.:");
        tipo = 1;
        ImprimeNode(raiz);

        printf("\nIn..:");
        tipo = 2;
        ImprimeNode(raiz);

        printf("\nPost:");
        tipo = 3;
        ImprimeNode(raiz);

        printf("\n\n");
    }

    return 0;
}

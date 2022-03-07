#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct arvore_binaria arvore_binaria;
int x;

struct arvore_binaria
{
  int valor;
  arvore_binaria *menor;
  arvore_binaria *maior;
};

arvore_binaria *prox_num(int valor, arvore_binaria *maior, arvore_binaria *menor)
{
  arvore_binaria *novo_num = (arvore_binaria *)malloc(sizeof(arvore_binaria));
  novo_num->maior = maior;
  novo_num->menor = menor;
  novo_num->valor = valor;
  return novo_num;
}

arvore_binaria *gerar_arvore(char *valor)
{
  int i = 0;
  int tam = strlen(valor);
  char provisoria[999];

  if (tam == x)
  {
    return NULL;
  }
  while (valor[x] == '(')
  {
    x = x + 1;
  }
  if (valor[x] == ')')
  {
    while (valor[x] == ')')
    {
      x = x + 1;
    }
    return NULL;
  }
  while (valor[x] >= '0' && valor[x] <= '9')
  {
    provisoria[i] = valor[x];
    i = i + 1;
    x = x + 1;
  }
  provisoria[i] = '\0';
  return prox_num(atoi(provisoria), gerar_arvore(valor), gerar_arvore(valor));
}

int analisar(arvore_binaria *arvore_binaria, int valor, int y, int *provisoria)
{
  if (arvore_binaria == NULL)
  {
    if (*provisoria != 1)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    if (arvore_binaria->valor != valor)
    {
      analisar(arvore_binaria->menor, valor, y + 1, provisoria);
      analisar(arvore_binaria->maior, valor, y + 1, provisoria);
    }
    else
    {
      printf("ESTA NA ARVORE");
      printf("\n%d", y);
      *provisoria = 1;
      return 1;
    }
  }
}

int main()
{
  int num, provisoria = 0, x = 0;
  char valor[999];

  scanf("%[^\n]", valor), scanf("%d", &num);
  arvore_binaria *z = gerar_arvore(valor);
  int a = analisar(z, num, 0, &provisoria);

  if (a == 0)
  {
    printf("NAO ESTA NA ARVORE");
    printf("\n-1");
  }
  return 0;
}
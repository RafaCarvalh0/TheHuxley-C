#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  int quantidade, quantidade_xicaras, i = 0, capsulas = 0;
  char tamanho;
  while (i < 7)
  {
    scanf("%d\n", &quantidade);
    scanf(" %c", &tamanho);
    i++;

    if (tamanho == 'P' || tamanho == 'p')
    {
      capsulas = capsulas + (quantidade * 10);
    }
    else
    {
      capsulas = capsulas + (quantidade * 16);
    }
  }
  quantidade_xicaras = (2 * capsulas / 7);
  printf("%d\n", capsulas);
  printf("%d", quantidade_xicaras);

  return 0;
}
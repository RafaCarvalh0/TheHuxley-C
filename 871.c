#include <stdio.h>

int main(void)
{
  int linha, coluna, tamlinha, tamcoluna, maior0 = 0, menor0 = 0;

  scanf("%d %d", &tamlinha, &tamcoluna);
  linha = tamlinha;
  coluna = tamcoluna;

  int matriz[linha][coluna];

  for (linha = 0; linha < tamlinha; linha++)
  {
    for (coluna = 0; coluna < tamcoluna; coluna++)
    {
      scanf("%d", &matriz[linha][coluna]);
      if (matriz[linha][coluna] > 0)
        maior0 += 1;
      else
        menor0 += 1;
    }
  }
  printf("Matriz formada:\n");
  for (linha = 0; linha < tamlinha; linha++)
  {
    for (coluna = 0; coluna < tamcoluna; coluna++)
    {
      if (coluna < tamcoluna - 1)
      {
        printf("%d ", matriz[linha][coluna]);
      }
      else
      {
        printf("%d", matriz[linha][coluna]);
      }
    }
    printf("\n");
  }

  int i = 0, j = 0, soma1 = 0, soma2 = 0, x;
  x = linha;

  if (linha == coluna)
  {
    for (i = 0; i < linha; i++)
    {
      x--;
      for (j = 0; j < coluna; j++)
      {
      }
      soma1 = soma1 + matriz[i][i];
      soma2 = soma2 + matriz[i][x];
    }
    printf("A diagonal principal e secundaria tem valor(es) %d e %d respectivamente.", soma1, soma2);
  }

  else
  {
    printf("A diagonal principal e secundaria nao pode ser obtida.");
  }

  printf("\nA matriz possui %d numero(s) menor(es) que zero.", menor0);
  printf("\nA matriz possui %d numero(s) maior(es) que zero.", maior0);

  return 0;
}
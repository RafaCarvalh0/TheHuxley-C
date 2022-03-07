#include <stdio.h>

int main(void)
{
  int votos, princesas, qtd_votos, qtd_princesas;
  int i, j;
  int total_votos;

  scanf("%d", &qtd_princesas);
  scanf("%d", &qtd_votos);
  votos = qtd_votos;
  princesas = qtd_princesas;

  int matriz[votos][princesas];

  for (i = 0; i < votos; i++)
  {
    for (j = 0; j < princesas; j++)
    {
      scanf("%d", &matriz[i][j]);
    }
  }

  for (j = 0; j < princesas; j++)
  {
    total_votos = 0;
    for (i = 0; i < votos; i++)
    {
      if (matriz[i][j] == 1)
      {
        total_votos += 1;
      }
    }
    printf("Princesa %d: %d voto(s)\n", j + 1, total_votos);
  }

  return 0;
}

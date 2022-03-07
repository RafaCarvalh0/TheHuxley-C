#include <stdio.h>

int main(void)
{
  int l, c;
  int i, j, k;
  int tamlista, variavel_condicao;

  scanf("%d", &l);
  scanf("%d", &c);
  int matriz[l][c];

  for (int i = 0; i < l; i++)
  {
    for (int j = 0; j < c; j++)
    {
      scanf("%d ", &matriz[i][j]);
    }
  }
  scanf("%d", &tamlista);
  int num[tamlista];

  for (i = 0; i < tamlista; i++)
  {
    scanf("%d", &num[i]);
  }
  for (i = 0; i < tamlista; i++)
  {
    variavel_condicao = 0;

    for (j = 0; j < l; j++)
    {
      if (num[i] <= matriz[j][c - 1])
      {
        break;
      }
    }
    for (k = 0; k < c; k++)
    {
      if (num[i] == matriz[j][k])
      {
        printf("YES WITH %d AND %d\n", j + 1, k + 1);
        variavel_condicao = 1;
      }
    }
    if (variavel_condicao == 0)
    {
      printf("NO\n");
    }
  }
  return 0;
}
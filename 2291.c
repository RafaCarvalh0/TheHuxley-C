#include <stdio.h>

int main()
{
  int m;
  float v1, v2;
  int i, j, n;
  char r, k;
  int atkRyu = 0, defRyu = 0;
  int atkKen = 0, defKen = 0;

  scanf("%d", &m), scanf("%f %f", &v1, &v2);

  int m1[m][m], m2[m][m];

  // matriz Ryu
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%d", &m1[i][j]);
      if (i == j)
      {
        atkRyu += m1[i][j];
      }
      if (i + j + 2 == m + 1)
      {
        defRyu += m1[i][j];
      }
    }
  }
  // matriz Ken
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < m; j++)
    {
      scanf("%d", &m2[i][j]);
      if (i == j)
      {
        atkKen += m2[i][j];
      }
      if (i + j + 2 == m + 1)
      {
        defKen += m2[i][j];
      }
    }
  }
  // luta
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf(" %c", &r), scanf(" %c", &k);
    if (r == 'A' && k == 'A')
    {
      if (atkRyu > atkKen)
      {
        v2 -= (float)(atkRyu - atkKen);
      }
      else
      {
        v1 -= (float)(atkKen - atkRyu);
      }
    }
    else if (r == 'A' && k == 'D')
    {
      v2 -= (float)(atkRyu - defKen) / 2;
    }
    else if (r == 'D' && k == 'A')
    {
      v1 -= (float)(atkKen - defRyu) / 2;
    }
  }
  // Resultado da luta
  if (v1 > v2)
  {
    printf("Ryu ganhou a batalha.");
  }
  else if (v1 < v2)
  {
    printf("Ken ganhou a batalha.");
  }
  else
  {
    printf("Houve empate.");
  }

  return 0;
}
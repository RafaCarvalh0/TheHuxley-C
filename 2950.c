#include <stdio.h>

int peao(int x, int y, char matriz_tabuleiro[8][8]);
int torre(int x, int y, char matriz_tabuleiro[8][8]);
int cavalo(int x, int y, char matriz_tabuleiro[8][8]);
int bispo(int x, int y, char matriz_tabuleiro[8][8]);
int rainha(int x, int y, char matriz_tabuleiro[8][8]);

void tabuleiro(char matriz_tabuleiro[8][8]);

// main
int main(void)
{
  int xeque = 0;
  char matriz_tabuleiro[8][8];

  tabuleiro(matriz_tabuleiro);

  int peca = 0;
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      // peao-------------------------------------------
      if (matriz_tabuleiro[i][j] == 'p')
      {
        peca = peca + peao(i, j, matriz_tabuleiro);
      }
      // torre-------------------------------------------
      else if (matriz_tabuleiro[i][j] == 't')
      {
        peca = peca + torre(i, j, matriz_tabuleiro);
      }
      // cavalo-------------------------------------------
      else if (matriz_tabuleiro[i][j] == 'c')
      {
        peca = peca + cavalo(i, j, matriz_tabuleiro);
      }
      // bispo-------------------------------------------
      else if (matriz_tabuleiro[i][j] == 'b')
      {
        peca = peca + bispo(i, j, matriz_tabuleiro);
      }
      // rainha-------------------------------------------
      else if (matriz_tabuleiro[i][j] == 'q')
      {
        peca = peca + rainha(i, j, matriz_tabuleiro);
      }
    }
    if (peca)
    {
      xeque = 1;
      break;
    }
  }
  if (xeque)
  {
    printf("XEQUE");
  }
  else
  {
    printf("NAO XEQUE");
  }
  return 0;
}
// matriz
void tabuleiro(char matriz_tabuleiro[8][8])
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      scanf(" %c", &matriz_tabuleiro[i][j]);
    }
  }
}
// peao
int peao(int x, int y, char matriz_tabuleiro[8][8])
{
  int movimento1 = matriz_tabuleiro[x + 1][y - 1] == 'K';
  if (movimento1)
  {
    return 1;
  }
  int movimento2 = matriz_tabuleiro[x + 1][y + 1] == 'K';
  if (movimento2)
  {
    return 1;
  }
  return 0;
}
// torre
int torre(int x, int y, char matriz_tabuleiro[8][8])
{
  for (int z = x + 1; z < 8; z++)
  {
    if (matriz_tabuleiro[z][y] != '-' && matriz_tabuleiro[z][y] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[z][y] == 'K')
    {
      return 1;
    }
  }
  for (int z = x - 1; z >= 0; z--)
  {
    if (matriz_tabuleiro[z][y] != '-' && matriz_tabuleiro[z][y] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[z][y] == 'K')
    {
      return 1;
    }
  }
  for (int z = y + 1; z < 8; z++)
  {
    if (matriz_tabuleiro[x][z] != '-' && matriz_tabuleiro[x][z] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[x][z] == 'K')
    {
      return 1;
    }
  }
  for (int z = y - 1; z >= 0; z--)
  {
    if (matriz_tabuleiro[x][z] != '-' && matriz_tabuleiro[x][z] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[x][z] == 'K')
    {
      return 1;
    }
  }
  return 0;
}
// cavalo
int cavalo(int x, int y, char matriz_tabuleiro[8][8])
{
  int movimento = x < 8 && x >= 0 && y < 8 && y >= 0;
  if (movimento && (matriz_tabuleiro[x + 2][y - 1] == 'K'))
  {
    return 1;
  }
  else if (movimento && (matriz_tabuleiro[x + 1][y - 2] == 'K'))
  {
    return 1;
  }
  else if (movimento && (matriz_tabuleiro[x - 1][y - 2] == 'K'))
  {
    return 1;
  }
  else if (movimento && (matriz_tabuleiro[x - 2][y - 1] == 'K'))
  {
    return 1;
  }
  else if (movimento && (matriz_tabuleiro[x - 2][y + 1] == 'K'))
  {
    return 1;
  }
  else if (movimento && (matriz_tabuleiro[x - 1][y + 2] == 'K'))
  {
    return 1;
  }
  else if (movimento && (matriz_tabuleiro[x + 2][y + 1] == 'K'))
  {
    return 1;
  }
  else if (movimento && (matriz_tabuleiro[x + 1][y + 2] == 'K'))
  {
    return 1;
  }
  return 0;
}
// bispo
int bispo(int x, int y, char matriz_tabuleiro[8][8])
{
  for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
  {
    if (matriz_tabuleiro[i][j] != '-' && matriz_tabuleiro[i][j] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[i][j] == 'K')
    {
      return 1;
    }
  }
  for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
  {
    if (matriz_tabuleiro[i][j] != '-' && matriz_tabuleiro[i][j] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[i][j] == 'K')
    {
      return 1;
    }
  }
  for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
  {
    if (matriz_tabuleiro[i][j] != '-' && matriz_tabuleiro[i][j] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[i][j] == 'K')
    {
      return 1;
    }
  }
  for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--)
  {
    if (matriz_tabuleiro[i][j] != '-' && matriz_tabuleiro[i][j] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[i][j] == 'K')
    {
      return 1;
    }
  }
  return 0;
}
// rainha
int rainha(int x, int y, char matriz_tabuleiro[8][8])
{
  for (int z = x + 1; z < 8; z++)
  {
    if (matriz_tabuleiro[z][y] != '-' && matriz_tabuleiro[z][y] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[z][y] == 'K')
    {
      return 1;
    }
  }
  for (int z = x - 1; z >= 0; z--)
  {
    if (matriz_tabuleiro[z][y] != '-' && matriz_tabuleiro[z][y] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[z][y] == 'K')
    {
      return 1;
    }
  }
  for (int z = y + 1; z < 8; z++)
  {
    if (matriz_tabuleiro[x][z] != '-' && matriz_tabuleiro[x][z] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[x][z] == 'K')
    {
      return 1;
    }
  }
  for (int z = y - 1; z >= 0; z--)
  {
    if (matriz_tabuleiro[x][z] != '-' && matriz_tabuleiro[x][z] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[x][z] == 'K')
    {
      return 1;
    }
  }
  for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
  {
    if (matriz_tabuleiro[i][j] != '-' && matriz_tabuleiro[i][j] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[i][j] == 'K')
    {
      return 1;
    }
  }
  for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
  {
    if (matriz_tabuleiro[i][j] != '-' && matriz_tabuleiro[i][j] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[i][j] == 'K')
    {
      return 1;
    }
  }
  for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
  {
    if (matriz_tabuleiro[i][j] != '-' && matriz_tabuleiro[i][j] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[i][j] == 'K')
    {
      return 1;
    }
  }
  for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--)
  {
    if (matriz_tabuleiro[i][j] != '-' && matriz_tabuleiro[i][j] != 'K')
    {
      break;
    }
    else if (matriz_tabuleiro[i][j] == 'K')
    {
      return 1;
    }
  }
  return 0;
}
#include <stdio.h>
int calculo(int c, int p)
{
	if (c == 0 || p == 0)
	{
		return 0;
	}
	else if (c == 1)
	{
		return p;
	}
	else
	{
		c--;
		return p + calculo(c, p);
	}
}
int main()
{
	int c, p, m;
	int resultado = 0;
	while (scanf("%d %d %d ", &c, &m, &p) != EOF)
	{
		resultado = calculo(c, p);
		resultado = (resultado - m);
		if (resultado == 0 || resultado < 0)
		{
			printf("Sim\n");
		}
		else
		{
			printf("Nao\n");
		}
	}
	return 0;
}
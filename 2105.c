#include <stdio.h>
int main(void)
{
	int i = 0, j = 0;
	int k = 0, aux;
	int obstaculo[3][3];
	int lista[9];
	while (scanf("%d", &aux) != EOF)
	{
		lista[k] = aux;
		k++;
		if (k != 9)
		{
			continue;
		}
		else
		{
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					obstaculo[i][j] = lista[i * 3 + j];
				}
			}
			float x = 0.0;
			for (i = 0; i < 3; i++)
			{
				for (j = 0; j < 3; j++)
				{
					if (obstaculo[1][0] == 0.0)
					{
						if (obstaculo[2][0] == 0.0)
						{
							if (obstaculo[2][1] == 0.0)
							{
								x = 1.0;
							}
						}
					}
				}
			}
			if (x == 1.0)
			{
				printf("Por baixo\n");
			}
			if (x == 0.0)
			{
				x = 0.0;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						if (obstaculo[0][1] == 0.0)
						{
							if (obstaculo[0][2] == 0.0)
							{
								if (obstaculo[1][2] == 0.0)
								{
									x = 1.0;
								}
							}
						}
					}
				}
				if (x == 1.0)
				{
					printf("Por cima\n");
				}
			}
			if (x == 0.0)
			{
				x = 0.0;
				for (i = 0; i < 3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						if (obstaculo[0][2] != 0.0 || obstaculo[2][0] != 0.0)
						{
							x = 1.0;
						}
					}
				}
				if (x == 1.0)
				{
					printf("Nao pode atravessar\n");
				}
			}
		}
		k = 0.0;
	}
	return 0;
}
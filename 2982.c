#include <stdio.h>

int main()
{
	float reais, centavos;
	int notas100, notas50, notas20, notas10, notas5, notas2;
	int moedas1, moedas050, moedas025, moedas010, moedas005, moedas001;

	printf("");
	scanf("%f", &reais);

	centavos = reais * 100;

	notas100 = centavos / 10000;
	centavos = centavos - notas100 * 10000;

	notas50 = centavos / 5000;
	centavos = centavos - notas50 * 5000;

	notas20 = centavos / 2000;
	centavos = centavos - notas20 * 2000;

	notas10 = centavos / 1000;
	centavos = centavos - notas10 * 1000;

	notas5 = centavos / 500;
	centavos = centavos - notas5 * 500;

	notas2 = centavos / 200;
	centavos = centavos - notas2 * 200;

	moedas1 = centavos / 100;
	centavos = centavos - moedas1 * 100;

	moedas050 = centavos / 50;
	centavos = centavos - moedas050 * 50;

	moedas025 = centavos / 25;
	centavos = centavos - moedas025 * 25;

	moedas010 = centavos / 10;
	centavos = centavos - moedas010 * 10;

	moedas005 = centavos / 5;
	centavos = centavos - moedas005 * 5;

	moedas001 = centavos;

	if (notas100 > 0)
	{
		printf("\n\n%d nota(s) de R$ 100.00", (notas100));
	}
	if (notas50 > 0)
	{
		printf("\n%d nota(s) de R$ 50.00", (notas50));
	}
	if (notas20 > 0)
	{
		printf("\n%d nota(s) de R$ 20.00", (notas20));
	}
	if (notas10 > 0)
	{
		printf("\n%d nota(s) de R$ 10.00", (notas10));
	}
	if (notas5 > 0)
	{
		printf("\n%d nota(s) de R$ 5.00", (notas5));
	}
	if (notas2 > 0)
	{
		printf("\n%d nota(s) de R$ 2.00", (notas2));
	}
	if (moedas1 > 0)
	{
		printf("\n%d moeda(s) de R$ 1.00", (moedas1));
	}
	if (moedas050 > 0)
	{
		printf("\n%d moeda(s) de R$ 0.50", (moedas050));
	}
	if (moedas025 > 0)
	{
		printf("\n%d moeda(s) de R$ 0.25", (moedas025));
	}
	if (moedas010 > 0)
	{
		printf("\n%d moeda(s) de R$ 0.10", (moedas010));
	}
	if (moedas005 > 0)
	{
		printf("\n%d moeda(s) de R$ 0.05", (moedas005));
	}
	if (moedas001 > 0)
	{
		printf("\n%d moeda(s) de R$ 0.01 \n\n", (moedas001));
	}

	return 0;
}
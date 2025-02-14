unsigned int quadrato(unsigned int num)
{
	return num * num;
}
unsigned int somma_quadrato_cifre(unsigned int num)
{
	unsigned int ris = 0;
	while (num != 0)
	{
		ris += quadrato(num % 10);
		num /= 10;
	}
	return ris;
}
int felice(unsigned int num)
{
	while (1)
	{
		if (num == 0 || num == 4)
		{
			return 0;
		}
		if (num == 1)
		{
			return 1;
		}
		num = somma_quadrato_cifre(num);
	}
}
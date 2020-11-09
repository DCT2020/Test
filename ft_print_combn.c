#include <io.h>

void ft_printf_combn(int n)
{
	char* buffer = new char[n + 1];
	buffer[n] = NULL;
	char divider[3] = ", ";

	bool bIsAble = true;
	int i = 0;
	while (i < pow(10, n + 1))
	{
		IntToString(buffer, i, n);

		bIsAble = true;
		int j = 0;
		while (j < n - 1)
		{
			if(buffer[j] >= buffer[j + 1])
				bIsAble = false;

			j++;
		}
	
		if (bIsAble)
		{
			_write(1, buffer, n);
			_write(1, divider,3);
		}

		++i;
	}
}

int pow(int value, int count)
{
	int result = 1;
	int i = 1;
	while (i < count)
	{
		result *= value;
		++i;
	}

	return result;
}

void IntToString(char* buffer,int number, int length)
{
	int spliter = pow(10, length);
	int i = 0;
	while (i < length)
	{
		buffer[i] = (number / spliter) % 10 + '0';
		spliter /= 10;
		++i;
	}
}
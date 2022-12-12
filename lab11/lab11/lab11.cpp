#include <iostream>

// быстрая сортировка

int pivot(int list[], int start, int end) // pivot - опорная точка
{
	int p = list[end];
	int pId = start;
	
	for (int i = start; i < end; i++)
	{
		if (list[i] <= p)
		{
			std::swap(list[i], list[pId]);
			pId++;
		}
	}

	std::swap(list[pId], list[end]);
	return pId;
}

void quickSort(int list[], int start, int end)
{
	if (start < end)
	{
		int p = pivot(list, start, end);

		quickSort(list, start, p - 1);
		quickSort(list, p + 1, end);
	}
}

int main()
{
	int list[] = {1, 2, 11, 10, 55, 2};

	quickSort(list, 0, sizeof(list) / sizeof(int) - 1);

	std::cout << "Result: ";
	for (int i = 0; i < sizeof(list) / sizeof(int); i++)
		std::cout << list[i] << " ";

	return 0;
}
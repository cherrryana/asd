#include <iostream>

// сортировка Шелла

void shellSort(int list[], int listLen)
{
	for (int step = listLen / 2; step > 0; step /= 2)
	{
		for (int i = step; i < listLen; i++) // сортировка вставками
		{
			for (int j = i; j >= step && list[j - step] > list[j]; j -= step)
				std::swap(list[j], list[j - step]);
		}
	}
}

int main()
{
	int list[] = {10, 11, 12, 6, 2, 3, 17, 19, 8, 24, 6};

	shellSort(list, sizeof(list) / sizeof(int));

	std::cout << "Result:\n";

	for (int i = 0; i < sizeof(list) / sizeof(int); i++)
		std::cout << list[i] << " ";
}
#include <iostream>

// сортировка вставками
void insertionSort(int list[], int listLen)
{
	for (int i = 1; i < listLen; i++)
	{
		int j = i - 1;
		while (j >= 0 && list[j] > list[j + 1])
		{
			std::swap(list[j], list[j + 1]);
			j--;
		}
	}
}

int main()
{
	int list[] = {1,2,5,7,19,11};

	insertionSort(list, sizeof(list) / sizeof(int));

	std::cout << "Result:";
	for (int i = 0; i < sizeof(list) / sizeof(int); i++)
		std::cout << list[i] << " ";
	return 0;
}
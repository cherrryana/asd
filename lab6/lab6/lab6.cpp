#include <iostream>

// сортировка выбором
int smallest(int list[], int start, int listLen)
{
	int smId = start;

	for (int i = start; i < listLen; i++)
	{
		if (list[i] < list[smId])
			smId = i;
	}
	return smId;
}

void selectionSort(int list[], int listLength)
{
	for (int i = 0; i < listLength; i++)
	{
		int smId = smallest(list, i, listLength);
		std::swap(list[i], list[smId]);
	}
	return;
}

int main()
{
	int list[] = {11, 2, 4, 0, 9, 2, 10};

	selectionSort(list, sizeof(list)/sizeof(int));

	std::cout << "Result:" << std::endl;

	for (int i = 0; i < sizeof(list) / sizeof(int); i++)
		std::cout << list[i] << ' ';
	std::cout << std::endl;
}
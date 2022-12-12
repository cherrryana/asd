#include <iostream>

// пирамидальная сортировка (heap sort)

void heap(int list[], int listLen, int root)
{
	int biggest = root;
	int left = 2 * root + 1, right = 2 * root + 2;

	if (left < listLen && list[left] > list[biggest])
		biggest = left;

	if (right < listLen && list[right] > list[biggest])
		biggest = right;

	if (biggest != root)
	{
		std::swap(list[root], list[biggest]);
		heap(list, listLen, biggest);
	}

}

void heapSort(int list[], int listLen)
{
	for (int i = (listLen / 2) - 1; i >= 0; i--) // i - индекс с нижним левым узлом
		heap(list, listLen, i);

	for (int i = listLen - 1; i >= 0; i--)
	{
		std::swap(list[0], list[i]);
		heap(list, i, 0);
	}
}

int main()
{
	int list[] = {1, 23, 11, 10, 1, 0, 19};

	heapSort(list, sizeof(list) / sizeof(int));

	std::cout << "Result: ";
	for (int i = 0; i < sizeof(list) / sizeof(int); i++)
		std::cout << list[i] << ' ';
}
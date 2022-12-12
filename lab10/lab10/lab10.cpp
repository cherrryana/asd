#include <iostream>

// сортировка слиянием

void merge(int list[], int start, int end, int mid)
{
	int doneList[10];
	int i = start, k = start, j = mid + 1;

	while (i <= mid && j <= end) 
	{
		if (list[i] < list[j]) 
		{
			doneList[k] = list[i];
			k++;
			i++;
		}
		else {
			doneList[k] = list[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {
		doneList[k] = list[i];
		k++;
		i++;
	}

	while (j <= end) {
		doneList[k] = list[j];
		k++;
		j++;
	}

	for (i = start; i < k; i++) {
		list[i] = doneList[i];
	}
}

void mergeSort(int list[], int start, int end)
{
	int mid;
	if (start < end) {

		mid = (start + end) / 2;
		mergeSort(list, start, mid);
		mergeSort(list, mid + 1, end);
		merge(list, start, end, mid);
	}
}

int main()
{
	int list[10] = {1, 2, 5, 6, 7, 10, 9, 4, 3, 8};
	
	mergeSort(list, 0, 9);

	std::cout << "Result:\n";
	for (int i = 0; i < 10; i++)
		std::cout << list[i] << " ";
}
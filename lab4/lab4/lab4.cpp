#include <iostream>

// сортировка расчёской

void combSort(int list[], int listLen)
{
    int step = listLen / 1.247;

    while (step >= 1)
    {
        for (int i = 0, j = step; j < listLen; i++, j++)
        {
            if (list[i] > list[j])
                std::swap(list[i], list[j]);
        }
        step /= 1.247;
    }
}

int main()
{
    int list[] = {1, 0, 3, 4, 6, 11, 10, 90, 7, 17};

    combSort(list, sizeof(list) / sizeof(int));

    std::cout << "Result: ";
    for (int i = 0; i < sizeof(list) / sizeof(int); i++)
        std::cout << list[i] << " ";
}
#include "Task3.h"

int main()
{
    uint8_t size = 9;
    uint32_t number = 8;

    uint32_t input[9] = {1, 7, 4, 8, 1, 8, 3, 2, 7};
    uint32_t *arr = malloc(size * sizeof(uint32_t));

    for (int i = 0; i < size; i++)
        arr[i] = input[i];

    uint8_t a = binarySearch(arr, size, number);

    printf("\n\n ANSWER IS %d", a);
}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void sort(uint32_t *arr, uint8_t size)
{
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (arr[j] > arr[j + 1])
                    swap(&arr[j], &arr[j + 1]);
    }
}

uint8_t binarySearch(uint32_t *arr, uint8_t size, uint32_t number)
{

    int f = 0;
    int l = size - 1;
    int m = (f + l) / 2;

    sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    if (size >= 250)
    {
        printf("Size too big, needs to be lower than 250");
    }

    while (f <= l)
    {
        int m = (f + l) / 2;

        if (arr[m] == number)
        {
            return m;
        }
        if (arr[m] < number)
        {
            f = m + 1;
        }
        else
        {
            l = m - 1;
        }
    }
    return -1;
}
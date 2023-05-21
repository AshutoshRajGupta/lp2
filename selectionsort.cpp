#include <iostream>
using namespace std;

void selectionsort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the Array :";
    cin >> size;
    int arr[size];

    cout << "Enter the elements of Array :";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    selectionsort(arr, size);

    cout << "Sorted Array is :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
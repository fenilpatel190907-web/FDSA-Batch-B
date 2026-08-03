#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int n;

    cout << "Enter number of answer sheets: ";
    cin >> n;

    int marks[n];

    cout << "Enter marks:" << endl;
    for(int i = 0; i < n; i++)
        cin >> marks[i];

    int bubble[n], selection[n], insertion[n];

    for(int i = 0; i < n; i++)
    {
        bubble[i] = marks[i];
        selection[i] = marks[i];
        insertion[i] = marks[i];
    }

    bubbleSort(bubble, n);
    cout << "\nBubble Sort: ";
    display(bubble, n);

    selectionSort(selection, n);
    cout << "Selection Sort: ";
    display(selection, n);

    insertionSort(insertion, n);
    cout << "Insertion Sort: ";
    display(insertion, n);

    return 0;
}
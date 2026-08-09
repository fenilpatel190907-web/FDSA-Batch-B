#include <iostream>
using namespace std;

void sortColors(int arr[], int n)
{
    int index = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 0)
        {
            arr[index] = 0;
            index++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 1)
        {
            arr[index] = 1;
            index++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 2)
        {
            arr[index] = 2;
            index++;
        }
    }
}

int main()
{
    int n;

    cout << "Enter number of buckets: ";
    cin >> n;

    int arr[n];

    cout << "Enter colour codes (0, 1, 2):" << endl;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sortColors(arr, n);

    cout << "Sorted colour codes: ";

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
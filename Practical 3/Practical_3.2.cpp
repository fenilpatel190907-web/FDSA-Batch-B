#include <iostream>
using namespace std;

void sortColors(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            int temp = arr[low];
            arr[low] = arr[mid];
            arr[mid] = temp;
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
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
#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> s(n);

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int left = 0;
    int right = n - 1;
    int index = 0;

    while (left <= right) {

        int mid = left + (left + right) / 2;

        if (s[mid] == target) {
            index = mid;
            break;
        }
        else if (target > s[mid]) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

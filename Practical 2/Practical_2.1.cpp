#include <iostream>
#include <vector>
#include <string>
using namespace std;
int plateIterative(const vector<string>& plates, const string& target) {
    for (int i = 0; i < plates.size(); ++i) {
        if (plates[i] == target) {
            return i;
        }
    }
    return -1;
}

int plateRecursive(const vector<string>& plates, const string& target, int index = 0) {
    if (index >= plates.size()) {
        return -1;
    }


    if (plates[index] == target) {
        return index;
    }

    return plateRecursive(plates, target, index + 1);
}

int main() {
    vector<string> parkingLot = {"GJ06AB1234", "MH12XY5678", "GJ01ZZ9999", "DL01AA1111"};
    string targetCar = "GJ01ZZ9999";

    int iterative = plateIterative(parkingLot, targetCar);
    int recursive = plateRecursive(parkingLot, targetCar);

    cout << "Iterative index " << iterative <<endl;
    cout << "Recursive index " << recursive <<endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Array
{
private:
    vector<double> dynamicArray;
    double sum, average;

public:
    Array(double arr[], int arraySize) {
        fillArray(arr, arraySize);
        calculateSumsAndAddToVector();
        divideElementsByHalfSum();
        coutFunction();
        menu();
    }

    void deleteElements() {
        dynamicArray.pop_back();
        cout << "-: " << dynamicArray.size() << endl;
        coutFunction();
        calculateSumsAndAddToVector();
        divideElementsByHalfSum();
        coutFunction();
    }

    void addElements() {
        double elements = 0;
        cin >> elements;
        dynamicArray.push_back(elements);
        cout << "+: " << dynamicArray.size() << endl;
        coutFunction();
        calculateSumsAndAddToVector();
        divideElementsByHalfSum();
        coutFunction();
    }

    void fillArray(double arr[], int arraySize) {
        cout << arraySize << endl;

        for (int i = 0; i < arraySize; i++) {
            dynamicArray.push_back(arr[i]);
        }

        coutFunction();
    }

    void calculateSumsAndAddToVector() {
        sum = 0.0;
        average = 0.0;

        for (int i = 0; i < dynamicArray.size(); i++) {
            sum += dynamicArray[i];
        }

        if (!dynamicArray.empty()) {
            average = sum / dynamicArray.size();
        }

        dynamicArray.push_back(sum);
        dynamicArray.push_back(average);

        coutFunction();
    }

    void divideElementsByHalfSum() {
        double halfSum = 0.0;
        int firstNegativeIndex = -1;

        for (int i = 0; i < dynamicArray.size(); i++) {
            if (dynamicArray[i] < 0 && firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
        }

        if (firstNegativeIndex != -1) {
            halfSum = (dynamicArray[firstNegativeIndex] + dynamicArray[5]) / 2.0;

            if (halfSum != 0.0) {
                for (int i = 0; i < dynamicArray.size(); i++) {
                    dynamicArray[i] /= halfSum;
                }
            }
        }
        else {
            coutFunction();
        }
    }

    void coutFunction() {
        cout << fixed << setprecision(3);
        for (int i = 0; i < dynamicArray.size(); i++) {
            cout << dynamicArray[i] << " ";
        }
        cout << endl;
    }

    void menu() {
        int choice;
        while (true) {
            cin >> choice;

            switch (choice) {
            case 0:
                return;
            case 1:
                addElements();
                break;
            case 2:
                deleteElements();
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }
};

int main() {
    int arraySize;
    cin >> arraySize;
    double arr[arraySize];

    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
    }

    Array myArray(arr, arraySize);
    return 0;
}

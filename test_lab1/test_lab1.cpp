#include <iostream>
#include <vector>
#include <iomanip>

class Array
{
private:
    std::vector<double> dynamicArray;
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
        std::cout << "-: " << dynamicArray.size() << std::endl;
        coutFunction();
        calculateSumsAndAddToVector();
        divideElementsByHalfSum();
        coutFunction();
    }

    void addElements() {
        double elements = 0;
        std::cin >> elements;
        dynamicArray.push_back(elements);
        std::cout << "+: " << dynamicArray.size() << std::endl;
        coutFunction();
        calculateSumsAndAddToVector();
        divideElementsByHalfSum();
        coutFunction();
    }

    void fillArray(double arr[], int arraySize) {
        std::cout << arraySize << std::endl;

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
        std::cout << std::fixed << std::setprecision(3);
        for (int i = 0; i < dynamicArray.size(); i++) {
            std::cout << dynamicArray[i] << " ";
        }
        std::cout << std::endl;
    }

    void menu() {
        int choice;
        while (true) {
            std::cin >> choice;

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
                std::cout << "Invalid choice." << std::endl;
                break;
            }
        }
    }
};

int main() {
    int arraySize;
    std::cin >> arraySize;
    double arr[arraySize];

    for (int i = 0; i < arraySize; i++) {
        std::cin >> arr[i];
    }

    Array myArray(arr, arraySize);
    return 0;
}

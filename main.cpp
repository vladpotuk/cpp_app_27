#include <iostream>
#include <vector>
#include<Windows.h>

int main() {
    system("chcp 1251");
    system("cls");
    int N;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> N;

    std::vector<double> arr(N);

    std::cout << "Введіть елементи масиву:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    
    double negativeSum = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            negativeSum += arr[i];
        }
    }

    
    double minValue = arr[0];
    double maxValue = arr[0];
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < N; i++) {
        if (arr[i] < minValue) {
            minValue = arr[i];
            minIndex = i;
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }

    
    double elementsBetweenMinMax = 1.0;

    int start, end;
    if (minIndex < maxIndex) {
        start = minIndex + 1;
        end = maxIndex;
    }
    else {
        start = maxIndex + 1;
        end = minIndex;
    }

    for (int i = start; i < end; i++) {
        elementsBetweenMinMax *= arr[i];
    }
    double productEvennumbers = 1.0;
    for (int i = 0; i < N; i += 2) {
        productEvennumbers *= arr[i];
    }

    
    double sumBetweenNegatives = 0.0;

    int firstNegativeIndex = -1;
    int lastNegativeIndex = -1;

    for (int i = 0; i < N; i++) {
        if (arr[i] < 0) {
            if (firstNegativeIndex == -1) {
                firstNegativeIndex = i;
            }
            else {
                lastNegativeIndex = i;
            }
        }

        if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
            break; 
        }
    }

    if (firstNegativeIndex != -1 && lastNegativeIndex != -1) {
        for (int i = firstNegativeIndex + 1; i < lastNegativeIndex; i++) {
            sumBetweenNegatives += arr[i];
        }
    }

    //відповіді блін
    std::cout << "Сума від'ємних елементів: " << negativeSum << std::endl;
    std::cout << "Добуток елементів між min і max елементами: " << elementsBetweenMinMax << std::endl;
    std::cout << "Добуток елементів з парними номерами: " << productEvennumbers << std::endl;
    std::cout << "Сума елементів між першим і останнім від'ємними елементами: " << sumBetweenNegatives << std::endl;

    return 0;
}

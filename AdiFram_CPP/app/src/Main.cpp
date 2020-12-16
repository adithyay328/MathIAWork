#include <vector>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include "Sorting.hpp"

using namespace std::chrono;

void populateVectorWithRandomValues(std::vector<int>& vectorToPopulate) {
    for(int i = 0; i < vectorToPopulate.capacity(); i++) {
        vectorToPopulate.push_back(rand() % 100000);
    }
};

void printElementsInVector(std::vector<int>& vectorToPrint) {
    for(size_t i = 0; i < vectorToPrint.size(); i++) {
        std::cout << vectorToPrint[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    int numOfElements = 0;
    std::cin >> numOfElements;

    std::vector<int> vectorToSort;   
    vectorToSort.reserve(numOfElements);

    populateVectorWithRandomValues(vectorToSort);

    std::vector<int> tempVector(vectorToSort);
    printElementsInVector(tempVector);

    std::vector<int> resultVector;
    resultVector.reserve(numOfElements);

    auto startTime = steady_clock::now();
    sorting::singlethreaded::mergeSort_numeric(tempVector, resultVector);
    auto endTime = steady_clock::now();

    printElementsInVector(resultVector);

    auto duration = duration_cast<microseconds>(endTime - startTime);
    std::cout << duration.count();
    std::cout << std::endl;

    return 0;
}
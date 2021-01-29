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

    for(int j = 1; j <= 3; j++) {
        std::cout << "Trial " << j << ":" << std::endl;

        for(int i = 1; i < 40; i = i + 5) {
            std::vector<int> tempVector(vectorToSort);

            std::vector<int> resultVector;
            resultVector.reserve(numOfElements);

            auto startTime = steady_clock::now();
            //sorting::singlethreaded::mergeSort_numeric(tempVector, resultVector, i);
            sorting::singlethreaded::selectionSort_numeric(vectorToSort);
            auto endTime = steady_clock::now();

            auto duration = duration_cast<microseconds>(endTime - startTime);
            std::cout << i << ":" << duration.count();
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
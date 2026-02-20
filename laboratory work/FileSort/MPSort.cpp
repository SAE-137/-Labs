#include "MPSort.h"

#include<iostream>
#include <fstream>
#include <string>
#include <random>

#include <random>
#include <chrono>


int randomValue(int min, int max)
{
    static std::mt19937 rng(static_cast<unsigned int>(
        std::chrono::system_clock::now().time_since_epoch().count()));  // Seed от времени

    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}


bool createMainFile(const std::string& fileName, int amount, int min, int max)
{
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "ERROR " << fileName << std::endl;
        return false;
    }

    for (int i = 0; i < amount; ++i) {
        file << randomValue(min, max) << " ";
    }

    file.close();
    return true;
}

bool isSorted1(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "ERROR " << fileName << std::endl;
        return false;
    }

    int prev, current;
    if (!(file >> prev)) {
        return true;
    }

    while (file >> current) {
        if (prev > current) {
            return false;
        }
        prev = current;
    }

    return true;
}


bool createFiles(std::string& flowName, int amount) {
    for (int i = 0; i < amount; ++i) {
        std::string fileName = flowName + std::to_string(i) + ".txt";
        std::ofstream file(fileName);

        if (!file.is_open()) {
            std::cerr << "ERROR: cant create file " << fileName << std::endl;
            return false;
        }

        file.close();
    }

    return true;
}


int sequence(const std::string& fromFile, const std::string& toFilePrefix, int amount) {
    std::ifstream input(fromFile);
    if (!input.is_open()) {
        std::cerr << "ERROR " << fromFile << std::endl;
        return 0;
    }

    std::ofstream* outputs = new std::ofstream[amount];
    for (int i = 0; i < amount; ++i) {
        outputs[i].open(toFilePrefix + std::to_string(i) + ".txt");
        if (!outputs[i].is_open()) {
            std::cerr << "ERROR " << toFilePrefix + std::to_string(i) << std::endl;
            delete[] outputs;
            return 0;
        }
    }

    int value = 0;
    int prev, curr;
    int fileIndex = 0;
    if (input >> prev) {
        outputs[fileIndex] << prev << " ";
    }

    while (input >> curr) {
        if (curr < prev) {
            fileIndex = (fileIndex + 1) % amount;
            outputs[fileIndex] << "\n";
            value++;
        }
        outputs[fileIndex] << curr << " ";
        prev = curr;
    }

    for (int i = 0; i < amount; ++i) {
        outputs[i].close();
    }

    delete[] outputs;
    input.close();


    return value;
}




bool isSorted(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "ERROR " << fileName << std::endl;
        return false;
    }

    int prevValue, currentValue;
    if (file >> prevValue) {
        while (file >> currentValue) {
            if (currentValue < prevValue) {
                file.close();
                return false;
            }
            prevValue = currentValue;
        }
    }

    file.close();
    return true;
}


void clearFiles(const std::string& fileName, int amount) {
    for (int i = 0; i < amount; ++i) {
        std::ofstream file(fileName + std::to_string(i) + ".txt", std::ios::trunc);
        if (!file) {
            std::cerr << "ERROR " << fileName + std::to_string(i) + ".txt" << std::endl;
        }
    }
    if (amount == 1)
    {
        std::ofstream file(fileName + ".txt", std::ios::trunc);
        if (!file) {
            std::cerr << "ERROR " << fileName + ".txt" << std::endl;
        }
    }
}


void printFile(const std::string& nameFile, int amount)
{
    int curr = 0;
    if (amount == 1)
    {
        std::ifstream input(nameFile);
        if (!input.is_open()) {
            std::cerr << "ERROR " << nameFile << std::endl;
            return;
        }

        std::cout << nameFile << ": ";
        while (input >> curr)
        {
            std::cout << curr << " ";
        }
        std::cout << std::endl;

        input.close();
        return;
    }

    std::ifstream* inputs = new std::ifstream[amount];

    for (int i = 0; i < amount; ++i) {
        inputs[i].open(nameFile + std::to_string(i) + ".txt");
        if (!inputs[i].is_open()) {
            std::cerr << "ERROR " << nameFile + std::to_string(i) + ".txt" << std::endl;
            for (int j = 0; j < i; ++j) inputs[j].close();
            delete[] inputs;
            return;
        }
    }



    for (int i = 0; i < amount; ++i)
    {
        std::cout << nameFile << ": ";
        while (inputs[i] >> curr)
        {
            std::cout << curr << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < amount; ++i)
    {
        inputs[i].close();
    }
    delete[] inputs;
}



#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <vector>

int mergeSortPass(const std::string& fromFilePrefix,
    const std::string& toFilePrefix, const std::string& mainF,
    int amount)
{
    std::ifstream* inputs = new std::ifstream[amount];
    std::ofstream* outputs = new std::ofstream[amount];
    std::ofstream mainFile(mainF); 

    if (!mainFile.is_open()) {
        std::cerr << "ERROR opening main.txt" << std::endl;
        return -1;
    }

    for (int i = 0; i < amount; ++i) {
        inputs[i].open(fromFilePrefix + std::to_string(i) + ".txt");
        if (!inputs[i].is_open()) {
            std::cerr << "ERROR opening " << fromFilePrefix + std::to_string(i) + ".txt" << std::endl;
            return -1;
        }
    }

    for (int i = 0; i < amount; ++i) {
        outputs[i].open(toFilePrefix + std::to_string(i) + ".txt");
        if (!outputs[i].is_open()) {
            std::cerr << "ERROR opening " << toFilePrefix + std::to_string(i) + ".txt" << std::endl;
            return -1;
        }
    }

    int* currentValues = new int[amount];
    bool* hasValue = new bool[amount];
    int* lastValues = new int[amount];
    bool* runActive = new bool[amount];

    bool allEmpty = true;
    for (int i = 0; i < amount; ++i) {
        if (inputs[i] >> currentValues[i]) {
            hasValue[i] = true;
            runActive[i] = true;
            lastValues[i] = currentValues[i];
            allEmpty = false;
        }
        else {
            hasValue[i] = false;
            runActive[i] = false;
        }
    }

    if (allEmpty) {
        return 0;
    }

    int runCount = 0;
    int outputFileIndex = 0;

    while (true) {
        int minValue = std::numeric_limits<int>::max();
        int minIndex = -1;

        for (int i = 0; i < amount; ++i) {
            if (hasValue[i] && runActive[i] && currentValues[i] < minValue) {
                minValue = currentValues[i];
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            bool anyRemaining = false;
            for (int i = 0; i < amount; ++i) {
                if (hasValue[i]) {
                    anyRemaining = true;
                    runActive[i] = true;
                    lastValues[i] = currentValues[i];
                }
            }
            if (!anyRemaining)
                break;

            outputFileIndex = (outputFileIndex + 1) % amount;
            runCount++;
            continue;
        }

        outputs[outputFileIndex] << minValue << " ";
        mainFile << minValue << " "; 

        if (inputs[minIndex] >> currentValues[minIndex]) {
            if (currentValues[minIndex] >= lastValues[minIndex]) {
                lastValues[minIndex] = currentValues[minIndex];
            }
            else {
                runActive[minIndex] = false;
            }
        }
        else {
            hasValue[minIndex] = false;
            runActive[minIndex] = false;
        }
    }

    for (int i = 0; i < amount; ++i) {
        inputs[i].close();
        outputs[i].close();
    }

    mainFile.close(); 

    delete[] inputs;
    delete[] outputs;
    delete[] currentValues;
    delete[] hasValue;
    delete[] lastValues;
    delete[] runActive;

    return runCount;
}



bool isEmpty(const std::string& filePrefix, int amount) {
    for (int i = 1; i < amount; ++i) {
        std::ifstream file(filePrefix + std::to_string(i) + ".txt", std::ios::ate);
        if (!file.is_open()) {
            std::cerr << "ERROR " << filePrefix + std::to_string(i) + ".txt" << std::endl;
            return false;
        }
        if (file.tellg() > 0) {
            return false;
        }
    }


    std::ifstream firstFile(filePrefix + "0.txt", std::ios::ate);
    if (!firstFile.is_open() || firstFile.tellg() == 0) {
        return false;
    }

    return true;
}

void multiwayMergeSort(const std::string& inputPrefix, const std::string& outputPrefix, int amount) {
    std::string fromPrefix = inputPrefix;
    std::string toPrefix = outputPrefix;

    while (true) {

        //mergeSortPass(fromPrefix, toPrefix, amount);
        clearFiles(fromPrefix, amount);




        std::swap(fromPrefix, toPrefix);


        if (isEmpty(fromPrefix, amount) && isSorted(fromPrefix + "0.txt")) {

            //printFile(fromPrefix + "0.txt", 1);
            break;
        }
    }

    if (isSorted(fromPrefix + "0.txt")) std::cout << "Sorted is end " << std::endl;
}











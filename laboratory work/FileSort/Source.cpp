#include <iostream>
#include <fstream>
#include <random>
#include <string>

bool createFileWithRandomNumbers(const std::string& fileName, const int numbersCount, const int maxNumberValue) {
    std::ofstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "ERror" << fileName << std::endl;
        return false;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, maxNumberValue);

    for (int i = 0; i < numbersCount; ++i) {
        int num = dist(gen);
        file << num << std::endl;
    }

    file.close();
    return true;
}

void sortFile(const std::string& fileName)
{

}


bool isFileContainsSortedArray(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file) return false;

    int prev, current;
    if (!(file >> prev)) return false;

    while (file >> current) {
        if (current < prev) return false;
        prev = current;
    }
    return true;
}

int createAndSortFile(const std::string& fileName, const int numbersCount, const int maxNumberValue) {
    if (!createFileWithRandomNumbers(fileName, numbersCount, maxNumberValue)) {
        return -1;
    }

    sortFile(fileName); 

    if (!isFileContainsSortedArray(fileName)) {
        return -2;
    }

    return 1;
}

int main() {
    std::string fileName = "file.txt";
    const int numbersCount = 1000000;
    const int maxNumberValue = 100000;

    for (int i = 0; i < 10; i++) {
        switch (createAndSortFile(fileName, numbersCount, maxNumberValue)) {
        case 1:
            std::cout << "Test passed." << std::endl;
            break;
        case -1:
            std::cout << "Test failed: can't create file." << std::endl;
            break;
        case -2:
            std::cout << "Test failed: file isn't sorted." << std::endl;
            break;
        }
    }

    return 0;
}
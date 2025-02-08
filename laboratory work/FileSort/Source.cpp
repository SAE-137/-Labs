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

int main()
{




	return 0;
}
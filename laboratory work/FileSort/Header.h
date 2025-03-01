#include <iostream>
#include <fstream>
#include <string>


int randomValue(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);


    return dist(gen);

}

bool createMainFile(const std::string& fileName, int amount, int min, int max)
{
    std::ofstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "ERROR: cant open main file " << fileName << std::endl;
        return false;
    }

    for (int i = 0; i < amount; ++i) {
        file << randomValue(min, max) << " ";
    }

    file.close();
    return true;
}

bool isSorted(const std::string& fileName) {
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "ERROR: cant open file " << fileName << std::endl;
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




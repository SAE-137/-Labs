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


bool sequence(const std::string& fromFile, const std::string& toFilePrefix, int amount) {
    std::ifstream input(fromFile);
    if (!input.is_open()) {
        std::cerr << "ERROR " << fromFile << std::endl;
        return false;
    }

    std::ofstream* outputs = new std::ofstream[amount];
    for (int i = 0; i < amount; ++i) {
        outputs[i].open(toFilePrefix + std::to_string(i) + ".txt");
        if (!outputs[i].is_open()) {
            std::cerr << "ERROR " << toFilePrefix + std::to_string(i) << std::endl;
            delete[] outputs;
            return false;
        }
    }

    int prev, curr;
    int fileIndex = 0;
    if (input >> prev) {
        outputs[fileIndex] << prev << " ";
    }

    while (input >> curr) {
        if (curr < prev) {
            fileIndex = (fileIndex + 1) % amount;
            outputs[fileIndex] << "\n";
        }
        outputs[fileIndex] << curr << " ";
        prev = curr;
    }

    for (int i = 0; i < amount; ++i) {
        outputs[i].close();
    }

    delete[] outputs;
    input.close();
    return true;
}

void multiPathSorting(std::string& fromFilePrefix, std::string& toFilePrefix, int amount)
{

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



bool mergeSortPass(const std::string& fromFilePrefix, const std::string& toFilePrefix, int amount) {
    std::ifstream* inputs = new std::ifstream[amount];
    std::ofstream* outputs = new std::ofstream[amount];

   
    for (int i = 0; i < amount; ++i) {
        inputs[i].open(fromFilePrefix + std::to_string(i) + ".txt");
        if (!inputs[i].is_open()) {
            std::cerr << "ERROR " << fromFilePrefix + std::to_string(i) + ".txt" << std::endl;
            for (int j = 0; j < i; ++j) inputs[j].close();
            delete[] inputs;
            delete[] outputs;
            return false;
        }
    }

    
    for (int i = 0; i < amount; ++i) {
        outputs[i].open(toFilePrefix + std::to_string(i) + ".txt");
        if (!outputs[i].is_open()) {
            std::cerr << "ERROR " << toFilePrefix + std::to_string(i) + ".txt" << std::endl;
            for (int j = 0; j < amount; ++j) inputs[j].close();
            for (int j = 0; j < i; ++j) outputs[j].close();
            delete[] inputs;
            delete[] outputs;
            return false;
        }
    }

    int* values = new int[amount];
    bool* hasValue = new bool[amount];
    bool allEmpty = true;

    
    for (int i = 0; i < amount; ++i) {
        if (inputs[i] >> values[i]) {
            hasValue[i] = true;
            allEmpty = false;
        }
        else {
            hasValue[i] = false;
        }
    }

    
    if (allEmpty) {
        for (int i = 0; i < amount; ++i) {
            inputs[i].close();
            outputs[i].close();
        }
        delete[] inputs;
        delete[] outputs;
        delete[] values;
        delete[] hasValue;
        return false;
    }

    int fileIndex = 0; 

    while (true) {
       
        int minValue = std::numeric_limits<int>::max();
        int minIndex = -1;
        for (int i = 0; i < amount; ++i) {
            if (hasValue[i] && values[i] < minValue) {
                minValue = values[i];
                minIndex = i;
            }
        }


        if (minIndex == -1) break;
        outputs[fileIndex] << minValue << "\n";

        if (inputs[minIndex] >> values[minIndex]) {
           
            if (values[minIndex] < minValue) {
                fileIndex = (fileIndex + 1) % amount;
            }
        }
        else {
            hasValue[minIndex] = false;
        }
    }

    
    for (int i = 0; i < amount; ++i) {
        inputs[i].close();
        outputs[i].close();
    }

    //printFile(toFilePrefix, amount);
    //printFile(fromFilePrefix, amount);

    
    delete[] inputs;
    delete[] outputs;
    delete[] values;
    delete[] hasValue;

    return true;
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
        
        bool result = mergeSortPass(fromPrefix, toPrefix, amount);
        clearFiles(fromPrefix, amount);
       
        if (!result) break;

       
        std::swap(fromPrefix, toPrefix);

       
        if (isEmpty(fromPrefix, amount) && isSorted(fromPrefix + "0.txt")) {
            
            //printFile(fromPrefix + "0.txt", 1);
            break;
        }
    }

    if (isSorted(fromPrefix + "0.txt")) std::cout << "Sorted is end " << std::endl;
}




void printSortingProcess(const std::string& main, const std::string& f, const std::string& g, int amount, bool printOnCmd)
{
   //if(printOnCmd) printFile(main, 1);
    sequence(main, f, amount);
   //if (printOnCmd)printFile(f, amount);
    multiwayMergeSort(f, g, amount);

}







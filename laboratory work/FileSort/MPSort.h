#pragma once
#include <string>

int randomValue(int min, int max);
bool createMainFile(const std::string& fileName, int amount, int min, int max);
bool createFiles(std::string& flowName, int amount);
int sequence(const std::string& fromFile, const std::string& toFilePrefix, int amount);
bool isSorted(const std::string& fileName);
void clearFiles(const std::string& fileName, int amount);
void printFile(const std::string& nameFile, int amount);
int mergeSortPass(const std::string& fromFilePrefix, const std::string& toFilePrefix, const std::string& mainF, int amount);
void multiwayMergeSort(const std::string& inputPrefix, const std::string& outputPrefix, int amount);
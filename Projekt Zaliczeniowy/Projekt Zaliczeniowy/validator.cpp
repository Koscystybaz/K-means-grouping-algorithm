#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include "validator.h"


bool validateArguments(std::string inputFile, std::string outputFile, std::string clusterNumberString, std::string dimensionsNumberString)
{

    if (inputFile.empty())
    {
        std::cout << "Input File does not exist!" << std::endl;
        return false;
    }

    if (outputFile.empty())
    {
        std::cout << "Output File is empty string!" << std::endl;
        return false;
    }

    std::ifstream file(inputFile);

    if (!file.good())
    {
        std::cout << "Input file has wrong path!" << std::endl;
        return false;
    }

    if (!isNumber(clusterNumberString))
    {
        std::cout << "Cluster number is not numeric!" << std::endl;
        return false;
    }

    if (!isNumber(dimensionsNumberString))
    {
        std::cout << "Dimensions number is not numeric!" << std::endl;
        return false;
    }

    return true;
}

bool isNumber(const std::string& str)
{
    for (char const& c : str) {
        if (isdigit(c) == 0) return false;
    }
    return true;
}
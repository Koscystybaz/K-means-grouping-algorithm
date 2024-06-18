#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "screen.h"


void showData(const std::vector<std::vector<double>>& data, int decimals, bool indices, bool newLine)
{
    for (int i = 0; i < data.size(); ++i)
    {
        if (indices) std::cout << i << " ";
        for (int j = 0; j < data[i].size(); ++j)
        {
            if (data[i][j] >= 0.0) std::cout << " ";
            std::cout << std::setprecision(decimals) << std::fixed << data[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
    if (newLine) std::cout << "" << std::endl;
}

void showVector(const std::vector<int>& vector, bool newLine)
{
    for (int i = 0; i < vector.size(); ++i)
        std::cout << vector[i] << " ";
    if (newLine) std::cout << "\n" << std::endl;
}

void showClustered(const std::vector<std::vector<double>>& data, const std::vector<int>& clustering, int numClusters, int decimals)
{
    for (int k = 0; k < numClusters; ++k)
    {
        std::cout << "===================" << std::endl;
        for (int i = 0; i < data.size(); ++i)
        {
            int clusterID = clustering[i];
            if (clusterID != k) continue;
            std::cout << i << " ";
            for (int j = 0; j < data[i].size(); ++j)
            {
                if (data[i][j] >= 0.0) std::cout << " ";
                std::cout << std::setprecision(decimals) << std::fixed << data[i][j] << " ";
            }
            std::cout << "" << std::endl;
        }
        std::cout << "===================" << std::endl;
    }
}

void showException(std::string message)
{
    std::cout << message;
}

void showUsage()
{
    std::cout << "Usage of option(s)\n"
        << "Options:\n"
        << "\t-h,--help\t\t\tShow this help message\n"
        << "\t-i,--inputFile\t\t\tSpecify path for input file\n"
        << "\t-o,--outputFile\t\t\tSpecify path for result file\n"
        << "\t-k,--clusterNumber\t\tSpecify number of clusters\n"
        << "\t-d,--dimensionsNumber\t\tSpecify number of dimensions in input file\n"
        << std::endl;
}
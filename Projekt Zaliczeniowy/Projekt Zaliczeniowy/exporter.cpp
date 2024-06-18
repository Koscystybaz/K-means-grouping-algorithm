#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "exporter.h"


void exportFile(std::string fileName, const std::vector<std::vector<double>>& rawData, const std::vector<int>& clustering, int numClusters, int decimals)
{
    std::ofstream myFile(fileName);

    myFile << "Raw unclustered data:" << std::endl;
    
    myFile << "-------------------" << std::endl;

    exportData(myFile, rawData, decimals, true, true);

    myFile << "K-means clustering complete" << std::endl;

    myFile << "Final clustering in internal form:" << std::endl;

    exportVector(myFile, clustering, true);

    myFile << "Raw data by cluster:" << std::endl;

    exportClustered(myFile, rawData, clustering, numClusters, decimals);

    myFile.close();

}

void exportData(std::ofstream& myFile, const std::vector<std::vector<double>>& data, int decimals, bool indices, bool newLine)
{
    for (int i = 0; i < data.size(); ++i)
    {
        if (indices) myFile << i << " ";
        for (int j = 0; j < data[i].size(); ++j)
        {
            if (data[i][j] >= 0.0) myFile << " ";
            myFile << std::setprecision(decimals) << std::fixed << data[i][j] << " ";
        }
        myFile << "" << std::endl;
    }
    if (newLine) myFile << "" << std::endl;
}

void exportVector(std::ofstream& myFile, const std::vector<int>& vector, bool newLine)
{
    for (int i = 0; i < vector.size(); ++i)
        myFile << vector[i] << " ";
    if (newLine) myFile << "\n" << std::endl;
}

void exportClustered(std::ofstream& myFile, const std::vector<std::vector<double>>& data, const std::vector<int>& clustering, int numClusters, int decimals)
{
    for (int k = 0; k < numClusters; ++k)
    {
        myFile << "===================" << std::endl;
        for (int i = 0; i < data.size(); ++i)
        {
            int clusterID = clustering[i];
            if (clusterID != k) continue;
            myFile << i << " ";
            for (int j = 0; j < data[i].size(); ++j)
            {
                if (data[i][j] >= 0.0) myFile << " ";
                myFile << std::setprecision(decimals) << std::fixed << data[i][j] << " ";
            }
            myFile << "" << std::endl;
        }
        myFile << "===================" << std::endl;
    }
}
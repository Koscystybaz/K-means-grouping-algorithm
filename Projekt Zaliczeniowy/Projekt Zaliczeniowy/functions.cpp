#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <math.h>
#include "functions.h"


std::vector <int> cluster(const std::vector<std::vector<double>>& rawData, int numClusters)
{
    std::vector<std::vector<double>> data = normalized(rawData);
    bool changed = true; bool success = true;
    std::vector<int> clustering = initClustering(data.size(), numClusters, 0);
    std::vector<std::vector<double>> means = allocate(numClusters, data[0].size());
    int maxCount = data.size() * 10;
    int ct = 0;
    while (changed == true && success == true && ct < maxCount)
    {
        ++ct;
        success = updateMeans(data, clustering, means);
        changed = updateClustering(data, clustering, means);
    }
    return clustering;
}

std::vector<std::vector<double>> normalized(const std::vector<std::vector<double>>& rawData)
{
    std::vector<std::vector<double>> result(rawData);
  
    for (int j = 0; j < result[0].size(); ++j)
    {
        double colSum = 0.0;
        for (int i = 0; i < result.size(); ++i)
            colSum += result[i][j];
        double mean = colSum / result.size();
        double sum = 0.0;
        for (int i = 0; i < result.size(); ++i)
            sum += (result[i][j] - mean) * (result[i][j] - mean);
        double sd = sum / result.size();
        for (int i = 0; i < result.size(); ++i)
            result[i][j] = (result[i][j] - mean) / sd;
    }
    return result;
}

std::vector<int> initClustering(int numTuples, int numClusters, int seed)
{
    srand(seed);
    std::vector<int> clustering;
    for (int i = 0; i < numClusters; ++i)
        clustering.push_back(i);
    for (int i = numClusters; i < numTuples; ++i)
        clustering.push_back(rand() % numClusters);

    return clustering;
}

std::vector<std::vector<double>> allocate(int numClusters, int numColumns)
{
    std::vector<std::vector<double>> result;
    for (int k = 0; k < numClusters; ++k)
    {
        std::vector<double> alocate;

        for (int l = 0; l < numColumns; ++l)
        {
            alocate.push_back(0.0);
        }
        result.push_back(alocate);
    }
    return result;
}

bool updateMeans(const std::vector<std::vector<double>>& data, std::vector<int>& clustering, std::vector<std::vector<double>>& means)
{
    int numClusters = means.size();
    std::vector<int> clusterCounts;
    for (int i = 0; i < numClusters; i++)
        clusterCounts.push_back(0);

    for (int i = 0; i < data.size(); ++i)
    {
        int cluster = clustering[i];
        ++clusterCounts[cluster];
    }

    for (int k = 0; k < numClusters; ++k)
        if (clusterCounts[k] == 0)
            return false;

    for (int k = 0; k < means.size(); ++k)
        for (int j = 0; j < means[k].size(); ++j)
            means[k][j] = 0.0;

    for (int i = 0; i < data.size(); ++i)
    {
        int cluster = clustering[i];
        for (int j = 0; j < data[i].size(); ++j)
            means[cluster][j] += data[i][j];
    }

    for (int k = 0; k < means.size(); ++k)
        for (int j = 0; j < means[k].size(); ++j)
            means[k][j] /= clusterCounts[k];
    return true;
}

bool updateClustering(const std::vector<std::vector<double>>& data, std::vector<int>& clustering, const std::vector<std::vector<double>>& means)
{
    int numClusters = means.size();
    bool changed = false;

    std::vector<int> newClustering(clustering);

    std::vector<double> distances;

    for (int i = 0; i < data.size(); ++i)
    {
        for (int k = 0; k < numClusters; ++k)
            distances.push_back(distance(data[i], means[k]));

        int newClusterID = minIndex(distances);
        if (newClusterID != newClustering[i])
        {
            changed = true;
            newClustering[i] = newClusterID;
        }
    }

    if (changed == false)
        return false;

    std::vector<int> clusterCounts;
    for (int i = 0; i < numClusters; i++)
        clusterCounts.push_back(0);

    for (int i = 0; i < data.size(); ++i)
    {
        int cluster = newClustering[i];
        ++clusterCounts[cluster];
    }

    for (int k = 0; k < numClusters; ++k)
        if (clusterCounts[k] == 0)
            return false;

    clustering = newClustering;
    
    return true;
}

double distance(const std::vector<double>& tuple, const std::vector<double>& mean)
{
    double sumSquaredDiffs = 0.0;
    for (int j = 0; j < tuple.size(); ++j)
        sumSquaredDiffs += pow((tuple[j] - mean[j]), 2);
    return sqrt(sumSquaredDiffs);
}

int minIndex(const std::vector<double>& distances)
{
    int indexOfMin = 0;
    double smallDist = distances[0];
    for (int k = 0; k < distances.size(); ++k)
    {
        if (distances[k] < smallDist)
        {
            smallDist = distances[k];
            indexOfMin = k;
        }
    }
    return indexOfMin;
}
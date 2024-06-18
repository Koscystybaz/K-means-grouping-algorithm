/** Header file functions @file */
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


/**
 * @brief Main clustering function.
 * @param rawData imported unclustered data
 * @param numClusters number of clusters to split for data 
 */
std::vector<int> cluster(const std::vector<std::vector<double>>& rawData, int numClusters);

/**
 * @brief Normalizating input data using standard deviation.
 * @param rawData imported unclustered data
 */
std::vector<std::vector<double>> normalized(const std::vector<std::vector<double>>& rawData);

/**
 * @brief Propose random clustering for data.
 * @param numTuples number of rows in file
 * @param numClusters number of clusters to split for data
 * @param seed pseudo random number of splitting configuration
 */
std::vector<int> initClustering(int numTuples, int numClusters, int seed);

/**
 * @brief Prepare memory for data.
 * @param numClusters number of clusters to split for data
 * @param numColumns number of columns in file 
 */
std::vector<std::vector<double>> allocate(int numClusters, int numColumns);

/**
 * @brief Calculate centroids for cluster groups.
 * @param data data from file
 * @param clustering clustering from previous iteration
 * @param means old means - centroids 
 */
bool updateMeans(const std::vector<std::vector<double>>& data, std::vector<int>& clustering, std::vector<std::vector<double>>& means);

/**
 * @brief Calculating new clusters grouping based on new centroids.
 * @param data data from file 
 * @param clustering clustering from previous iteration
 * @param means new centroinds calculated
 */
bool updateClustering(const std::vector<std::vector<double>>& data, std::vector<int>& clustering, const std::vector<std::vector<double>>& means);

/**
 * @brief Calculate distances between vectors.
 * @param tuple one row from file
 * @param mean current mean 
 */
double distance(const std::vector<double>& tuple, const std::vector<double>& mean);

/**
 * @brief Get the closest centroid.
 * @param distances distances from all centroids 
 */
int minIndex(const std::vector<double>& distances);

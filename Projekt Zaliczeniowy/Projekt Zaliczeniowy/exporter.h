/** Header file exporter @file */
#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


/**
 * @brief Exports data to output file in format of txt with final form of clusters grouped.
 * @param fileName name of outnput file
 * @param rawData imported data
 * @param clustering final groups
 * @param numClusters number of clusters to split for data
 */
void exportFile(std::string fileName, const std::vector<std::vector<double>>& rawData, const std::vector<int>& clustering, int numClusters, int decimals);

/**
 * @brief Exports data to exportFile function.
 * @param myFile opened output file 
 * @param data capacitor for data 
 * @param decimals decimal digits after point
 * @param indices indexes of data line in file 
 * @param newLine new line in file.txt
 */
void exportData(std::ofstream& myFile, const std::vector<std::vector<double>>& data, int decimals, bool indices, bool newLine);

/**
 * @brief Exports groups of splitted clusters to ountput file.
 * @param myFile opened output file 
 * @param vector data represented for line in file 
 * @param newLine new line in file.txt
 */
void exportVector(std::ofstream& myFile, const std::vector<int>& vector, bool newLine);

/**
 * @brief Export cluster resolution to output file.
 * @param myFile opened output file 
 * @param data capacitor for data 
 * @param clustering final groups
 * @param numClusters number of clusters to split for data
 * @param decimals decimal digits after point
 */
void exportClustered(std::ofstream& myFile, const std::vector<std::vector<double>>& data, const std::vector<int>& clustering, int numClusters, int decimals);
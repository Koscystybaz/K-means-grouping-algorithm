/** Header file screen @file */
#pragma once
#include <vector>
#include <string>


/**
 * @brief Displays whole algoritm with results in console.
 * @param data input data from file
 * @param decimals decimals points in double 
 * @param indices indexes of rows of data in file 
 * @param newLine should add new line at the end 
 */
void showData(const std::vector<std::vector<double>>& data, int decimals, bool indices, bool newLine);

/**
 * @brief Displays vector as a line in console.
 * @param vector display one vector as a line
 * @param newLine should add new line at the end
 */
void showVector(const std::vector<int>& vector, bool newLine);

/**
 * @brief Diplays clustered resolution.
 * @param data input data 
 * @param clustering final clusters
 * @param numClusters number of clusters to split data
 * @param decimals decimal digits after point
 */
void showClustered(const std::vector<std::vector<double>>& data, const std::vector<int>& clustering, int numClusters, int decimals);

/**
*@brief Showing finded exception in input file  
*@param message massage shown in console
*/
void showException(std::string message);

/**
*@brief Instruction of program usage
*/
void showUsage();
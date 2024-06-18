/** Header file validator @file */
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>


/**
 * @brief Validate arugmetns for they rights forms.
 * @param inputFile given input file 
 * @param outputFile given output file
 * @param clusterNumberString number of clusters to group
 * @param dimensionsNumberString number of dimensions of one row in file
 */
bool validateArguments(std::string inputFile, std::string outputFile, std::string clusterNumberString, std::string dimensionsNumberString);
/**
 * @brief Check if string is number.
 * @param str string to beeing checked
 */
bool isNumber(const std::string& str);
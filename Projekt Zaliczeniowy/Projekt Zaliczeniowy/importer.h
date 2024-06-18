/** Header file importer @file */
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


/**
 * @brief Imports unclustered data from input file in format of txt.
 * @param fileName filepath with data
 */
std::vector<std::vector<double>> readFile(std::string fileName);
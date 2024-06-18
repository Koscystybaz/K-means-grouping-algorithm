#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "importer.h"
#include "screen.h"
 

std::vector<std::vector<double>> readFile(std::string fileName)
{
	std::string oneLine;
	std::vector<std::vector<double>> wholeFileData;

	std::ifstream file(fileName);
	try
	{
		while (std::getline(file, oneLine))
		{
			std::vector<double> oneLineVector;
			std::stringstream  stream(oneLine);
			std::string stringNumber;

			while (getline(stream, stringNumber, ' '))
			{
				double doubleNumber = std::stod(stringNumber);
				oneLineVector.push_back(doubleNumber);
			}

			wholeFileData.push_back(oneLineVector);
		}
	}
	catch (const std::exception& exception)
	{
		showException("Wrong file format");
	}
	
	return wholeFileData;
}
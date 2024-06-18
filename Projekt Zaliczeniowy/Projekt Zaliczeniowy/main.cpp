/**
 * @copyright
 * Copyright 2022 Jakub Dudek.
 */

#include "functions.h"
#include "importer.h"
#include "exporter.h"
#include "screen.h"
#include "validator.h"


int main(int argc, char* argv[]) 
{
	std::string inputFile;
	std::string outputFile;
	std::string clusterNumberString;
	std::string dimensionsNumberString;
	
	int decimals = 2;

	if (argc != 9)
	{
		showUsage();
		return 0;
	}


	for (int i = 0; i < argc; ++i) {
		std::string arg = argv[i];

		if ((arg == "-h") || (arg == "--help")) {
			showUsage();
		}
		if ((arg == "-i") || (arg == "--inputFile")) {
			inputFile = argv[i + 1];
		}
		if ((arg == "-o") || (arg == "--outputFile")) {
			outputFile = argv[i + 1];
		}
		if ((arg == "-k") || (arg == "--clusterNumber")) {
			clusterNumberString = (argv[i + 1]);
		}
		if ((arg == "-d") || (arg == "--dimensionsNumber")) {
			dimensionsNumberString = (argv[i + 1]);
		}
	}

	if (!validateArguments(inputFile, outputFile, clusterNumberString, dimensionsNumberString))
	{
		std::cout << "Given argument are wrong";
		return 0;
	}

	int clusterNumber = std::stoi(clusterNumberString);
	int dimensionsNumber = std::stoi(dimensionsNumberString);

	std::cout <<"Begin" << std::endl;

	std::vector<std::vector<double>> rawData = readFile(inputFile);

	if(rawData.empty())
	{
		std::cout << "file is corrupted or empty";
		return 0;
	}

	std::cout <<"Raw unclustered data:" << std::endl;
	std::cout <<"-------------------" << std::endl;
	showData(rawData, decimals, true, true);

	std::cout <<"Setting numClusters to " << clusterNumber << std::endl;

	std::vector<int> clustering = cluster(rawData, clusterNumber);

	std::cout <<"K-means clustering complete" << std::endl;

	std::cout <<"Final clustering in internal form:" << std::endl;
	showVector(clustering, true);

	std::cout <<"Raw data by cluster:" << std::endl;
	showClustered(rawData, clustering, clusterNumber, decimals);

	std::cout <<"End" << std::endl;

	exportFile(outputFile, rawData, clustering, clusterNumber, decimals);
	
	int i;
	std::cin >> i;

}
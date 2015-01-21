#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <vector>
#include <iostream>
#include "features.h"

class CSVReader
{
public:
	int nRows;
	int validationIndex;
	std::vector<std::string> headers;
	std::vector<Features> dataRows;

	void readFile(std::string fileName, std::string valueColumn);

	CSVReader(std::string fileName, std::string valueColumn)
	{
		nRows = 0;
		validationIndex = -1;
		headers.clear();
		dataRows.clear();
		
		std::cerr << fileName << ' ' << valueColumn << std::endl;
		readFile(fileName, valueColumn);
	}
};


#endif // CSV_READER_H
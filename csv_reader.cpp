#include "csv_reader.h"
#include "utils.h"
#include "assert.h"
#include <fstream>
#include <vector>
#include <iostream>

void CSVReader::readFile(std::string fileName, std::string valueColumn)
{	
	// empty string if this is test data
	nRows = -1;
	validationIndex = -1;
	std::ifstream input(fileName.c_str());

	for (std::string line; getline(input, line); )
	{
		// the first line is always header
		if (nRows < 0)
		{
			nRows = 0;
			headers = splitInputByCommaByString(line);
			// for (auto elem : headers)
			// 	std::cout << elem << std::endl;

			for (unsigned int i = 0; i < headers.size(); i++)
				if (headers[i] == valueColumn)
				{
					validationIndex = i;
				}
		}
		else
		{
			nRows++;
			Features newRow;
			newRow.ReadLine(line);
			if (validationIndex >= 0)
			{
				newRow.isTrainData = true;
				newRow.value = newRow.data[validationIndex];
				assert(newRow.value >= 0 && newRow.value <= 9);
				newRow.data.erase(newRow.data.begin() + validationIndex);
			}
			for (unsigned int i = 0; i < newRow.data.size(); i++)
				newRow.data[i] = (newRow.data[i] > 127) ? 1 : 0;
			dataRows.push_back(newRow);
		}
	}
}
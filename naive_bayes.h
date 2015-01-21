#ifndef NAIVE_BAYES_H
#define NAIVE_BAYES_H

#include <map>
#include "csv_reader.h"
#include "features.h"
#include "frequency_count.h"

class NaiveBayes
{
public:
	void fit(CSVReader trainData);
	int predict(Features testRow);
	double getFrequency(int category);
	std::vector< FrequencyCount > data;
	std::map<int,int> categoryFrequency;
};

#endif // NAIVE_BAYES_H
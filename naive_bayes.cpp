#include "naive_bayes.h"
#include "csv_reader.h"
#include "features.h"
#include "frequency_count.h"
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <cmath>

// This works for each feature
void NaiveBayes::fit(CSVReader trainData) 
{
	for (unsigned int i = 0; i < trainData.dataRows[0].data.size(); i++)
		data.push_back(FrequencyCount());

	for (unsigned int i = 0; i < trainData.dataRows.size(); i++)
	{			
		Features& F = trainData.dataRows[i];
		categoryFrequency[F.value]++;
		
		for (unsigned int j = 0; j < F.data.size(); j++)
		{		
			data[j].addInstance((int) F.value, (int) F.data[j]);
		}
	}
}

double NaiveBayes::getFrequency(int category)
{
	int sumCount = 0;
	for (std::map<int,int>::iterator it = categoryFrequency.begin(); it != categoryFrequency.end(); it++)
	{
		sumCount += it->second;
	}
	return (double) categoryFrequency[category]/sumCount;
}

int NaiveBayes::predict(Features row)
{
	double bestLogProbability = -1e9;
	int categoryIndex = -1;
	int sampleSize = categoryFrequency.size();

	for (std::map<int,int>::iterator it = categoryFrequency.begin(); it != categoryFrequency.end(); it++)
	{
		double logProbability = log(getFrequency(it->first));
		
		for (unsigned int j = 0; j < data.size(); j++)
		{
			logProbability += log(data[j].getProbability( (int) it->first, (int) row.data[j], sampleSize) );
		}
		if (bestLogProbability < logProbability || categoryIndex < 0)
		{
			bestLogProbability = logProbability;
			categoryIndex = it->first;
		}
	}
	return categoryIndex;
}
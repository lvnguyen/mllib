#include <map>
#include <iostream>
#include "frequency_count.h"

void FrequencyCount::addInstance(int category, int value)
{
	if (categoryCollection.find(category) == categoryCollection.end())
	{
		categoryCollection[category] = std::map<int, int>();
	}		

	// Smoothing with value 1
	categoryCollection[category][value]++;	
	categoryCount[category]++;
};

double FrequencyCount::getProbability(int category, int value, int numCategory)
{
	return (double) (categoryCollection[category][value] + 1) / (categoryCount[category] + numCategory);
};
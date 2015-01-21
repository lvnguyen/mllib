#ifndef FREQUENCY_COUNT_H
#define FREQUENCY_COUNT_H

#include <map>

class FrequencyCount
{
public:
	// Each position is a map between category and its frequency
	FrequencyCount() {};

	std::map< int, std::map<int, int> > categoryCollection;
	std::map< int,int > categoryCount;

	void addInstance(int category, int value);
	
	double getProbability(int category, int value, int numCategory);
};

#endif // FREQUENCY_COUNT_H
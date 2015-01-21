#ifndef FEATURES_H
#define FEATURES_H

#include <string>
#include <vector>

class Features
{
public:
	std::vector<int> data;
	bool isTrainData;
	int value;
	void ReadLine(std::string input);
};

#endif // FEATURES_H
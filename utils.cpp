#include "utils.h"
#include "assert.h"
#include <iostream>

std::vector<int> splitInputByCommaByInt(std::string input)
{
	std::vector<int> answer;
	std::istringstream ss(input);
	std::string token;

	while (std::getline(ss, token, ','))
	{
		std::istringstream tokenConvert(token);
		int newValue;
		tokenConvert >> newValue;
		assert(newValue >= 0 and newValue <= 255);
		answer.push_back(newValue);
	}
	return answer;
}

std::vector<std::string> splitInputByCommaByString(std::string input)
{
	std::vector<std::string> answer;
	std::istringstream ss(input);
	std::string token;

	while (std::getline(ss, token, ','))
	{
		std::istringstream tokenConvert(token);
		std::string newValue;
		tokenConvert >> newValue;
		answer.push_back(newValue);
	}
	return answer;
}
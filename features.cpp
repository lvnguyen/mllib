#include <vector>
#include <string>
#include "features.h"
#include "utils.h"

// Right now we assume double-typed
void Features::ReadLine(std::string input)
{
	isTrainData = false;
	data = splitInputByCommaByInt(input);
}
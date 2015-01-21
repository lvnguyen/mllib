#ifndef SOLVER_H
#define SOLVER_H

#include <string>
#include <fstream>
#include <iostream>
#include "csv_reader.h"
#include "naive_bayes.h"

class Solver
{
public:
	void solve() {
		std::string trainFile = "train.csv";
		std::string testFile = "test.csv";
		std::string outFile = "mySubmission.csv";

		CSVReader trainData = CSVReader(trainFile, "label");
		CSVReader testData = CSVReader(testFile, "");

		NaiveBayes model;
		model.fit(trainData);

		std::ofstream outputModel;
		outputModel.open(outFile.c_str(), std::ofstream::out);
		outputModel << "ImageId,Label\n";
		for (int i = 0; i < testData.nRows; i++)
		{
			int answer = model.predict(testData.dataRows[i]);
			outputModel << i + 1 << "," << answer << "\n";
		}
		outputModel.close();
	}
};

#endif // SOLVER_H
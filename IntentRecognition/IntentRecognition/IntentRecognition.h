// IntentRecognition.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.
#include <string>

class IntentRecognition
{
private:
	
	std::string intentInputStr;
	std::string intentOutput;

public:

	// Constructor
	IntentRecognition();

	void printIntroduction();
	void getIntentInputandProcess();
	void identifyIntent();
	void publishIntent();

private:

	bool isQuestionFormat();
	bool isWeatherIntent();
	bool isWeatherWithCityIntent();
	bool isFactIntent();
	bool isDayOrWeekSpecified();

	inline std::size_t findStringInInput(const std::string& searchStr)
	{
		return intentInputStr.find(searchStr);
	};

public:

	// Functions introduced to support unit test	
	void setIntentInput(const std::string& intentStr);
	void getIntentOutput(std::string& intentStr);	
};

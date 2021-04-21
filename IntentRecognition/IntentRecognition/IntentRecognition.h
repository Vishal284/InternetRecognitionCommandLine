// IntentRecognition.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.
#include <string>

#define MAX_INPUT_SIZE 100

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

	bool isWhatOrHowFormat();
	bool isWeatherIntent();
	bool isWeatherWithCityIntent();
	bool isFactIntent();	

};

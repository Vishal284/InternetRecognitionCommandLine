// IntentRecognition.cpp : Defines the entry point of application and Intent recognition class
//

#include "IntentRecognition.h"
#include <vector>
using namespace std;


// Constructor
IntentRecognition::IntentRecognition() : intentOutput ("Intent: ")
{}

// Print the introduction regarding this tool
void IntentRecognition::printIntroduction()
{
	cout << "Hello. I am an Intent Recognition tool. You can ask me anything to check the intent." << endl;
	cout << "e.g. " << endl << "how is the weather" << endl << "please tell me the weather in paris" << endl << "tell me a fact" << endl;
	cout << "NOTE: Please give input in lower case" << endl;
	cout << "*******************************" << endl;
}

// Get the input from the user
void IntentRecognition::getIntentInputandProcess()
{
	std::string decision;
	do
	{
		intentInputStr.clear();
		decision.clear();
		cout << "So how can I help you today? -->  ";
		std::getline(std::cin, intentInputStr);

		// Call the function which will identify the intent
		identifyIntent();
		publishIntent();

		cout << "Type yes, if you want to ask anything else" << endl;
		std::getline(std::cin, decision);

	} while (decision.compare("yes") == 0);

}

// Function to identify the intent of the input
void IntentRecognition::identifyIntent()
{
	// Intent input should be atleast 10 characters
	if (intentInputStr.length() <= 10)
	{
		intentOutput.clear();
		intentOutput.append("INFO: Please elaborate your request, if you wish to continue");		
	}
	// Check if the input is having keywords like what, how, tell
	else if (isQuestionFormat())  
	{		
		// Check if the intent is Weather
		if (isWeatherIntent())
		{
			// Only for Weather intent, we should check the possibility of a city
			isWeatherWithCityIntent();

			// Check if the time is also specified for weather request
			if (isDayOrWeekSpecified())
			{
				// For requesting weather, we can also use the day parameter.
				// However, there is no change in intent. It will still stay "Get Weather"
				// as specified in the task
				//cout << "DAY IS FOUND" << endl;
			}
		}
		// Check for Fact intent
		else
		{
			// Check if its a Fact intent
			isFactIntent();
		}
	}
	// Else, the intent is not supported 
	else
	{
		intentOutput.append("Sorry, its not supported");
	}
}

// Publish the intent on console
void IntentRecognition::publishIntent()
{
	cout << intentOutput << endl;

	// Clear the output string and append the default
	intentOutput.clear();
	intentOutput.append("Intent: ");
}

// Check the question format is what or how or tell
bool IntentRecognition::isQuestionFormat()
{
	std::size_t keywordFound = false;
	std::vector<std::string> keywords = { "what", "how", "tell" };

	// Navigate through the question keywords
	for (auto keyword : keywords)
	{
		if (findStringInInput(keyword) != std::string::npos)
		{
			// If question keyword is found, set the variable to true and break out of the loop
			keywordFound = true;
			break;
		}
	}
	return keywordFound;

}

// Check if the intent is only regarding Weather
bool IntentRecognition::isWeatherIntent()
{
	// It will work only if input is weather. Weather, WEATHER also will not work.
	// I have not used C++ Boost library. Else, the input string can be converted to lower case 
	// And then we just need to check for "weather"	
	if (findStringInInput("weather") != std::string::npos)
	{
		intentOutput.append("Get Weather");
		return true;
	}	

	return false;

}

// Check if the intent also includes a city
bool IntentRecognition::isWeatherWithCityIntent()
{
	// Generally "in" will be used before city name
	// e.g. How is the weather in Paris
	// What is the weather in Paris	

	// If in is found in the string, append the City intent also
	if (findStringInInput("in") != std::string::npos)
	{
		intentOutput.append(" City");
		return true;
	}
	return false;
}

// Check if the intent is Fact
bool IntentRecognition::isFactIntent()
{
	// Check if the user has asked for a fact
	if (findStringInInput("fact") != std::string::npos)
	{
		intentOutput.append("Get fact");
		return true;
	}
	return false;
}

// Check if the user has also requested for weather for a particular
// Day like today or tomorrow or week. 
// Generally weather is not requested for past, so yesterday is not included
bool IntentRecognition::isDayOrWeekSpecified()
{
	std::size_t keywordFound = false;
	std::vector<std::string> dayKeywords = { "today", "tomorrow", "week" };

	// Navigate through the question keywords
	for (auto keyword : dayKeywords)
	{
		if (findStringInInput(keyword) != std::string::npos)
		{
			// If day keyword is found, break out of the loop
			keywordFound = true;			
			break;
		}
	}
	return keywordFound;
}

// Set the intent via function parameter instead of taking from command line
void IntentRecognition::setIntentInput(const std::string& intentStr)
{
	intentInputStr.clear();
	intentInputStr.append(intentStr);
}

// Get the intent output string
void IntentRecognition::getIntentOutput(std::string& intentStr)
{
	intentStr.clear();
	intentStr.append(intentOutput);
}

// End of the file



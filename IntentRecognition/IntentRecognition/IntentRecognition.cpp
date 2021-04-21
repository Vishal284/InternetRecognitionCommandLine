// IntentRecognition.cpp : Defines the entry point for the application.
//

#include "IntentRecognition.h"

using namespace std;

int main()
{	
	IntentRecognition intentReco;
	intentReco.getIntentInput();
	intentReco.publishIntent();

	cout << "Press any key to exit" << endl;
	cin.get();

	return 0;
}

// Constructor
IntentRecognition::IntentRecognition() : intentOutput ("Intent: ")
{}

void IntentRecognition::getIntentInput()
{

	cout << "Hello. How may I help you --> ";
	std::getline(std::cin, intentInputStr);
	
	// Call the function which will identify the intent
	identifyIntent();	
}

// Function to identify the intent of the input
void IntentRecognition::identifyIntent()
{
	// Check if the input is having What or How
	if (isWhatOrHowFormat())
	{
		// Check if the intent is Weather
		if (isWeatherIntent())
		{
			// Only for Weather intent, we should check the possibility of a city
			isWeatherWithCityIntent();
		}		
	}
	// Check if the intent is Fact
	else if (isFactIntent())
	{
		return;
	}
	// Else, the intent is not supported 
	else
	{
		intentOutput.append(" Sorry, its not supported");
	}
}

// Publish the intent on console
void IntentRecognition::publishIntent()
{
	cout << intentOutput << endl;
}

// Check the question format is What or How
bool IntentRecognition::isWhatOrHowFormat()
{
	std::size_t foundWhat = intentInputStr.find("What");
	std::size_t foundHow = intentInputStr.find("How");
	if (foundWhat != std::string::npos || foundHow != std::string::npos)
	{
		return true;
	}

	return false;

}

// Check if the intent is only regarding Weather
bool IntentRecognition::isWeatherIntent()
{
	// It will work only if input is weather or Weather. WEATHER also will not work.
	// I have not used C++ Boost library. Else, the input string can be converted to lower case 
	// And then we just need to check for "weather"
	std::size_t foundL = intentInputStr.find("weather");
	std::size_t foundC = intentInputStr.find("Weather");
	if (foundL != std::string::npos || foundC != std::string::npos)
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
	std::size_t found = intentInputStr.find("in");

	// If in is found in the string, append the City intent also
	if (found != std::string::npos)
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
	std::size_t found = intentInputStr.find("fact");

	if (found != std::string::npos)
	{
		intentOutput.append("Get fact");
		return true;
	}
	return false;
}

// End of the file



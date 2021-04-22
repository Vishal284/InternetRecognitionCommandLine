

#include "IntentRecognition.h"
using namespace std;

int main()
{
	// Create the object of Intent recognition class
	IntentRecognition intentReco;	
	intentReco.printIntroduction();

	// Take input from user and analyze
	intentReco.getIntentInputandProcess();

	return 0;
}
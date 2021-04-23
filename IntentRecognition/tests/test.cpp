// 010-TestCase.cpp
// And write tests in the same file:
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../IntentRecognition/IntentRecognition.h"

// Initialize the object and call the functions
void Initialize(std::string intentStr, std::string& intentOutputStr)
{
    IntentRecognition intentObj;
    intentObj.setIntentInput(intentStr);
    intentObj.identifyIntent();
    intentObj.getIntentOutput(intentOutputStr);

}

TEST_CASE("how is the weather", "first") {
    std::string intentStr = "how is the weather";
    std::string intentOutputStr; intentOutputStr.clear();
    Initialize(intentStr, intentOutputStr);
    REQUIRE(intentOutputStr.compare("Intent: Get Weather") == 0);

}

SCENARIO("Weather and city given together") {

    GIVEN("how is the weather in paris") {
        std::string intentStr = "how is the weather in paris";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("Intent: Get Weather City") == 0);        
    }
}

SCENARIO("What and weather") {

    GIVEN("what is the weather today") {
        std::string intentStr = "what is the weather today";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("Intent: Get Weather") == 0);
    }
}

SCENARIO("What, weather and city") {

    GIVEN("what is the weather in stuttgart today") {
        std::string intentStr = "what is the weather in stuttgart today";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("Intent: Get Weather City") == 0);
    }
}

SCENARIO("tell me and weather") {

    GIVEN("please tell me the weather today") {
        std::string intentStr = "please tell me the weather today";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("Intent: Get Weather") == 0);
    }
}

SCENARIO("Tell me, weather and city") {

    GIVEN("please tell me the weather in cologne today") {
        std::string intentStr = "please tell me the weather in cologne today";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("Intent: Get Weather City") == 0);
    }
}

SCENARIO(" Fact ") {

    GIVEN("tell me an interesting fact") {
        std::string intentStr = "tell me an interesting fact";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("Intent: Get fact") == 0);
    }
}

SCENARIO(" Short input ") {

    GIVEN("hello") {
        std::string intentStr = "hello";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("INFO: Please elaborate your request, if you wish to continue") == 0);
    }
}

SCENARIO(" Short input 2") {

    GIVEN("yes") {
        std::string intentStr = "yes";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("INFO: Please elaborate your request, if you wish to continue") == 0);
    }
}

SCENARIO("Enter only weather") {

    GIVEN("weather today") {
        std::string intentStr = "weather today";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("Intent: Sorry, its not supported") == 0);
    }
}

SCENARIO("Enter weather with city and time") {

    GIVEN("how is the weather today in paris") {
        std::string intentStr = "how is the weather today in paris";
        std::string intentOutputStr; intentOutputStr.clear();
        Initialize(intentStr, intentOutputStr);
        REQUIRE(intentOutputStr.compare("Intent: Get Weather City") == 0);
    }
}
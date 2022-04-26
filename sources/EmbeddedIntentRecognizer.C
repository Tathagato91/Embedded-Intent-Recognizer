#include <algorithm>
#include <cctype>
#include <iostream>
#include <functional>
#include <string>

#include "../headers/EmbeddedIntentRecognizer.h"

using namespace std;

// Constructing object EmbeddedIntentRecognizer
EmbeddedIntentRecognizer::EmbeddedIntentRecognizer()
:mWeather("")
,mFact("")
,mTime("")
,mDate("")
,mPlace("")
{
}

// Destructing object EmbeddedIntentRecognizer
EmbeddedIntentRecognizer::~EmbeddedIntentRecognizer()
{
}

inline bool caseInsCharCompSingle(char a, char b) 
{
   return(tolower(a) == b);
}

// find toSearch string in data string
bool EmbeddedIntentRecognizer::findCaseInsensitive(string data, string toSearch) 
{
   string tmp;
   transform (toSearch.begin(), toSearch.end(), back_inserter(tmp), ::tolower);
   string::iterator it = search(data.begin(), data.end(), tmp.begin(), tmp.end(), caseInsCharCompSingle);
   return ( it != data.end() );   
}

// function called by main()
string EmbeddedIntentRecognizer::extractIntent(const int i_countWords, char** i_words)
{
    string converted = ConvertCLAtoString(i_countWords, i_words);
	return extractIntentSupport(converted);
}

// Support function of extractIntent()
string EmbeddedIntentRecognizer::extractIntentSupport(const string user_Sentense)
{
    // flush out member varibles before running anything
    string finalIntent("");
    mWeather.clear();
    mFact.clear();
    mTime.clear();
    mDate.clear();
    mPlace.clear();
	
    // invoke decicated functions intent validation
    findFactIntent(user_Sentense);
	findWeatherIntent(user_Sentense);
    findPlaceIntent(user_Sentense);
	findTimeIntent(user_Sentense);
	findMomentIntent(user_Sentense);
	
	if(mWeather != "")
	{
		finalIntent.append("Intent: Get Weather");
		if(mPlace != "")
		{
			finalIntent.append(" City");
		}
		if((mTime != "") || (mDate != ""))
		{
			finalIntent.append(" Time");
		}
	}
  
	else if(mFact != "")
		{
			finalIntent.append("Intent: Get Fact");
		}

		 else if((mTime != "") || (mDate != ""))
		{
			finalIntent.append("Intent: Get Appointment");
		} 
		/* All other cases*/
		else
		{
			finalIntent.append("No Intent Recognized");
		}

		return finalIntent;
}

// process the command line input passed as a composite string
string EmbeddedIntentRecognizer::ConvertCLAtoString(const int i_count, char** i_array)
{
    char *str = (char *)malloc(0);
    for(int i = 1; i <= i_count - 1; i++)
    {
        str = (char *)realloc(str, (strlen(i_array[i])));
        strcat(str, i_array[i]);
        strcat(str, " ");
    }
    return str;
}

// decicated functions for weather and fact intent validation
void EmbeddedIntentRecognizer::findWeatherIntent(string user_Sentense)
{
    string word_weather;
	fstream inFile_weather;
    string filename_weather = "../databases/weather_database.txt";
    inFile_weather.open(filename_weather.c_str());

    // extracting words from the database file and compare it with user_Sentense
    while (inFile_weather >> word_weather)
    {
        if( findCaseInsensitive(user_Sentense, word_weather) )
        {
            // setting mWeather gives us the intent at extractIntentSupport()
            mWeather = word_weather;
		}
	}

    // close stream to avoid memory leaks
    inFile_weather.close();
}

// dedicated function to identify place intent
void EmbeddedIntentRecognizer::findPlaceIntent(string user_Sentense)
{
    string word_place;
	fstream inFile_place;
    string filename_place = "../databases/place_database.txt";
	inFile_place.open(filename_place.c_str());
	
    // extracting words from the database file and compare it with user_Sentense
    while (inFile_place >> word_place)
    {
        if( findCaseInsensitive(user_Sentense, word_place) )
        {
            // setting mPlace gives us the intent at extractIntentSupport()
            mPlace = word_place;
        }
	}
    // close stream to avoid memory leaks
    inFile_place.close();
}

// dedicated function to identify time intent
void EmbeddedIntentRecognizer::findTimeIntent(string user_Sentense)
{
    string word_time;
	fstream inFile_time;
    string filename_time = "../databases/time_database.txt";
	inFile_time.open(filename_time.c_str());

    // extracting words from the database file and compare it with user_Sentense
    while (inFile_time >> word_time)
    {
        if( findCaseInsensitive(user_Sentense, word_time) )
        {
            // setting mTime gives us the intent at extractIntentSupport()
            mTime = word_time;
		}
    }
    // close stream to avoid memory leaks
    inFile_time.close();
}

// dedicated function to identify moment intent
void EmbeddedIntentRecognizer::findMomentIntent(string user_Sentense)
{
    smatch foundDate;
    regex tagetDateFormat;

    tagetDateFormat = regex("([0-9][.|:][0-5][0-9]"
                        "|[0-9][.|:][0-5][0-9][ |][a|A][m|M]"
                        "|[0-9][.|:][0-5][0-9][ |][p|P][m|M]"
                        "|[1][0-9][.|:][0-5][0-9]"
                        "|[1][0-9][.|:][0-5][0-9][ |][a|A][m|M]"
                        "|[1][0-9][.|:][0-5][0-9][ |][p|P][m|M]"
                        "|[2][0-3][.|:][0-5][0-9]"
                        "|[2][0-3][.|:][0-5][0-9][ |][a|A][m|M]"
                        "|[2][0-3][.|:][0-5][0-9][ |][p|P][m|M])");
						
	if(regex_search(user_Sentense, foundDate, tagetDateFormat))
    {
        // setting mDate gives us the intent at extractIntentSupport()
	    mDate = string(foundDate[0]);
    }
}

// dedicated function to identify fact intent
void EmbeddedIntentRecognizer::findFactIntent(string user_Sentense)
{
    string word_fact;
	fstream inFile_fact;
    string filename_fact = "../databases/facts_database.txt";
	inFile_fact.open(filename_fact.c_str());

    // extracting words from the database file and compare it with user_Sentense
    while (inFile_fact >> word_fact)
    {
        if( findCaseInsensitive(user_Sentense, word_fact) )
        {
            // setting mFact gives us the intent at extractIntentSupport()
            mFact = word_fact;
		}
	}
	inFile_fact.close();
}
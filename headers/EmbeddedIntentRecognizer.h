#ifndef EMBEDDED_INTENT_RECOGNIZER_H
#define EMBEDDED_INTENT_RECOGNIZER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>

using namespace std;

class EmbeddedIntentRecognizer
{
public:
	EmbeddedIntentRecognizer();
	~EmbeddedIntentRecognizer();
	/*main routine to calculate intent*/
    	string extractIntent(const int i_countWords, char** i_words);
    	string extractIntentSupport(const string i_sentence);

private:
    	/* Member variables for extracting and storing Keywords */
	 string mWeather;
	 string mFact;
	 string mTime;
	 string mDate;
	 string mPlace;
	
	/*data parsing and string utilities*/	
    string ConvertCLAtoString(const int i_count, char** i_array);


	/*intent sub-routines*/
	void findWeatherIntent(string i_sentence);
	void findFactIntent(string i_sentence);
	void findPlaceIntent(string i_sentence);
	void findTimeIntent(string i_sentence);
	void findMomentIntent(string i_sentence);
public:
	bool findCaseInsensitive(string data, string toSearch);
};
#endif
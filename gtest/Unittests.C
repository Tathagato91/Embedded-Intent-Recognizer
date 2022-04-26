#include "googletest/googletest/include/gtest/gtest.h"
#include "../headers/EmbeddedIntentRecognizer.h"

using namespace std;

TEST(EmbeddedIntentRecognizer, extractIntent)
{
    EmbeddedIntentRecognizer enrObject;
    string data = "What is the weather like today";
	string toSearch = "weather";
    size_t result;
    result = enrObject.findCaseInsensitive(data, toSearch);
    GTEST_ASSERT_EQ(result, 1);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    for (int i = 1; i < argc; ++i) {
        printf("arg %2d = %s\n", i, argv[i]);
    }

    return RUN_ALL_TESTS();
}
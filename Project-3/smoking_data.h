#ifndef SMOKING_DATA_H
#define SMOKING_DATA_H

#include <string>

using namespace std;

struct SmokingData{
    string country;
    int year;
    float dailyCigarettes;
    float percentageMale;
    float percentageFemale;
    float percentageTotal;
    int smokersTotal;
    int smokersFemale;
    int smokersMale;

    SmokingData(string country, int year, float dailyCigarettes, float percentageMale, float percentageFemale, float percentageTotal, int smokersTotal, int smokersFemale, int smokersMale) : country(country), year(year), dailyCigarettes(dailyCigarettes), percentageMale(percentageMale),
    percentageFemale(percentageFemale), percentageTotal(percentageTotal), smokersTotal(smokersTotal), smokersFemale(smokersFemale), smokersMale(smokersMale) {}
};

#endif
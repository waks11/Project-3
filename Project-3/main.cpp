
#include "smoking_data.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
using namespace std::chrono;

string removeQuotes(const string& input) {
    if (!input.empty() && input.front() == '"' && input.back() == '"') {
        return input.substr(1, input.size() - 2);
    }
    return input;
}

vector<SmokingData> readCSV(const string &filename) {
    ifstream file(filename);
    vector<SmokingData> data;

    string line;

    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        vector<string> row;
        string val;

        while (getline(ss, val, ',')) {
            row.push_back(removeQuotes(val));
        }



        if (row.size() == 9) {
            SmokingData sd(
                    row[0],
                    stoi(row[1]),
                    stof(row[2]),
                    stof(row[3]),
                    stof(row[4]),
                    stof(row[5]),
                    stoi(row[6]),
                    stoi(row[7]),
                    stoi(row[8])
            );
            data.push_back(sd);
        }
    }

    file.close();
    return data;
}




int main() {
    auto data = readCSV("smoking.csv");
    cout << "Data loaded: " << data.size() << " entries." << endl;
    auto startMerge = high_resolution_clock::now();
    mergeSort(data, 0, data.size() - 1);
    auto stopMerge = high_resolution_clock::now();
    auto durationMerge = duration_cast<microseconds>(stopMerge - startMerge);
    cout << "Merge Sort took " << durationMerge.count() << " microseconds." << endl;

    auto startQuick = high_resolution_clock::now();
    quickSort(data, 0, data.size() - 1);
    auto stopQuick = high_resolution_clock::now();
    auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
    cout << "Quick Sort took " << durationQuick.count() << " microseconds." << endl;

    return 0;
}

//
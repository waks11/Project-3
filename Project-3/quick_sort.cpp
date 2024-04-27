


#include "quick_sort.h"
#include <vector>

using namespace std;


void swap(SmokingData &a, SmokingData &b) {
    SmokingData temp = a;
    a = b;
    b = temp;
}

int partition(vector<SmokingData> &data, int low, int high) {
    SmokingData pivot = data[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (data[j].dailyCigarettes <= pivot.dailyCigarettes) {
            i++;
            swap(data[i], data[j]);
        }
    }
    swap(data[i + 1], data[high]);
    return (i + 1);
}

void quickSort(vector<SmokingData> &data, int low, int high) {
    if (low < high) {
        int pi = partition(data, low, high);
        quickSort(data, low, pi - 1);
        quickSort(data, pi + 1, high);
    }
}

//

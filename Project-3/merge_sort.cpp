

#include "merge_sort.h"
#include <vector>

using namespace std;


void merge(vector<SmokingData>& data, int left, int mid, int right){
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    vector<SmokingData> L(data.begin() + left, data.begin() + mid + 1);
    vector<SmokingData> R(data.begin() + mid + 1, data.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    while (i < subArrayOne && j < subArrayTwo) {
        if (L[i].dailyCigarettes <= R[j].dailyCigarettes) {
            data[k] = L[i];
            i++;
        } else {
            data[k] = R[j];
            j++;
        }
    }
    while (i < subArrayOne) {
        data[k] = L[i];
        i++;
        k++;
    }
    while (j < subArrayTwo) {
        data[k] = R[j];
        j++;
        k++;
    }


}

void mergeSort(vector<SmokingData> &data, int low, int high){
    if (low >= high){
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(data, low, mid);
    mergeSort(data, mid + 1, high);
    merge(data, low, mid, high);
}
//
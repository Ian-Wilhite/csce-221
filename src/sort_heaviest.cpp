// sorting items from the heaviest to lightest
// by selecting the heaviest item at each time  

#include <iostream>
#include <vector>
#include "sort_heaviest.h"

using namespace std;

void sort_heaviest(vector<int>& v, int& comparisons){
    // The index of the heaviest element
    size_t heaviest;

    for (size_t i = 0; i < v.size(); ++i) {
        heaviest = i;
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] > v[heaviest]) {
                heaviest = j;
            }
            comparisons++;
        }
        swap(v[i], v[heaviest]);
    }
}

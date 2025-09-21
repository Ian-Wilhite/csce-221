#include <iostream>
using namespace std;

int main1() {
    // ptr arr on stack to arrays on heap

    int* ptr_arr [10];
    for (int i=0; i<10; i++){
        ptr_arr[i] = new int[](10);
    }
    
    return 0;
}

int main2() {
    // ptr arr on heap to arrays on heap
    int** ptr_arr = new int*[10];
    for (int i=0; i<10; i++){
        ptr_arr[i] = new int[](10);
    }
    return 0;
}



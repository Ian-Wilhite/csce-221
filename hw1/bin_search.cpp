#include <bits/stdc++.h>
using namespace std;

static long long num_comp = 0;  // global comparison counter

// Helper: verify ascending order (strict or nondecreasing, pick one; slides imply ascending)
template <typename T>
bool is_sorted_ascending(const vector<T>& v) {
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i-1] > v[i]) return false;
    }
    return true;
}

// Templated binary search (lower_bound style) that counts comparisons in num_comp.
// Matches your lecture slide structure; only templated and with a sortedness check.
template <typename T>
int Binary_Search(vector<T> &v, const T& x) {
    if (!is_sorted_ascending(v)) {
        throw runtime_error("Binary_Search: input vector is not sorted in ascending order.");
    }
    int mid, low = 0;
    int high = static_cast<int>(v.size()) - 1;

    while (low < high) {
        mid = (low + high) / 2;
        if (num_comp++, v[mid] < x) low = mid + 1;
        else high = mid;
    }
    if (num_comp++, x == v[low]) return low; // OK: found
    return -1; // not found
}

int main() {
    // 16 ascending elements
    vector<int> v{2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32};

    // Case (a): target x is the first element
    num_comp = 0;
    int idxA = Binary_Search(v, v.front());
    cout << "(a) first element => index " << idxA << ", num_comp = " << num_comp << "\n";

    // Case (b): target x is the last element
    num_comp = 0;
    int idxB = Binary_Search(v, v.back());
    cout << "(b) last element  => index " << idxB << ", num_comp = " << num_comp << "\n";

    // Case (c): target x is in the middle (with n=16 there are two middles: indices 7 and 8)
    // We'll test both to be explicit.
    num_comp = 0;
    int idxC1 = Binary_Search(v, v[7]);  // left middle
    cout << "(c1) middle (index 7) => index " << idxC1 << ", num_comp = " << num_comp << "\n";

    num_comp = 0;
    int idxC2 = Binary_Search(v, v[8]);  // right middle
    cout << "(c2) middle (index 8) => index " << idxC2 << ", num_comp = " << num_comp << "\n";

    // Conclusion for n=16
    cout << "\nConclusion for n=16: the loop performs log2(16)=4 '<' comparisons,\n"
            "plus the final equality check, totaling 5 comparisons when found.\n";

    // Optional: demonstrate unsorted error (uncomment to see exception)
    // vector<int> bad = v; swap(bad[0], bad[1]);
    // num_comp = 0; Binary_Search(bad, 10);

    return 0;
}

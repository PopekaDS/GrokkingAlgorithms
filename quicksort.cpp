#include <iostream>
#include <vector>
using namespace std;

vector <int> plusVector(vector <int> v1, int item, vector <int> v2) {
    vector <int> out;
    for(auto now: v1) {
        out.push_back(now);
    }
    out.push_back(item);
    for(auto now: v2) {
        out.push_back(now);
    }
    return out;
}

vector <int> quicksort(vector <int>& v) {
    // base case, arrays with 0 or 1 element are already "sorted"
    if(v.size() < 2) {
        return v;
    } else {
        // recursive case
        int pivot = v[0];
        // sub-array of all the elements less than the pivot
        vector <int> less;
        
        // sub-array of all the elements greater than the pivot
        vector <int> greater;
        
        for(int i = 1; i < v.size(); ++i) {
            if(v[i] <= pivot) {
                less.push_back(v[i]);
            } else {
                greater.push_back(v[i]);
            }
        }
        return plusVector(quicksort(less), pivot, quicksort(greater));
    }
}

int main()
{
    
    vector <int> a = {10, 5, 2, 3};
    a = quicksort(a);
    for(auto now: a) {
        cout << now << " ";
    }
    return 0;
}

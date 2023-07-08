#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Finds the smallest value in an array
int findSmallest(vector<int> v) {
    // Stores the smallest value
    int smallest = v[0];
    // Stores the index of the smallest value
    int smallest_index = 0;
    for(int i = 0; i < v.size(); ++i) {
        if(v[i] < smallest) {
            smallest = v[i];
            smallest_index = i;
        }
    }
    
    return smallest_index;
}

// Sort array
vector <int> selectionSort(vector <int> v) {
    vector <int> newV;
    
    while(!v.empty()) {
        // Finds the smallest element in the array and adds it to the new array
        int smallest = findSmallest(v);
        vector<int>::iterator it = find(v.begin(), v.end(), v[smallest]);
        newV.push_back(v[smallest]);
        v.erase(it);
    }
    
    return newV;
}

int main() {
    vector <int> v2, v1 = {5, 3, 6, 2, 10};
    v2 = selectionSort(v1);
    for(auto now: v2) {
        cout << now << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> v, int item) {
    // low and high keep track of which part of the list you'll search in.
    int low = 0;
    int high = v.size() - 1;
    
    // While you haven't narrowed it down to one element ...
    while(low <= high) {
        // ... check the middle element
        int mid = (low + high) / 2;
        int guess = v[mid];
        // Found the item.
        if(guess == item) {
            return mid;
        }
        // The guess was too high.
        if(guess > item) {
            high = mid - 1;
        } else {
            // The guess was too low.
            low = mid + 1;
        }
    }
    // Item doesn't exist
    cout << "\nItem doesn't exist\n";
    return -1;
}

int main()
{
    vector <int> example {1, 3, 5, 7, 9};
    cout << binary_search(example, 3); // 1
    cout << binary_search(example, -1); // -1

    return 0;
}
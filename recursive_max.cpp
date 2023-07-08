#include <iostream>
#include <vector>
using namespace std;

vector <int> slice(vector <int> v, int m, int n) {
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n + 1;
 
    vector<int> vec(first, last);
    return vec;
}

int max(vector <int> v) {
    if(v.size() == 2) {
        return (v[0] > v[1]) ? v[0] : v[1];
    }
    int sub_max = max(slice(v, 1, v.size() - 1));
    return (v[0] > sub_max) ? v[0] : sub_max;
}

int main()
{
    vector <int> a = {-4, 3, 2, 5, 3, 2};
    cout << max(a);
    return 0;
}

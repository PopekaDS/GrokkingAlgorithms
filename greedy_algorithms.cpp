#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

void print(set<string> s) {
    for(auto now: s) {
        cout << now << " ";
    }
    cout << endl;
}

int main()
{
    set<string> states_needed{"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};
    map<string, set<string>> stations;

    stations["kone"] = {"id", "nv", "ut"};
    stations["ktwo"] = {"wa", "id", "mt"};
    stations["kthree"] = {"or", "nv", "ca"};
    stations["kfour"] = {"nv", "ut"};
    stations["kfive"] = {"ca", "az"};
    
    set<string> final_stations;
    while(!states_needed.empty()) {
        string best_station = "None";
        set<string> states_covered;
        for(auto now: stations) {
            string station = now.first;
            set<string> states = now.second;
            set<string> covered;
            for(auto s: states_needed){
                if(states.count(s) != 0) {
                    covered.insert(s);
                }
            }

            for(auto s: states_needed) {
                if(covered.size() > states_covered.size()) {
                    best_station = station;
                    states_covered = covered;
                }
            }
        }

        for(auto s: states_covered) {
            states_needed.erase(s);
        }

        final_stations.insert(best_station);
    }
    for(auto fs: final_stations) {
        cout << fs << " ";
    }
    
    return 0;
}
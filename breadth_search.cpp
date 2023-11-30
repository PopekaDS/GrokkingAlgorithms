#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

bool person_is_seller(string name) {
    return name[name.size() - 1] == 'm';
}

bool search(map <string, vector<string>> graph, string name) {
    std::deque<string> search_queue;
    for(int i = 0; i < graph[name].size(); ++i) {
        search_queue.push_back(graph[name][i]);
    }
    
    // This array is how you keep track of which people you've searched before.
    std::deque<string> searched = {};
    while(!search_queue.empty()) {
        string person = search_queue[0];
        search_queue.pop_front();

        // Only search this person if you haven't already searched them.
        auto itr = find(searched.begin(), searched.end(), person);
        if(itr == searched.end()) {
            if(person_is_seller(person)) {
                cout << person << " is a mango seller!\n";
                return true;
            } else {
                for(int i = 0; i < graph[person].size(); ++i) {
                    search_queue.push_back(graph[person][i]);
                    // Marks this person as searched
                    searched.push_back(person);
                }  
            }
        }
    }
    
    return false;
}

int main()
{
    map <string, vector<string>> graph;
    graph["you"] = {"alice", "bob", "claire"};
    graph["bob"] = {"anuj", "peggy"};
    graph["alice"] = {"peggy"};
    graph["claire"] = {"thom", "jonny"};
    graph["anuj"] = {};
    graph["peggy"] = {};
    graph["thom"] = {};
    graph["jonny"] = {};
    
    search(graph, "you");
    return 0;
}
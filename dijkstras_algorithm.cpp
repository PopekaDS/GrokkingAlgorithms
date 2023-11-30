#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string find_lowest_cost_node(map<std::string, int> costs, vector <string> processed) {
    int lowest_cost = 99999999;
    string lowest_cost_node = "";
    // Go through each node.    
    for(auto node: costs) {
        int cost = node.second;
        // If it's the lowest cost so far and hasn't been processed yet...
        auto itr = find(processed.begin(), processed.end(), node.first);
        if(cost < lowest_cost && itr == processed.end()) {
            // ... set it as the new lowest-cost node.
            lowest_cost = cost;
            lowest_cost_node = node.first;
        }
    }
    
    return lowest_cost_node;
}

int main()
{
    // the graph
    map<std::string, map<std::string, int>> graph;
    graph["start"] = {};
    graph["start"]["a"] = 6;
    graph["start"]["b"] = 2;
    
    graph["a"] = {};
    graph["a"]["fin"] = 1;
    
    graph["b"] = {};
    graph["b"]["a"] = 3;
    graph["b"]["fin"] = 5;
    
    graph["fin"] = {};
    
    // the costs table
    map<std::string, int> costs;
    costs = {};
    costs["a"] = 6;
    costs["b"] = 2;
    costs["fin"] = 99999999;
    
    // the parents table
    map<std::string, string> parents;
    parents["a"] = "start";
    parents["b"] = "start";
    parents["fin"] = "0";
    
    vector <string> processed = {};
    
    // Find the lowest-cost node that you haven't processed yet.
    string node = find_lowest_cost_node(costs, processed);

    // If you've processed all the nodes, this while loop is done.
    while(node != "") {
        int cost = costs[node];
        // Go through all the neighbors of this node.
        map<std::string, int> neighbors = graph[node];
        for(auto n: neighbors) {
            int new_cost = cost + neighbors[n.first];
            // If it's cheaper to get to this neighbor by going through this node...
            if (costs[n.first] > new_cost) {
                // ... update the cost for this node.
                costs[n.first] = new_cost;
                // This node becomes the new parent for this neighbor.
                parents[n.first] = node;
            }
        }
        
        // Mark the node as processed.
        processed.push_back(node);
        // Find the next node to process, and loop.
        node = find_lowest_cost_node(costs, processed);
    }
    cout << "Cost from the start to each node:\n";
    for(auto now: costs) {
        cout << now.first << " " << now.second << '\n';
    }
    return 0;
}


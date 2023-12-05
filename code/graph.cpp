#include<iostream>
#include<map>
#include<vector>
#include<tuple>

using namespace std;

class Graph{
    public:
        map<string, vector<tuple<string, int>>> adjList;
        void addEdge(string u, string v, int weight = 1){
            adjList[u].push_back(make_tuple(v, weight));
            adjList[v].push_back(make_tuple(u, weight));

        }
        vector<string> getSuccessor(string s){
            vector<string> result;
            for(auto neighbour : adjList[s]){
                result.push_back(get<0>(neighbour));
            }
            return result;
        }
        string getStartState(){
            return "Syracuse";
        }
        bool isGoalState(string s){
            if(s == "Manhattan"){
                return true;
            }
            return false;
        }

};


map<string, bool> visited;


void dfs(Graph g, string s){
    visited[s] = true;
    cout << s << endl;
    for(string neighbour : g.getSuccessor(s)){
        if(!visited[neighbour]){
            dfs(g, neighbour);
        }
    }
}
 
int main(){
    Graph g;
    g.addEdge("Syracuse", "Rome", 44);
    g.addEdge("Syracuse", "Cortland", 33);
    g.addEdge("Cortland", "Binghamton", 43);
    g.addEdge("Binghamton", "Scranton", 57);
    g.addEdge("Binghamton", "Hancock", 41);
    g.addEdge("Scranton", "Stroudsburg", 43);
    g.addEdge("Stroudsburg", "Manhattan", 84);
    g.addEdge("Rome", "Albany", 110);
    g.addEdge("Albany", "Woodbury", 96);
    g.addEdge("Woodbury", "Manhattan", 48);
    g.addEdge("Hancock", "Woodbury", 100);


    dfs(g, g.getStartState())
    return 0;
}
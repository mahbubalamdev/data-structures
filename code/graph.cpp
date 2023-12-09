#include<iostream>
#include<map>
#include<vector>
#include<tuple>
#include<queue>
#include <algorithm>

using namespace std;

typedef pair<int, string> state;

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


vector<string> dfs(Graph g, string s){
    visited[s] = true;
    if (g.isGoalState(s)){
        return {s};
    }
    vector<string> neighbours = g.getSuccessor(s);
    sort(neighbours.begin(), neighbours.end());

    for(string neighbour : neighbours){
        if(!visited[neighbour]){
            vector<string> result = dfs(g, neighbour);
            if(!result.empty()){
                result.push_back(s);
                return result;
            }
        }
    }
    return {};
}

vector<string> bfs(Graph g, string s){
    map<string, string> parent;
    queue<string> queue;
    queue.push(s);
    parent[s] = "";
    visited[s] = true;
    while(!queue.empty()){
        string current = queue.front();
        queue.pop();
        vector<string> neighbours = g.getSuccessor(current);
        sort(neighbours.begin(), neighbours.end());
        for(string neighbour : neighbours){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                queue.push(neighbour);
                parent[neighbour] = current;
                if (g.isGoalState(neighbour)){
                    break;
                }
            }
        }
    }

    vector<string> result;
    string current = "Manhattan";
    while(current != ""){
        result.push_back(current);
        current = parent[current];
    }
    return result;
}

vector<string> djkistra(Graph g, string s, string goal){
    priority_queue<state, vector<state>, greater<state>> pq;
    map<string, int> dist;

    pq.push(make_pair(0, s));
    dist[s] = 0;
    while(!pq.empty()){
        string node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

    
        vector<tuple<string, int>>::iterator it;ß
        for(it=g.adjList[node].begin(); it!=g.adjList[node].end(); ++it){
            int newDistance = distance + (get<1>(*it));
            if(!dist.count(neighbour) || newDistance < dist[neighbour]){
                dist[neighbour] = newDistance;
                pq.push(make_pair(newDistance, neighbour));
            }
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


    cout << "DFS" << endl;
    visited = map<string, bool>();
    vector<string> path = dfs(g, g.getStartState());
    reverse(path.begin(), path.end());
    for(string s : path){
        cout << s << endl;
    }

    cout << "\nBFS" << endl;
    visited = map<string, bool>();
    path = bfs(g, g.getStartState());
    reverse(path.begin(), path.end());
    for(string s : path){
        cout << s << endl;
    }

    return 0;
}
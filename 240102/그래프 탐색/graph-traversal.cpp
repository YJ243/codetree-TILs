#include <iostream>
#include <vector>
#define MAX_N 1000
using namespace std;
int n, m;
vector<int> graph[MAX_N+1];
bool visited[MAX_N+1];
int ans;

void DFS(int v){
    for(int i=0; i<graph[v].size(); i++){
        if(!visited[graph[v][i]]){
            visited[graph[v][i]] = true;
            DFS(graph[v][i]);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    int root_v = 1;
    visited[root_v] = true;
    DFS(root_v);

    for(int i=2; i<=n; i++){
        if(visited[i]) ans++; 
    }
    
    cout << ans;
    return 0;
}
#include <iostream>
#include <vector>
#define MAX_N 1000
using namespace std;

int N, M;
vector<int> graph[MAX_N+1];
bool visited[MAX_N+1];

void DFS(int vertex){
    for(int i=0; i<graph[vertex].size(); i++){
        if(!visited[graph[vertex][i]]){
            visited[graph[vertex][i]] = true;
            DFS(graph[vertex][i]);
        }
    }
}
int main(){
    cin >> N >> M;
    while(M--){
        int x,y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int root_vertex = 1;
    visited[root_vertex] = true;
    DFS(root_vertex);
    int result = 0;
    for(int i=1; i<=N; i++){
        if(visited[i]) result++;
    }
    cout << result-1 << '\n';
}
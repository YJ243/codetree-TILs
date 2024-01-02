#include <iostream>
#include <vector>
#define MAX_N 1000
using namespace std;
int n, m;

// index를 1번부터 사용하기 위해 MAX_N+1만큼 할당하기
vector<int> graph[MAX_N+1];
bool visited[MAX_N+1];
int ans;

void DFS(int v){
    // 해당 정점에서 이어져있는 모든 정점을 탐색해주기
    for(int i=0; i<graph[v].size(); i++){
        if(!visited[graph[v][i]]){
            // 아직 방문한 적이 없는 정점에 대해서만 탐색 진행
            visited[graph[v][i]] = true;
            DFS(graph[v][i]);
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        // 각 정점이 서로 이동이 가능한 양방향 그래프이기 때문에
        // 각 정점에 대한 간선을 각각 저장해주
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
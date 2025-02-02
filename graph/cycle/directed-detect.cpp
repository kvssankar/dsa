vector<int>visited;
bool isCycle(int v, vector<int>adj[]){
    visited[v]=1;
    for(int i:adj[v]){
        if(visited[i]==1) return true;
        if(visited[i]==0 && isCycle(i,adj)) return true;
    }
    visited[v]=2;
    return false;
}
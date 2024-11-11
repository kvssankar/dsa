void dfs(vector<int> adj[], int start, vector<int>&visited){
    visited[start]=1;
    cout<<start<<endl;
    for(int i:adj[start]){
        if(!visited[i]){
            dfs(adj,i,visited);
        }
    }
}

int main(){
    int v;e;
    cin>>v>>e;
    vector<int>adj[v];
    vector<int>visited(v,0);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}
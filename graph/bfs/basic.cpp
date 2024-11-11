
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

    vector<int>visited(v,0);
    visited[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
        for(int i:adj[temp]){
            if(!visited[i]){
                visited[i]=1;
                q.push(i);
            }
        }
    }
}
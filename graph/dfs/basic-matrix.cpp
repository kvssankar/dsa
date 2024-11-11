//adj matrix
#include <bits/stdc++.h>
using namespace std;

void dfs(int **edges, int start, vector<int>&visited){
    visited[start]=1;
    cout<<start<<endl;
    int v=visited.size();
    for(int i=0;i<v;i++){
        if(edges[start][i] && visited[i]==0){
            dfs(edges,i,visited);
        }
    }
}


int main(){
    int v,e;
    cin>>v>>e;

    int **edges = new int*[v];
    for(int i=0;i<v;i++){
        edges[i]= new int[v];
        for(int j=0;i<v;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edges[a][b]=1;
    }

    return 0;
}
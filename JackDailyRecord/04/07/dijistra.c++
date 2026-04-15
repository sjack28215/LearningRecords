#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
const int INF = 0x3f3f3f3f;

int n,m;
vector<pair<int,int>> g[N];
int dist[N];
bool vis[N];

void dijistra(int s){
    memset(dist,0x3f,sizeof dist);
    memset(vis,false,sizeof dist);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    dist[0] = 0;
    pq.push_back{0,s};
}
int main(){
    cin >> n >> m;
    for(int i = 0;i < n;i ++){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w})
    }

    int s = 1;
    dijiistra(s);
}
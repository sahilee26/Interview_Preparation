#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define lld long double
struct Edge{
    ll from;
    ll next;
    lld weight;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    Edge edges[2*k];
    ll u, v;
    lld w;
    for(ll i=0; i<2*k; i+=2){
        cin >> u >> v >> w;
        edges[i].from=u;
        edges[i].next=v;
        edges[i].weight=-log(w);
        edges[i+1].from=v;
        edges[i+1].next=u;
        edges[i+1].weight=-log(1/w);
    }
    int flag=0;
    ll src=0;
    lld dist[n];
    for(ll i=0; i<n; i++)
        dist[i]=1e12;
    dist[src]=0.0;
    for(ll i=0; i<n-1; i++){
        for(ll j=0; j<2*k; j++){
            u=edges[j].from;
            v=edges[j].next;
            w=edges[j].weight;
            if(dist[u] != 1e12 && dist[u] + w < dist[v])
                dist[v]=dist[u]+w ;
        }
    }
    for(ll j=0; j<2*k; j++){
        u=edges[j].from;
        v=edges[j].next;
        w=edges[j].weight;
        if(dist[u] != 1e12 && dist[u] + w < dist[v]){
            flag=1;
            break;
        }
    }
    if(flag==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

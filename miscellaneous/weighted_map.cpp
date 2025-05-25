#include<iostream>
#include<list>
#include<vector>
using namespace std;
vector<list<pair<int,int>>> graph;
int v;
void add_edge(int source, int destination,int weight, bool bi_dir= true){
    graph[source].push_back({destination,weight});
    if(bi_dir){
        graph[destination].push_back({source,weight});
    }
    return;
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele: graph[i]){
            cout<<"("<<ele.first<<","<<ele.second<<")"<<" ";
        }
        cout<<endl;
    }
    return;
}
int main(){
    cin>>v;
    graph.resize(v,list<pair<int,int>> ());
    int e;
    cin>>e;
    while(e--){
        int s,d,wet;
        cin>>s>>d>>wet;
        add_edge(s,d,wet);
    }
    display();
    return 0;
}
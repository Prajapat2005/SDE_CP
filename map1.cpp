#include<iostream>
#include<list>
#include<vector>
using namespace std;
vector<list<int>> graph;
int v;
void add_edge(int source, int destination, bool bi_dir= true){
    graph[source].push_back(destination);
    if(bi_dir){
        graph[destination].push_back(source);
    }
    return;
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" -> ";
        for(auto ele: graph[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return;
}
int main(){
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
    return 0;
}
/* 
7
7
0 2
0 1
1 5
2 5
2 3
3 6
6 4
   
0 -> 2 1 
1 -> 0 5 
2 -> 0 5 3 
3 -> 2 6 
4 -> 6 
5 -> 1 2 
6 -> 3 4 
*/
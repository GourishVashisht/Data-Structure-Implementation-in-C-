#include<iostream>
#include<list>
#include<queue>
#include<map>
#include<limits.h>
using namespace std;

class graph
{
    int v;
    list<int> *l;
public:
    graph(int v){
        this->v=v;
        l=new list<int>[v];
    }

    void addEdge(int u,int v,bool bidir=true){
        l[u].push_back(v);
        if(bidir)
            l[v].push_back(u);
    }

    void printAdjacencyList(){
        for(int i=0;i<v;i++){
            cout<<i<<"->";
            for(list<int>::iterator it=l[i].begin();it!=l[i].end();it++)
                cout<<*it<<",";
            cout<<endl;
        }
    }

    void bfs(int src)
    {
        queue<int> q;
        q.push(src);
        map<int,int> dist;
        dist[src]=0;
        map<int,int>::iterator it;
        for(int i=1;i<v;i++)
        {
            dist[i]=INT_MAX;
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(list<int>::iterator it=l[node].begin();it!=l[node].end();it++){
                if(dist[*it]==INT_MAX){
                    q.push(*it);
                    dist[*it]=dist[node]+1;
                }
            }
        }
        /// printing the distance map
        for(it=dist.begin();it!=dist.end();it++){
            int temp=it->first;
            cout<<"Distance of ";
            cout<<temp;
            cout<<" from "<<src<<" is : "<<dist[it->first]<<endl;
        }
    }
};
int main()
{
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<<"The adjacency list is as follows : \n";
    g.printAdjacencyList();
    cout<<endl;

    cout<<"Single source shortest path using Breadth first search algorithm : \n";
    g.bfs(0);
    cout<<endl;

}



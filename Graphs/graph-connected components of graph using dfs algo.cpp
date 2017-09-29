#include<iostream>
#include<map>
#include<list>
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

    void dfsHelper(int val,map<int,bool> &visited)
    {
        visited[val]=true;
        cout<<val<<" ";
        int components=1;
        for(list<int>::iterator it=l[val].begin();it!=l[val].end();it++)
        {
            if(!visited[*it])
                dfsHelper(*it,visited);
        }

    }

    void dfs(int src)
    {
        map<int,bool> visited;
        dfsHelper(src,visited);
        int components=1;
        for(int i=0;i<v;i++){
        for(list<int>::iterator it=l[i].begin();it!=l[i].end();it++)
        {
            if(!visited[*it])
            {
                dfsHelper(*it,visited);
                components++;
            }
        }
        }
        cout<<endl;
        cout<<"This graph has "<<components<<" components."<<endl;
    }
};
int main()
{
    graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(0,2);
    g.addEdge(4,5);

    cout<<"The adjacency list is as follows : \n";
    g.printAdjacencyList();
    cout<<endl;

    cout<<"Depth first search algorithm : \n";
    g.dfs(0);
}


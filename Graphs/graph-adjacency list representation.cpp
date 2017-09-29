#include<iostream>
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

    void checkEdgeExist(int u,int v){
        int f=1;
        if(u>=0 && u<v){
            for(list<int>::iterator it=l[u].begin();it!=l[u].end();it++){
                if(*it==v){
                    f=0;
                    cout<<"Yes The edge exist between "<<u<<" and "<<v<<endl;
                }
            }
            if(f)
                cout<<"No edge exist between "<<u<<" and "<<v<<endl;
        }
        else{
            cout<<"No edge exist between "<<u<<" and "<<v<<endl;
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
    g.addEdge(0,2);

    g.printAdjacencyList();

    g.checkEdgeExist(2,3);
}

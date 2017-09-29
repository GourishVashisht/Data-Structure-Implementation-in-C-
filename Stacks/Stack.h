#include<vector>
using namespace std;
template <typename T>
class Stack
{
public:
    vector<T> v;
    void push(T val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    T top()
    {
        T val=v.back();
        return val;
    }
    bool isEmpty()
    {
        return v.empty();
    }
};

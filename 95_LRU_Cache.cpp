#include<bits/stdc++.h>
using namespace std;

class LRUCache
{
    public:
    unordered_map<int,int> mymap;
    list<int> lists;
    int cp;

    LRUCache(int capacity)
    {
        cp=capacity;
        mymap.clear();
        lists.clear();
    }

    int get(int key)
    {
        if(mymap.find(key)==mymap.end())
        {
            return -1;
        }
        lists.remove(key);
        lists.push_front(key);
        return mymap[key];
    }

    void put(int key,int value)
    {
        if(mymap.find(key)==mymap.end())
        {
            if(lists.size()==cp)
            {
                int last=lists.back();
                lists.pop_back();
                mymap.erase(last);
            }
            mymap[key]=value;
            lists.push_front(key);
        }
        else{
            mymap[key]=value;
            lists.remove(key);
            lists.push_front(key);
        }
    }
};

int main()
{
    LRUCache l(2);
    l.put(1,1);
    l.put(2,2);
    cout<<l.get(1)<<endl;
    l.put(3,3);
    cout<<l.get(4)<<endl;
    l.put(4,4);
}
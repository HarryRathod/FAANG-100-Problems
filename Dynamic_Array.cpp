#include<iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int index;
    int size;

public:
    DynamicArray()
    {
        data=new int[5];
        index=0;
        size=5;
    }

    DynamicArray(int c)
    {
        data=new int[c];
        index=0;
        size=c;
    }

    DynamicArray(DynamicArray const &d)
    {
        this->index=d.index;
        this->size=d.size;
        this->data=new int[d.size];
        for(int i=0;i<index;i++)
            this->data[i]=d.data[i];
    }

    void operator=(DynamicArray const &d)
    {
        this->index=d.index;
        this->size=d.size;
        this->data=new int[d.size];
        for(int i=0;i<index;i++)
            this->data[i]=d.data[i];
    }
    void add(int x)
    {
        if(index==size)
        {
            int *newdata=new int[2*size];
            size=2*size;
            for(int i=0;i<index;i++)
                newdata[i]=data[i];
            delete []data;
            data=newdata;
        }
        data[index++]=x;
    }

    int getElement(int i)
    {
        if(i>=0 && i<index)
            return data[i];
        else
            return -1;
    }

    void insert(int x,int i)
    {
        if(i>=0 && i<index)
            data[i]=x;
        else if(i==index)
            add(x);
        else
            cout<<"Please enter Valid Index"<<endl;
    }

    void print()
    {
        for(int i=0;i<index;i++)
            cout<<data[i]<<" ";
        cout<<endl;
    }

    int getSize()
    {
        return size;
    }

};

int main()
{
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    d1.insert(100,3);

    cout<<d1.getElement(3)<<endl;

    d1.print();

    DynamicArray d2(d1);
    d2.print();

    d1.insert(500,5);
    d1.print();
    d2.print();

    cout<<endl;

    DynamicArray d3;
    d3=d1;

    d1.add(111);

    d1.print();

    d3.print();

    DynamicArray d4(105);

    cout<<d4.getSize()<<endl;

    return 0;
}

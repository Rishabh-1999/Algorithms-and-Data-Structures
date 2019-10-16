#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
class hashTable
{
    int capacity;
    vector<int> *hash;

    public:
        hashTable(int cap)
        {
            capacity=cap;
            hash=new vector<int>[cap];
        }

        int hashFunction(int x)
        {
            return x%capacity;
        }

        void insert(int data)
        {
            int i=hashFunction(data);
            hash[i].push_back(data);
        }

        void displayHashTable()
        {
            for(int i = 0;i<capacity;i++)
            {
                cout<<i;
                vector<int>::iterator it;
                for(it=hash[i].begin();it!=hash[i].end();it++)
                {
                    cout<<"--> "<<*it<<' ';
                }
                cout<<endl;
            }
        }
};

int main()
{
    hashTable h(10);
    int n;
    cin>>n;
    int data;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        h.insert(data);
    }
    cout<<endl;
    h.displayHashTable();
}

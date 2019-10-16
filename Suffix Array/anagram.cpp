#include<iostream>
using namespace std;
int main()
{
    string str;
    cin>>str;
    string str1;
    cin>>str1;
    int ar[26]={0};
    int c=0;
    if(str.length()!=str1.length())
        cout<<"Not Anagram";
    else{
        for(int i=0;i<str.length();i++)
            ar[str[i]-97]++;
        for(int i=0;i<str1.length();i++)
            ar[str[i]-97]--;
        for(int i=0;i<26;i++)
            {
            if(ar[i]!=0)
            {
                c=1;
                break;
            }
            }
            if(c==0)
            cout<<"Anagram";
    }
}

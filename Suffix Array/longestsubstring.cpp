#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string str;
    int k=-1;
    cin>>str;
    
    char store[100][100];
    for(int i=0;i<str.length();i++)
    {
        char temp[100];
        int k1=-1;
        for(int j=i;j<str.length();j++)
            temp[++k1]=str[j];
        temp[++k1]='\0';
        strcpy(store[++k],temp);
    }
    
    for(int i=0;i<k;i++)
        for(int j=i+1;j<=k;j++)
        if(strcmp(store[i],store[j])>0)
    {
        char temp[100];
        strcpy(temp,store[i]);
        strcpy(store[i],store[j]);
        strcpy(store[j],temp);
    }
    
    int max=0;
    string result;
    int x=0,count=0;
    for(int i=0;i<k;i++)
    {
        x=0;
        count=0;
        char temp[100];
        int k1=-1;
        while(x<strlen(store[i]) && x<strlen(store[i+1]))
        {
            if(store[i][x]!=store[i+1][x])
                break;
                count++;
                temp[++k1]=store[i][x];
            x++;
        }
        
        if(count>max)
        {
            max=count;
            if(x==strlen(store[i]))
            result=store[i];
            else if(x==strlen(store[i+1]))
                result=store[i+1];
            else
            {
                temp[++k1]='\0';
                result=temp;
            }
        }
    }
    cout<<result;
    return 0;
}

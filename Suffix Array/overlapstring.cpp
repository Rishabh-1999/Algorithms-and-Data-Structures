
#include<iostream>
#include<string.h>
using namespace std;
struct Node{
int id;
char part[100];
};
int main()
{

    string str;
    int k=-1;
    cin>>str;
    struct Node ptr[100];
    for(int i=0;i<str.length();i++)
    {
        char temp[100];
        int k1=-1;
        for(int j=i;j<str.length();j++)
            temp[++k1]=str[j];
        temp[++k1]='\0';
        ptr[++k].id=i;
        strcpy(ptr[k].part,temp);
    }
    for(int i=0;i<k;i++)
        for(int j=i+1;j<=k;j++)
        if(strcmp(ptr[i].part,ptr[j].part)>0)
    {
        struct Node temp;
        temp=ptr[i];
        ptr[i]=ptr[j];
        ptr[j]=temp;
    }
    for(int i=0;i<=k;i++)
    {
        cout<<ptr[i].id<<" "<<ptr[i].part<<endl;
    }
    int max=0;
    string result;
    int x=0,count=0,overlap=0;
    for(int i=0;i<k;i++)
    {
        x=0;
        count=0;
        char temp[100];
        int k1=-1;
        while(x<strlen(ptr[i].part)&&x<strlen(ptr[i+1].part))
        {
            if(ptr[i].part[x]!=ptr[i+1].part[x])
                break;
                count++;
                temp[++k1]=ptr[i].part[x];
            x++;
        }
        if(count>max)
        {
            max=count;
            if(x==strlen(ptr[i].part))
            {
            result=ptr[i].part;
            if(ptr[i].id==ptr[i+1].id+(count-1))
                overlap=1;
            else if(ptr[i+1].id==ptr[i].id+(count-1))
                overlap=1;
            else
                overlap=0;
            }
            else if(x==strlen(ptr[i+1].part))
            {
            result=ptr[i+1].part;
            if(ptr[i].id==ptr[i+1].id+(count-1))
                overlap=1;
            else if(ptr[i+1].id==ptr[i].id+(count-1))
                overlap=1;
            else
                overlap=0;
            }
            else
            {
                temp[++k1]='\0';
                result=temp;
            }

        }
    }
    if(overlap==1)
    cout<<"Overlap"<<endl;
    cout<<result;
}

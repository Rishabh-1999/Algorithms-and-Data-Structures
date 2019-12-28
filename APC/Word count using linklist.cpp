#include <iostream>
using namespace std;
int z=0;
char f[200];
struct word
{
    char *str;
    int Count;
    word *ptr = NULL;
};

struct hash
{
    word *ptr = NULL;
} node[250];

int compareWord(char *str, char *str2)
{
    int i=0;
    while(str[i]!='\0' && str2[i]!='\0')
    {
        if(str[i]!=str2[i])
        {
            break;
        }
        i++;
    }
    if(str[i]==str2[i])
    {
        return 0;
    }
    else{
        if(str[i]!='\0')
        {
            return -1;
        }
        return 1;
    }
}

void formnode(char *str)
{
    word *ptr = node[(int)str[0]].ptr;
    if(ptr==NULL)
    {
        f[z++]=str[0];
        word *s = new word;
        s->str = str;
        s->Count=1;
        s->ptr = NULL;
        node[(int)str[0]].ptr = s;
    }
    else{
        do
        {
            if(!compareWord(str,ptr->str))
            {
                (ptr->Count)++;
                return;
            }
            ptr=ptr->ptr;
        }while(ptr->ptr!=NULL);
        word *s = new word;
        s->Count=1;
        s->str=str;
        s->ptr=NULL;
        ptr->ptr = s;
    }

}

char* subString(char *str,int i, int j)
{
    int n=j-i;
    char *s = new char[n+1];
    for(int k=0;k<n;k++)
    {
        s[k]=str[k+i];
    }
    s[n]='\0';
    return s;
}

void split(char *str)
{
    int i=0,j=0;
    bool flag=false;
    while(true)
    {
        if(str[i]==' ' || str[i]=='\0')
        {
            if(flag==true)
            {
                formnode(subString(str,j,i));
                flag=false;
            }
            if(str[i]=='\0')
            {
                return;
            }
        }
        else
        {
            if(flag==false)
            {
                j=i;
                flag=true;
            }
        }
        i++;
    }
}

void showData()
{
    for(int i=0;i<z;i++)
    {
        word *ptr = node[(int)f[i]].ptr;
        while(ptr!=NULL)
        {
            cout << ptr->str << " " << ptr->Count<< endl;
            ptr = ptr->ptr;
        }
    }
}

int main()
{
    char *str = new char[100];
    cin.getline(str,100);
    split(str);
    showData();
    delete str;
    return 0;
}

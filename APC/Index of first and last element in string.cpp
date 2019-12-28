#include<iostream>
using namespace std;

void index(char str[50]) 
{
    int i = 0, count = 0;
    bool flag = false;
    while(str[i] != '\0') 
	{
    
        if(str[i] == ' ')
		{
            if(flag == true)
                cout<<"Last index of word is "<<i-1<<endl;
            flag = false;
        } 
		else 
		{
            if(flag == false) 
			{
                count++;
                cout<<"Starting index of word is "<<i<<endl;
                flag = true;
            }

        }
        i++;    
    }
}

int main() {

    char str[20];
    cout<<"Enter the string"<<endl;
    cin.getline(str, 20);
    index(str);
    return 0;
}

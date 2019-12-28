#include<iostream>
using namespace std;

int index(char str[50]) 
{
    int i = 0, count = 0;
    bool flag = false;
    while(str[i] != '\0') 
	{
    
        if(str[i] == ' ')
		{
            if(flag == true)
            flag = false;
        } 
		else 
		{
            if(flag == false) 
			{
                count++;
                flag = true;
            }

        }
        i++;    
    }
    return count;
}

int main() {

    char str[20];
    cout<<"Enter the string"<<endl;
    cin.getline(str, 20);
    cout<<"Nof word in a string is "<<index(str);
    return 0;
}

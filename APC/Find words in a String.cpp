#include<stdio.h>
char* getSubStr(char str[], int startIndex, int endIndex) 
{
    char *newStr = new char[20];
    int j = 0;
    for(int i = startIndex;i< startIndex + (endIndex - startIndex);i++,j++)
	{
        newStr[j] = str[i];
    }
    newStr[j] = '\0';
    return newStr;
}
int main()
{
    char str[50], subStr[20];
    int i = 0, startIndex, endIndex;
    bool flag = false;
    printf("Enter the string :");
    scanf("%[^\n]s",&str);
    while(str[i] != '\0') 
	{
        if(str[i] == ' ') 
		{
            if(flag == true) 
			{
                endIndex = i;
                printf("%s\n",getSubStr(str, startIndex, endIndex));
            }
            flag = false;
        }
		else 
		{
            if(flag == false) 
                startIndex = i;
            flag = true;
        }
        i++;
    }
    if(str[i] == '\0') 
	{
        endIndex = i;
        printf("%s\n",getSubStr(str, startIndex, endIndex));
    }
}

// CPP Program to Count numbers on fingers 
#include <iostream> 
using namespace std; 
  
int count_num_finger(int n) 
{ 
	int quo = n / 4; 
	int rem= n % 4;
   
   if(rem==0)
   rem=quo;
   else if(rem==1)
   {
   }
   else
   quo++;
   
   cout<<"row : "<<quo<<" col :"<<rem<<endl;; 
} 
  
// Driver code 
int main() 
{ 
    int n; 
    n = 11; 
    count_num_finger(11);
	 count_num_finger(13);
  
    return 0; 
}

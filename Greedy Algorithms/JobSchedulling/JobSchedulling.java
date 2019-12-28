import java.io.*;
import java.util.*;
import java.lang.*;

class JobSchedulling
{
    class Job
    {
        int deadline,profit;
        char id;
        public Job(char id,int deadline, int profit) 
        { 
            this.deadline = deadline; 
            this.profit = profit; 
            this.id = id; 
        } 
    }

    Job[] sort(Job arr[],int n)
    {
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-i-1;j++)
                if(arr[i].profit < arr[i+1].profit)
                {
                    Job temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
        return arr;
    }

// Returns minimum number of platforms reqquired 
void printJobScheduling(Job arr[], int n) 
{ 
    // Sort all jobs according to decreasing order of prfit 
    arr=sort(arr,n); 
  
    int result[]=new int[n]; // To store result (Sequence of jobs) 
    boolean slot[]=new boolean[n];  // To keep track of free time slots 
  
    // Initialize all slots to be free 
    for (int i=0; i<n; i++) 
        slot[i] = false; 
  
    // Iterate through all given jobs 
    for (int i=0; i<n; i++) 
    { 
       // Find a free slot for this job (Note that we start 
       // from the last possible slot) 
       for (int j=Math.min(n, arr[i].deadline)-1; j>=0; j--) 
       { 
          // Free slot found 
          if (slot[j]==false) 
          { 
             result[j] = i;  // Add this job to result 
             slot[j] = true; // Make this slot occupied 
             break; 
          } 
       } 
    } 
  
    // Print the result 
    for (int i=0; i<n; i++) 
       if (slot[i])
        System.out.println(arr[result[i]].id);
}

void startJob()
{
        Job arr[]={new Job('a', 2, 100),new Job('b', 1, 19),new Job('c', 2, 27),
                    new Job('d', 1, 25),new Job('e', 3, 15)};

                    printJobScheduling(arr, arr.length); 
}
	public static void main(String[] agrs)
	{
        JobSchedulling j=new JobSchedulling();
        j.startJob();
	}
}
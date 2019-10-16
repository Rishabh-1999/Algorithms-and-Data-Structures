import java.util.Scanner;

class Knapsack 
{   
    static int max(int a, int b) { return (a > b)? a : b; } 

    static int knapSack(int W, int wt[], int val[], int n) 
    { 
    int i, w; 
    int K[][] = new int[n+1][W+1]; 
       
    for (i = 0; i <= n; i++) 
    { 
        for (w = 0; w <= W; w++) 
        { 
            if (i==0 || w==0) 
                K[i][w] = 0; 
            else if (wt[i-1] <= w) 
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
            else
                K[i][w] = K[i-1][w]; 
        }
      }
      return K[n][W]; 
    } 

    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no of Number or elements");
        int n=sc.nextInt();
        int val[] = new int[n]; 
        int wt[] = new int[n];
        
        for(int i=0;i<n;i++) {
            System.out.println("Enter value of "+i);
            System.out.print("Enter value : ");
            val[i]=sc.nextInt();
            System.out.print("Enter weight : ");
            wt[i]=sc.nextInt();
        }
        System.out.println("Enter Total Weight : ");
        int  W = sc.nextInt();
        System.out.println("Final Answer : "+knapSack(W, wt, val, n)); 
    } 
} 
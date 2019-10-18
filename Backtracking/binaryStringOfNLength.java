import java.util.Scanner;

class binaryStringOfNLength
{
	public static void printArray(int arr[],int n)
	{
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]);
		}
		System.out.println();
	}

	public static void calculateBinaryString(int low,int high,int arr[])
	{
		if(low == high)
		{
			printArray(arr,high);
			return;
		}
		arr[low] = 0;
		calculateBinaryString(low+1,high,arr);
		arr[low] = 1;
		calculateBinaryString(low+1,high,arr);
	}

	public static void main(String[] args) 
	{
		Scanner obj = new Scanner(System.in);
		System.out.println("Enter No till u want Binary String : ");
		int n = obj.nextInt();
		int arr[] = new int[n];
		calculateBinaryString(0,n,arr);
	}
}
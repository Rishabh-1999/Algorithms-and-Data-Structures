/* Generate all binary strings of lenght n whose nth bit from left must be always 1 */

import java.util.Scanner;

class binrayString2
{
	public static void printArray(int arr[],int n)
	{
		for(int i=0;i<n;i++)
		{
			System.out.print(arr[i]);
		}
		System.out.println();
	}

	public static void calculateBinaryString(int low,int high,int arr[],int bit)
	{
		if(low == high)
		{
			printArray(arr,high);
			return;
		}
		else
		{
			if(low != bit-1)
			{
				arr[low] = 0;
				calculateBinaryString(low+1,high,arr,bit);			
			}
			arr[low] = 1;
				calculateBinaryString(low+1,high,arr,bit);
		}
	}

	public static void main(String[] args) 
	{
		Scanner obj = new Scanner(System.in);
		System.out.println("Enter No till u want Binary String : ");
		int n = obj.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter Bit no which u wan to keep 1 from left : ");
		int bit = obj.nextInt();
		
		calculateBinaryString(0,n,arr,bit);
	}
}

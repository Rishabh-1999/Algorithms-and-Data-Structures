import java.util.Scanner;

class upperBoundlowerBound
{
	public static int LowerBound(int[] arr,int s,int e,int n)
	{
		int ans=-1;
		while(s<=e)
		{
			int m = (e+s)/2;
			if(arr[m] == n)
			{
				ans = m;
				e = m-1;
			}
			else if(arr[m] > n)
			{
				e = m-1;
			}
			else
			{
				s = m+1;
			}
		}
		return ans;
	}

	public static int UpperBound(int[] arr,int s,int e,int n)
	{
		int ans=-1;
		while(s<=e)
		{
			int m = (e+s)/2;
			if(arr[m] == n)
			{
				ans = m;
				s = m+1;
			}
			else if(arr[m] > n)
			{
				e = m-1;
			}
			else
			{
				s = m+1;
			}
		}
		return ans;
	}

	public static void main(String[] args) 
	{
		
		Scanner obj = new Scanner(System.in);
		System.out.println("Enter size");
		int size = obj.nextInt();
		int[] arr = new int[size];
		for(int i=0;i<size;i++)
		{
			System.out.println("Enter No to Array = ");
			arr[i] = obj.nextInt();
		}	
		System.out.println("Enter No to Search = ");
		int n = obj.nextInt();
		System.out.println(LowerBound(arr,0,size,n));
		System.out.println(UpperBound(arr,0,size,n));
	}
	
}
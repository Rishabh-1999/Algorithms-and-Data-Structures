import java.util.Scanner;

class CountSetBit2
{
	public static int countBits(int n)
	{
		int count = 0;
		while(n>0)
		{
			n = (n & (n-1));
			count++;
		}
		return count;
	}

	public static void main(String[] args) 
	{
		Scanner obj = new Scanner(System.in);
		System.out.println("Enter a number = ");
		int n = obj.nextInt();
		System.out.println(countBits(n));
	}
}
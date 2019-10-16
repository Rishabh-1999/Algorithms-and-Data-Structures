import java.util.*;

public class BinaryStream
{
    public static void fun(int arr[],int l,int r)
    {
        if(l==r)
        {
            for(int i=0;i<arr.length;i++)
                System.out.print(arr[i]);
            System.out.println();
        }
        else
        {
            if(l!=1)
            {
	            arr[l]=0;
	            fun(arr,l+1,r);
            }
            arr[l]=1;
            fun(arr,l+1,r);
            
        }
    }
    public static void main(String a[])
    {
        int n;
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int arr[]=new int[n];
        fun(arr,0,n);
    }
}
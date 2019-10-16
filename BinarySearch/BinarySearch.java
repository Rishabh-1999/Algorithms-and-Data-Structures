import java.util.*;
public class BinarySearch
{
    public static boolean Binary(int ar[],int s,int e,int f)
    {
        if(s>=e)
        {
        int m=(s+e)/2;
        if(ar[m]==f)
            return true;
        else if(ar[m]>f)
            return Binary(ar,s,m-1,f);
        else if(ar[m]<f)
            return Binary(ar,m+1,e,f);
        }
        return false;
    }

    public static void main(String a[])
    {
        Scanner sc=new Scanner(System.in);
        int n;
        n=sc.nextInt();
        int ar[]=new int[n];
        for(int i=0;i<n;i++)
            ar[i]=sc.nextInt();
        int f;
        f=sc.nextInt();
        if(Binary(ar,0,n-1,f))
            System.out.print("found");
        else
            System.out.print("No found");
    }
}
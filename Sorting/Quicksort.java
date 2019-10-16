import java.util.*;

public class Quicksort
{
    public static int partition(int ar[],int l,int r)
    {
        int i=l-1;
        int x=ar[r];
        int j=l;
        int temp;
        while(j<=r-1)
        {
            if(ar[j]<=x)
            {
                i++;
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
            j++;
        }
        temp=ar[i+1];
        ar[i+1]=ar[r];
        ar[r]=temp;
        return (i+1);
    }

    public static void quicksort(int ar[],int l,int r)
    {
        if(l<r)
        {
        int p=partition(ar,l,r);
        quicksort(ar,l,p-1);
        quicksort(ar,p+1,r);
        }
    }

    public static void main(String a[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter no of No");
        int n=sc.nextInt();
        int ar[]=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.print("Enter no : ");
            ar[i]=sc.nextInt();
        }
        quicksort(ar,0,n-1);
        System.out.println("QuickSorted Elements are :");
        for(int i=0;i<n;i++)
            System.out.print(ar[i]+" ");
    }
}
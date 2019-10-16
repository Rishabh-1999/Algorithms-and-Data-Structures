import java.util.*;
public class Operation
{
    static int n;
    public static void heapify(int ar[],int i,int n)
    {
        int l=2*i;
        int r=2*i+1;
        int max=i;
        if(l<=n&&ar[l]>ar[i])
            max=l;
        else
            max=i;
        if(r<=n&&ar[r]>ar[max])
            max=r;
        if(max!=i)
        {
            int temp=ar[max];
            ar[max]=ar[i];
            ar[i]=temp;
            heapify(ar,max,n);
        }
    }
    public static void insertheapify(int ar[],int i)
    {
        if(i/2==0)
            return;
        if(ar[i/2]<ar[i])
        {
            int temp=ar[i/2];
            ar[i/2]=ar[i];
            ar[i]=temp;
            insertheapify(ar,i/2);
        }
    }
    public static void deletemax(int ar[])
    {
        ar[1]=ar[n];
        n--;
        heapify(ar,1,n);
    }
    public static void insert(int ar[],int c)
    {
        ar[++n]=c;
        insertheapify(ar,n);
    }
    public static void heapsort(int ar[],int n)
    {
        for(int i=n;i>1;i--)
        {
            int temp=ar[i];
            ar[i]=ar[1];
            ar[1]=temp;
            heapify(ar,1,i-1);
        }
    }
    public static void main(String a[])
    {
        Scanner sc=new Scanner(System.in);
        n=sc.nextInt();
        int n1=n;
        int ar[]=new int[100];
        for(int i=1;i<=n;i++)
            ar[i]=sc.nextInt();
        for(int i=n/2;i>=1;i--)
            heapify(ar,i,n);
        System.out.println("After Heapify ....");
        for(int i=1;i<=n;i++)
            System.out.println(ar[i]);
        System.out.println();
        deletemax(ar);
        System.out.println("After Deletion ....");
        for(int i=1;i<=n;i++)
        System.out.println(ar[i]);
        System.out.println();
        System.out.println("Enter two element for insertion ....");
        for(int i=0;i<2;i++)
        {
            int c=sc.nextInt();
        insert(ar,c);
        }
        heapsort(ar,n);
        System.out.println("After Heapsort ....");
        for(int i=1;i<=n;i++)
            System.out.println(ar[i]);
    }
}
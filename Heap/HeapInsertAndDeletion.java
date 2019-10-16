import java.util.*;
public class HeapInsertAndDeletion
{
    void heapify(int arr[], int n, int i) 
    { 
        int largest = i; // Initialize largest as root 
        int l = 2*i + 1; // left = 2*i + 1 
        int r = 2*i + 2; // right = 2*i + 2 
    
        // If left child is larger than root 
        if (l < n && arr[l] > arr[largest]) 
            largest = l; 
    
        // If right child is larger than largest so far 
        if (r < n && arr[r] > arr[largest]) 
            largest = r; 
    
        // If largest is not root 
        if (largest != i) 
        { 
            
            int temp=arr[i];
            arr[i]=arr[largest];
            arr[largest]=temp;
    
            // Recursively heapify the affected sub-tree 
            heapify(arr, n, largest); 
        } 
    } 
    void printArray(int arr[])
    {
        for(int i=0;i<arr.length;i++)
        System.out.print(arr[i]+" ");
    }
    void insertheapify(int ar[],int i,int j)
    {
        if(i<0)
            return;
        else if(ar[i]>ar[j])
            return;
        else
        {
            int temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
            insertheapify(ar,i-1,i);
        }
    }
    void insert(int ar[],int n,int c)
    {
        ar[n++]=c;
        insertheapify(ar,n/2,n-1);
    }
    void deletemax(int ar[],int n)
    {
        ar[0]=ar[n-1];
        n--;
        heapify(ar,n,0);
    }
    public static void main(String[] args) {
        System.out.println("Enter no of elements : ");
        Scanner sc =new Scanner(System.in);
        int n=sc.nextInt();
        int[] a=new int[100];
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
        HeapInsertAndDeletion h=new HeapInsertAndDeletion();
        for (int i = n / 2 - 1; i >= 0; i--) 
            h.heapify(a, n, i);
            h.printArray(a);
            int add=sc.nextInt();
        h.insert(a,n+1,add);
        h.printArray(a);
    }
}
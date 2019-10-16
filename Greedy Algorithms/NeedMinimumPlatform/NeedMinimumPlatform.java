import java.io.*;
import java.util.*;
import java.lang.*;

public class NeedMinimumPlatform{
    public static void main(String agrs[]) {
    int n;
    Scanner sc =new Scanner(System.in);
    System.out.println("Enter no of variables :");
    n = sc.nextInt();
    System.out.println("");
    int arr[] = new int[n];
    int dep[] = new int[n];
    System.out.println("Enter arrival time : ");
    for(int i=0;i<n;i++) {
        System.out.print("Enter : ");
        arr[i] = sc.nextInt();
    }
    System.out.println("Enter desination time : ");
    for(int i=0;i<n;i++) {
        System.out.print("Enter : ");
        dep[i] = sc.nextInt();
    }
    int plat=1,r=1;
    int i=1,j=0;
    Arrays.sort(arr); 
    Arrays.sort(dep); 
    while(i<n&&j<n)
    {
        if(arr[i]<=dep[j])
        {
            plat++;
            i++;
            if(plat>r)
                r=plat;
        }
        else
        {
            plat--;
            j++;
        }
    }
    System.out.println("We need Min "+ r +" platform");
    }
}
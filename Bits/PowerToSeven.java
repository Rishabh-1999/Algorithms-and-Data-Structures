import java.io.*;
import java.util.*;
import java.lang.*;

public class PowerToSeven{
    public static void main(String agrs[]) {
        Scanner sc=new Scanner(System.in);
        int n;
        System.out.println("Enter Number");
        n=sc.nextInt();
         n=(n<<3)-n;
        System.out.println(n);
    }
}
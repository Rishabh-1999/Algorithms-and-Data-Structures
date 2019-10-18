import java.io.*;
import java.util.*;
import java.lang.*;

public class PowerToTwo{
    public static void main(String agrs[]) {
        System.out.println("Enter Number");
        Scanner sc =new Scanner(System.in);
        int value=sc.nextInt(),v;
	v=value;
        //Method 1
        if((v & (v-1))==0)
        	System.out.println("true");
	else
		System.out.println("false");
        //Method 2
        //find set bits
    }
}
import java.io.*;
import java.util.*;
import java.lang.*;

public class PowerOfFour{
    public static void main(String agrs[]) {
        System.out.println("Enter Number");
        Scanner sc =new Scanner(System.in);
        int value=sc.nextInt(),v,count=0;
        v=value;
        while(v>0)
        {
            v=v&(v-1);
            count++;
        }
        int s=0;
        if(count==1)
        {
            count=0;
            while(s<32)
            {
                if(((value>>s)&1)!=0)
                   count=1;
                s+=2;
            }
        }
        else
            count=0;
    
        if(count==1)
        	System.out.println("true");
	else
		System.out.println("false");
    }
}
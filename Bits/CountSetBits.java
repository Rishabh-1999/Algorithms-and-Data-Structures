import java.io.*;
import java.util.*;
import java.lang.*;

public class CountSetBits{
    public static void main(String agrs[]) {
        System.out.println("Enter Number");
        Scanner sc =new Scanner(System.in);
        int value=sc.nextInt();
        //Method 1
        int count=1,v=value;
        for(int i=1;i<=Math.log(v);i++) {
            if(((v>>i) & 1 )==1)
                count++;
        }
        System.out.println(count);
        //Method 2
        count=0;
        v=value;
        while(v!=0) {
            v=v&(v-1);
            count++;
        }
        System.out.println(count);
    }
}
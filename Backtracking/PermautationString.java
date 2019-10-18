import java.util.*;

public class PermautationString
{
    public static void permautation(String str,String ans)
    {
        if(str.length()==0)
        {
            System.out.print(ans+"-");
            return;
        }

        boolean flag[]=new boolean[26];
        for(int i=0;i<str.length();i++)
        {
            char ch=str.charAt(i);
            String res=str.substring(0,i)+str.substring(i+1);
            System.out.println(ch+" "+res);
            if(flag[ch -'a']==false)
                permautation(res,ans+ch);
            flag[ch - 'a']=true;
        }
    }
    
    public static void main(String a[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter String : ");
        String str=new String();
        str=sc.next();
        permautation(str,"");
    }
}
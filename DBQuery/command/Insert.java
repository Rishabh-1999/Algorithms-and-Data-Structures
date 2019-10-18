package command;
import java.util.*;
import java.io.*;
import java.lang.*;
public class Insert
{
    public void insert(String comm[],String str)throws IOException
    {
        if(comm.length<4)
        {System.out.println("Less number of argument");
        return;
        }
        else if(!comm[1].equals("into"))
        {
            System.out.println(comm+" instead of into");
            return ;
        }
        File f=new File("db/"+comm[2]+".txt");
        if(!f.exists())
        {
            System.out.println("Table not exist");
            return;
        }
        int s=0,c=0,br=0,count=0,no=0;
        if(str.charAt(str.length()-1)==' ')
                if(str.charAt(str.length()-2)!=')')
                    s=1;
            if(str.charAt(str.length()-1)!=' ')
                if(str.charAt(str.length()-1)!=')')
                    s=1;
            if(comm[3].charAt(0)=='('||s==1)
            {
                System.out.println("command not correct");
                return;
            }
            int bth=0,count1=0;
            for(int i=0;i<comm[3].length();i++)
            {
                if(comm[3].charAt(i)==')')
                {
                    bth=1;
                    break;
                }
                else if(comm[3].charAt(i)=='(')
                    count1++;
            }
        if(count1==0&&bth==1)
            {
                System.out.println("command not correct");
                return;
            }
        if(count1==0&&bth==0)
        {
        if(comm[3].charAt(comm[3].length()-1)=='('||comm[4]=="("||comm[4].charAt(0)=='(')
            {}
        else
        {
            System.out.println("command not correct");
            return;
        }
        }
            bth=0;count1=0;
           for(int i=0;i<str.length();i++)
            {
               if(str.charAt(i)=='(')
                   bth=1;
               else if(bth==1)
               {
                   if(str.charAt(i)==' ')
                       continue;
                   else if(str.charAt(i)>='A'&&str.charAt(i)<='z')
                       count1++;
                   else if(str.charAt(i)==')')
                       break;
               }
            }
            if(count1==0)
            {
                System.out.println("No argument passed");
                return;
            }
        for(int i=0;i<str.length();i++)
            {
                if(str.charAt(i)=='(')
                {count++;
                    c=1;
                }
                else if(c==1)
                {
                    if(str.charAt(i)==')')
                    {
                        br=1;
                        count++;
                    }
                }       
            }
       if(count!=2&&br!=1)
       {
           System.out.println("Brackets are not correct");
           return;
       }
         String value=new String("");
              for(int i=0;i<comm[3].length();i++)
              {
                  if(comm[3].charAt(i)=='(')
                  break;
                  value+=comm[3].charAt(i);
              }
            value=value.trim();
    if(!value.equals("values"))
    {
        System.out.println(value+" instead of values");
        return;
    }
        String col=new String("");
        String temp="";
        int ch=0,wr=0;
      for(int i=0;i<str.length();i++)
      {
        if(str.charAt(i)=='(')
            ch=1;
        else if(str.charAt(i)==')')
        {
            temp=temp.trim();
            int z1=0;
            for(int j=0;j<temp.length();j++)
                {
                if(temp.charAt(0)=='_')
                {
                    System.out.println("Data name not correct");
                    z1=1;
                    break;
                }
                if((temp.charAt(j)>='A'&&temp.charAt(j)<='z')||(temp.charAt(j)>='0'&&temp.charAt(j)<='9')||(temp.charAt(j)=='_'))
            {}
                else
                {
                    System.out.println("Data name not correct");
                    z1=1;
                    break;
                }
                }
            if(z1==1)
                return;
            col+=temp;
            break;
        }
        else if(str.charAt(i)==',')
        {
           if(str.charAt(i-1)=='('||str.charAt(i-2)=='('||str.charAt(i+1)==')'||str.charAt(i+2)==')'||str.charAt(i+1)==','||str.charAt(i-1)==',')
           {

               wr=1;
               break;
           }
            temp=temp.trim();
            int z1=0;
            for(int j=0;j<temp.length();j++)
                {
                if(temp.charAt(0)=='_')
                {
                    System.out.println("Column name not correct");
                    z1=1;
                    break;
                }
                if((temp.charAt(j)>='A'&&temp.charAt(j)<='z')||(temp.charAt(j)>='0'&&temp.charAt(j)<='9')||(temp.charAt(j)=='_'))
            {}
                else
                {
                    System.out.println("Column name not correct");
                    z1=1;
                    break;
                }
                }
            if(z1==1)
                return;
            col+=temp;
            col+=" ";
            temp="";
        }
        else if(ch==1)
        {
            if(str.charAt(i)==' ')
            {
                if(str.charAt(i-1)!='('&&str.charAt(i+1)!=')')
                {
                    if(str.charAt(i+1)==','&&str.charAt(i-1)==',')
                    {
                    wr=1;
                    break;
                    }
                    else if(str.charAt(i+1)==','||str.charAt(i-1)==',')
                    {}
                    else
                    {
                        wr=1;
                        break;
                    }

                }
            }
            temp+=str.charAt(i); 
        }
      }
    if(wr==1)
    {
        System.out.println("command not correct");
        return;
    }
    String insrt[]=col.split(" ");
    BufferedReader br1=new BufferedReader(new FileReader("db/"+comm[2]+".txt"));
    String file[]=br1.readLine().split(" ");
    br1.close();
    if(insrt.length!=file.length)
    {
        System.out.println("No. of data are not correct");
        return;
    }
    BufferedWriter pr=new BufferedWriter(new FileWriter("db/"+comm[2]+".txt",true));
    pr.write("\n");    
    pr.write(col);
    pr.flush();
    pr.close();
    System.out.println("Data inserted");
    }
}
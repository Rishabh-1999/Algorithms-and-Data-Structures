package command;
import java.util.*;
import java.io.*;
import java.lang.*;
public class Select
{
    public void select(String comm[],String str)throws IOException
    {
        if(comm.length<4)
        {
            System.out.println("Less number of argument");
            return;
        }
        else if(!comm[comm.length-2].equals("from"))
        {
            System.out.println(comm[comm.length-2]+" instead of from");
            return;
        }
        File f=new File("db/"+comm[comm.length-1]+".txt");
        if(!f.exists())
        {
            System.out.println("Table not exist");
            return;
        }
        if(comm[1].equals("*"))
        {
            BufferedReader br=new BufferedReader(new FileReader("db/"+comm[3]+".txt"));
            String str1;
            while((str1=br.readLine())!=null)
            {
                System.out.println(str1);
            }
            br.close();
            return;
        }
        if(!((comm[1].charAt(0)>='A'&&comm[1].charAt(0)<='z')||(comm[1].charAt(0)>='0'&&comm[1].charAt(0)<='9')))
        {
            System.out.println("command not correct");
            return;
        }
        int ind=str.indexOf(" ");
        String temp="";
        String data[]=new String[100];
        int k=-1,wr=0;
        for(int i=ind+1;i<str.length();i++)
        {
            if(str.charAt(i)==' ')
            {
               if(str.charAt(i+1)=='f'&&str.charAt(i+2)=='r'&&str.charAt(i+3)=='o'&&str.charAt(i+4)=='m')
               {
                   if(str.charAt(i-1)==',')
                   {
                       wr=1;
                       break;
                   }
                   temp=temp.trim();
                   data[++k]=temp;
                   temp="";
                   break;
               }
                temp+=str.charAt(i);
            }
            else if(str.charAt(i)==',')
            {
                if(str.charAt(i-1)==',')
                {
                    wr=1;
                    break;
                }
                temp=temp.trim();
                data[++k]=temp;
                temp="";
                
            }
            else
                temp+=str.charAt(i);
        }
        if(wr==1)
        {
            System.out.println("command not correct");
            return;
        }
        int count=0;
        BufferedReader br=new BufferedReader(new FileReader("db/"+comm[comm.length-1]+".txt"));
        String fstr=br.readLine();
        String table[]=fstr.split(" ");
        count++;
        while((fstr=br.readLine())!=null)
        {
            count++;
        }
        br.close();
        if(table.length<k+1)
        {
            System.out.println("No. of arguments not matched");
            return;
        }
        int l=table.length;
        String bdata[][]=new String[count][table.length];
        k=-1;
        br=new BufferedReader(new FileReader("db/"+comm[comm.length-1]+".txt"));
        while((fstr=br.readLine())!=null)
        {
            ++k;
            table=fstr.split(" ");
            for(int j=0;j<table.length;j++)
            {
                bdata[k][j]=table[j];
            }
        }
        br.close();
        for(int z=0;z<data.length;z++)
        {
            for(int j=0;j<l;j++)
            {
                if(bdata[0][j].equals(data[z]))
                {
                    for(int z1=0;z1<count;z1++)
                        System.out.print(bdata[z1][j]+" ");
                    System.out.println();
                }
            }
        }
        return;
        
    }
}
package command;
import java.util.*;
import java.io.*;
import java.lang.*;
public class Create
{
     public void create(String comm[],String str)throws IOException
    {
        if(!comm[1].equals("table"))
          System.out.print(comm[1]+" instead of table");
        else
        {
            int s=0,c=0,br=0,count=0,no=0;
            if(str.charAt(str.length()-1)==' ')
                if(str.charAt(str.length()-2)!=')')
                    s=1;
            if(str.charAt(str.length()-1)!=' ')
                if(str.charAt(str.length()-1)!=')')
                    s=1;
            if(comm[2].charAt(0)=='('||s==1)
            {
                System.out.println("command not correct");
                return;
            }
            int bth=0,count1=0;
            for(int i=0;i<comm[2].length();i++)
            {
                if(comm[2].charAt(i)==')')
                {
                    bth=1;
                    break;
                }
                else if(comm[2].charAt(i)=='(')
                    count1++;
            }
            if(count1==0&&bth==1)
            {
                System.out.println("command not correct");
                return;
            }
            if(count1==0&&bth==0)
            {
            if(comm[2].charAt(comm[2].length()-1)=='('||comm[3]=="("||comm[3].charAt(0)=='(')
            {}
            else
                s=1;
            }
            if(s==1)
            {
             System.out.println("command not correct");
                return;   
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
            else
            {
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
            if(s==0&&count==2&&br==1)
            {
                String table=new String("");
              for(int i=0;i<comm[2].length();i++)
              {
                  if(comm[2].charAt(i)=='(')
                  break;
                  table+=comm[2].charAt(i);
              }
            table=table.trim();
                 int z=0;
                        for(int j=0;j<table.length();j++)
                            {
                            if(table.charAt(0)=='_')
                            {
                                System.out.println("table name not correct");
                                z=1;
                                break;
                            }
                            if((table.charAt(j)>='A'&&table.charAt(j)<='z')||(table.charAt(j)>='0'&&table.charAt(j)<='9')||(table.charAt(j)=='_'))
                        {}
                            else
                            {
                                System.out.println("table name not correct");
                                z=1;
                                break;
                            }
                            }
                        if(z==1)
                            return;
                if(table.equals("table")||table.equals("create"))
                {
                    System.out.println("Table name not correct");
                    return;
                }
            File f=new File("db/"+table+".txt");
                if(f.exists())
                {
                    System.out.println("Table already exist");
                }
                else
                {
                    String col=new String("");
                    String temp="";
                    int ch=0,wr=0;
                    String colarr[]=new String[1000];
                    int col1=-1;
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
                         if(col1!=-1)
                        {
                         for(int j=0;j<=col1;j++)
                             if(colarr[j].equals(temp))
                             {
                                 z1=1;
                                 System.out.println("Column name not correct");
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
                         if(col1!=-1)
                        {
                         for(int j=0;j<=col1;j++)
                             if(colarr[j].equals(temp))
                             {
                                 z1=1;
                                 break;
                             }
                        }
                        if(z1==1)
                            return;
                        colarr[++col1]=temp;
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
                        System.out.println("command not correct");
                    else
                    {
                        PrintWriter pr=new PrintWriter(new FileWriter("db/"+table+".txt"));
                        pr.write(col);
                        pr.flush();
                        pr.close();
                        System.out.println("Table created");
                    }
                }
                
            }
            else
                System.out.println("command not correct");
            }
        }
    }
}
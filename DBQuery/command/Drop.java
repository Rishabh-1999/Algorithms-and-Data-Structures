package command;
import java.util.*;
import java.io.*;
import java.lang.*;
public class Drop
{
    public void drop(String comm[],String str)throws IOException
    {
        if(comm.length<3)
        {
            System.out.println("Less no. of argument");
            return;
        }
        else if(comm.length>3)
        {
            System.out.println("command not correct");
            return;
        }
        else if(!comm[1].equals("table"))
        {
            System.out.println(comm[1]+" instead of table");
            return;
        }
       else if(!((comm[2].charAt(0)>='A'&&comm[2].charAt(0)<='z')||(comm[2].charAt(0)>='0'&&comm[2].charAt(0)<='9')))
       {
           System.out.println("command not correct");
           return;
       }
        File f=new File("db/"+comm[2]+".txt");
        if(!f.delete())
        {
            System.out.println("Table not exist");
            return;
        }
        else
        {
            System.out.println("Table deleted");
            return;
        }
        
    }
}
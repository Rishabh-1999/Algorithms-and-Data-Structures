package command;
import java.util.*;
import java.io.*;
import java.lang.*;
public class Load
{
    public void load(String comm[],ArrayList<ArrayList<String>>alist)throws IOException
    {
        if(comm.length<2)
        {
            System.out.println("Less no of argument");
            return;
        }
        else if(comm.length>2)
        {
            System.out.println("command not correct");
            return;
        }

        File f=new File("db/"+comm[1]+".txt");
        if(!f.exists())
        {
            System.out.println("Table not exist");
            return;
        }

        ArrayList<String> al = new ArrayList<String>();
        BufferedReader br=new BufferedReader(new FileReader("db/"+comm[1]+".txt"));
        String str=br.readLine();
        int c=0;
        for(int i=0;i<alist.size();i++)
        {
            if((alist.get(i).get(0)).equals(str))
            {
                c=1;
                break;
            }
        }
        if(c==1)
        {
            System.out.println("Already loaded");
            return;
        }
        while(str!=null)
        {
            al.add(str);
            str=br.readLine();
        }
        if(al.size()>1)
        {
        alist.add(al);
            System.out.println("Data loaded");
        }
        else
        {
            System.out.println("No data in "+comm[1]+" table");
        }
        br.close();
        return;
    }
}
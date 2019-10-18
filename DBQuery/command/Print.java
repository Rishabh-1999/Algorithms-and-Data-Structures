package command;
import java.util.*;
import java.io.*;
import java.lang.*;

public class Print
{
    public void print(String comm[],ArrayList<ArrayList<String>>alist)throws IOException
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

        BufferedReader br = new BufferedReader(new FileReader("db/"+comm[1]+".txt"));
        String str=br.readLine();
        br.close();
        for(int i=0;i<alist.size();i++)
        {
            if((alist.get(i).get(0)).equals(str))
            {
                for(int j=1;j<alist.get(i).size();j++)
                    System.out.println(alist.get(i).get(j));
                break;
            }
        }
        return;
    }
}
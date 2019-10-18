import java.util.*;
import java.io.*;
import java.lang.*;
import command.*;

public class DBQuery
{
   
    public static void main(String agrs[]) throws IOException
    {
        System.out.println("DBQuery Opened : \nYou can use this for command create,insert,select,drop,load and print.");
        Scanner sc=new Scanner(System.in);

        ArrayList<ArrayList<String>> alist = new ArrayList<ArrayList<String>>();

        while(true)
        {
	        String str=sc.nextLine();
	        if(str.equals("EXIT") || str.equals("exit") || str.equals("QUIT") || str.equals("quit"))
	            System.exit(0);

	        str=str.trim().replaceAll("\\s{1,}"," ");
	        str=str.toLowerCase();

	        String comm[]=str.split(" ");
	        switch(comm[0])
	        {
	            case "create":
	            	if(comm.length<3) {
	            		System.out.println("Less number of argument is passed");
	            		break;
	             	}
	                Create createclass=new Create();
	                createclass.create(comm,str);
	                break;

	            case "select":
	                Select selectclass=new Select();
	                selectclass.select(comm,str);
	                break;

	            case "insert":
	            	if(comm.length<3) {
	            		System.out.println("Less number of argument is passed");
	            		break;
	             	}
	                Insert insertclass=new Insert();
	                insertclass.insert(comm,str);
	                break;

	            case "update":
	            	if(comm.length<3) {
	            		System.out.println("Less number of argument is passed");
	            		break;
	             	}
	                break;

	            case "drop":
	            	if(comm.length<3) {
	            		System.out.println("Less number of argument is passed");
	            		break;
	             	}
	                Drop dropclass=new Drop();
	                dropclass.drop(comm,str);
	                break;

	            case "load":
	                Load loadclass=new Load();
	                loadclass.load(comm,alist);
	                break;

	            case "print":
	            	Print printclass=new Print();
	                printclass.print(comm,alist);
	                break;
	                
	            default:
	                System.out.println("command not recognised");
	        }
        }
    }
}
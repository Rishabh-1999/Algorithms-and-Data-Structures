import java.io.*;
import java.util.*;
import java.lang.*;

public class NQueens
{
    static int n;

     static void printArray(int board[][]) 
     { 
         for (int i = 0; i < n; i++) { 
             for (int j = 0; j < n; j++) 
                 System.out.print(" " + board[i][j] + " "); 
             System.out.println(); 
         } 
     } 

    static boolean isSafe(int board[][],int row,int col)
    {
        int i, j; 
  
        for (i = 0; i < col; i++)
            if (board[row][i] == 1) 
                return false; 
  
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
            if (board[i][j] == 1) 
                return false; 
  
        for (i = row, j = col; j >= 0 && i < n; i++, j--) 
            if (board[i][j] == 1) 
                return false; 
  
        return true; 
    }

    static boolean SolveNQueen(int board[][],int col)
    {
        if(col>=n)
            return true;
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,i,col))
            {
                board[i][col]=1;

                if(SolveNQueen(board,col+1)==true)
                return true;
            }

            board[i][col]=0;
        }

        return false;
    }

    static void findAns(int n)
    {
        int board[][]=new int[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                board[i][j]=0;
        if(SolveNQueen(board,0)==true)
        {
            System.out.println("It is solveable");
            printArray(board);
        }
        else
            System.out.println("It is not solveable");
    }

	public static void main(String[] agrs)
	{
        Scanner sc =new Scanner(System.in);
        System.out.print("Enter N : ");
        n=sc.nextInt();
        findAns(n);
	}
}
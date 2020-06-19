import java.util.*;
import java.io.*;

class Matrix
{
   int rows, cols;
   int [][]m;
   
   Matrix(int rows, int cols)
   {
      this.rows = rows;
      this.cols = cols;
      m = new int[this.rows][this.cols];
   }

   void readMat()
   {
      Scanner sc = new Scanner(System.in);
      System.out.println("Enter elements of matrix");
      for(int i=0; i<this.rows; i++)
      {
         for(int j=0; j<this.cols; j++)
         {
            m[i][j] = sc.nextInt();
         }
      }
   }
 
   void displayMat()
   {
      System.out.println("Matrix is : ");
      for(int i=0; i<this.rows; i++)
      {
         for(int j=0; j<this.cols; j++)
         {
            System.out.print(m[i][j]+" ");
         }
         System.out.println();
      }
   }
  
   Matrix mulMat(Matrix m2)
   {
      Matrix temp = new Matrix(m2.rows, this.cols);
      if(this.cols == m2.rows)
      {
        for(int i=0; i<this.rows; i++)
        {
           for(int j=0; j<m2.cols; j++)
           {
              for(int k=0; k<m2.rows; k++)
              {
                 temp.m[i][j] = temp.m[i][j] + this.m[i][k] + this.m[k][j];
              }
           }
        }
      }
      return temp;
    }
          
   void symMat()
   {
      if(this.rows != this.cols)
      {
         System.out.println("The given matrix is not a square matix thus cannot be symmetric");
      }
      else
      {
         boolean symmetric = true;
         for(int i=0; i<this.rows ; i++)
         {
           for(int j=0; j<this.cols ; j++)
           {  
              if(this.m[i][j] != this.m[j][i])
              {
                 symmetric = false;
                 break;
              }
           }
         }
         if(symmetric)
         {
            System.out.println("The given matrix is symmetric");
         }
         else
         {
             System.out.println("The given matrix is not symmetric");
         }   
      }
   }

   Matrix transMat()
   {
      Matrix temp = new Matrix(this.rows, this.cols);
       for(int c=0; c<this.rows; c++)
      {
         for(int d=0; d<this.cols; d++)
         {
             temp.m[d][c] = this.m[c][d];
         }
      }
      return temp;
   }

   public static void main(String args[])
   {
      Scanner sc = new Scanner(System.in);

      System.out.println("Enter no. of rows and columns for Matrix 1");
      int r1 = sc.nextInt();
      int c1 = sc.nextInt();
      Matrix m1 = new Matrix(r1,c1);
      m1.readMat();


      System.out.println("Enter no. of rows and columns for Matrix 2");
      int r2 = sc.nextInt();
      int c2 = sc.nextInt();
      Matrix m2 = new Matrix(r2,c2);
      m2.readMat();

      m1.displayMat();
      m2.displayMat();
      
      boolean exit = true;

      do
      {
         System.out.println("Enter any one of the following: ");  
         System.out.println("1:Transpose matrix first matrix");
         System.out.println("2:Transpose matrix second matrix");
         System.out.println("3:Check whether Matrix 1 is symmetric");
         System.out.println("4:Check whether Matrix 2 is symmetric");
         System.out.println("5:mulmat");
         System.out.println("6:exit");

         int ch = sc.nextInt();
        
           switch(ch)
           {
                case 1: 
                        Matrix m3 = m1.transMat();
                        m3.displayMat();
                        break;

                case 2: 
                        Matrix m4 = m2.transMat();
                        m4.displayMat();
                        break;

                case 3: 
                        m1.symMat();
                        break;

                case 4: 
                        m2.symMat();
                        break;

                case 5: 
                        m3 = m1.mulMat(m2);
                        m3.displayMat();
                        break;

                case 6: 
                        exit = false;
                        break; 

               default: 
                        System.out.println("Invalid Input");
                        break;
            }
     }while(exit == true);

     sc.close();
  }
}

/*OUTPUT :
Enter no. of rows and columns for Matrix 1
2
2
Enter elements of matrix
1
2
3
4
Enter no. of rows and columns for Matrix 2
2
2
Enter elements of matrix
1
0
0
1
Matrix is :
1 2
3 4
Matrix is :
1 0
0 1
Enter any one of the following:
1:Transpose matrix first matrix
2:Transpose matrix second matrix
3:Check whether Matrix 1 is symmetric
4:Check whether Matrix 2 is symmetric
5:mulmat
6:exit
1
Matrix is :
1 3
2 4
Enter any one of the following:
1:Transpose matrix first matrix
2:Transpose matrix second matrix
3:Check whether Matrix 1 is symmetric
4:Check whether Matrix 2 is symmetric
5:mulmat
6:exit
2
Matrix is :
1 0
0 1
Enter any one of the following:
1:Transpose matrix first matrix
2:Transpose matrix second matrix
3:Check whether Matrix 1 is symmetric
4:Check whether Matrix 2 is symmetric
5:mulmat
6:exit
3
The given matrix is not symmetric
Enter any one of the following:
1:Transpose matrix first matrix
2:Transpose matrix second matrix
3:Check whether Matrix 1 is symmetric
4:Check whether Matrix 2 is symmetric
5:mulmat
6:exit
4
The given matrix is symmetric
Enter any one of the following:
1:Transpose matrix first matrix
2:Transpose matrix second matrix
3:Check whether Matrix 1 is symmetric
4:Check whether Matrix 2 is symmetric
5:mulmat
6:exit
5
Matrix is :
7 9
11 13
Enter any one of the following:
1:Transpose matrix first matrix
2:Transpose matrix second matrix
3:Check whether Matrix 1 is symmetric
4:Check whether Matrix 2 is symmetric
5:mulmat
6:exit
6
*/
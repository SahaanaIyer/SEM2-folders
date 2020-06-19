import java.util.*;
import java.io.*;

class Empsort
{
  int id;
  float sal;
  static int count;
  Empsort()                 //Default Constructor
  {
     id = 0;
     sal = 0.0f;
  }
  
  Empsort(float sal)        //Parameterized Constructor
  {
     count++;
     this.id = count;
     this.sal = sal;
  }
  
  void display()
  {
     System.out.println("Employee id is" +id);
     System.out.println("Employee salary is" +sal);
  }
}
 
class DemoEmpSort
{
   public static void main(String[] args)
   {
      Scanner sc = new Scanner(System.in);

      System.out.println("Enter no. of employees");
      int n = sc.nextInt();
      
      Empsort[] e = new Empsort[n];    //Creating array
      
      for(int i=0; i<e.length; i++)
      {
         System.out.println("Enter employee salary");
         float s = sc.nextFloat();
         e[i] = new Empsort(s);
      }
     
      Empsort temp = new Empsort();    //temp created for sorting & is a class object
 
      for(int j=0; j<e.length; j++)
      {
         for(int k=0; k<e.length-1; k++)
         {
            if(e[k].sal > e[k+1].sal)
            {
                temp = e[k];
                e[k] = e[k+1];
                e[k+1] = temp;
            }
         }
      }
 
      for(int i=0; i<e.length; i++)
      {
         e[i].display();
      }
   }
}
/*OUTPUT :
Enter no. of employees
3
Enter employee salary
10000
Enter employee salary
20000
Enter employee salary
30000
Employee id is1
Employee salary is10000.0
Employee id is2
Employee salary is20000.0
Employee id is3
Employee salary is30000.0

*/
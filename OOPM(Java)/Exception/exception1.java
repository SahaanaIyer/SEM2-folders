import java.util.*;

class exception1
{
   public static void main(String args[])
   {
       try
       {
           int a, b;
           Scanner sc = new Scanner (System.in);
           System.out.println("Enter the two numbers");
           a = sc.nextInt();
           b = sc.nextInt();
           int c = a / b;
           System.out.println ("The output is " +c);
       }


       catch (ArithmeticException e)
       {
            System.out.println("Arithmetic Exception caught");
       }

       catch (Exception e)
       {
            System.out.println("Exception caught");
       }

   }
}
/*OUTPUT:
Enter the two numbers
2
0
Arithmetic Exception caught
*/
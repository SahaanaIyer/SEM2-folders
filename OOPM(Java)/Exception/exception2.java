import java.util.*;

class exception2
{
   static void valid(int i)
   {
       if(i < 18)
       {
          throw new ArithmeticException ("not valid number");
       }
       else
       {
           System.out.println("Welcome");
       }
   }


   public static void main(String args[])
   {
       try
       {
           valid(16);
       }


       catch (ArithmeticException e)
       {
            System.out.println(e);
       }
   }
}
/*OUTPUT:
java.lang.ArithmeticException: not valid number
*/
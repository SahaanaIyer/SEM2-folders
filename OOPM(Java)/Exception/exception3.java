import java.util.*;

class exception3
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
       valid(20);
   }
}
/*OUTPUT:
Welcome
*/
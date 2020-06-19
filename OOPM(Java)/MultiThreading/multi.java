import java.util.*;
import java.lang.*;

class multi implements Runnable
{
   public void run()
   {
      System.out.println("\n Hello world \n");
   }
   
   public static void main(String args[])
   {
      multi obj = new multi();
      Thread t1 = new Thread(obj);
      t1.start();
   }
}
/*OUTPUT:

 Hello world

*/
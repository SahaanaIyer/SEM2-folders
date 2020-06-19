import java.util.*;
import java.lang.*;

class MultiThreading extends Thread
{
   public void run()
   {
      System.out.println("\n Hello world \n");
   }
   
   public static void main(String args[])
   {
      MultiThreading obj = new MultiThreading();
      obj.start();
   }
}
/*OUTPUT:

 Hello world

*/
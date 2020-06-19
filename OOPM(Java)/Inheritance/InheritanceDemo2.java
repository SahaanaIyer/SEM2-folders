import java.lang.*;
import java.util.*;

class A
{
     protected int x;

     A()
     {
       	 x = 10;
     }

     A (int x)
     {
  	 this.x = x;
     }

     public String toString() 
     {
 	 return (new Integer(x).toString()); 
     }
}

class B extends A
{
     private int y;
	
     B()
     {
	 y = 5;
     }

     public String toString() 
     {
		return (x+ "," +y);
     }
}

public class InheritanceDemo2
{
     public static void main(String [] args)
     {
	 A ob1 = new A();
	 System.out.println(ob1);

	 System.out.println("--------------------------------------");

	 B ob2 = new B();
	 System. out.println(ob2);		
     }
}

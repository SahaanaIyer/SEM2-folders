import java.util.*;
import java.lang.*;

class Rational
{
   int num, den;
   
   Rational()
   {
 
   }

   Rational(int a, int b)
   {
     num = a;
     den = b;
   }

  void display()
  {
     System.out.println( num+ "/" +den );
  }

  Rational add(Rational r2)
  {
     Rational temp = new Rational();
    
     temp.num = (this.num * r2.den) + (this.den * r2.num);
     temp.den = (this.den * r2.den);

     return temp;
  }

  Rational sub(Rational r2)
  {
     Rational temp = new Rational();
    
     temp.num = (this.num * r2.den) - (this.den * r2.num);
     temp.den = (this.den * r2.den);

     return temp;
  }
}

class DemoRational
{
   public static void main(String args[])
   {
     Scanner sc=new Scanner(System.in);
     
     System.out.println("Enter the numerator of 1st no.");
     int a=sc.nextInt();
     System.out.println("Enter the denominator part of 1st no.");
     int b=sc.nextInt();
     Rational r1 = new Rational(a,b);
     
     System.out.println("Enter the numerator of 2nd no.");
     int c=sc.nextInt();
     System.out.println("Enter the denominator of 2nd no.");
     int d=sc.nextInt();
     Rational r2 = new Rational(c,d);

     Rational r3 = new Rational();
     r3 = r1.add(r2);
     r3.display();

     Rational r4 = new Rational();
     r4 = r1.sub(r2);
     r4.display();
  }
}

/*OUTPUT :
Enter the numerator of 1st no.
1
Enter the denominator part of 1st no.
2
Enter the numerator of 2nd no.
3
Enter the denominator of 2nd no.
2
8/4
-4/4
*/
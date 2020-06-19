import java.util.*;
import java.lang.*;

class Polygon
{
   int l,b;

   Polygon()
   {

   }

  Polygon(int l, int b)
  {
      this.l = l;
      this.b = b;
  }

  int area()
  {
      return l * b;
  }
}

class Rectangle implements Polygon
{
   Rectangle (int l, int b)
   {
       super(l, b);
   }
   int area()
   {
       return super.area();
   }
}

class Triangle implements Polygon
{
   Triangle(int l, int b)
   {
       super(l, b);
   }
   int area()
   {
       return super.area() / 2;
   }
}

class SingleInheritance
{
  public static void main (String args[])
  {
     int l, b;
    
     Scanner sc = new Scanner(System.in);
     System.out.println("Enter the length");
     l = sc.nextInt();
     
     System.out.println("Enter the breadth");
     b = sc.nextInt();

     Rectangle r = new Rectangle(l, b);
     System.out.println("Area of rectangle is " +r.area());
     
     
     Triangle t = new Triangle(l, b);
     System.out.println("Area of triangle is " +t.area());
   }
}
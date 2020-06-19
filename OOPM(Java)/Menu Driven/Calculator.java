import java.lang.*;
import java.util.*;

class Calculator
{
  static void add(int a, int b)
  {
    int c = a+b;
    System.out.println(c);
  }

  static void sub(int a, int b)
  {
    int c = a - b;
    System.out.println(c);
  }
  
  static void div(int a, int b)
  {
    float c = (float) a / b;
    System.out.println(c);
  }

  
  static void mul(int a, int b)
  {
    int c = a * b;
    System.out.println(c);
  }

  public static void main(String args[])
  {
     int a , b, n=1;
     Scanner sc = new Scanner(System.in);
     while(n==1){
     System.out.println("1: Addition  2: Subtraction  3: Multiplication  4: Division  5: Exit");
     System.out.println("Enter the choice");
     int choice = sc.nextInt();
     
     System.out.println("Enter the two numbers");

     a = sc.nextInt();
     b = sc.nextInt();

     switch(choice)
            {
                case 1 :  add(a , b);
                          break;

                case 2 :  sub(a , b);
                          break;

                case 3 :  mul(a , b);
                          break;

                case 4 :  div(a , b);
                          break;

                case 5 :
                          System.exit(0);
            }
     }
   }   
}
/*OUTPUT :
1: Addition  2: Subtraction  3: Multiplication  4: Division  5: Exit
Enter the choice
1
Enter the two numbers
1
2
3
1: Addition  2: Subtraction  3: Multiplication  4: Division  5: Exit
Enter the choice
2
Enter the two numbers
1
2
-1
1: Addition  2: Subtraction  3: Multiplication  4: Division  5: Exit
Enter the choice
3
Enter the two numbers
1
2
2
1: Addition  2: Subtraction  3: Multiplication  4: Division  5: Exit
Enter the choice
4
Enter the two numbers
2
1
2.0
1: Addition  2: Subtraction  3: Multiplication  4: Division  5: Exit
Enter the choice
5
*/
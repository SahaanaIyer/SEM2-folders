import java.util.*;
import java.lang.*;

class complex
{
  int real,imag;

  complex()
  {
    real = 0;
    imag = 0;
  }

  complex(int a, int b)
  {
     real = a;
     imag = b;
  }

  void display()
  {
     System.out.println( real+ "+ i" +imag);
  }

  complex add(complex C2)
  {
     complex temp = new complex();
     
     temp.real = this.real + C2.real;
     temp.imag = this.imag + C2.imag;

     return temp;
  }

  complex sub(complex C2)
  {
     complex temp = new complex();
     
     temp.real = this.real - C2.real;
     temp.imag = this.imag - C2.imag;

     return temp;
  }

  complex mul(complex C2)
  {
     complex temp = new complex();
     
     temp.real = (this.real * C2.real) - (this.imag * C2.imag);
     temp.imag = (this.real * C2.imag) + (this.imag * C2.real);

     return temp;
  }

  complex div(complex C2)
  {
     complex temp = new complex();
     
     temp.real = ((this.real * C2.real) + (this.imag * C2.imag)) / ((C2.real*C2.real) + (C2.imag*C2.imag));
     temp.imag = ((this.imag * C2.real) - (this.real * C2.imag)) / ((C2.real*C2.real) + (C2.imag*C2.imag));

     return temp;
  }
}

class DemoComplex
{
   public static void main(String args[])
   {
     int n=1;
     Scanner sc=new Scanner(System.in);
     
     System.out.println("Enter the real part of 1st no.");
     int a=sc.nextInt();
     System.out.println("Enter the imaginary part of 1st no.");
     int b=sc.nextInt();
     complex C1 = new complex(a,b);
     
     System.out.println("Enter the real part of 2nd no.");
     int c=sc.nextInt();
     System.out.println("Enter the imaginary part of 2nd no.");
     int d=sc.nextInt();
     complex C2 = new complex(c,d);

    while(n==1){
     System.out.println("Main Menu");
     System.out.println("1.Addition");
     System.out.println("2.Subtraction");
     System.out.println("3.Multiplication");
     System.out.println("4.Division");
     System.out.println("5.Exit");
     
     
     System.out.println("Enter Your Choice :");
     int ch=sc.nextInt();
     
      do
     {
        switch(ch)
        {
           case 1 :
                     complex C3 = new complex();
                     C3 = C1.add(C2);
                     System.out.println("Added complex no. is ");
                     C3.display();
                     break;

           case 2 :
                     complex C4 = new complex();
                     C4 = C1.sub(C2);
                     System.out.println("Subtracted complex no. is ");
                     C4.display();
                     break;

           case 3 :
                     complex C5 = new complex();
                     C5 = C1.mul(C2);
                     System.out.println("Multiplied complex no. is ");
                     C5.display();
                     break;

           case 4 :
                     complex C6 = new complex();
                     C6 = C1.div(C2);
                     System.out.println("Divided complex no. is ");
                     C6.display();
                     break;
           
           case 5 :
                     System.exit(0);
         }
      }while(ch == 6);
    }
   }
}
/*OUTPUT :
Enter the real part of 1st no.
1
Enter the imaginary part of 1st no.
2
Enter the real part of 2nd no.
3
Enter the imaginary part of 2nd no.
4
Main Menu
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
Enter Your Choice :
1
Added complex no. is
4+ i6
Main Menu
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
Enter Your Choice :
2
Subtracted complex no. is
-2+ i-2
Main Menu
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
Enter Your Choice :
3
Multiplied complex no. is
-5+ i10
Main Menu
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
Enter Your Choice :
4
Divided complex no. is
0+ i0
Main Menu
1.Addition
2.Subtraction
3.Multiplication
4.Division
5.Exit
Enter Your Choice :
5
*/
import java.util.*;

class book
{
   String auth, titl, publ;
   float price;
   int stock;
   
   book()
   {

   }

   book(String auth, String titl, String publ, float price, int stock)
   {
      this.auth = auth;
      this.titl = titl;
      this.publ = publ;
      this.price = price;
      this.stock = stock;
   }
	
   boolean searchBook(String author,String title)
   {
      if(auth.equals(author) && titl.equals(title))
      {
	 System.out.println("The book is found");
	 return true;
      }
      else
      {
	 System.out.println("The book is not available");
	 return false;
      }
   }

   void display()
   {
		
       System.out.println(auth+"\t"+titl+"\t"+publ+"\t"+price+"\t"+stock);
   }
}

class Library
{
    public static void main(String args[])
    {
        int stock, x=0, y, i;
	float price;
	String auth,titl,publ;

	Scanner sc = new Scanner(System.in);
		
        System.out.println("Enter no. of books");
        int n = sc.nextInt();

	book b[] = new book[n];

	for(i=0; i<b.length; i++)
	{
           System.out.println("Enter the Author name of  "+(i+1)+" book");
	   auth = sc.next();

           System.out.println("Enter the Title name of  "+(i+1)+" book");
	   titl = sc.next();

           System.out.println("Enter the Publisher name of  "+(i+1)+" book"); 
	   publ = sc.next();

	   System.out.println("Enter the price of  "+(i+1)+" book");
	   price = sc.nextFloat();

           System.out.println("Enter the stock of  "+(i+1)+" book");
	   stock = sc.nextInt();
			
			
	   b[i] = new book(auth, titl, publ, price, stock);
	}

	System.out.println("Author \t Title \t Publisher \t Price \t Stock");
	for(i=0; i<b.length; i++)
	{
	   b[i].display();
	}

	System.out.println("Enter the name of the author and the name of the title of the book you want to search: ");
	auth = sc.next();
	titl = sc.next();

	for(i=0; i<b.length; i++)
        {
	    if(b[i].searchBook(auth, titl))
	    {
		x = b[i].stock;
		break;
            }
	    else 
            {
                System.exit(0);
	    } 
         }

	 System.out.println("Enter the required no. of copies of the book which is searched: ");
	 y = sc.nextInt();

	 if(y <= x)
         {
	     System.out.println("There are sufficient copies available");
	 }
         else
         {
             System.out.println("No copies available");
         }
    }		
}

/*OUTPUT :
Enter no. of books
3
Enter the Author name of  1 book
abc
Enter the Title name of  1 book
ABC
Enter the Publisher name of  1 book
AbC
Enter the price of  1 book
1200
Enter the stock of  1 book
300
Enter the Author name of  2 book
def
Enter the Title name of  2 book
DEF
Enter the Publisher name of  2 book
DeF
Enter the price of  2 book
400
Enter the stock of  2 book
500
Enter the Author name of  3 book
ghi
Enter the Title name of  3 book
GHI
Enter the Publisher name of  3 book
gHi
Enter the price of  3 book
300
Enter the stock of  3 book
160
Author   Title   Publisher       Price   Stock
abc     ABC     AbC     1200.0  300
def     DEF     DeF     400.0   500
ghi     GHI     gHi     300.0   160
Enter the name of the author and the name of the title of the book you want to search:
abc
ABC
The book is found
Enter the required no. of copies of the book which is searched:
444
No copies available
*/
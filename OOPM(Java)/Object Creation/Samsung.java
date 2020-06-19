import java.util.*;

class customer
{
   int id;
   String brand, prod;
   
   customer(int id, String brand, String prod)
   {
      this.id = id;
      this.brand = brand;
      this.prod = prod;
   }

   void display()
   {
      {
       	 System.out.println("Product id = " +id+ "Brand = " +brand+ "Product = " +prod);
      }
   }
}
	
class Samsung
{
   public static void main(String args[])
   {
      int i, id, count=0, count1=0;
      String brand, prod;

      Scanner sc = new Scanner(System.in);

      System.out.println("Enter no. of customers");
      int n = sc.nextInt();

      customer c[] = new customer[n];

      for(i=0; i<c.length; i++)
      {
	 id = ++count;

	 System.out.println("Enter the brand name:");
     brand = sc.nextLine();	

  	 System.out.println("Enter the product name:");
	 prod = sc.nextLine();

	 c[i] = new customer(id, brand, prod);
      }

      for(i=0;i<c.length;i++)
      {
	 if(c[i].brand.equals("Samsung"))
	 {
	     c[i].display();
	     count1++;
	 }
      }

      System.out.println(count1+" Customers have brought Samsung product ");
   }
}

/*OUTPUT :
Enter no. of customers
2
Enter the brand name:
Enter the product name:
Samsung  Mobile
Enter the brand name:
Micromax
Enter the product name:
Mobile
1 Customers have brought Samsung product
*/
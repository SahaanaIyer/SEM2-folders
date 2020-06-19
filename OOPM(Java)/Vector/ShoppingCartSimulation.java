import java.util.*;

class ProductItem
{
    private int id;
    private double price;
    ProductItem(int id,double price)
    {
        this.id=id;
        this.price=price;
    }
    double getPrice()
    {
        return price; //private members are accessed using non-private method
    }
    public String toString()
    {
        return "ID : "+id+"Price : "+price; //string representation of Product Item
    }
}
class ShoppingCart
{
    int custid;
    Vector itemsv;

    ShoppingCart(int custid)
    {
        this.custid=custid;
        itemsv=new Vector();
    }
    public void addItem(ProductItem item)
    {
        itemsv.add(item);
    }
    public void removeItem(ProductItem item)
    {
        itemsv.remove(item);
    }
    public void showAllItem()
    {
        for(int i=0;i<itemsv.size();i++)
        {
            ProductItem temp=(ProductItem)itemsv.get(i);
            System.out.println(temp);
        }
    }
    public double calculateAmt()
    {
        double amt=0.0;
        for(int i=0;i<itemsv.size();i++)
        {
            ProductItem temp=(ProductItem)itemsv.get(i);
            amt=amt+temp.getPrice();
        }
        return amt;
    }
}
public class ShoppingCartSimulation
{
    public static void main(String[] args)
    {
       
        ProductItem [] p = new ProductItem[11];//there are total 10 items , p[1] is first item

        populateItems(p);
       
        ShoppingCart sc=new ShoppingCart(1); //first shopping cart

        Scanner in = new Scanner(System.in);
        do
        {
            System.out.println("1.Add item \n2. Remove item \n3. Make final Payment");
            System.out.print("Enter your option:= ");
            int option = in.nextInt();
            switch(option)
            {
                case 1:
                    System.out.println("Which item put in bag:= ");
                    int item_no1 = in.nextInt();

                    sc.addItem(p[item_no1]);

                break;
                case 2:
                    System.out.println("Which item to remove from bag:= ");
                    int item_no2 = in.nextInt();

                    sc.removeItem(p[item_no2]);
                break;
                case 3:
                    System.out.println("Printed Bill");
                    sc.showAllItem();
                    System.out.println("You have to make payment of "+sc.calculateAmt());
               
                    System.exit(0); //leave the shop
            }   
        }while(true);       
    }

    static void populateItems(ProductItem [] h)
    {
        Scanner in = new Scanner(System.in);
        for(int i = 0 ; i < h.length; i++)
        {
            System.out.println("Enter price of a product item "+(i+1)+":= ");
            double price = in.nextDouble();
            h[i] = new ProductItem(i+1,price);
        }
    }
}
/*OUTPUT
[universe@localhost oopm]$ java ShoppingCartSimulation
Enter price of a product item 1:=
100
Enter price of a product item 2:=
200
Enter price of a product item 3:=
300
Enter price of a product item 4:=
400
Enter price of a product item 5:=
500
Enter price of a product item 6:=
600
Enter price of a product item 7:=
700
Enter price of a product item 8:=
2000
Enter price of a product item 9:=
3000 
Enter price of a product item 10:=
4000
Enter price of a product item 11:=
3500
1.Add item
2. Remove item
3. Make final Payment
Enter your option:= 1
Which item put in bag:=
9
1.Add item
2. Remove item
3. Make final Payment
Enter your option:= 1
Which item put in bag:=
5
1.Add item
2. Remove item
3. Make final Payment
Enter your option:= 1
Which item put in bag:=
3
1.Add item
2. Remove item
3. Make final Payment
Enter your option:= 1
Which item put in bag:=
7
1.Add item
2. Remove item
3. Make final Payment
Enter your option:= 2
Which item to remove from bag:=
3
1.Add item
2. Remove item
3. Make final Payment
Enter your option:= 3
Printed Bill
ID : 10Price : 4000.0
ID : 6Price : 600.0
ID : 8Price : 2000.0
You have to make payment of 6600.0
*/
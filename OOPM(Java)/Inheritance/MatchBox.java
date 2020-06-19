import java.lang.*;
import java.util.*;

class box 
{
    double width;
    double height;
    double depth;
    
    box () 
    {	

    }

    box (double w, double h, double d) 
    {
        width = w;
	height = h;
	depth = d;
    }
	
    double volume () 
    {
	return (width * height * depth);
    }
}

class Matchbox extends box 
{
     double weight;
	
     Matchbox () 
     {
	
     }
	
     Matchbox (double w, double h, double d, double m) 
     {
	width = w;
	height = h;
	depth = d;
	weight = m;
     }
}

public class MatchBox
{
     public static void main (String[] args)
     {
	Matchbox mb = new Matchbox (); 

        Scanner sc = new Scanner (System.in);

        System.out.println ("Enter the width of the Matchbox");
        int w = sc.nextInt ();

        System.out.println ("Enter the height of the Matchbox");
        int h = sc.nextInt ();

        System.out.println ("Enter the depth of the Matchbox");
        int d = sc.nextInt ();

        System.out.println ("Enter the weight of the Matchbox");
        int m = sc.nextInt ();

	Matchbox mb1 = new Matchbox (w, h, d, m);

	System.out.println ("Volume is " +mb1.volume());
	System.out.println ("Width of Matchbox is " +mb1.width);
	System.out.println ("Height of Matchbox is " +mb1.height);
	System.out.println ("Depth of Matchbox is " +mb1.depth);
	System.out.println ("Weight of Matchbox is " +mb1.weight);	
     }
}

/*OUTPUT :
Enter the width of the Matchbox
10
Enter the height of the Matchbox
10
Enter the depth of the Matchbox
10
Enter the weight of the Matchbox
10
Volume is 1000
Width of Matchbox is 10
Height of Matchbox is 10
Depth of Matchbox is 10
Weight of Matchbox is 10
*/

import java.util.*;
import java.lang.*;
class Vectordemo
{
	public static void main(String args[])
	{
		Vector v = new Vector();
		v.add(0,10);
		v.add(1,10.5);
		v.add(2,"Sahaana");
		System.out.println(v);
	}
}

/*OUTPUT:
[10, 10.5, Sahaana]
*/
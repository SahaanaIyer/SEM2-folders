import java.util.*;
import java.lang.*;

class array
{
    static int findmin(int h[])
    {
        int min = h[0];
        for(int i=1; i<h.length; i++)
        {
            if(h[i]<min)
             {
                  min = h[i];
             }
        }
        return min;
    }

    static int findmax(int h[])
    {
        int max = h[0];
        for(int i=1; i<h.length; i++)
        {
            if(h[i]>max)
             {
                  max = h[i];
             }
        }
        return max;
    }
   
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter no. of elements");
        int n = sc.nextInt();
        int a[] = new int[n];
        
        for(int i=0; i<n; i++)
        {
            System.out.println("Enter element no." +(i+1));
            a[i] = sc.nextInt();
        }
        int max = findmax(a);
        int min = findmin(a);
        System.out.println("The Max Value is " +max);
        System.out.println("The Min Value is " +min);
    }
}

/*OUTPUT :
Enter no. of elements
5
Enter element no.1
2
Enter element no.2
3
Enter element no.3
4
Enter element no.4
5
Enter element no.5
1
The Max Value is 5
The Min Value is 1
*/

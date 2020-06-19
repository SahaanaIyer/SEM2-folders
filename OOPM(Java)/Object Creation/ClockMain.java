import java.util.*;

class Clock
{
    protected int hh;
    protected int mm;
    protected int ss;

    Clock(){}                    //default constructor

    Clock(int h, int m, int s)  //parametrized constructor
    {
        hh=h;
        mm=m;
        ss=s;
    }
}

class DigitalClock extends Clock  //singlelevel inheritance
{
    String tag=new String();
    DigitalClock(int h, int m, int s)
    {
        super(h,m,s);
        if(hh>12)
        {
            tag="pm";
            hh=hh-12;
        }
        else
        {
            tag="am";
        }
    }

    public String toString()
    {

        return hh+":"+mm+":"+ss+tag;
    }
}

public class ClockMain
{
    public static void main(String [] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the details in 24 system:");
        System.out.println("Enter the value hour");
        int h=sc.nextInt();
        System.out.println("Enter the value min");
        int m=sc.nextInt();
        System.out.println("Enter the value sec");
        int s=sc.nextInt();
        DigitalClock p=new DigitalClock(h,m,s);
        System.out.println(p.toString());
    }
}

/*OUTPUT :
Enter the details in 24 system:
Enter the value hour
1
Enter the value min
34
Enter the value sec
23
1:34:23am
Enter the details in 24 system:
Enter the value hour
22
Enter the value min
34
Enter the value sec
2
10:34:2pm
*/


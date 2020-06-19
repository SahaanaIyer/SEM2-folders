import java.lang.*;
import java.util.*;

class cricketer
{
   int runs, no_matches, wickets, ball_avg, catches;
   String nationality, name;
   
   cricketer()
   {

   }

   cricketer (String name, String nationality, int runs, int no_matches, int wickets, int ball_avg, int catches)
   {
      this.name = name;
      this.nationality = nationality;
      this.runs = runs;
      this.no_matches = no_matches;
      this.wickets = wickets;
      this.ball_avg = ball_avg;
      this.catches = catches;
   }

   boolean searchCricketer( int runs)
   {
      if(runs.equals(runs))
      {
System.out.println("The cricketer is found");
return true;
      }
      else
      {
System.out.println("The cricketer is not available");
return false;
      }
   }

   boolean searchCricketer(int wickets)
   {
      if( wickets.equals(wickets))
      {
System.out.println("The cricketer is found");
return true;
      }
      else
      {
System.out.println("The cricketer is not available");
return false;
      }
   }  

   boolean searchCricketer(int catches)
   {
      if( catches.equals(catches))
      {
System.out.println("The cricketer is found");
return true;
      }
      else
      {
System.out.println("The cricketer is not available");
return false;
      }
   }  
   

   void display()
   {
      System.out.println(name+ "\t" +nationality+ "\t" +runs+ "\t" +no_matches+ "\t" +wickets+ "\t" +catches+ "\t" +ball_avg );
   }
}

class CricketerData
{
    public static void main(String args[])
    {
        int i, x;
        int runs, no_matches, wickets, ball_avg, catches;
        String nationality, name;

        Scanner sc = new Scanner(System.in);
       
        System.out.println("Enter no. of cricketers");
        int n = sc.nextInt();

        cricketer c[] = new cricketer[n];

for(i=0; i<c.length; i++)
{
           System.out.println("Enter the Name of  "+(i+1)+" cricketer");
  name = sc.next();

           System.out.println("Enter the nationality of  "+(i+1)+" cricketer");
  nationality = sc.next();

           System.out.println("Enter no. of runs scored by  "+(i+1)+"th cricketer");
  runs = sc.nextInt();

  System.out.println("Enter the no. of matches of  "+(i+1)+"th cricketer");
  no_matches = sc.nextInt();

           System.out.println("Enter the no. of wickets of  "+(i+1)+"th cricketer");
  wickets = sc.nextInt();

           System.out.println("Enter the no. of catches of  "+(i+1)+"th cricketer");
  catches = sc.nextInt();

  System.out.println("Enter the average no. of balls of  "+(i+1)+"th cricketer");
  ball_avg = sc.nextInt();

  c[i] = new cricketer(name, nationality, runs, no_matches, wickets, catches, ball_avg);
}

        System.out.println("Name \t Nationality \t Runs \t Matches \t Wickets\t Catches \t Average_Balls \n");
for(i=0; i<c.length; i++)
{
  c[i].display();
}

        System.out.println("Enter the no. of runs of the cricketer to be searched: \n");
runs = sc.nextInt();

for(i=0; i<c.length; i++)
        {
   if(c[i].searchCricketer(runs))
   {
x = c[i].runs;
break;
            }
   else
            {
                System.exit(0);
   }
         }

System.out.println("Enter the no. of wickets of the cricketer to be searched: \n");
wickets = sc.nextInt();

for(i=0; i<c.length; i++)
        {
   if(c[i].searchCricketer(wickets))
   {
x = c[i].wickets;
break;
            }
   else
            {
                System.exit(0);
   }
         }
 
        System.out.println("Enter the no. of catches of the cricketer to be searched \n");
catches = sc.nextInt();

for(i=0; i<c.length; i++)
        {
   if(c[i].searchCricketer(catches))
   {
x = c[i].catches;
break;
            }
   else
            {
                System.exit(0);
   }
         }


    }
}

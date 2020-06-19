// Employee class declaration.

public class Employee {

   private String firstName;

   private String lastName;

   private static int count = 0;  // number of objects in memory

 

   // initialize employee, add 1 to static count and

   // output String indicating that constructor was called

   public Employee( String first, String last )

   {

      firstName = first;

      lastName = last;

 

      ++count;  // increment static count of employees

      System.out.println( "Employee constructor: " +

         firstName + " " + lastName );

   }

 

   // subtract 1 from static count when garbage collector

   // calls finalize to clean up object and output String

   // indicating that finalize was called

   protected void finalize()

   {

      --count;  // decrement static count of employees

      System.out.println( "Employee finalizer: " +

         firstName + " " + lastName + "; count = " + count );

   }

 

   // get first name

   public String getFirstName()

   {

      return firstName;

   }

 

   // get last name

   public String getLastName()

   {

      return lastName;

   }

 

   // static method to get static count value

   public static int getCount()

   {

      return count;

   }

 

} // end class Employee

 

 


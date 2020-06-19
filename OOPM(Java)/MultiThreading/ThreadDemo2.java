class NewThread extends Thread
 {
	NewThread(){}
	NewThread( String name)
	{
		super(name);//assigning name to a thread
	}
  	
   	public void run() 
        {
     		try 
		{
        		for(int i = 5; i > 0; i--)
		 	{
            			System.out.println("Child Thread: " + i);
                       			 // Let the thread sleep for a while.
         			Thread.sleep(500);
        		 }
      		} 
		catch (InterruptedException e)
		{
        		System.out.println("Child interrupted.");
      		}

      		System.out.println("Exiting child thread.");
   	}
}

public class ThreadDemo2
{
  	 public static void main(String args[])
	 {
        		Thread t1 = new NewThread("Demo Thread 1");
        		System.out.println("Child thread: " + t1);
        		t1.start(); // Start the thread

			    Thread t2 = new NewThread("Demo Thread 2");
        		System.out.println("Child thread: " + t2);
        		t2.start(); // Start the thread
        		
      			System.out.println("Main thread exiting.");
   	}
}

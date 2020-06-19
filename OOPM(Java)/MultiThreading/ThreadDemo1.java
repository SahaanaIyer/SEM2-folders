class NewThread implements Runnable 
{
   
   	// This is the entry point for the  thread.
   	public void run() 
    	{
      		try 
		{
         		for(int i = 5; i > 0; i--) 
			{
            			System.out.println(Thread.currentThread().getName()+":"+i);
            			// Let the thread sleep for a while.
            			Thread.sleep(500);//sleep for 500 ms 
         		}
     		}	 
		catch (InterruptedException e) 
		{
         		System.out.println("Child interrupted.");
     		}
     	
		System.out.println("Exiting child thread.");
   	}
}

public class ThreadDemo1 
{
   public static void main(String args[]) 
  {
      NewThread nt = new NewThread(); // create a new thread
      
      Thread t1 = new Thread(nt,"Demo Thread 1");

      Thread t2 = new Thread(nt,"Demo Thread 2");
      
      System.out.println("Child thread: " + t1);
	 t1.start();

      System.out.println("Child thread: " + t2);
	 t2.start();
	
	
/*	try{
        t1.join();
        t2.join();
    }
    catch(InterruptedException e){
            e.printStackTrace();
    } */
    
      System.out.println("Main thread exiting.");
   }
}

/*OUTPUT:
Child thread: Thread[Demo Thread 1,5,main]
Child thread: Thread[Demo Thread 2,5,main]
Main thread exiting.
Demo Thread 1:5
Demo Thread 2:5
Demo Thread 1:4
Demo Thread 2:4
Demo Thread 1:3
Demo Thread 2:3
Demo Thread 1:2
Demo Thread 2:2
Demo Thread 1:1
Demo Thread 2:1
Exiting child thread.
Exiting child thread.
*/
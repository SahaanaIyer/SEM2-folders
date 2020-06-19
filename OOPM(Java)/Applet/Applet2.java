import java.applet.Applet;
import java.awt.Graphics;
/*
<applet code="HelloWorldApplet.class" height=300 width=200>Applet1</applet> */

public class HelloWorldApplet extends Applet
{
   public void init()
   {
    System.out.println("Applet initialized");
   }
   public void start()
   {
    System.out.println("Applet is running-Gained Focus");
   }
   public void stop()
   {
    System.out.println("Lost focus");
   }
   public void destroy()
   {
    System.out.println("Destroyed from memory");
   }
   public void paint (Graphics g) //to write on applet window
   {
      g.drawString ("Hello World", 25, 50);
   }
}
/*OUTPUT
Applet initialized
Applet is running-Gained Focus
Lost focus
Applet is running-Gained Focus
Lost focus
Destroyed from memory
*/

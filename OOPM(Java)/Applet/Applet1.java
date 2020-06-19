import java.applet.Applet;
import java.awt.Graphics;
/*
<applet code="Applet1.class height=300 width=200>Applet1</applet> */

public class Applet1 extends Applet 
{
   Font f1;
   public void init()
   { 
	f1 = new Font("Arial",Font.BOLD,18);
	setForeground(Color.red);
        setBackground(Color.cyan);
   }
  
   public void paint (Graphics g) //to write on applet window
   {
        

	g.setFont(f1);
	
        g.drawString ("Hello World", 25, 50);

	g.setFont(new Font("Forte",Font.PLAIN,24));

	g.drawString("Applet Programming",50,100);
   }
}
import java.util.*;
class Account
{
	int ac, bal;
	static int count;
	
	Account()//default constructor
	{
		bal=500;
		count++;
		ac=1000+count;
	}
	
	Account(int x)//parameterized constructor with 1 parameter
	{
		bal=x;
		count++;
		ac=1000+count;
	}
	
	void setAccNo(int x)
	{
		ac=x;
		
	}
	
	void withdraw(int x)
	{
		bal=bal-x;
	}
	
	void deposit(int x)
	{
		bal=bal+x;
	}
	
	void display()
	{
		System.out.println("Account number is "+ac);
		System.out.println("Current balance is"+bal);
	}
	
	void transfer(Account h, int amt)
	{
		this.bal=this.bal-amt;
		h.bal=h.bal+amt;
	}
}

public class AccountMain
{
	public static void main(String[]args)
	{
		Account a1=new Account(5000);
		Account a2=new Account();
		a1.transfer(a2,2000);
		a1.display();
		a2.display();
 
	}
}
/*OUTPUT
Account number is 1001
Current balance is3000
Account number is 1002
Current balance is2500
*/
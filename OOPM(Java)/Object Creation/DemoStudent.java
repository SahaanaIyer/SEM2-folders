import java.util.*;

class Student
{
    int rollno;
    double atten;
    String name;
    int marks;
    public Student(int rollno,double atten,String name,int marks)
    {
        this.rollno=rollno;
        this.atten=atten;
        this.name=name;
        this.marks=marks;
    }
    void Display()
    {
        System.out.println(name+"\t"+rollno+"\t"+atten+"\t\t"+marks);
    }
}
    
class DemoStudent
{
    public static void main(String [] args)
    {
        int rollno,n,i,marks;
        double atten;
        String name;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of students :");
        n=sc.nextInt();
        Student []s=new Student[n];
        for(i=0;i<s.length;i++)
        {
            System.out.println("Enter the Roll no of Student "+ (i+1) );
            rollno=sc.nextInt();
            System.out.println("Enter the Name of Student "+(i+1));
            name=sc.next();
            System.out.println("Enter the Attendance of Student "+(i+1));
            atten=sc.nextInt(); 
            System.out.println("Enter the average marks of "+(i+1)+"Student in percentage");
            marks=sc.nextInt();
            s[i]=new Student(rollno,atten,name,marks);  
        }
        System.out.println("The List of Students are :");
        System.out.println("Name\tRoll No\tAttendance\tMarks");
        for(i=0;i<s.length;i++)
        {
            s[i].Display();
        }
        System.out.println("The Defaulters List is :");
        System.out.println("Name\tRoll No\tAttendance\tMarks");
        for(i=0;i<s.length;i++)
        {
            if((s[i].atten<75) && s[i].marks<75)
            {
                s[i].Display();
            }
            
        }

        
     }
}
/*OUTPUT
Enter the number of students :
3
Enter the Roll no of Student 1
1
Enter the Name of Student 1
ram
Enter the Attendance of Student 1
56
Enter the average marks of 1Student in percentage
78
Enter the Roll no of Student 2
2
Enter the Name of Student 2
dina
Enter the Attendance of Student 2
76
Enter the average marks of 2Student in percentage
32
Enter the Roll no of Student 3
3
Enter the Name of Student 3
rose
Enter the Attendance of Student 3
98
Enter the average marks of 3Student in percentage
78
The List of Students are :
Name	Roll No	Attendance	Marks
ram	1	56.0		78
dina	2	76.0		32
rose	3	98.0		78
The Defaulters List is :
Name	Roll No	Attendance	Marks
*/
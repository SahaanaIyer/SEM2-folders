import java.util.*;

class MyStack {
    int[] a;
    int top;

    MyStack() {
        a = new int[5];
        top = -1;
    }

    MyStack(int n) {
        a = new int[n];
        top = -1;
    }

    void push(int ele) {
        if (top == a.length - 1) {
            System.out.println("stack is full");
        } else
            a[++top] = ele;
    }

    int pop() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return -1;
        } else
            return a[top--];
    }

    boolean isEmpty() {
        return top == -1;
    }

    int peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty");
            return -1;
        } else
            return a[top];
    }

    void display() {
        if(top==-1)
        {
            System.out.println("Stack is empty");
        }
        else
        {
            System.out.println("The elements of the stack are: ");
            for (int i = top; i >= 0; i--) {
                System.out.println(a[i]);
            }
        }
    }
}

class MyStackDemo {
    public static void main(String args[])  {
        Scanner br = new Scanner(System.in);
        MyStack s = new MyStack();
        System.out.println("1.PUSH,2.POP,3.isEmpty,4.Peek,5.Display,6.Exit\n");
        while (true) {
            System.out.println("Enter the choice");
            int n = br.nextInt();
            switch (n) {
            case 1:
                System.out.println("enter the element to be inserted");
                int b = br.nextInt();
                s.push(b);
                break;
            case 2:
                int a = s.pop();
                System.out.println("Popped element is :" + a);
                break;
            case 3:
                boolean m=s.isEmpty();
                if (m==true)
                    System.out.println("1");
                else
                    System.out.println("0");
                break;
            case 4:
                int x = s.peek();
                if (x != -1)
                    System.out.println("The element on the top of the stack is " + x);
                break;
            case 5:
                s.display();
                break;
            case 6:
                System.exit(0);
            }
        }
    }
}
/*OUTPUT
1.PUSH,2.POP,3.isEmpty,4.Peek,5.Display,6.Exit

Enter the choice
1
enter the element to be inserted
10
Enter the choice
1
enter the element to be inserted
20
Enter the choice
3
0
Enter the choice
4
The element on the top of the stack is 20
Enter the choice
1
enter the element to be inserted
30
Enter the choice
2
Popped element is :30
Enter the choice
1
enter the element to be inserted
50
Enter the choice
5
The elements of the stack are:
50
20
10
Enter the choice
6
*/


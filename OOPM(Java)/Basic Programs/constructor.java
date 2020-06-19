import java.util.*;
import java.lang.*;

class constructor
{
    int a;
    float f;
    double d;
    String s;

    constructor()                //default constructor
    {
        a=10;
        f=20.05f;
        d=30.0;
        s="abcd\0";
    }

    constructor(int x)                                  //parametrized constructor passing 1 parameter
    {
        a=x;
        f=x;
        d=x;
    }

    constructor(int x, float y, double z, String w)             //parametrized constructor with 4 parameters
    {
        a=x;
        f=y;
        d=z;
        s=w;
    }


    public static void main(String[]args)
    { 
        constructor obj1 = new constructor();
        constructor obj2 = new constructor();
        System.out.println(obj1.a);
        System.out.println(obj1.f);
        System.out.println(obj1.d);
        System.out.println(obj1.s);
    }
}

/*OUTPUT :
10
20.05
30.0
abcd
*/
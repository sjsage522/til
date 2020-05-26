# Implement Runnable vs Extend Thread

- By extending Thread class
- By implementing Runnable interface

****

In the first approach, Our class always extends Thread class. There is no chance of extending any other class.

In the second approach, while implementing Runnable interface we can extends any other class.

****

*Extending Thread class*

```java
// Java program to illustrate defining Thread 
// by extending Thread class 
  
// Here we cant extends any other class 
class Test extends Thread  
{ 
    public void run() 
    { 
        System.out.println("Run method executed by child Thread"); 
    } 
    public static void main(String[] args) 
    { 
        Test t = new Test(); 
        t.start(); 
        System.out.println("Main method executed by main thread"); 
    } 
}
```

*<b>output</b>*

> ```
> Main method executed by main thread
> Run method executed by child Thread
> ```

<br/>

*Implementing Runnable interface*

```java
// Java program to illustrate defining Thread 
// by implements Runnable interface 
class Geeks { 
    public static void m1() 
    { 
        System.out.println("Hello Visitors"); 
    } 
} 
  
// Here we can extends any other class 
class Test extends Geeks implements Runnable { 
    public void run() 
    { 
        System.out.println("Run method executed by child Thread"); 
    } 
    public static void main(String[] args) 
    { 
        Test t = new Test(); 
        t.m1(); 
        Thread t1 = new Thread(t); 
        t1.start(); 
        System.out.println("Main method executed by main thread"); 
    } 
} 
```

*<b>output</b>*

> ```
> Hello Visitors
> Main method executed by main thread
> Run method executed by child Thread
> ```

****

*reference* : https://www.geeksforgeeks.org/implement-runnable-vs-extend-thread-in-java/
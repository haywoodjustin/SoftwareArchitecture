
/* This is a simple Java program.
   FileName : "HelloWorld.java". */
import java.io.*;

public class CallFakeJavaAutomation
{
    // Your program begins with a call to main().
    // Prints "Hello, World" to the terminal window.
    public static void main(String args[])
    {
        System.out.println("Hello, World from CallFakeJavaAutomation");

        FakeAutomationJava fakeClass = new FakeAutomationJava();

        String ans = fakeClass.DoSomeStuff(42, "What a great number");

        System.out.println("We got ans " + ans);



        
    }
}
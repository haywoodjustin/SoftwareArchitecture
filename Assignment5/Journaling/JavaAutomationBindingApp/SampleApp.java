
/* This is a simple Java program.
   FileName : "HelloWorld.java". */
import java.io.*;
import automationapi.*;

public class SampleApp
{
    // Your program begins with a call to main().
    // Prints "Hello, World" to the terminal window.
    public static void main(String args[])
    {
        System.out.println("Hello, World from CallFakeJavaAutomation");

        Session theSession = Session.getSession();

        Part thePart = theSession.makePart("SomePart.prt");

        thePart.save();

    }
}
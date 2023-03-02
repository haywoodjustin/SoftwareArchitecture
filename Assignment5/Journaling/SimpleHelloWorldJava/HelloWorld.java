
/* This is a simple Java program.
   FileName : "HelloWorld.java". */
import java.io.*;

public class HelloWorld
{
    // Your program begins with a call to main().
    // Prints "Hello, World" to the terminal window.
    public static void main(String args[])
    {
        System.out.println("Hello, World from Java");
        if(args.length == 0)
        {
            System.out.println("Java input string not present" );
            System.err.println("Err Java input string not present" );
        }
        else
        {
            System.out.println("Java input string " + args[0]);
            System.err.println("Err Java input string " + args[0]);
        }

        try
        {
            String filename= "MyFile.txt";
            FileWriter fw = new FileWriter("LogFile.txt",true); //the true will append the new data
            fw.write(args[0] +"\n");//appends the string to the file
            fw.close();
        }
        catch(Exception ioe)
        {
            System.err.println("IOException: " + ioe.getMessage());
        }

        
    }
}
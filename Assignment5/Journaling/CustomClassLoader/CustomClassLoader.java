
import java.nio.file.*;
import java.net.*;
import java.lang.*;
import java.lang.reflect.*;

/* This is a simple Java program.
   FileName : "HelloWorld.java". */
class CustomClassLoader
{
    // Your program begins with a call to main().
    // Prints "Hello, World" to the terminal window.
    public static void main(String args[]) throws Exception
    {
        System.out.println("Hello, CustomClassLoader");
        if(args.length == 0)
        {
            System.out.println("Java input string not present" );
            return;
        }
        else
        {
            System.out.println("Going to run class file " + args[0]);
        }

        

        Path path = Paths.get(args[0]);

        Path fileName = path.getFileName();
        String fileNameString = fileName.toString();


        System.out.println("Going to run class file full path " + fileName);
        System.out.println("Going to run class file " + fileNameString);
        int pos = fileNameString.indexOf(".");
        String className = fileNameString.substring(0, pos);
        System.out.println("Going to run class Name " + className);
        String dirPath = args[0].substring(0, args[0].indexOf(fileNameString) -1);
        String urlString = "file:///"+ dirPath +"/";
        System.out.println("ClassPath to use " + urlString);

        URLClassLoader child = new URLClassLoader (
                new URL[] {new URL(urlString)}, null);

        Class<?> clazz = Class.forName(className, true, child);

        String [] argsIn = new String[1];
        argsIn[0] = "Calling from ClassLoader";


        Method mainEntryPoint = clazz.getMethod("main", String[].class);
        if(mainEntryPoint == null)
        {
            throw new Exception("can't fine main method");
        }

        mainEntryPoint.invoke(null, new Object[]{argsIn});
        
    }
}


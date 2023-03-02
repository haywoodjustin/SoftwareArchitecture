public class FakeAutomationJava
{

    static {
        System.out.println("Loading native library");
        System.loadLibrary("jniAutomationLibrary");
    }

    FakeAutomationJava()
    {

    }

    native String DoSomeStuff(int p1, String p2);



}
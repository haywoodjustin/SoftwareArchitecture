

package automationapi;
import automationapi.Part;

public class Session
{

    private static Session instance;

    
    private Session()
    {
        initSession();
    }
    
    public static Session getSession(){
        if(instance == null){
            instance = new Session();
        }
        return instance;
    }

    static {
        System.out.println("Loading native library");
        System.loadLibrary("JavaAutomationBinding");
    }

    private native void initSession();

	public native Part makePart(String partFilePath);

}
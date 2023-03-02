package automationapi;


public class Part
{
    
    private Part(int guid)
    {
        m_guid = guid;
    }
    
    public native void save();

    private int m_guid;

}
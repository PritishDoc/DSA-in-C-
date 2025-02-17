public class Test {
    static{
        System.out.println("BLOCK 1");
    }
    {
    System.out.println("nonstatic");
    }
    Test(){
        System.out.println("constructor call");
    }

    public static void main(String[] args) {
        System.out.println("from main");

        new Test();
        System.out.println("end");
        
       
    }
    
}

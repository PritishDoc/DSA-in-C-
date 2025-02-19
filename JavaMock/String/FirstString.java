package String;

public class FirstString {
    public static void main(String[] args) {
        
    
    String s1=new String("Java");
        System.out.println(s1);

        String s2="Java";
        System.out.println(s2);
        
        System.out.println(s1==s2);
        System.out.println(s1.equals(s2));
        String s3="JAVA";

        System.out.println(s1.equalsIgnoreCase(s3));
}
}

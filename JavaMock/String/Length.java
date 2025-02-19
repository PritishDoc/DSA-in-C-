package String;

public class Length {
    public static void main(String[] args) {
        String s1="Java";
        System.out.println(s1.length());
        System.out.println(s1.charAt(1));
       // System.out.println(s1.charAt(-1));

        for(int i=0;i<s1.length();i++){
            char c=s1.charAt(i);
            System.out.print(c);
        }
    }
    
}

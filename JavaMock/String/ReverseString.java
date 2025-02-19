package String;

public class ReverseString {
    public static void main(String[] args) {
        String s1="Pritish";

        for(int i=s1.length()-1;i>0;i--){
            char c=s1.charAt(i);
            System.out.print(c);
        }
    }
    
}

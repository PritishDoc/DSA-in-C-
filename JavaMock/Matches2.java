//package String;
import java.util.regex.*;
public class Matches2 {
    public static void main(String[] args) {
        Pattern p=Pattern.compile("ana");
        Matcher m=p.matcher("banana");
        int count=0;
        while(m.find()){
            count++;

        }
        System.out.println(count);
    }
}

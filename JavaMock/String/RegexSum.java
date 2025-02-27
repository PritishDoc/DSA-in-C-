import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class RegexSum {
    public static void main(String[] args) {
        String s1="a2,b4,c33j";
       // String regex="[0-9]";
        Pattern p=Pattern.compile("[0-9]");
        Matcher m=p.matcher(s1);

        int sum=0;
        while(m.find()){
            sum+=Integer.parseInt(m.group());
            
        }
        System.out.println(sum);
    }
    
}

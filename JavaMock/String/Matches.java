package String;
import java.util.*;
public class Matches {
    public static void main(String[] args) {
        System.out.println("Enter 3 digit num: ");
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        Partten p=Partten.compile("[0-9],{3}");
        if(p.Matches()){
            System.out.println("valid");
        }
        else{
            System.out.println("Invalid");
        }
    }
    
}

import java.util.*;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

    double a,b,c,s,area;
    System.out.println("Enter the 3 side of a tringle: ");
    a=sc.nextDouble();
    b=sc.nextDouble();
    c=sc.nextDouble();
    
    s=(a+b+c)/2f;
    area=Math.sqrt(s*(s-a)*(s-b)*(s-c));
    
    System.out.println(area);
    
        sc.close(); // Close scanner to prevent memory leaks
    }
}
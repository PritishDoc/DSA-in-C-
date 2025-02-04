import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

    float base,area,height;
    System.out.println("Enter the base of a Triengle: ");
    base=sc.nextFloat();
    height=sc.nextFloat();
    
    area=(base*height)/2;
    System.out.println("Area of the triengle is : "+area);
        sc.close(); // Close scanner to prevent memory leaks
    }
}
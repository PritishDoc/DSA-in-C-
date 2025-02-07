import java.util.Arrays;

class Rectangle{
    private double length;
    private double breadth;
    
    public double getLength(){
        return length;
    }
    public double getbreadth(){
        return breadth;
    }
    public void setLength(double l){
        length=l;
    }
    public void setbreadth(double b){
        breadth=b;
    }
    public double area(){
        return length*breadth;
    }
    public double perimetr(){
        return 2*(length+breadth);
        
    }
    public boolean isSqure(){
        if(length==breadth)return true;
        else return false;
    }
}
public class Main {
    public static void main(String[] args) {
    
    
    Rectangle r=new Rectangle();
   // r.length=1;
   // r.breadth=3;
   r.setbreadth(5);
   r.setLength(3);
   
   System.out.println(r.getbreadth());
   System.out.println(r.getLength());
   System.out.println(r.area());
}
}

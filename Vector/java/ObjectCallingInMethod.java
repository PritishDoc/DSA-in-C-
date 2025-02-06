

public class Main {
    int max(int x,int y){
       if(x>y)
       return x;
       else return y;
   }
   static void inc(int x){
       x++;
       System.out.println(x);
   }
   public static void main(String[] args) {
       
       int a=9;
       int b=5;
       
       Main m=new Main();
       inc(a);
     System.out.println(m.max(a,b));
    // System.out.println(inc(a));
   }
}

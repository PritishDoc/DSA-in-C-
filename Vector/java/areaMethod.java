//import java.Math;
public class Main
{
	public static void main(String[] args) {
		System.out.println("Hello World");
	//	int x=9;f
	//	if(isPrime(x));
	//int arr[]={1,8,9,4,5,33,3,5};
	//	System.out.println(MaxelementArray(arr));
	
	System.out.println("Area of the rectangle is : "+(area(2.9,9.7)));
	System.out.println("Area of circle is : "+(area(4.8)));
	}
	
	
  static double area(double l,double b){
      return l*b;
  }
  static double area(double r){
      return Math.PI*r*r;
  }
}

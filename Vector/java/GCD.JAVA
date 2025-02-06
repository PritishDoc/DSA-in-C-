
public class Main
{
	public static void main(String[] args) {
		System.out.println("Hello World");
	//	int x=9;f
	//	if(isPrime(x));
		System.out.println(gcd(23,10));
	}
	
	
	static int gcd(int m,int n){
	    while(m!=n){
	        if(m>n)m=m-n;
	        else n=n-m;
	    }
	    return m;
	}
}

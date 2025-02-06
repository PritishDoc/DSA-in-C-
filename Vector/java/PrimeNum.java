
public class Main
{
	public static void main(String[] args) {
		System.out.println("Hello World");
		int x=9;
	//	if(isPrime(x));
		System.out.println(isPrime(x));
	}
	
	static boolean isPrime(int n){
	    for(int i=2;i<n/2;i++){
	        if(n%2==0)
	            return false;
	        
	        
	    }
	    return true;
	}
}


public class Main
{
	public static void main(String[] args) {
		System.out.println("Hello World");
	//	int x=9;f
	//	if(isPrime(x));
	int arr[]={1,8,9,4,5,33,3,5};
		System.out.println(MaxelementArray(arr));
	}
	
	
    static int MaxelementArray(int arr[]){
        int max=arr[0];
        for(int i=0;i<arr.length;i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
}

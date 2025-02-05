
public class Main
{
	public static void main(String[] args) {
		int arr[]={2,4,55,3,66,89};
		for(int x:arr)
		    System.out.print(x+",");
		System.out.println("");
	
		
		int temp=arr[arr.length-1];
		for(int i=arr.length-1;i>0;i--){
		    arr[i]=arr[i-1];
		}
		arr[0]=temp;
		for(int x:arr)
		    System.out.print(x+",");
		System.out.println("");
	}
}

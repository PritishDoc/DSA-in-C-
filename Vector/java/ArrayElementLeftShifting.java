public class Main
{
	public static void main(String[] args) {
		int arr[]={2,4,55,3,66,89};
		for(int x:arr)
		    System.out.print(x+",");
		System.out.println("");
		
		int temp=arr[0];
		for(int i=1;i<arr.length;i++){
		    arr[i-1]=arr[i];
		}
		arr[arr.length-1]=temp;
		for(int x:arr)
		    System.out.print(x+",");
		System.out.println("");
	}
}
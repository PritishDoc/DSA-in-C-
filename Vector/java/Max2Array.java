public class Main
{
	public static void main(String[] args) {
		int arr[]={2,4,55,3,66,89};
		int sum=0;
		int key=3;
		int max2,max1;
		max1=max2=arr[0];
		for(int i=0;i<arr.length;i++){
		    if(arr[i]>max1){
		        max2=max1;
		        max1=arr[i];
		        
		    }
		    else if(arr[i]>max2){
		        max2=arr[i];
		    }
		}
		System.out.println("THE Max ELEMENT INDEX IS : "+max2);
		        System.exit(0);
		
	}
}

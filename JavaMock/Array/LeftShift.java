package Array;

public class LeftShift {
    public static void main(String[] args) {
        
    
    int arr[]={1,3,4,5,6};

    int temp=arr[0];
    for(int i=1;i<arr.length;i++){
        arr[i-1]=arr[i];
    }
    arr[arr.length-1]=temp;

    for(int x:arr){
        System.out.print(x+" ");
    }
}
}
package Array;

public class Rightshift {
    public static void main(String[] args) {
        int arr[]={3,2,4,1,7};
        

        int temp=arr[arr.length-1];
        for(int i=arr.length-1;i>0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
        for(int x:arr){
            System.out.print(x+" ");
        }
    }
}

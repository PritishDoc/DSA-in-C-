package Array;

public class ReverseCopyOfArray {
    public static void main(String[] args) {
        int arr[]={1,2,3,4,5};
        int arr2[]=new int[5];

        for(int i=arr.length-1, j=0;i>=0;i--,j++){
            arr2[j]=arr[i];
        }
        for(int x:arr2){
            System.out.print(x+" ");
        }
    }
}

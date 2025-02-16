package Array;

public class CopyOfAnArray {
    public static void main(String[] args) {
        int arr[]={1,2,4,5,6};

        int arr2[]=new int[5];
        for(int i=0;i<arr.length;i++){
            arr2[i]=arr[i];
        }
        for(int x:arr2){
            System.out.print(x+" ");
        }
    }
    
}

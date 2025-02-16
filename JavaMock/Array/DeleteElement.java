package Array;

public class DeleteElement {
    public static void main(String[] args) {
        int arr[]={1,2,3,4,5};
        int x=18;
        int index=4;
        int n=4;
        for(int i=n;i>index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=x;
        for(int y:arr){
            System.out.print(y+" ");
        }
    }
}

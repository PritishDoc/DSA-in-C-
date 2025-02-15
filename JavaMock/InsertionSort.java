public class InsertionSort {
    static void in(int arr[]){
        for(int i=1;i<arr.length;i++){
            int cur=arr[i];
            int prev=i-1;
            while(prev>=0 && arr[prev]>cur){
                arr[prev+1]=arr[prev];
                prev--;   
            }
            arr[prev+1]=cur;
        }
    }
    static void Print(int arr[]){
        for(int x:arr){
            System.out.print(x);
        }
    }
    public static void main(String[] args) {
        int arr[]={3,1,5,9,8,4};

        in(arr);
        Print(arr);
    }
}

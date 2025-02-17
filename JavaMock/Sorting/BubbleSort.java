public class BubbleSort{
    static void  Bubblesort(int arr[]){
        
        for(int i=0;i<arr.length-1;i++){
            boolean isswap=false;
            for(int j=0;j<arr.length-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
            if(!isswap){
                return;
            }
        }
    }
    static void Print(int arr[]){
        for(int x:arr){
            System.out.print(x);
        }
    }
public static void main(String[] args) {
    int arr[]={2,5,9,3,1};

    Bubblesort(arr);
    Print(arr);
}
};;
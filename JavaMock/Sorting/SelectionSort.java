public class SelectionSort {
    static void sort(int arr[]){
        for(int i=0;i<arr.length-1;i++){
            int si=i;
            for(int j=i+1;j<arr.length;j++){
                if(arr[j]<arr[si]){
                    si=j;
                }
            }
                int temp = arr[si];
            arr[si] = arr[i];
            arr[i] = temp;
            
        }
    }
    
    static void print(int arr[]){
        for(int x:arr){
            System.out.print(x);
        }
    }
    public static void main(String[] args) {
        int arr[]={1,4,2,9,3};
        sort(arr);
        print(arr);
    }
}

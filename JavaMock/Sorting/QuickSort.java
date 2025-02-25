public class QuickSort {
    static int partion(int arr[],int low,int high){
        int pivot=arr[high];
        int i=low-1;
        for(int j=low;j<high;j++){
            if(arr[j]<pivot){
                i++;
                int temp=arr[i];
                     arr[i]=arr[j];
                     arr[j]=temp;
            }
        }
        //ADJUSTING PIVOT 
            
            int temp=arr[i+1];
            arr[i+1]=pivot;
            arr[high]=temp;
            
        
        return i+1;
    }
    static void print(int arr[]){
        for(int x:arr){
            System.out.print(x);
        }
    }
    static void qs(int arr[],int low,int high){
        if(low<high){
        int pivot=partion(arr,low,high);
        qs(arr,low,pivot-1);
        qs(arr,pivot+1,high);

    }
    }
    public static void main(String[] args) {
     
        
        int arr[]={2,5,3,9,1};
        int n=arr.length;

        qs(arr, 0, n-1);
        print(arr);

    }
}

package Array;

public class DeleteAnElement {
    public static void main(String[] args) {
        int arr[]={1,3,4,5,6};
        int index=-1;
        int delete=4;
        int n=arr.length-1;
        for(int i=0;i<n;i++){
            if(arr[i]==delete){
                index=i;
                break;

            }}
            if(index!=-1){
                for(int i=index;i<n;i++){
                    arr[i]=arr[i+1];


                
            }
            arr[arr.length-1]=0;
        }
        for(int x:arr){
            System.out.print(x+" ");
        }
    }
    
}

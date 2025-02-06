public class Main {
    public static void main(String[] args) {
        int a[] = new int[10]; // Array with extra space for insertion

       int arr[] = {2, 4, 3, 5, 6, 3, 33, 66};
       int n=arr.length;
       int deleteElement=6;
       int index=-1;
       
       for(int i=0;i<n-1;i++){
       if(arr[i]==deleteElement){
           index=i;
           break;
       }
       }
       
       if(index!=-1){
           for(int i=index;i<n-1;i++){
               arr[i]=arr[i+1];
           }
           n--;
        //    arr[n] = 0; 
       }
       else{
           System.out.println("Element is not found ");
       }
       System.out.println("new array is : ");
       for(int x:arr){
           System.out.print(x+",");
       }
    }
}

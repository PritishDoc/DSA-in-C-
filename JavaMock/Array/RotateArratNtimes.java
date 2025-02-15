package Array;

public class RotateArratNtimes {
    public static void main(String[] args) {
        int arr[]={1,2,3,4,5,6};
            int n=3;
            for(int i=0;i<n;i++){
                for(int j=0;j<arr.length-1;j++){
                    int st=0,end=arr.length-1;
                    if(st<end){
                        int temp=arr[st];
                         arr[st]=arr[end];
                         arr[end]=temp;
                         st++;
                         end--;
                    }
                }
            }
            for(int x:arr){
                System.out.print(x+" ");
            }

        }
    }
    


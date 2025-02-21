package String;

public class reverseinArray {
    public static void main(String[] args) {
        String str="Java is an language";
        String arr[]=str.split(" ");
        for(int i=arr.length-1;i>=0;i--){
            System.out.print(arr[i]+" ");
        }
    }
}

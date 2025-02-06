

public class Main {
    public static void main(String[] args) {
        int a[] = new int[10]; // Array with extra space for insertion

        int b[]={12,21,34,54,6,7};
        
        for(int i=0;i<b.length;i++){
            a[i]=b[i];
        }
        for(int x:a)
        System.out.print(x+",");
    }
}

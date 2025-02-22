public class LL1{
    Node head;
    class Node{
        String data;
        Node next;

        Node(String data){
            this.data=data;
            this.next=null;
        }
    }
    //add - First,Last
    public void addFirst(String data){
       Node newNode=new Node(data);
        if(head==null){
            head=newNode;
            return;
        }
        newNode.next=head;
        head=newNode;
    }
    //addLast
    public void addLast(String data){
        Node newNode=new Node(data);
        if(head==null){
            head=newNode;
            return;
        }
        Node currNode= head;
        while(currNode.next!=null){
            currNode=currNode.next;
        }
        currNode.next=newNode;
    }
    public void PrintList(){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        Node currNode =head;
        while(currNode!=null){
            System.out.print(currNode.data+"->");
            currNode=currNode.next;
        }
        System.out.print("null");
    }
    public static void main(String[] args) {
        LL1 list=new LL1();
        list.addFirst("A");
        list.addFirst("B");
        list.addLast("c");
        list.PrintList();


    }
    
}
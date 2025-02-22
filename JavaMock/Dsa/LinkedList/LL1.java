public class LL1{
    Node head;
    private int size;
    LL1(){
        this.size=0;
    }
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
        size++;
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
        size++;
    }

    //Delete First
    public void DeleteFirst(){
        if(head==null){
            System.out.println("This list is empty");
            return;
        }
        size--;
        head=head.next;

    }
    //delete last
    public void deleteLast(){
        if(head==null){
            System.out.println("This list is empty");
            return;
        }
        Node secondLast=head;
        Node lastNode=head.next;//if its null then last node must be null 
        size--;
        if(head.next==null){
            head=null;
            return;
        }
        while(lastNode.next!=null){//null.next  null then throw error
            lastNode=lastNode.next;
            secondLast=secondLast.next;
        }
        
        secondLast.next=null;
    }

    public int getsize(){
        return size;
    }
    public void PrintList(){
        if(head==null){
            System.out.println("List is empty");
            return;
        }
        Node currNode =head;
        while(currNode!=null){
            System.out.println(currNode.data+"->");
            currNode=currNode.next;
        }
        System.out.print("null");
    }
    public static void main(String[] args) {
        LL1 list=new LL1();
        list.addFirst("A");
        list.addFirst("B");
        list.addLast("c");
        System.out.println(list.getsize());
        list.PrintList();

        list.DeleteFirst();
        list.PrintList();

        list.DeleteFirst();
        list.PrintList();
        
  


    }
    
}
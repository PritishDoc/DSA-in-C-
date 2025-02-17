class A {
    void show() {
        System.out.println("A's show method");
    }
}

class B extends A {
    void show() {  
        System.out.println("B's show method");
    }

    void display() {  
        System.out.println("B's display method");
    }
}

public class A2 {
    public static void main(String[] args) {
        A obj1 = new B();
        obj1.show();  
      //  obj1.display();
    }
}

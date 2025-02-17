class A {
    void show() {
        System.out.println("Pritish");
    }
}

class B extends A {
    @Override
    void show() {
        super.show();
        System.out.println("Ray"); 
    }
}

public class Main {
    public static void main(String[] args) {
        B obj = new B(); 
        obj.show(); 
    }
}

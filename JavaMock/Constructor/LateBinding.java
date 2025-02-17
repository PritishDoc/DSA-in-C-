class Parent {
    void show() {
        System.out.println("Parent class method");
    }
}

class Child extends Parent {
    @Override
    void show() {
        System.out.println("Child class method");
    }
}

public class LateBinding {
    public static void main(String[] args) {
        Parent obj = new Child();  // Upcasting
        obj.show();  // Calls Child's show() method (late binding)
    }
}

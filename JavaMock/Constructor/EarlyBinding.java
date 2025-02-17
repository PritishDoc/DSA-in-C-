class Parent {
    static void show() {
        System.out.println("Parent class static method");
    }
}

class Child extends Parent {
    static void show() {
        System.out.println("Child class static method");
    }
}

public class EarlyBinding {
    public static void main(String[] args) {
        Parent obj = new Child();  // Upcasting
        obj.show();  // Calls Parent's show() method (early binding)
    }
}

public class Example {
    static {
        System.out.println("Static block");
    }

    {
        System.out.println("Instance initializer block");
    }

    public Example() {
        System.out.println("Constructor");
    }

    public static void main(String[] args) {
        System.out.println("Main method");
        new Example();
        new Example();
    }
}

Static block
Main method
Instance initializer block
Constructor
Instance initializer block
Constructor


----------

jdk->jre+compiler(create class file)->jvm(run class file)+libraries


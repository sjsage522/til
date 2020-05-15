# The try-with-resource Statement

The `try`-with-resources statement is a `try` statement that declares one or more resources. A *resource* is an object that must be closed after the program is finished with it. 

The `try`-with-resources statement ensures that each resource is closed at the end of the statement. Any object that implements `java.lang.AutoCloseable`, which includes all objects which implement `java.io.Closeable`, can be used as a resource.

*The following example*

> If my class wants to release resources with try-with-resources, I need to implement AutoCloseable.

```java
public static void main(String[] args) {
    try(AutoCloseable customResource = new AutoCloseable() {
        @Override
        public void close() throws Exception {
            System.out.println("customResource.close() is called");
        }
    };) {
        System.out.println(customResource.hashCode());
    } catch (Exception e) { e.printStackTrace(); }
}
```

If you pass a resource object to the try statement, <b>the resource is automatically terminated</b> (*close method of resource is called*) <b>when the try code ends even if the finally statement does not finish processing.</b>

<hr />

*reference* : <a href="https://codechacha.com/ko/java-try-with-resources/">codechacha.com</a>, <a href="https://docs.oracle.com/javase/tutorial/essential/exceptions/tryResourceClose.html">oracleJavaDoc</a>

*moreInfo* : <a href="https://docs.oracle.com/javase/tutorial/essential/exceptions/tryResourceClose.html">The try-with-resource Statement</a>

 


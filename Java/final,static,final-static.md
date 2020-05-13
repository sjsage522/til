# final, static, final static

> Why final variable is static ?

## final keyword

- <b>final variable</b>
  - This means that the variable can be initialized only once through the constructor or assignment operator.
- <b>final method</b>
  - The method cannot be overridden or hidden.
- <b>final class</b>
  - The class cannot be inherited.
  - `java.lang.System`, `java.lang.String` etc...

### final variable is not necessarily a constant

```java
public class Test {
  private final int value;

  public Test(int value) {
    this.value = value;
  }

  public int getValue() {
    return value;
  }
}
```

Instances of this class have different values. It won't change within each instance, but it's not a constant that is commonly used at the class level.

<br />

## static keyword

- <b>static variable</b>

  - Also called class variable.
  - This is shared between objects of the same class.
  - It can be used without creating an instance.

- <b>static method</b>

  - Also called class method.
  - It cannot be overridden.

- <b>static block</b>

  - An initialization block that can be created inside a class.
  - It is executed when the class is initialized, and is performed before `main ()`.

- <b>static class</b>

  - It is a error when applied to normal classes, that is, top-level classes.

    > ```
    > However, this does not mean that the top-level class is not static.
    > ```

  - Can only be used with `nested classes`.
    - `static nested class` : nested class defined as static
    - `inner class` : non-static nested class

<br />

## static final

Constants that must be initialized at the same time as declaration
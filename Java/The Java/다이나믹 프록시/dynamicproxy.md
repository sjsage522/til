# 다이나믹 프록시

## 런타임에 특정 인터페이스들을 구현하는 클래스 또는 인스턴스를 만드는 기술

- https://docs.oracle.com/javase/8/docs/technotes/guides/reflection/proxy.html

**프록시 인스턴스 만들기**

- Object Proxy.newProxyInstance(ClassLoader, interfaces, InvocationHandler)

```java
BookService bookService = (BookService) Proxy.newProxyInstance(BookService.class.getClassLoader(), new Class[]{BookService.class},
        new InvocationHandler() {
            BookService bookService = new DefaultBookService();
            @Override
            public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
                if (method.getName().equals("rent")) {
                    System.out.println("aaaa");
                    Object invoke = method.invoke(bookService, args);
                    System.out.println("bbbb");
                    return invoke;
                }

                return method.invoke(bookService, args);
            }
        });
```

- 유연한 구조가 아니다.
  - 제약사항 : DefaultBookService를 받을 수 없음. 자바의 다이나믹 프록시는 클래스 기반의 프록시를 만들 수 없음 두번 째 인자로 받는 클래스는 반드시 인터페이스 이여야 한다. (new Class[] {BookService.class})
  - 여러가지 부가기능이 필요할 때 프록시로 한번더 감싸야 하거나, 코드가 길어질 수 있음
- 그래서 스프링 AOP 등장.

***

![img](https://lh4.googleusercontent.com/4Cntz3hXOuCxnG3T8do5jxgk4NZsd4EOmFlw-XZmtj7syEp6g9qQU1-hku-ePU_Nf2J6EnGbAwXvz-l5wlXLdj7uLvQ_C9fJZF6PRg7n6hJEUJGTl61Y9Ld5aIi-Ch9i29JXf1mt)

> BookService.java (서브젝트)
>
> DefaultBookService.java (리얼 서브젝트)

- DefaultBookService에 정의된 메소드 네임이 rent 일 때 추가적인 기능
- 그 외에는 단순 호출

***

**참고**

- https://docs.oracle.com/javase/8/docs/technotes/guides/reflection/proxy.html
- https://docs.oracle.com/javase/8/docs/api/java/lang/reflect/Proxy.html#newProxyInstance-java.lang.ClassLoader-java.lang.Class:A-java.lang.reflect.InvocationHandler-


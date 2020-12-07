# 프록시 패턴

![img](https://lh4.googleusercontent.com/4Cntz3hXOuCxnG3T8do5jxgk4NZsd4EOmFlw-XZmtj7syEp6g9qQU1-hku-ePU_Nf2J6EnGbAwXvz-l5wlXLdj7uLvQ_C9fJZF6PRg7n6hJEUJGTl61Y9Ld5aIi-Ch9i29JXf1mt)

- 프록시와 리얼 서브젝트가 공유하는 인터페이스 존재, 클라이언트는 해당 인터페이스 타입으로 프록시를 사용한다.
- 클라이언트는 프록시를 거쳐서 리얼 서브젝트를 사용하기 때문에 프록시는 리얼 서브젝트에 대한 접근을 관리하거나 부가기능을 제공하거나 리턴값을 변경할 수도 있다.
- 리얼 서브젝트는 자신이 해야 할 일만 하면서(SRP) 프록시를 사용해서 부가적인 기능(접근 제한, 로깅, 트랜잭션 등)을 제공할 때 이런 패턴을 주로 사용한다.

**참고**

- https://www.oodesign.com/proxy-pattern.html
- https://en.wikipedia.org/wiki/Proxy_pattern
- https://en.wikipedia.org/wiki/Single_responsibility_principle


# 스프링 데이터 JPA

**스프링 데이터 JPA에서 인터페이스 타입의 인스턴스는 누가 만들어 주는것인가?**

- Spring AOP를 기반으로 동작하며 RepositoryFactorySupport에서 프록시를 생성한다.


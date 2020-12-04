# 자바, JVM, JDK, 그리고 JRE

## 1. JVM

![img](https://lh5.googleusercontent.com/8QsqBhyHbJxEfFCTRdqu1j7AZ02StOpBpOUGQ0BQShr0fcFpYl78qpi3odqUr0qo9L00mEeVL-tPwyfvWcm4I3qP2LW1pvIvW-kWlh4r9wGPfMgIDw563YOo-tycyhfNCPag5zuC)

**JVM** (Java Virtual Machine)

- 자바 가상머신, 자바 바이트 코드(.class 파일)를 OS에 특화된 코드로 변환(인터프리터와 JIT 컴파일러)하여 실행
- 바이트 코드를 실행하는 표준(JVM 자체는 표준)이자 구현체이다.(특정 벤더가 구현한 JVM)
- JVM 스펙 
  - https://docs.oracle.com/javase/specs/jvms/se11/html/
- JVM 벤더 : 오라클, 아마존, Azul, ...
- 특정 플랫폼에 종속적

**JRE** (Java Runtime Environment) : JVM + 라이브러리

- 자바 애플리케이션을 실행할 수 있도록 구성된 배포판
- JVM과 핵심 라이브러리 및 자바 런타임 환경에서 사용하는 프로퍼티 세팅이나 리소스 파일을 가지고 있다.
- 개발 관련 도구는 포함하지 않는다. (JDK에서 제공)

**JDK** (Java Development Kit) : JRE + 개발 툴

- JRE + 개발에 필요한 툴
- 소스 코드를 작성할 때 사용하는 자바 언어는 플랫폼에 독립적
- 오라클은 자바 11부터 JDK만 제공하며 JRE는 따로 제공하지 않는다.
- Write Once Run Anywhere

**자바**

- 프로그래밍 언어
- JDK에 들어있는 자바 컴파일러(javac)를 사용하여 바이트코드(.class 파일)로 컴파일 할 수 있다.
- 자바 유료화?... 오라클에서 만든 Oracle JDK 11 버전부터 상용으로 사용할 때 유료
  - https://medium.com/@javachampions/java-is-still-free-c02aef8c9e04

**JVM** 언어

- JVM 기반으로 동작하는 프로그래밍 언어
  - 클로저, 그루비, JRuby, Python, Kotlin, Scala ... 

**참고**

- JIT 컴파일러
  - https://aboullaite.me/understanding-jit-compiler-just-in-time-compiler/
- JDK, JRE, JVM
  -  https://howtodoinjava.com/java/basics/jdk-jre-jvm/
  - https://en.wikipedia.org/wiki/List_of_JVM_languages
# 03. 배열(Array)

## 3.1 배열

### 배열의 개념

- 배열(array)은 거의 모든 프로그래밍 언어에서 기본적으로 제공되는 데이터 타입이다. 배열은 기본이 되는 중요한 자료형으로서 많은 자료 구조들이 배열을 사용하여 구현된다. 배열은 동일한 타입의 데이터를 한 번에 여러 개 만들 때 사용된다. 예를 들어서 6개의 정수를 저장할 공간이 필요한 경우, 배열이 없다면 다음과 같이 6개의 정수형의 변수를 선언하여야 할 것이다.

  ```c
  int list1, list2, list3, list4, list5, list6
  ```

- 그러나 배열이 지원된다면 아주 간단하게 다음과 같이 선언하면 된다.

  ```c
  int list[6];
  ```

- 대량의 데이터를 저장하기 위하여 여러 개의 개별 변수를 사용하는 것은 "인접한 요소를 교환 하라"와 같은 연산을 할 때, 매번 다른 이름으로 접근을 해야 하므로 많은 불편이 따를 수 있다. 하지만 배열을 사용하면 "연속적인 메모리 공간"이 할당되고 인덱스(index) 번호를 사용하여 쉽게 접근이 가능하기 때문에 반복 루프를 이용하여 여러가지 작업을 손쉽게 할 수 있다.

  <img src="./picture/array1.png">

### 배열 ADT

- 배열을 추상 자료형으로 정의하여 본다. 즉 배열을 단순히 "연속적인 메모리 공간"으로만 보지 말고 배열의 핵심적인 내용을 추상적으로 살펴본다. 배열은 <인덱스, 값>의 쌍으로 이루어진 집합으로 정의할 수 있다. 즉 인덱스(index)가 주어지면 해당하는 값(value)이 대응되는 자료 구조이다. 수학적으로 배열은 인덱스에 서 값으로서의 사상(mapping)에 해당된다. 배열에서는 어떤 연산을 생각할 수 있을까? 주어진 인덱스에 값을 저장하는 set연산(store 연산이라고도 한다)과 인덱스가 주어지면 해당되는 값을 추출하는 get 연산(retrieve 연산이라고도 한다)을 생각할 수 있다.

  - ADT_Array

    - 객체 : <인덱스, 값> 쌍의 집합

    - 연산 :

      - create(size) ::= size개의 요소를 저장할 수 있는 배열 생성

      - get(A, i) ::= 배열 A의 i번째 요소 반환

      - set(A, i, v) ::= 배열 A의 i번째 위치에 값 v 저장

        

  - C언어에서는 배열이 기본적으로 제공되기 때문에 위의 연산들을 구현할 필요는 없다. 그러나 만약 기본적으로 제공되지 않는다면 프로그래머가 구현하여야 할 것이다. get 함수는 배열과 인덱스를 받는다. 만약 그 인덱스가 유효하다면 인덱스 위치의 값을 반환한다. 만약 인덱스가 유효하지 않다면 오류를 반환한다. set 함수는 배열, 인덱스, 값을 받아서 새로운 인덱스 위치에 값을 저장한다.



### C언어에서의 1차원 배열

- C언어에서 6개의 정수를 저장할 수 있는 배열을 선언해보자. 배열은 변수 이름 끝에 []을 추가하여서 선언한다. []안의 숫자는 배열의 크기이다. 배열 ADT의 create 연산은 아래의 문장에 대응된다.

  ```C
  int list[6];	// create 연산에 해당된다.
  ```

- 배열 ADT의 set과 get 연산은 어떻게 구현될까? C언어에서 배열은 아주 많이 사용되기 때문에 전용 연산자가 존재한다. 즉 [] 연산자를 사용하여서 원하는 인덱스에서 값을 가져오거나 값을 저장할 수 있다.

  ```C
  list[0] = 100;  // set 연산에 해당된다.
  value = list[0];// get 연산에 해당된다.
  ```

- C에서 배열의 인덱스는 0부터 시작한다. 따라서 위와 같이 선언된 배열에서 배열의 요소는 list[0], list[1], list[2], list[3], list[4], list[5]가 된다.

  <img src="./picture/array2.png">

- 컴파일러는 배열을 어떻게 구현할까? 컴파일러는 배열에 메모리의 연속된 위치에 할당한다. 첫 번째 배열 요소인 list[0]의 주소가 기본주소가 되고 다른 요소들의 주소는 다음과 같이 된다.

  | 배열의 요소 |     메모리 주소      |
  | :---------: | :------------------: |
  |   list[0]   |    기본주소=base     |
  |   list[1]   | base + 1*sizeof(int) |
  |   list[2]   | base + 2*sizeof(int) |
  |   list[3]   | base + 3*sizeof(int) |
  |   list[4]   | base + 4*sizeof(int) |
  |   list[5]   | base + 5*sizeof(int) |

- 우리가 프로그램에서 list[i]라고 적으면 컴파일러는 주소 base+i*sizeof(int)에 있는 값을 가져온다.



### 2차원 배열

- 2차원 배열은 요소들이 2차원 형태로 나열된 배열이다. 2차원 배열에서 가로줄을 행(row), 세로 줄을 열(column)이라고 한다. C언어에서 2차원 배열은 다음과 같이 선언한다.

  ```C
  int list[3][5];
  ```

  <img src="./picture/array3.png">

- 위의 선언에서는 3개의 행과 5개의 열을 가지는 2차원 배열이 생성된다. C언어에서는 배열의 배열을 만들어서 2차원 배열을 구현한다. 크기가 3인 1차원 배열을 만들고 이 배열의 요소에 크기가 5인 배열을 생성하여 추가한다.

  <img src="./picture/array4.png">



## 3.2 구조체

### 구조체의 개념

- 복잡한 객체에는 다양한 타입의 데이터들이 한데 묶여져서 있다. 배열이 타입이 같은 데이터의 모임이라면 구조체(structure)는 타입이 다른 데이터를 묶는 방법이다. C언어에서는 struct 키워드를 이용하여 표기한다.

  <img src="./picture/array5.png">

- 구조체의 형식은 다음과 같이 정의한다.

  ```C
  struct 구조체이름 {
      항목1;
      항목2;
      ...
  };
  ```

- 구조체의 형식이 위와 같이 정의되었다면 구조체 변수는 다음과 같이 생성한다.

  ```C
  struct 구조체이름 구조체변수;
  ```

- 간단한 예로 학생을 나타내는 구조체를 만들어 보면 다음과 같다. 구조체에 저장되는 항목들은 다음과 같다.

  - 문자 배열로 된 이름
  - 나이를 나타내는 정수값
  - 평균평점을 나타내는 실수값

  ```C
  struct studentTag {
      char name[10];
      int age;
      double gpa;
  };
  ```

- struct 키워드 다음에 오는 studentTag는 구조체와 구조체를 구별할 수 있게 해주는 식별자로서 보통 구조체 태그(tag)라고 한다. 위의 문장은 구조체 형식만을 정의한 것이고 실제로 구조체가 만들어진 것은 아니다. 구조체를 만들려면 다음과 같이 하여야 한다.

  ```C
  struct studentTag s;
  ```

- 구조체 안에 들어 있는 맴버를 사용하려면 구조체 변수 뒤에 '.'을 첨가한 후 항목 이름을 적으면 된다. '.'을 맴버연산자(membership operator)라고 한다.

  ```C
  strcpy(s.name, "kim");
  s.age = 20;
  s.gpa = 4.3;
  ```

- C언어에서는 typedef을 사용하여 구조체를 새로운 타입으로 선언하는 것이 가능하다. 아래의 예에서 student은 새로운 데이터 타입의 이름이 된다.

  ```C
  typedef studentTag {
      char name[10];
      int age;
      double gpa;    
  } student;
  ```

- 이 경우에는 새로운 타입인 student만을 사용하여서 변수를 선언하는 것이 가능해진다. student는 C에서의 기본 데이터 타입인 int나 float와 마찬가지로 새로운 데이터 타입의 이름이 된다.

  ```c
  student s;
  ```

- 구조체는 중괄호를 사용하여 선언 시에 초기화 하는 것이 가능하다. 다음 문장을 참조하라.

  ```C
  student s = { "kim", 20, 4.3 };
  ```

- 구조체를 이용하여 간단한 프로그램을 작성하면 다음과 같다.

  ```C
  #include <stdio.h>
  
  typedef struct studentTag {
      char name[10];
      int age;
      double gpa;  
  } student;
  
  int main() {
      student a = { "kim", 20, 4.3 };
      student b = { "park", 21, 4.2 };
      return 0;
  }
  ```



## 3.3 배열의 응용 : 다항식

- 다항식을 나타내는 두 가지의 자료 구조를 생각할 수 있다.

### 첫 번째 방법

- 첫 번째 방법은 모든 차수의 계수값을 배열에 저장하는 것이다. 예를 들어 다항식 10x<sup>5</sup> + 6x + 3은 다음과 같이 다시 쓸 수도 있다.

  10x<sup>5</sup> + 0x<sup>4</sup> + 0x<sup>3</sup> + 0x<sup>2</sup> + 6x + 3

- 모든 차수에 대한 계수값들의 리스트인 ( 10, 0, 0, 0, 6, 3 )을 배열 coef에 저장하는 것이다. 위의 다항식의 경우에는 아래의 그림과 같이 된다. 여기서 다항식의 차수는 변수 degree에 저장된다.

  <img src="./picture/array6.png">

- 하나의 다항식이 하나의 degree 변수와 하나의 coef 배열을 필요로 하므로 이를 묶어서 구조체를 만들고 이 구조체를 사용하여 하나의 다항식을 표현할 수 있다. 일반적으로 계수는 실수일 수 있으므로 coef 배열은 실수 배열로 선언되었다. 아래 코드에서 구조체 변수 a는 10x<sup>5</sup> + 6x + 3을 표현하고 있다.

  ```C
  #define MAX_DEGREE 101 // 다항식의 최대차수 + 1
  typedef struct {
      int degree;
      float coef[MAX_DEGREE];
  } polynomial;
  
  polynomial a = { 5, {10, 0, 0, 0, 6, 3} };
  ```

  - 위의 방법은 간단하고 쉽게 이해가 가는 방법이다. 하지만 이 방법의 문제점은 대부분의 항의 계수가 0인 희소 다항식의 경우에는 공간의 낭비가 심하다는 것이다. 그러나 이방법의 최대 장점은 다항식의 덧셈이나 뺄셈 시에 같은 차수의 계수를 쉽게 찾을 수 있으므로 알고리즘이 간단해진다는 것이다.

  - 이 방법으로 표현된 2개의 다항식을 받아서 덧셈을 하는 프로그램을 아래의 프로그램에 보였다. 최고차하부터 배열에 차례대로 저장되어 있음을 유의해야 한다. 구조체 A, B의 coef배열을 스캔하면서 차수가 큰 항을 구조체 C로 이동하였다. 차수가 같으면 구조체 A, B의 coef 값을 더하여 C의 coef에 대입한다. 두개의 다항식 모두 차수가 최고차항에서 0까지 존재하므로 while 루프가 끝나면 모든 항들이 처리되는 것이 보장된다.

  - polynomial1.c

    ```C
    #include <stdio.h>
    #include <math.h>
    #define MAX(a,b) ( a > b ? a : b )
    #define MAX_DEGREE 101
    
    typedef struct {
        int degree;
        float coef[MAX_DEGREE];
    } polynomial;
    
    polynomial poly_add1(polynomial A, polynomial B){
        polynomial C;
        int Apos = 0, Bpos = 0, Cpos = 0;
        int A_degree = A.degree, B_dgree = B.degree;
        C.degree = MAX(A.degree, B.degree);
    
        while(Apos <= A_degree && Bpos <= B_dgree){
            if(A.degree > B.degree){
                C.coef[Cpos++] = A.coef[Apos++];
                A.degree--;
            }
    
            else if(A.degree == B.degree){
                if(A.coef[Apos] + B.coef[Bpos] == 0 && C.degree == A.degree){
                    Apos++; Bpos++;
                    C.degree--; A.degree--; B.degree--;
                }
                else{
                    C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
                    A.degree--; B.degree--;
                }
            }
    
            else{
                C.coef[Cpos++] = B.coef[Bpos++];
                B.degree--;
            }
        }
        return C;
    }
    
    void print_poly(polynomial P){
        for(int i=P.degree; i>0; i--){
            printf("%3.1fx^%d + ", P.coef[P.degree - i], i);
        }
        printf("%3.1f\n", P.coef[P.degree]);
    }
    
    float poly_eval(int x, polynomial P){
        float result = 0;
        for(int i=P.degree; i>=0; i--){
            result += ( P.coef[P.degree - i] * pow(x, i) ); 
        }
        return result;
    }
    
    int main(){
        polynomial A = {4, {-1, 4, 10, -3, 5}};
        polynomial B = {4, {1, 2, -2, 3, 4}};
        polynomial C;
    
        print_poly(A);
        print_poly(B);
        printf("-------------------------------------------------\n");
    
        C = poly_add1(A, B);
        print_poly(C);
    
        printf("eval : %3.1f\n", poly_eval(2, C));
    }
    ```



### 두 번째 방법

- 공간을 절약하기 위하여 다항식에서 0이 아닌 항만을 하나의 전역 배열에 저장하는 방법도 생각할 수 있다. 다항식의 0이 아닌 항들은 (계수, 차수)의 형식으로 구조체 배열에 저장된다. 즉 10x<sup>5</sup> + 6x + 3의 경우, ( (10, 5), (6, 1), (3, 0) )로 표시하는 것이다. 이 방식에서는 하나의 배열에 하나이상의 다항식을 저장할 수 있다.  먼저 (계수, 차수) 쌍을 구조체로 선언하고 이 구조체의 배열을 생성한다. 이 배열을 사용하여 다항식을 표현한다.

  ```C
  #define MAX_TERMS 101
  typedef struct {
      float coef;
      int expon;
  } terms[MAX_TERMS];
  ```

- 이 방법을 이용하여 다음의 2개의 다항식을 표현해보자.

  - A = 8x<sup>3</sup> + 7x + 1,				B = 10x<sup>3</sup> + 3x<sup>2</sup> + 1

- terms 배열의 내용을 나타내면 다음과 같이 될 것이다. avail 변수는 현재 비어있는 요소의 인덱스를 가르친다. 위의 예제에서는 avail 변수가 6이 된다.

  <img src="./picture/array7.png">

- 이러한 표현 방법은 terms안에 항의 총 개수가 MAX_TERMS을 넘지만 않으면 많은 다항식을 저장할 수 있다. 그러나 이 방식도 단점이 존재한다. 우선 하나의 다항식이 시작되고 끝나는 위치를 가리키는 인덱스 변수들을 관리하여야 한다. 또한 차수도 저장해야 하기 때문에, 다항식에 따라서는 계수만을 저장하는 첫 번째 방식보다 공간을 더 많이 필요로 할 수도 있다. 또한 다항식의 덧셈을 비롯한 연산들의 구현이 첫 번째 방법보다 좀 더 어려워진다.

- 두개의 다항식을 더하는 알고리즘을 생각해보자.  두개의 다항식 A, B를 더하여 다항식 C를 구하려고 하면, 순서대로 A와 B의 각 항의 차수를 비교하여, 차수가 같으면 A와 B의 각 항의 계수를 더하여 C로 옮기고, 차수가 다르면 A와 B중에서 차수가 큰 항을 C로 옮기면 된다. 이와 같은 과정을 어느 한쪽의 다항식이 끝날 때까지 계속한다.

- 예를 들어 아래의 그림에서 먼저 다항식 A의 첫 번째 항인 8x<sup>3</sup>의 차수와 다항식 B의 첫 번째 항인 10x<sup>3</sup>의 차수를 비교한다. 양쪽의 차수가 같으므로 각 항의 계수를 더하여 C의 첫 번째 위치로 옮긴다. 다음에는 B의 다음 항인 3x<sup>2</sup>이 A의 7x보다 지수가 크므로 B의 3x<sup>2</sup>을 C로 옮긴다. 이런식으로 항목과 항목을 비교하여 옮긴 다음, 어느 한쪽의 다항식이 끝나게 되면 A나 B에 남아있는 항목들을 전부 옮기면 된다.

  <img src="./picture/array8.png">

- 아래의 프로그램은 다항식 덧셈을 구현한 프로그램이다. As과 Ae는 다항식 A의 처음과 마지막을 가리키며 Bs와 Be는 각각 다항식의 B의 처음과 끝을 가리킨다. Cs와 Ce는 덧셈의 결과로 생성되는 다항식의 처음과 끝을 가리킨다. attach 함수는 해당 항목을 배열 terms의 다음 빈 공간에 더하는 함수이다. 이때 avail 변수가 증가된다.

- polynomial2.c

  ```C
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #define MAX_TERMS 101
  
  typedef struct {
      float coef;
      int expon;
  } polynomial;
  
  polynomial terms[MAX_TERMS] = { {4,3}, {3,2}, {2,1}, {1,0}, {2,3}, {5,2}, {-2,1}, {8,0} };
  int avail = 8;
  
  char compare(int a, int b){
      if (a > b) return '>';
      else if (a == b) return '=';
      else return '<';
  }
  
  void attach(float coef, int expon){
      if(avail > MAX_TERMS){
          fprintf(stderr, "항의 개수가 너무 많음\n");
          exit(1);
      }
      terms[avail].coef = coef;
      terms[avail].expon = expon;
      avail++;
  }
  
  void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce){
      float tempcoef;
      *Cs = avail;
      while(As <= Ae && Bs <= Be){
          switch(compare(terms[As].expon, terms[Bs].expon)) {
              case '>':
                  attach(terms[As].coef, terms[As].expon);
                  As++;       break;
              case '=':
                  tempcoef = terms[As].coef + terms[Bs].coef;
                  if(tempcoef)
                      attach(tempcoef, terms[As].expon);
                  As++; Bs++; break;
              case '<':
                  attach(terms[Bs].coef, terms[Bs].expon);
                  Bs++;       break;
          }       
      }
  
      for(; As <= Ae; As++)
          attach(terms[As].coef, terms[As].expon);
      for(; Bs <= Be; Bs++)
          attach(terms[Bs].coef, terms[Bs].expon);
      *Ce = avail - 1;
  }
  
  void print_poly(int s, int e){
      for(int i=s; i<e; i++){
          printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
      }
      printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
  }
  
  float poly_eval(int x, int Ps, int Pe){
      float result = 0;
      for(int i=Ps; i<=Pe; i++){
          result += terms[i].coef * pow(x, terms[i].expon);
      }
      return result;
  }
  
  int main(){
      int As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;
      poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
      print_poly(As, Ae);
      print_poly(Bs, Be);
      printf("------------------------------------------\n");
      print_poly(Cs, Ce);
  
      printf("eval : %3.1f\n", poly_eval(2, Cs, Ce));
  }
  ```

  

## 3.4 포인터

### 포인터의 개념

- 포인터(pointer)는 다른 변수의 주소를 가지고 있는 변수이다. 모든 변수는 메모리 공간에 저장되고 메모리의 각 바이트에는 주소가 매겨져있다. 이 주소가 포인터에 저장된다. 주소는 컴퓨터에 따라 다를 수 있으므로 포인터 변수는 대개 정확한 숫자보다는 그냥 화살표로 그려진다. 모든 변수는 주소를 가지고 있음을 기억하라. 컴퓨터 메모리는 바이트로 구성되어 있고 각 바이트마다 순차적으로 주소가 매겨져있다.

  <img src="./picture/array9.png">

- 위의 그림에서 p는 a라는 변수를 가리키는 포인터 변수이다.

  ```C
  int a = 100;
  int *p;
  p = &a;
  ```

  - 먼저 int 형의 변수 a가 정의되고 p는 int형을 가리키는 포인터로 정의된다. p가 a를 가리키게 하려면 a의 주소를 p에 대입한다. 변수의 주소는 &연산자를 변수에 적용시켜서 추출할 수 있다.



### 포인터와 관련된 연산자

- 포인터와 관련된 2가지의 중요한 연산이 있다.

  - & 연산자 --- 주소 연산자

  - \* 연산자 --- 간접참조 연산자(역참조 연산자)

    - & 연산자는 변수의 주소를 추출하는 연산자이다. 앞에서 선언한 포인터 p가 특정한 변수를 가리키게 하려면 변수의 주소를 & 연산자로 추출하여서 p에 대입한다. 

      ```C
      int a;	// 정수형 변수
      p = &a;	// 변수의 주소를 포인터에 저장
      ```

    - \* 연산자는 포인터가 가리키는 장소에 값을 저장하는 연산자이다. 예를 들어서 p가 가리키는 장소에 200을 저장하려면 다음과 같은 문장을 사용한다.

      ```C
      *p = 200;
      ```

      <img src="./picture/array10.png">

- 이들 예제 문장에서는 *p와 a가 동일한 메모리 위치를 참조함을 유의해야 한다. 즉 *p와 a는 전적으로 동일하다. 즉 값만 같은 것이 아니고 동일한 실제적인 객체를 가리키기 때문에 *p의 값을 변경하게 되면 a의 값도 바뀌게 된다.



### 다양한 포인터

- 포인터는 다음과 같이 여러 가지 자료형에 대하여 선언될 수 있다.

  ```C
  int *p;		// p는 int형 변수를 가리키는 포인터
  float *pf;	// pf는 double형 변수를 가리키는 포인터
  char *pc;	// pc는 char형 변수를 가리키는 포인터
  ```

  

###  널 포인터

- 널 포인터는 어떤 객체도 가리키지 않는 포인터이다. 일반적으로 C언어에서 널 포인터는 NULL이라는 매크로로 표시한다. 포인터를 사용하기 전에는 반드시 널 포인터인지를 검사하여야 한다.

  ```C
  if(p == NULL) {
      fprintf(stderr, "오류: 포인터가 아무 것도 가리키지 않습니다.");
      return;
  }
  ```

- 포인터가 아무 것도 가리키고 있지 않을 때는 항상 널 포인터 상태로 만들어 두는 것이 좋다. 널 포인터를 가지고 간접참조를 하려고 하면 컴퓨터 시스템에서 오류가 발생되어서 쉽게 알 수 있기 때문이다. 잘못된 포인터를 가지고 메모리를 변경하는 것은 치명적인 결과를 가져올 수 있다.



### 함수 매개변수로 포인터 사용하기

- 포인터는 함수의 매개변수로 전달될 수 있다. 특정한 변수를 가리키는 포인터가 함수의 매개변수로 전달되면 그 포인터를 이용하여 함수 안에서 외부 변수의 값을 변경할 수 있다. 하나의 예로 외부 변수 2개의 값을 서로 바꾸는 swap() 함수를 포인터를 이용하여 작성하여 보자.

- swap.c 포인터를 함수의 매개변수로 사용하는 프로그램

  ```C
  #include <stdio.h>
  
  void swap(int *px, int *py) {
      int tmp;
      tmp = *px;
      *px = *py;
      *py = tmp;
  }
  
  int main() {
      int a = 1, b = 2;
      printf("swap을 호출하기 전: a=%d, b=%d\n", a, b);
      swap(&a, &b);
      printf("swap을 호출하기 전: a=%d, b=%d\n", a, b);
      return 0;
  }
  ```

  

### 배열과 포인터

- 함수로 배열이 전달되면 함수 안에서 배열의 내용을 변경할 수 있다. 그 이유는 아래의 그림과 같이 배열의 이름이 배열의 시작위치를 가리키는 포인터이기 때문이다.

  <img src="./picture/array11.png">

- 위의 그림에서 배열의 이름이 점선으로 그려져 있는 이유는 실제로 컴파일러가 배열의 이름에 공간을 할당하지는 않기 때문이다. 대신에 배열의 이름이 있는 곳을 배열의 첫 번째 요소의 주소로 대치한다. 따라서 배열의 이름이 포인터이기 때문에 배열이 함수의 매개변수로 전달될때에 사실은 포인터가 전달되는 것이다. 이것은 메모리 공간과 함수 호출 시간을 절약하는 기법이기도 하다. 함수 호출 시에 배열을 복사할 필요가 없기 때문이다.
- 이것을 다음과 같은 프로그램으로 살펴보자 get_integers()와 cal_sum() 함수는 모두 배열을 매개 변수로 받는다. 배열의 경우에는 원본이 전달되므로 함수 안에서 배열의 내용을 변경하면 원본 배열이 변경된다.

- array1.c

  ```C
  #include <stdio.h>
  #define SIZE 6
  
  void get_integers(int list[]){
      printf("6개의 정수를 입력하시오: ");
      for(int i=0; i<SIZE; i++){
          scanf("%d", &list[i]);
      }
  }
  
  int cal_sum(int list[]){
      int sum = 0;
      for(int i=0; i<SIZE; i++){
          sum += *(list + i);
      }
      return sum;
  }
  
  int main(){
      int list[SIZE];
      get_integers(list);
      printf("합 = %d \n", cal_sum(list));
  }
  ```

  

## 3.5 동적 메모리 할당

- 일반적인 배열은 크기가 고정되어 있다. 예를 들어서 학생들의 성적을 저장하는 아래의 배열 scores는 크기가 100으로 고정되어 있다.

  ```c
  int score[100];
  ```

- 이 고정된 크기 때문에 많은 문제가 발생한다. 흔히 프로그램을 작성할 당시에는 얼마나 많은 입력이 있을지를 알 수 없기 때문이다. 만약 처음에 결정된 크기보다 더 큰 입력이 들어온다면 처리하지 못할 것이고 더 작은 입력이 들어온다면 남은 메모리 공간은 낭비될 것이다.

- 따라서 이러한 문제들을 해결하기 위하여 C 언어에서는 필요한 만큼의 메모리를 운영체제로부터 할당받아서 사용하고, 사용이 끝나면 시스템에 메모리를 반납하는 기능이 있다. 이것을 동적 메모리 할당(dynamic memory allocation)이라고 한다.

  <img src="./picture/array12.png">

- 동적 메모리가 할당되는 공간을 히프(heap)라고 한다. 히프는 운영체제가 사용되지 않는 메모리 공간을 모아 놓은 곳이다. 필요한 만큼만 할당을 받고 또 필요한 때에 사용하고 반납하기 때문에 메모리를 매우 효율적으로 사용할 수 있다. 전형적인 동적 메모리 할당 코드는 다음과 같다.

  ```C
  int *p;
  p = (int *)malloc(sizeof(int))	// 1. 동적 메모리 할당
  *p = 1000;						// 2. 동적 메모리 사용
  free(p);						// 3. 동적 메모리 반납
  ```

- malloc() 함수는 size 바이트 만큼의 메모리 블록을 할당한다. sizeof 키워드는 변수나 타입의 크기를 숫자로 반환한다. 크기의 단위는 바이트가 된다. sizeof(int)는 int형의 크기를 반환한다. malloc()은 동적 메모리 블럭의 시작 주소를 반환한다.반환되는 주소의 타입은 void *이므로 이를 적절한 포인터로 형변환시켜야 한다. 메모리 확보가 불가능하면 NULL을 함수의 반환값으로 반환한다.

- 동적 메모리는 포인터로만 사용할 수 있다. *p는 p가 가리키는 장소이다. *p=1000; 문장을 실행하면 p가 가리키는 장소에 1000이 저장된다.

- free() 함수는 할당된 메모리 블록을 운영체제에게 반환한다.여기서 주의할 점은 malloc() 함수가 반환했던 포인터 값을 잊어버리면 안된다는 것이다. 포인터 값을 잊어버리면 동적 메모리를 반환할 수 없다. malloc()은 시스템의 메모리가 부족해서 요구된 메모리를 할당할 수 없으면 NULL을 반환한다. 따라서 malloc()의 반환값은 항상 NULL인지 검사하여야 한다. 정수 10개를 저장할 수 있는 메모리를 동적으로 할당해본다.

  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #define SIZE 10
  
  int main(){
      int *p;
  
      p = (int *)malloc(SIZE * sizeof(int));
      if(p == NULL) {
          fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
          exit(1);
      }
  
      for(int i=0; i<SIZE; i++)
          p[i] = i;
      for(int i=0; i<SIZE; i++)
          printf("%d ", p[i]);
      
      free(p);
      return 0;
  }
  ```

  

### 구조체와 포인터

- 우리는 구조체에 대한 포인터를 선언하고 포인터를 통하여 구조체 맴버에 접근할 수 있다. 여기서 하나 주의할 것은 포인터를 통하여 구조체의 맴버에 접근하는 편리한 표기법 "->"이다. ps가 구조체를 가리키는 포인터라고 할 때, (*ps).i보다 ps->i라고 쓰는 것이 더 편리하다. 자료 구조에서 구조체에 대한 포인터도 자주 함수의 매개변수로 전달된다. 구조체 자체를 함수로 전달하는 경우, 구조체가 함수로 복사되어 전달되기 때문에 큰 구조체의 경우에는 구조체 포인터를 전달하는 것이 좋다.

- 종합적인 예제로 동적 메모리 할당을 이용하여 구조체를 생성하고 여기에 데이터를 저장해보자. 동적으로 생성된 구조체는 포인터를 통해서만이 접근할 수 있다. 

- malloc2.c 동적 메모리 할당 사용 예제

  ```C
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  
  typedef struct studentTag {
      char name[10];
      int age;
      double gpa;
  } student;
  
  int main() {
      student *s;
  
      s = (student *)malloc(sizeof(student));
      if (s == NULL) {
          fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
          exit(1);
      }
  
      strcpy(s->name, "Park");
      s->age = 20;
  
      free(s);
      return 0;
  }
  ```

  
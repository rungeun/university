## hello2024.java
```java
public class hello2024 { }
```
소스 파일명: `hello2024`

컴파일 명령문: `javac hello2024.java`

컴파일 후 생성되는 파일명: `hello2024.class`

실행 명령문: `hello2024`

## 메인함수 헤더
```java
public static void main(String[] args) { } // 메인함수 헤더
```

## 함수
함수 선언 및 정의
```java
static 반환값자료형 함수이름(매개변수){ 
    return 반환값;
}
```

함수 호출
```java
함수이름(인자);
```

## 입출력 클래스
일출력 클래스 포함
```java
import java.util.Scanner;
```
클래스의 객체 생성
```java
Scanner sc = new Scanner(System.in);
```

예외 처리(try, catch, finally)
```java
        try {
            System.out.print("R>>");
            int r = sc.nextInt();
            double x = circle(r);
            System.out.println("AREA = " + x);
        } catch (Exception e) {
            System.out.println("ERROR");
        } finally {
            sc.close(); // Scanner 인스턴스를 닫음
        }
```
[try catch 를 처리하는 방식은 아래와 같습니다.](#https://mozi.tistory.com/550)

1. try 블록 안에서 예외가 발생하면 그 순간에 코드 실행을 중단

2. 발생된 예외종류가 catch 블럭의 ( ) 안에 지정한 예외와 일치하면 그 안의 코드를 실행

3. catch 블록 안의 코드가 모두 실행되면 try catch 블록 다음에 등장하는 코드를 실행

try: try 문 안에 있는 코드들이 에러가 발생하는 경우 catch 문으로 전달합니다.

catch: try 에서 발생한 예외처리를 진행합니다.

finally: 구문은 예외처리가 발생여부를 떠나 무조건 실행하도록 하는 구문입니다.

## 출력
출력
```java
System.out.print( );
```
출력+개행
```java
System.out.println( );
```

















# Data Structure 문제 풀이

## 1번
다음 순환 공식의 시간복잡도를 Big-Oh 표시법으로 구하는 과정을 보이시오

문제: 
>T(n) = 2T(n/2) + 1, for n >= 2 with T(1)= 1

해설: O(n)
![1번해설](img\1번시간복잡도빅오풀이.jpg)
## 2번
> a) 연결 리스트로 구현된 스택과 큐에서 공백 상태 조건은 각각 무엇인가.
> 
> b) 크기가 7(0~6)이고 front = 3, rear = 6인 원형 큐에서 삽압과 삭제 연산이 가각 1회 수행되었을 때, front와 rear의 값은 각각 얼마인가?

해설:

a) 

스택의 공백상태: top == -1

큐의 공백상태: front == rear
![큐상태](img\큐상태.PNG)

b) 4, 0

(초기 상태)

front = 3: 큐의 첫 번째 원소 위치

rear = 6: 큐의 마지막 원소 위치

(삭제 연산 후)

front를 한 칸 앞으로 옮김 (그러나 원형 큐이므로, 한 칸 앞으로 가는 것은 단순히 인덱스를 1 증가시키는 것을 의미함)

(새로운 front 위치)

front = 4

rear = 6

(삽입 연산 후)

rear를 한 칸 뒤로 옮김(이 경우, rear가 이미 배열의 끝(6)에 있으므로, 다음 위치는 배열의 시작인 0이 됨)

(새로운 rear 위치)

6에서 1 증가시키고, 크기 7로 나누면(모듈로 연산) 0이 됨

front = 4

rear = 0

(최종 결과)

front 위치는 4

rear 위치는 0

![원형큐삽입삭제](img\원형큐삽입삭제.jpg)

## 3번
문제:
> 다음과 같은 linked stack에 대하여 문제 답하시오
> ![3번문제](img\3번문제.PNG)
>
> a) pop 연산 수행 코드를 작성하시오
>
> b) 메모리를 할당받아, 데이터필드 값이 'D'인 노드를 push하는 코드를 작성하시오

해설:

a)      //FIXME: PPT 코드로 수정하기
```c
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Pop function
char pop(Node** top) {
    if (*top == NULL) {                 // 스택이 비어있으면
        printf("Stack is empty.\n");
        return '\0';                    // 스택이 비어있다는 것을 나타내는 특별한 값 반환
    }
    
    Node* temp = *top;                  // 삭제할 노드를 가리키는 임시 포인터
    char data = temp->data;             // 반환할 데이터
    *top = (*top)->next;                // top을 다음 노드로 이동
    free(temp);                         // 노드 메모리 해제
    
    return data;                        // pop된 데이터 반환
}

```
b)      //FIXME: PPT 코드로 수정하기
```c
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Push function
void push(Node** top, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // 새 노드 메모리 할당
    if (newNode == NULL) {
        printf("Heap overflow\n");
        return;
    }
    
    newNode->data = data;               // 데이터 설정
    newNode->next = *top;               // 새 노드가 이전의 top을 가리키도록 설정
    *top = newNode;                     // top을 새 노드로 업데이트
}
```

main함수(참고용)
```c
// 메인 함수
int main() {
    Node* top = NULL;       // 스택 초기화

                            // Push 연산을 수행하여 스택에 데이터를 추가
    push(&top, 'A');
    push(&top, 'B');
    push(&top, 'C');
    
                            // Pop 연산을 수행하여 스택의 상단 요소를 제거
    printf("Popped: %c\n", pop(&top)); // 'C'를 제거하고 출력
    
                            // 'D' 데이터 값을 가진 노드를 스택에 푸시
    push(&top, 'D');
    
                            // 스택의 현재 상태 출력
    printStack(top);        // 'D', 'B', 'A' 순으로 출력되어야 함

    return 0;
}
```

## 4번
> 연산자들에 대한 PIS와 PIE가 다음과 같때 문제에 답하시오.
>
> a) 중위 표현식 (A * B) + (C ^ D) * E를 후위 표현식으로 변환하시오
>
> b) 변환 중 스택에 쌓이는 연산자의 최대 수는 몊 개인가
>
> |연산자|PIS(Priority In Stack)|PIE( Priority In Expression)|
> |:---:|:---:|:---:|
> |)|-|-|
> |^|2|2|
> |*|3|3|
> |+|4|4|
> |(|1|5|


해설:

a) A B * C D ^ + E *

b) 3개
![4번문제풀이1](img\4번풀이_1.jpg)
![4번문제풀이2](img\4번풀이_2.jpg)

### 전위중위후위 표기식 개념
![전위중위후위표기식개념필기](img\전위중위후위표기식개념필기.jpg)

### 후위 표기식 연산
![스택후위표기식계산](img\스택후위표기식계산.PNG)
### 중위 표기식 연산
![스택중위표기식계산](img\스택중위표기식계산.PNG)
### 연산 예제
![연산예제](img\예제.PNG)



# 개념 정리
## Stack

  스택에 저장된 원소는 top으로 정한 곳에서만 접근 가능

is_empty(s) ::= 스택이 비어있는지를 검사 

is_full(s) ::= 스택이 가득 찼는가를 검사

push(s, e) ::= 스택의 맨 위에 요소 e를 추가

pop(s) ::= 스택의 맨 위에 있는 요소를 삭제

peek(s) ::= 스택의 맨 위에 있는 요소를 반환

size(s) ::= 스택 내의 요소들의 개수를 반환

display(s) ::= 스택 내의 모든 요소들을 

### 스택
![스택](img\스택.png)
### 다중 스택
![다중스택](img\다중스택.PNG)
### 함수 호출&반환 과정(스택)
![스택함수호출](img\스택함수호출.PNG)
### 괄호 검사
![스택괄호](img\스택괄호.PNG)
### 후위 표기식 연산
![스택후위표기식계산](img\스택후위표기식계산.PNG)
### 중위 표기식 연산
![스택중위표기식계산](img\스택중위표기식계산.PNG)
### 연산 예제
![연산예제](img\예제.PNG)
### 다중 스택 과정
![다중스택과정](img\다중스택과정.PNG)

+)DFS, 미로탐색




//TODO: 리스트 인덱스 주소 구하는 문제

//TODO: Big-O 최선 최악
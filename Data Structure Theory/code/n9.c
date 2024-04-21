#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;

// 리스트의 모든 노드의 데이터 값을 합산하는 함수
int get_sum(ListNode *head) {
    int sum = 0; // 합산 값을 저장할 변수
    ListNode *current = head; // 현재 노드를 가리키는 포인터

    // 리스트를 순회하면서 각 노드의 data 값을 sum에 더함
    while (current != NULL) {
        sum += current->data;
        current = current->link; // 다음 노드로 이동
    }

    return sum; // 계산된 합산 값 반환
}

// 노드 생성 및 리스트 구성을 위한 도우미 함수
ListNode* insert(ListNode *head, int value) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = value;
    newNode->link = head;
    head = newNode;
    return head;
}

// 리스트와 노드의 메모리 해제를 위한 도우미 함수
void free_list(ListNode *head) {
    ListNode *p;
    while (head != NULL) {
        p = head;
        head = head->link;
        free(p);
    }
}

// 메인 함수로 테스트 용도
int main() {
    ListNode *head = NULL;

    // 리스트에 노드를 추가
    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);

    // 리스트의 노드 데이터 합산 결과 출력
    printf("%d\n", get_sum(head));

    // 메모리 해제
    free_list(head);
    
    return 0;
}

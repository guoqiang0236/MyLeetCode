#include <iostream>
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 创建一个哨兵节点，简化逻辑
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;  // 进位

        // 遍历两个链表，直到都为空且没有进位
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // 获取当前位的值
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // 计算和与进位
            int sum = val1 + val2 + carry;
            carry = sum / 10;      // 进位
            int digit = sum % 10;  // 当前位

            // 创建新节点并追加到结果链表
            current->next = new ListNode(digit);
            current = current->next;

            // 移动指针
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        // 返回哨兵节点的下一个节点（跳过哨兵）
        return dummyHead->next;
    }
};

// 辅助函数：创建链表
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) std::cout << " -> ";
        current = current->next;
    }
    std::cout << std::endl;
}

// 辅助函数：释放链表内存
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// main 函数 - 调用示例
int main() {
    Solution solution;

    // 示例 1: [2,4,3] + [5,6,4] = [7,0,8]
    int arr1[] = { 2, 4, 3 };
    int arr2[] = { 5, 6, 4 };
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    std::cout << "输入 l1: ";
    printList(l1);
    std::cout << "输入 l2: ";
    printList(l2);

    ListNode* result = solution.addTwoNumbers(l1, l2);
    std::cout << "输出: ";
    printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    std::cout << std::endl;

    // 示例 2: [0] + [0] = [0]
    int arr3[] = { 0 };
    int arr4[] = { 0 };
    l1 = createList(arr3, 1);
    l2 = createList(arr4, 1);

    std::cout << "输入 l1: ";
    printList(l1);
    std::cout << "输入 l2: ";
    printList(l2);

    result = solution.addTwoNumbers(l1, l2);
    std::cout << "输出: ";
    printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    std::cout << std::endl;

    // 示例 3: [9,9,9,9,9,9,9] + [9,9,9,9] = [8,9,9,9,0,0,0,1]
    int arr5[] = { 9, 9, 9, 9, 9, 9, 9 };
    int arr6[] = { 9, 9, 9, 9 };
    l1 = createList(arr5, 7);
    l2 = createList(arr6, 4);

    std::cout << "输入 l1: ";
    printList(l1);
    std::cout << "输入 l2: ";
    printList(l2);

    result = solution.addTwoNumbers(l1, l2);
    std::cout << "输出: ";
    printList(result);

    deleteList(l1);
    deleteList(l2);
    deleteList(result);

    return 0;
}
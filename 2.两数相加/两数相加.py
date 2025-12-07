# Definition for singly-linked list.
from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        # 1. 创建哑节点，作为结果链表的头部占位符
        dummy_head = ListNode(0)
        current = dummy_head  # current 指针用于移动和构建新节点
        carry = 0            # 进位变量

        # 2. 循环条件：只要 l1 没走完，或者 l2 没走完，或者还有进位没处理
        while l1 is not None or l2 is not None or carry != 0:
            # 获取当前节点的值，如果链表已经走完了，就用 0 代替
            val1 = l1.val if l1 is not None else 0
            val2 = l2.val if l2 is not None else 0

            # 计算和
            total = val1 + val2 + carry

            # 更新进位 (比如 15 // 10 = 1)
            carry = total // 10

            # 创建新节点存储当前位的数字 (比如 15 % 10 = 5)
            current.next = ListNode(total % 10)

            # 移动指针
            if l1 is not None:
                l1 = l1.next
            if l2 is not None:
                l2 = l2.next
            current = current.next
        
        return dummy_head.next


# 辅助函数：将列表转换为链表
def create_linked_list(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head


# 辅助函数：将链表转换为列表（用于打印）
def linked_list_to_array(head):
    result = []
    current = head
    while current:
        result.append(current.val)
        current = current.next
    return result


if __name__ == "__main__":
    solution = Solution()
    
    # 测试用例 1: 342 + 465 = 807
    # 链表表示：[2,4,3] + [5,6,4] = [7,0,8]
    l1 = create_linked_list([2, 4, 3])
    l2 = create_linked_list([5, 6, 4])
    result = solution.addTwoNumbers(l1, l2)
    print(f"测试用例 1: {linked_list_to_array(result)}")  # 输出: [7, 0, 8]
    
    # 测试用例 2: 0 + 0 = 0
    l1 = create_linked_list([0])
    l2 = create_linked_list([0])
    result = solution.addTwoNumbers(l1, l2)
    print(f"测试用例 2: {linked_list_to_array(result)}")  # 输出: [0]
    
    # 测试用例 3: 9999999 + 9999 = 10009998
    # 链表表示：[9,9,9,9,9,9,9] + [9,9,9,9] = [8,9,9,9,0,0,0,1]
    l1 = create_linked_list([9, 9, 9, 9, 9, 9, 9])
    l2 = create_linked_list([9, 9, 9, 9])
    result = solution.addTwoNumbers(l1, l2)
    print(f"测试用例 3: {linked_list_to_array(result)}")  # 输出: [8, 9, 9, 9, 0, 0, 0, 1]
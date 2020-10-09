/*------------------------------------------------------------------|
给定一个链表，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。

 

进阶：

你能用 O(1)（即，常量）内存解决此问题吗？

 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	快慢双指针法
*
*	执行用时：8 ms, 在所有 C++ 提交中击败了95.43%的用户
*	内存消耗：7.3 MB, 在所有 C++ 提交中击败了99.91%的用户
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return false;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (slow != fast) {
		if (fast->next == NULL || fast->next->next == NULL) {
			return false;
		}
		else {
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	return true;
}
 
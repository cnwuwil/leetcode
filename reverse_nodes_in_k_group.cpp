#include <iostream> 
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
      if(head == NULL)
        return NULL;
      if(k == 1)
        return head;
      
      ListNode* pretail  = NULL;
      ListNode* seghead  = head;
      ListNode* lefthead = NULL;
      ListNode* tmp = head;
      while(1)
      {
        tmp = seghead;
        int i = 0;
        for(i = 1; i < k && tmp->next != NULL; ++i)
          tmp = tmp->next;
        
        // the part less then k, do nothing
        if(tmp->next == NULL && i < k)
        {
          if(pretail != NULL)
            pretail->next = seghead;
          break;
        }
        
        lefthead = tmp->next;
        tmp->next = NULL;
        if(seghead == head)
        {
          head = reverse(seghead);
          pretail = head;
        }
        else
        {
          pretail->next = reverse(seghead);
        }
        
        //find pretail
        while(pretail->next != NULL)
          pretail = pretail->next;
      
        seghead = lefthead;

        if(seghead == NULL)
          break;
      }
      return head;
    }
    
    ListNode* reverse(ListNode* phead)
    {
      ListNode *head = NULL;
      ListNode *current = phead;
      ListNode *tmp = NULL;

      do{
        tmp = current->next;
        current->next = head;
        head = current;
        current = tmp;
      }
      while(current != NULL);

      return head;
    }

};

int main()
{
  ListNode a = 1;
  ListNode b = 2;
  ListNode c = 3;
  ListNode d = 4;
  ListNode e = 5;
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  Solution sl;
  
  ListNode* ret = sl.reverseKGroup(&a, 3);
  while(ret != NULL)
  {
    cout << ret->val << " "; 
    ret = ret->next;
  }

  return 0;
}

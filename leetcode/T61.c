/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stddef.h>

struct ListNode* rotateRight(struct ListNode* head, int k){

    if (head == NULL){ // test null list
        return head;
    }
    //calculate the length of list
    struct ListNode *cal_len_ptr = head;
    int len = 1;
    while (cal_len_ptr->next){ //while the node cal_len_ptr point to is not the end node
        cal_len_ptr = cal_len_ptr->next;
        len++;
    } 


    //confirm the final shift n
    int n = k%len;
    if (n == 0){   //no need move
        return head;
    }


    // find the first and last position of new list
    struct ListNode *last_ptr = head, *first_ptr = head;
    for (int i = 0;i<len-n-1;i++){
        last_ptr = last_ptr->next;
    }
    first_ptr = last_ptr->next;


    //shift the list
    struct ListNode *end_shift_ptr = cal_len_ptr;
    end_shift_ptr->next = head;
    head = first_ptr;
    last_ptr->next = NULL;
    return head;
}
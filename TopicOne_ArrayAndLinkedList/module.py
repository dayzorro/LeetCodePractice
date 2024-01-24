# -*- encoding: utf-8 -*-
"""
@File    :   module.py.py   
@Contact :   690359650@qq.com
@License :   (C)Copyright 2018-2021
 
@Modify Time      @Author          @Version     @Desciption
------------      -------         --------    -----------
2024/1/22         Pengcheng Ruan       1.0         None
"""
import heapq

from Definition import *


# 合并两个有序列表
# note dummy Node 的思想
def mergeTwoLists(list1:ListNode,list2:ListNode)->ListNode:
    dummy_node = ListNode([-1])
    p = dummy_node
    point1,point2 = list1,list2
    while(point1 is not None and point2 is not None):
        if (point1.val>point2.val):
            p.next= point2
            point2 = point2.next
        else:
            p.next = point1
            point1 = point1.next
        p = p.next
        if(point1 is not None):
            p.next = point1
        if (point2 is not None):
            p.next = point2

    return dummy_node.next

def mergeKAscLists(lists)->ListNode:
    if (len(lists)<=0):
        return None
    dummy = ListNode([-1])
    p = dummy
    pq = []
    for head in lists:
            if head:
                # heapq 是python自带的堆栈函数,可以用来创建最小堆
                heapq.heappush(pq,head)
    # 现在，pq 是一个最小堆，并且根据 ListNode 的 val 属性来排序
    # 你可以通过 heapq.heappop(pq) 来获取最小元素，并按需要对堆进行操作
    while pq:
        node = heapq.heappop(pq)
        p.next = node
        if node.next:
            heapq.heappush(pq, node.next)
        p = p.next
    merged_head = dummy.next
    return merged_head

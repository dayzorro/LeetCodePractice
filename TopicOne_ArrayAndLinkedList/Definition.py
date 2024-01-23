# -*- encoding: utf-8 -*-
"""
@File    :   Definition.py
@Contact :   690359650@qq.com
@License :   (C)Copyright 2018-2021
 
@Modify Time      @Author          @Version     @Desciption
------------      -------         --------    -----------
2024/1/22         Pengcheng Ruan       1.0         None
"""
# This file is used to define all the classes.

# 1. ListNode
class ListNode:
    def __init__(self, array_list=None):
        if array_list is None:
            array_list = []

        next_ptr = self
        for idx, data in enumerate(array_list):
            if idx >=(len(array_list)-1):
                next_ptr.val = data
                next_ptr.next = None
                break
            next_ptr.val = data
            next_ptr.next = ListNode()
            next_ptr = next_ptr.next
    def show(self):
        ptr = self
        while ptr is not None:
            print(ptr.val)
            ptr = ptr.next




# -*- encoding: utf-8 -*-
"""
@File    :   test_module.py.py   
@Contact :   690359650@qq.com
@License :   (C)Copyright 2018-2021
 
@Modify Time      @Author          @Version     @Desciption
------------      -------         --------    -----------
2024/1/22         Pengcheng Ruan       1.0         None
"""
import unittest
from module import *
from Definition import *

class TestmergeTwoLists(unittest.TestCase):
    def test_base(self):
        list1 = ListNode([1,2,4])
        list2 = ListNode([1,2,3,4])
        list3 = mergeTwoLists(list1,list2)
        list3.show()

/**
  ******************************************************************************
  * @file           : SingleLinkedList.cpp
  * @author         : shawn
  * @brief          : None
  * @attention      : None
  * @date           : 24-1-26
  ******************************************************************************
  */
#include "../include/SingleLinkedList.h"
SingleLinkedList::SingleLinkedList(int init_value){
    this->value= init_value;
    this->next = nullptr;
}
SingleLinkedList::SingleLinkedList(std::vector<int> init_array) {
    if (init_array.empty()) {
        this->value = 0;
        this->next = nullptr;
    } else {
        SingleLinkedList* dummy = new SingleLinkedList(0); // 创建一个值为0的 dummy 节点
        SingleLinkedList* current = dummy; // 使用 current 来遍历并构建链表

        for (int val : init_array) {
            current->next = new SingleLinkedList(val); // 创建新节点并附加到链表
            current = current->next; // 移动到新创建的节点
        }

        this->value = dummy->next->value; // 设置 this 指向的节点的值为第一个实际节点的值
        this->next = dummy->next->next; // 设置 this 指向的节点的 next 指针

        dummy->next = nullptr; // 断开 dummy 节点与链表的连接
        delete dummy; // 释放 dummy 节点
    }
}

SingleLinkedList::~SingleLinkedList() {
    SingleLinkedList* iter_point = this->next; // 从下一个节点开始，因为当前节点（this）由调用者管理
    while (iter_point != nullptr) {
        SingleLinkedList* free_point = iter_point; // 保存当前节点
        iter_point = iter_point->next; // 移动到下一个节点
        free_point->next = nullptr; // 断开当前节点与链表的连接
        delete free_point; // 删除当前节点
    }
}
int SingleLinkedList::GetValue(){
    return this->value;
}
SingleLinkedList* SingleLinkedList::GetNext(){
    return this->next;
}

SingleLinkedList* SingleLinkedList::MergeTwoSingleLinkedList(SingleLinkedList* list) {
    auto* dummy = new SingleLinkedList(-1);
    SingleLinkedList* p = dummy;
    SingleLinkedList* p1 = this;
    SingleLinkedList* p2 = list;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->value < p2->value) {
            p->next = new SingleLinkedList(p1->value);
            p1 = p1->next;
        } else {
            p->next = new SingleLinkedList(p2->value);
            p2 = p2->next;
        }
        p = p->next;
    }

    while (p1 != nullptr) {
        p->next = new SingleLinkedList(p1->value);
        p1 = p1->next;
        p = p->next;
    }

    while (p2 != nullptr) {
        p->next = new SingleLinkedList(p2->value);
        p2 = p2->next;
        p = p->next;
    }

    SingleLinkedList* result = dummy->next;
    dummy->next = nullptr;
    delete dummy;
    return result;
}

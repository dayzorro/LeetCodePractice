/**
  ******************************************************************************
  * @file           : SingleLinkedList.h
  * @author         : shawn
  * @brief          : None
  * @attention      : None
  * @date           : 24-1-26
  ******************************************************************************
  */

#ifndef LEETCODEPRACTICE_SINGLELINKEDLIST_H
#define LEETCODEPRACTICE_SINGLELINKEDLIST_H

#endif //LEETCODEPRACTICE_SINGLELINKEDLIST_H
#include <vector>

class SingleLinkedList{
public:
    SingleLinkedList(int init_value);
    SingleLinkedList(std::vector<int> init_array);
    ~SingleLinkedList();
    int GetValue();
    SingleLinkedList* GetNext();
    SingleLinkedList* MergeTwoSingleLinkedList(SingleLinkedList* list);
private:
    int value;
    SingleLinkedList* next;

};

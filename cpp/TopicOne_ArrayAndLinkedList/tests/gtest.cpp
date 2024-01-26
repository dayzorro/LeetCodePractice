/**
  ******************************************************************************
  * @file           : gtest.cpp
  * @author         : shawn
  * @brief          : None
  * @attention      : None
  * @date           : 24-1-26
  ******************************************************************************
  */
#include <gtest/gtest.h>
#include "../include/SingleLinkedList.h" // 你的单链表类的头文件

// 测试单链表的构造函数
TEST(SingleLinkedListTest, Constructor) {
    SingleLinkedList list({1, 2, 3});
    EXPECT_EQ(1, list.GetValue());
    EXPECT_EQ(2, list.GetNext()->GetValue());
    EXPECT_EQ(3, list.GetNext()->GetNext()->GetValue());
    EXPECT_EQ(nullptr, list.GetNext()->GetNext()->GetNext());
}

// 测试单链表的合并函数
TEST(SingleLinkedListTest, MergeLinkedList) {
    SingleLinkedList list1({1, 2, 3});
    SingleLinkedList list2({2, 3, 4});
    SingleLinkedList list3({1, 2, 2, 3, 3, 4});

    // Merge list1 and list2
    auto* list4 = list1.MergeTwoSingleLinkedList(&list2);

    // Check for null pointers
    ASSERT_NE(list4, nullptr) << "Merged list is null.";
    ASSERT_NE(&list3, nullptr) << "Expected list is null.";

    auto* p = list4;
    auto* q = &list3;
    while (p != nullptr && q != nullptr) {
        EXPECT_EQ(p->GetValue(), q->GetValue()) << "Values are not equal.";
        p = p->GetNext();
        q = q->GetNext();
    }

    // Check if both lists have reached their end
    EXPECT_EQ(p, nullptr) << "Merged list is longer than expected.";
    EXPECT_EQ(q, nullptr) << "Expected list is longer than merged list.";
    delete list4; // 安全地删除合并后的链表

    // Clean up if necessary (depends on your implementation of MergeTwoSingleLinkedList)
    // delete list4;
}


// 可以添加更多测试用例...

//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}


from Definition import *




# 按间距中的绿色按钮以运行脚本。
if __name__ == '__main__':
    a = ListNode(array_list = [1,2,3])
    ptr = a
    while ptr is not None:
        print(ptr.val)
        ptr = ptr.next


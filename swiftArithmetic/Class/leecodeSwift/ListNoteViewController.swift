//
//  ListNoteViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/7.
//

import UIKit

func printlistNote(_ head: ListNode?) {
    var current = head
    var list: String = ""
    while current != nil {
        if let current = current {
            list.append("\(current.val)")
            list.append("---> ")
        }
        current = current?.next
    }
  print(list)
}

func newListNote(numbers: [Int]) -> ListNode? {
    var current: ListNode? = nil
    print("新建listNote---\(numbers)")
    let dummy: ListNode = ListNode(0, current)
    for num  in numbers {
        let newNote = ListNode(num, nil)
        if current == nil {
            current = newNote
            dummy.next = current
        } else {
            current?.next = newNote
            current = current?.next
        }
    }
    return dummy.next
}

func reverseListNode(_ head: ListNode?) -> ListNode? {
    func reverseListNode(_ pre: ListNode?, _ current: ListNode?) -> ListNode? {
        if current == nil {
            return pre
        }
        let temp: ListNode? = current?.next
        current?.next = pre
        return reverseListNode(current, temp)
    }
    return reverseListNode(nil, head)
}

class ListNoteViewController: BaseTableViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        title = "二叉链表"
        dataSource = ["移除列表倒数N个元素","链表下相交"]
        tableView.reloadData()
        self.compleBlock = { [weak self] title, indepath in
            guard let strongSelf = self else { return }
            strongSelf.didSelected(title: title)
         
        }
        let button = UIButton(type: .close)
        button.setTitle("宝山", for: .normal)
        button.frame =  CGRect(x: 100, y: 100, width: 50, height: 40)
        view.addSubview(button)
    }
    
    override func didSelected(title: String) {
        
        switch title {
        case "移除列表倒数N个元素":
            let head = newListNote(numbers: [1,2,3,4,5,6])
            printlistNote(head)
            let head1 = removeListNote(head, n: 1)
            printlistNote(head1)
            
        case "链表下相交":
            let headA = newListNote(numbers: [1,2,3,4,5,6])
            let headB = newListNote(numbers: [8,3,9,4,5,6])
            headB?.next?.next?.next = headA?.next?.next?.next
            if let inter = getIntersectionNode(headA, headB){
                print("xiangjiao----\(inter.val)")
            }
        default:
            print("-----")
        }
        
    }
    
    func addListNote(list1: ListNode, list2: ListNode) -> ListNode {
        var list1: ListNode? = list1
        var list2:ListNode? = list2
        let dummy: ListNode = ListNode(-1)
        var tail:ListNode? = dummy
        var carry: Int = 0
        while list1 != nil || list2 != nil {
            let a: Int = (list1 != nil) ? list1!.val : 0
            let b: Int = (list2 != nil) ? list2!.val : 0
            let sum: Int = a + b
            tail?.next = ListNode(sum % 10)
            tail = tail?.next
            carry = sum / 10
            if list1 != nil {
                list1 = list1?.next
            }
            if list2 != nil {
                list2 = list2?.next
            }
        }
        if carry != 0 {
            tail?.next = ListNode(carry)
        }
        return dummy.next!
    }
    
    
    func reverseListNode(_ head: ListNode?) -> ListNode? {
        var pre: ListNode? = nil
        var current: ListNode? = head
        var next: ListNode? = nil
        while current != nil {
            next = current?.next
            current?.next = pre
            pre = current
            current = next
        }
        return pre
    }
    
    func detectCycle(_ head: ListNode?) -> ListNode? {
        var fast: ListNode? = head
        var slow: ListNode? = head
        while fast != nil && fast?.next != nil {
            fast = fast?.next?.next
            slow = slow?.next
            if fast === slow {
                var index1 = fast
                var index2 = head
                while index1 !== index2 {
                    index1 = index1?.next
                    index2 = index2?.next
                }
                return index2
            }
        }
        return nil
    }
    
    func getIntersectionNode(_ headA: ListNode?, _ headB: ListNode?) -> ListNode? {
        var listA: ListNode? = headA
        var listB: ListNode? = headB
        while listA !== listB {
            listA = (listA != nil) ? listA?.next : headB
            listB = (listB != nil) ? listB?.next : headA
        }
        return listA
    }
    
    func commonView(_ viewA: UIView?, viewB: UIView? ) -> UIView? {
        var view1: UIView? = viewA
        var view2: UIView? = viewB
        while viewA != viewB {
            view1 = (view1 != nil) ? view1?.superview : viewB
            view2 = (view2 != nil) ? view2?.superview : viewA
        }
        return view1
    }
    
    func removeListNote(_ head: ListNode?, n: Int = 0) -> ListNode? {
        if head == nil {
            return head
        }
        let dummy: ListNode = ListNode(-1, head)
        var fast: ListNode? = dummy
        var slow: ListNode? = dummy
        var n = n
        while n > 0 {
            fast = fast?.next
            n -= 1
        }
        while fast?.next != nil {
            fast = fast?.next
            slow = slow?.next
        }
        slow?.next = slow?.next?.next
        return dummy.next
    }
    
    func reverseListNode(_ head: ListNode?, k: Int) -> ListNode? {
        if head == nil {
            return head
        }
        var head: ListNode? = head
        let dummy: ListNode = ListNode()
        dummy.next = head
        var pre: ListNode? = dummy
        while head != nil {
            var tail: ListNode? = pre
            for _ in 1...k {
                tail = tail?.next
                if tail == nil {
                    return dummy.next
                }
            }
            let next = tail?.next
            let (head1, tail1) = reverse(head, tail)
            pre?.next = head1
            tail?.next = tail1?.next
            pre = next
            head = next?.next
            
        }
        return dummy.next!
    }
    
    func reverse(_ head: ListNode?, _ tail: ListNode?) -> (ListNode? , ListNode?) {
        var head: ListNode? = head
        var pre: ListNode? = tail?.next
        while pre !== tail {
            let temp: ListNode? = head?.next
            head?.next = pre
            pre = head
            head = temp
        }
        return  (tail, head)
    }
    
    func addTwoNumbers(_ l1: ListNode? , _ l2: ListNode?) -> ListNode? {
        let dummy: ListNode = ListNode()
        var tail: ListNode? = dummy
        var carray: Int = 0
        var list1: ListNode? = l1
        var list2: ListNode? = l2
        while list1 != nil  || list2 != nil  || carray > 0 {
            let a: Int = list1 != nil ? list1!.val : 0
            let b: Int = list1 != nil ? list1!.val : 0
            let sum = a + b + carray
            tail?.next = ListNode(sum % 10)
            tail = tail?.next
            carray = sum / 10
            if list1?.next != nil {
                list1 = list1?.next
            }
            if list1?.next != nil {
                list2 = list2?.next
            }
        }
        return dummy.next
    }
    //  pre  start  current
      
    //  pre current  start
    func reverseBetween(_ head: ListNode?, _ left: Int, _ right: Int) -> ListNode? {
        let dummy = ListNode(0)
        dummy.next = head
        var pre: ListNode? = dummy
        for _ in 0..<left-1 {
            pre = pre?.next
        }
        let reverseStart = pre?.next        // 要开始反转的第一个节点
        var current = reverseStart?.next    // 反转区里正在处理的节点
        for _ in 0..<(right-left) {
            reverseStart?.next = current?.next
            current?.next = pre?.next
            pre?.next = current
            current = reverseStart?.next
        }
        return dummy.next
    }
}

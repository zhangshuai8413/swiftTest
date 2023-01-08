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
    }
    
    func didSelected(title: String) {
        
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
    
    
    func detectCycle(_ head: ListNode?) -> ListNode? {
        var fast: ListNode? = head
        var slow: ListNode? = head
        while fast != nil && fast?.next != nil {
            fast = fast?.next?.next
            slow = slow?.next
            if fast === slow {
                var index1 = slow
                var index2 = fast
                while index1 !== index1 {
                    index1 = index1?.next
                    index2 = index2?.next
                }
                
                return index1
            }
        }
        return nil
    }
    
    func getIntersectionNode(_ headA: ListNode?, _ headB: ListNode?) -> ListNode? {
        var listA: ListNode? = headA
        var listB: ListNode? = headB
        while listA !== listB {
            if listA != nil {
                listA = listA?.next
            } else {
                listA = headB
            }
            
            if listB != nil {
                listB = listB?.next
            } else {
                listB = headA
            }
        }
        return listA
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
        if fast == nil {
            return dummy.next
        }
        
        while fast?.next != nil {
            fast = fast?.next
            slow = slow?.next
        }
        slow?.next = slow?.next?.next
        return dummy.next
    }
}

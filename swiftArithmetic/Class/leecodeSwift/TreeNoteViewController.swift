//
//  TreeNoteViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/7.
//

import UIKit

indirect enum BinaryTree<T> {
    case val(T)
    case left(BinaryTree<T>?)
    case right(BinaryTree<T>?)
}

class TreeNoteViewController: BaseTableViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    
        
        var  lefttree = BinaryTree.val(1)
        var  root = BinaryTree.right(BinaryTree.val(2))
        

    }
    
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
        if p === root || q === root || root == nil {
            return root
        }
        let left = lowestCommonAncestor(root?.left, p, q)
        let right = lowestCommonAncestor(root?.right, p, q)
        if left != nil && right != nil {
            return root
        } else if left == nil {
            return right
        }
        return left
    }
    
    func searchTreelowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
        var root: TreeNode? = root
        while root != nil {
            if let root1 = root, let p = p, let q = q, root1.val > p.val, root1.val > q.val {
                root = root1.left
            } else if let root1 = root, let p = p, let q = q, root1.val < p.val, root1.val < q.val {
                root = root1.right
            } else {
                return root
            }
        }
        return nil
    }
}

func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) -> TreeNode? {
    if let root = root, let p = p, let q = q, root.val > p.val, root.val > q.val {
        return lowestCommonAncestor(root.left, q, p)
    } else if let root = root, let p = p, let q = q, root.val < p.val, root.val < q.val {
        return lowestCommonAncestor(root.right, q, p)
    } else {
        return root
    }
}

func getDeth(_ root: TreeNode?) -> Int {
    let head: TreeNode? = root
    var stack: [TreeNode?] = []
    if head != nil {
        stack.append(head)
    }
    var depth = 0; // 记录深度
    var maxDepth = 0;
    while !stack.isEmpty {
        if let node: TreeNode = stack.last as?TreeNode {
            stack.removeLast()
            stack.append(node)
            stack.append(nil)
            depth += 1
            if let right = node.right {
                stack.append(right)
            }
            if let left = node.left {
                stack.append(left)
            }
        } else {
            stack.removeLast()
            stack.removeLast()
            depth -= 1
        }
        maxDepth = max(maxDepth, depth)
    }
    return maxDepth
}


func postorderTraversal(_ root: TreeNode?) -> [Int] {
    guard let root = root else {
      return []
    }
    var result: [Int] = []
    var stack: [TreeNode] = [root]
    while !stack.isEmpty {
        let note = stack.removeFirst()
        if let left = note.left {
            stack.append(left)
        }
        if let right = note.right {
            stack.append(right)
        }
        result.insert(note.val, at: 0)
    }
    return result
 }


func postorderTraversal2(_ root: TreeNode?) -> [Int] {
    guard let root = root else {
      return []
    }
    var result: [Int] = []
    var stack: [TreeNode?] = [root]
    while !stack.isEmpty {
        var note: TreeNode? = stack.last ?? nil
        if let note = note {
            stack.removeLast()
            stack.append(note)
            stack.append(nil)
            if let right = note.right {
                stack.append(right)
            }
            if let left = note.left {
                stack.append(left)
            }
        } else {
            stack.removeLast()
            note = stack.removeLast()
            if let note = note {
                result.append(note.val)
            }
        }
    }
    return result
 }



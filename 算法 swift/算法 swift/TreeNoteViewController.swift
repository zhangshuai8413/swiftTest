//
//  TreeNoteViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/7.
//

import UIKit

class TreeNoteViewController: BaseTableViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        

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


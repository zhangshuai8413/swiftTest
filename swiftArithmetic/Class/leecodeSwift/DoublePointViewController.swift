//
//  DoublePointViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/8.
//

import UIKit

class DoublePointViewController: BaseTableViewController {
    
    enum Constant {
        static let replaceArray = "移除数组"
        static let replaceSa = "替换空格"
        static let reverseLeftString = "左转文字"
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title = "数组"
    }
    
    func threeSum(nums:[Int]) -> [[Int]] {
        var result: [[Int]] = []
        let nums: [Int] = nums.sorted(by: <)
        for (i,a) in nums.enumerated() {
            if a > 0  {
                break
            }
            if i > 0 && a == nums[i - 1] {
                continue
            }
            var set: Set<Int> = Set()
            for j in i + 1...nums.count - 1 {
                if j > i + 2 && nums[j] == nums[j-1] && nums[j - 1] == nums[j - 2]{
                    continue
                }
                let b: Int = nums[j]
                let c = 0 - (a + b)
                if set.contains(c) {
                    result.append([a,b,c])
                    set.remove(c)
                } else {
                    set.insert(b)
                }
            }
        }
        return result
    }
}

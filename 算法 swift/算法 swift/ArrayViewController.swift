//
//  ArrayViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/15.
//

import UIKit

class ArrayViewController: BaseTableViewController {

    enum Constant {
    
        static let replaceArray = "移除数组"
        static let reverseString = "翻转文字"
        static let reverseLeftString = "左转文字"
        static let quickSor = "快速排序"
     
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        title = "数组"
        dataSource = [Constant.replaceArray, Constant.quickSor]
    
        // Do any additional setup after loading the view.
    }
    
    override func didSelected(title: String) {
    
        switch title {
        case Constant.replaceArray:
            removeArray()
        case Constant.quickSor:
            quikSorted()
        default:
            break
        }
    }
    
    
    func removeArray() {
//        给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//
//        不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。
//
//        元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//
//        示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。
//
//        示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
//
        let nums = [0,1,2,2,3,0,4,2]
        let aa = removeElement(nums: nums, val: 2)
        print("aaaa-----\(aa)")
     
    }
    
    
    func quikSorted() {
        print("begin")
        var nums:[Int] = [1,3,5,7,10,5,7,24,5,6]
        quickSort(nums: &nums, low: 0, high: nums.count - 1)
        print("nums-----\(nums)")
    }
    
    func removeElement(nums:[Int], val: Int) -> [Int] {
        var nums: [Int] = nums
        var slow: Int = 0
        for num in  nums {
            if num != val {
                nums[slow] = num
                slow += 1
            }
        }
        print(nums)
        return Array(nums[0..<slow])
    }

    func quickSort(nums: inout [Int], low: Int, high: Int) {
        if low >= high { // 递归结束条件
            return
        }
        var i: Int = low
        var j: Int = high
        let key: Int = nums[i]
        while i < j {
            while i < j && nums[j] >= key {
                j -= 1
            }
            nums[i] = nums[j]
            
            while i < j && nums[i] <= key {
                i += 1
            }
            nums[j] = nums[i]
        }
        nums[i] = key

        quickSort(nums: &nums, low: low, high: i - 1)
        quickSort(nums: &nums, low: i + 1, high: high)
    }
}

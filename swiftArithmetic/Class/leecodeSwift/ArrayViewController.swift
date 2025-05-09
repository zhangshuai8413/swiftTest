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
        quickSort(&nums, low: 0, high: nums.count - 1)
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

    func quickSort(_ nums: inout [Int], low: Int, high: Int) {
        guard low < high else { return }
        var i = low
        var j = high
        let pivot = nums[low]
        while i < j {
            while i < j && nums[j] >= pivot {
                j -= 1
            }
            nums[i] = nums[j]
            while i < j && nums[i] <= pivot {
                i += 1
            }
            nums[j] = nums[i]
        }
        nums[i] = pivot
        quickSort(&nums, low: low, high: i - 1)
        quickSort(&nums, low: i + 1, high: high)
    }
}

/*
 16. 最接近的三数之和
 中等
 1.5K
 相关企业
 给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

 返回这三个数的和。

 假定每组输入只存在恰好一个解。

  

 示例 1：

 输入：nums = [-1,2,1,-4], target = 1
 输出：2
 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 示例 2：

 输入：nums = [0,0,0], target = 1
 输出：0
  

 提示：

 3 <= nums.length <= 1000
 -1000 <= nums[i] <= 1000
 -104 <= target <= 104
 */
func threeSumClosest(_ nums: [Int], _ target: Int) -> Int {
    
    let sortedNums = nums.sorted()
    var closestSum = sortedNums[0] + sortedNums[1] + sortedNums[2]
    
    for i in 0..<sortedNums.count - 2 {
        var left = i + 1
        var right = sortedNums.count - 1
        
        while left < right {
            let sum = sortedNums[i] + sortedNums[left] + sortedNums[right]
            
            if sum == target {
                return sum
            }
            
            if abs(sum - target) < abs(closestSum - target) {
                closestSum = sum
            }
            
            if sum < target {
                left += 1
            } else {
                right -= 1
            }
        }
    }
    
    return closestSum
}


nonisolated(unsafe) var meetingCount: Int = 0

func minMeetings(_ meetings:[[Int]]) -> Int {
    if meetings.isEmpty {
        return meetingCount
    }
    meetingCount += 1
    let meetings = meetings.sorted { meet1, meet2 in
        return meet1.first! < meet2.first!
    }
    var restMeeting: [[Int]] = []
    var lastMeeting: [Int] = []
    lastMeeting = meetings.first!
    for (i, meeting) in meetings.enumerated() {
        if i >= 1 {
           let start = meeting.first!
            if start < lastMeeting.last! {
                restMeeting.append(meeting)
            } else {
                lastMeeting = meeting
            }
        }
    }
    
  return minMeetings(restMeeting)

}

func merge(_ intervals: [[Int]]) -> [[Int]] {
    guard !intervals.isEmpty else { return [] }
    let sortIntervals = intervals.sorted { $0[0] < $1[0]}
    var merge:[[Int]] =  [sortIntervals[0]]
    for current in sortIntervals[1...] {
        var last = merge.removeLast()
        if current[0] < last[1] {
            last[1] = max(current[1], last[1])
        } else {
            merge.append(current)
        }
    }
    return merge
}

func generateMatrix(_ n: Int) -> [[Int]] {
    var matrix:[[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
    let maxNum = n * n
    var curNum = 1
    var row = 0
    var column = 0
    let directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    var directionIndex = 0
    while curNum <= maxNum  {
        matrix[row][column] = curNum;
        curNum += 1
        let nextRow = row + directions[directionIndex][0]
        let nextcolumn = column + directions[directionIndex][1]
        if nextRow >= n || nextRow < 0 || nextcolumn < 0 || nextcolumn >= n || matrix[nextRow][nextcolumn] != 0 {
            directionIndex = (directionIndex + 1) % 4
        }
        row = nextRow
        column = nextcolumn
    }
    return matrix
}

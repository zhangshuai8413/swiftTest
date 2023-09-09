//
//  StackViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/8.
//

import UIKit

struct Heap<T> {
    var elements: [T]
    let priorityFunction: (T, T) -> Bool
    
    init(elements: [T] = [], priorityFunction: @escaping (T, T) -> Bool) {
        self.elements = elements
        self.priorityFunction = priorityFunction
        buildHeap()
    }
    
    mutating func buildHeap() {
        for index in (0..<count/2).reversed() {
            siftDown(index)
        }
    }
    
    var isEmpty: Bool {
        return elements.isEmpty
    }
    
    var count: Int {
        return elements.count
    }
    
    mutating func push(_ element: T) {
        elements.append(element)
        siftUp(count - 1)
    }
    
    mutating func pop() -> T? {
        if isEmpty {
            return nil
        }
        elements.swapAt(0, count - 1)
        let element = elements.removeLast()
        siftDown(0)
        return element
    }
    
    mutating func siftUp(_ index: Int) {
        var childIndex = index
        var parentIndex = parentIndexFor(childIndex)
        while childIndex > 0 && priorityFunction(elements[childIndex], elements[parentIndex]) {
            elements.swapAt(childIndex, parentIndex)
            childIndex = parentIndex
            parentIndex = parentIndexFor(childIndex)
        }
    }
    
    mutating func siftDown(_ index: Int) {
        var parentIndex = index
        while true {
            let leftChildIndex = leftChildIndexFor(parentIndex)
            let rightChildIndex = rightChildIndexFor(parentIndex)
            var firstIndex = parentIndex
            if leftChildIndex < count && priorityFunction(elements[leftChildIndex], elements[firstIndex]) {
                firstIndex = leftChildIndex
            }
            if rightChildIndex < count && priorityFunction(elements[rightChildIndex], elements[firstIndex]) {
                firstIndex = rightChildIndex
            }
            if firstIndex == parentIndex {
                return
            }
            elements.swapAt(parentIndex, firstIndex)
            parentIndex = firstIndex
        }
    }
    
    func parentIndexFor(_ index: Int) -> Int {
        return (index - 1) / 2
    }
    
    func leftChildIndexFor(_ index: Int) -> Int {
        return 2 * index + 1
    }
    
    func rightChildIndexFor(_ index: Int) -> Int {
        return 2 * index + 2
    }
}

class StackViewController: BaseTableViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        
        //    // 示例用法
        let nums = [3, 2, 1, 5, 6, 4]
        let k = 2
        if let kthLargest = findKthLargestElement(nums, k) {
            print("第 \(k) 个最大元素是 \(kthLargest)")
        } else {
            print("数组中的元素不足 \(k) 个")
        }
        
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */
    
    // 自定义堆数据结构
  
    // 使用堆找到数组中第 k 个最大元素
    func findKthLargestElement(_ nums: [Int], _ k: Int) -> Int? {
        var minHeap = Heap(elements: nums, priorityFunction: <)
        var result: Int?
        for _ in 0..<k {
            result = minHeap.pop()
        }
        return result
    }




}


class SolutionLargestRectangleArea {
    
    func largestRectangleArea(_ heights: [Int]) -> Int {
        var stack = [Int]()
        var heights = heights
        heights.insert(0, at: 0) // 数组头部加入元素0
        heights.append(0) // 数组尾部加入元素0
        stack.append(0)
        var result = 0
        
        for i in 1..<heights.count {
            while heights[i] < heights[stack.last!] {
                let mid = stack.popLast()!
                let w = i - stack.last! - 1
                let h = heights[mid]
                result = max(result, w * h)
            }
            stack.append(i)
        }
        
        return result
    }
    
    func maximalRectangle(_ matrix: [[Character]]) -> Int {
        
        if matrix.isEmpty || matrix[0].isEmpty {
            return 0
        }
        let rows = matrix.count
        let cols = matrix[0].count
        var heights = [Int](repeating: 0, count: cols)
        var maxArea = 0
        
        for row in 0..<rows {
            for col in 0..<cols {
                if matrix[row][col] == "1" {
                    heights[col] += 1
                } else {
                    heights[col] = 0
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights))
        }
        return maxArea
        
    }
    
    

}

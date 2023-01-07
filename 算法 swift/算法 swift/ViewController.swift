//
//  ViewController.swift
//  算法 swift
//
//  Created by 张帅zhuangshuai09@corp.netease.com on 2022/10/11.
//

import UIKit

public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init() { self.val = 0; self.next = nil; }
    public init(_ val: Int) { self.val = val; self.next = nil; }
    public init(_ val: Int, _ next: ListNode?) { self.val = val; self.next = next; }
}


class TreeNode {
    var val: Int = 0
    var left: TreeNode?
    var right: TreeNode?
    init(value: Int, left: TreeNode? = nil, right: TreeNode? = nil) {
        self.val = value
        self.left = left
        self.right = right
    }
}

class ViewController: UIViewController, UIGestureRecognizerDelegate {
    @IBOutlet weak var redview: UIView!
    
    var a: Person? = nil
    var b: Person? = nil
    @IBOutlet weak var redButton: UIButton!
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }
    
    
    @objc
    func tapGesture(tap: UITapGestureRecognizer)  {
        
    }
    
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        //        var nums = [0,1,2,2,3,0,4,2]
        //        let index = removeElement(nums: &nums, target: 2)
        //        print(index)
//        sortSqr()
//        minSubArrayLen()
        printCircle()
    }
    
//    1 2 3,4  5
//    2 1    4 3
    
    func swapPairsWhile(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil {
            return head
        }
        let dummy: ListNode = ListNode(-1, head)
        var current: ListNode? = dummy
        while current != nil && current?.next != nil {
            let temp1 = current?.next
            let temp2 = current?.next?.next?.next
            current?.next = current?.next?.next
            current?.next?.next = temp1
            current?.next?.next?.next = temp2
            current = current?.next?.next
        }
        return dummy.next
    }
    
    func swapListNote(_ head: ListNode?) -> ListNode? {
        if head == nil || head?.next == nil {
            return head
        }
        let next = head?.next
        head?.next = swapListNote(next?.next)
        next?.next = head
        return next
        
    }
    
    func reverseListNote(head: ListNode?) -> ListNode? {
        var pre: ListNode?
        var next: ListNode?
        var current: ListNode? = head
        if head == nil {
            return head
        }
        
        while current != nil {
            next = current?.next
            if next == nil {
                return next
            }
            current?.next = pre
            pre = current
            current = next
        }
        
        return pre
    }
    
    func reverseList2(_ head: ListNode?) -> ListNode? {
       return reverse(pre: nil, cur: head)
    }
    
    func reverse(pre: ListNode?, cur: ListNode?) -> ListNode? {
        if cur == nil {
            return pre
        }
        let temp: ListNode? = cur?.next
        cur?.next = pre
        return reverse(pre: cur, cur: temp)
        
    }
//    func removeListNote(header: ListNode?, val: Int) -> ListNode? {
//        let dummy: ListNode = ListNode()
//        if header == nil || header?.val == val {
//            return header
//        }
//        dummy.next = header
//        var current = dummy
//        while let curentNext = current.next {
//            if curentNext.next?.val == val {
//                current.next = curentNext.next
//            } else {
//                current = curentNext
//            }
//        }
//        return dummy.next
//    }
    
    func minSubArrayLen() {
        // 输入：s = 7, nums = [2,3,1,2,4,3] 输出：2 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
        func minSubLen(nums: [Int], target: Int) -> Int {
            var sum: Int = 0
            var left: Int = 0
            var reslut: Int = Int.max
            for (i, num) in nums.enumerated() {
                sum += num
                while sum >= target {
                    reslut = min(reslut, i - left + 1)
                    sum -= nums[left]
                    left += 1
                }
            }
            return reslut == Int.max ? 0 : reslut
        }
        let nums:[Int] = [2,3,1,2,4,3]
        let lenght = minSubLen(nums: nums, target: 7)
        print(lenght)
    }
    
    func sortSqr() {
        // 输入：nums = [-4,-1,0,3,10] 输出：[0,1,9,16,100] 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
        var nums = [-4,-1,0,3,10]
        func sortSqr(nums: inout[Int]) -> [Int] {
            nums = nums.compactMap({ $0 * $0})
            var left: Int = 0
            var right: Int = nums.count - 1
            var index: Int = nums.count - 1
            var result: [Int] = [Int].init(repeating: 0, count: nums.count)
            while left <= right {
                let leftNum = nums[left]
                let rightNum = nums[right]
                if leftNum > rightNum {
                    result[index] = leftNum
                    left += 1
                } else {
                    result[index] = rightNum
                    index -= 1
                    right -= 1
                }
            }
            return result
        }
        let result = sortSqr(nums: &nums)
        print(result)
    }
    
    func removeElement(nums: inout[Int], target: Int) -> Int {
        var i: Int = 0
        for num in nums {
            if num != target {
                nums[i] = num
                i += 1
            }
        }
        return i
    }
    
    
    func getFleetCount(n: Int) -> Int {
        if  n <= 2 {
            return n
        }
        var c = 0
        var a = 1
        var b = 2
        for _ in 3...n {
            c = a + b
            a = b
            b = c
        }
        return c
    }
    
    func searchMid(nums: [Int], target: Int) -> Int {
        var left: Int = 0
        var right: Int = nums.count - 1
        while left <= right {
            let midIndex =  left + (right - left) / 2
            let midNum = nums[midIndex]
            if target == midNum {
                return midIndex
            }
            if midNum < target {
                left = midIndex + 1
            } else {
                right = midIndex - 1
            }
        }
        return -1
    }
    
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var map:[Int: Int] = [:]
        for num in nums { map[num, default: 0] += 1 }
        return Array(map.keys.sorted{ map[$0]! > map[$1]!}[0..<k])
    
    }
    
    func pathNumber(nums: [[Int]]) -> Int {
        let n: Int = nums.count
        let m: Int = nums[0].count
        var dp: [[Int]] = [[Int]](repeating: Array(repeating: 0, count: m), count: n)
        for (i ,_)in nums[0].enumerated() {
            if nums[0][i] == 0 {
                dp[0][i] = 1
            }
        }
        for i in 0..<n {
            if nums[i][0] == 0 {
                dp[i][0] = 1
            }
        }
        
        for i  in  0..<n {
            for j in 0..<m {
                if nums[i][j] == 1 {
                    continue
                }
               dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
            }
        }
        
        return dp[n - 1][m - 1]
    }

    func commonChars(_ words: [String]) -> [String] {
        var res: [String] = [ ]
        var dict: [Int : Int];
        let firstWords: [Character] =  Array(words.first ?? "")
        let char1: UInt8 = ("a" as Character).asciiValue!
        firstWords.forEach { ch in
            let  aa = ch.asciiValue  
            
        }
        return res
    }
    
    func removeDuplite(_ head: ListNode?) -> ListNode? {
        guard head != nil else {
            return head
        }
        let dummy: ListNode? = ListNode(0)
        dummy?.next = head
        var current: ListNode? = dummy
        while current != nil && current?.next != nil {
            if current?.next?.val == current?.next?.next?.val {
                let value = current?.next?.val
                while current?.next != nil && current?.next?.val == value {
                    current?.next = current?.next?.next
                }
            } else {
                current =  current?.next
            }
        }
        return dummy?.next
    }
    
    func removeNthFromEnd(_ head: ListNode?, _ n: Int) -> ListNode? {
        guard head != nil else {
            return head
        }
        let dummy: ListNode? = ListNode(0)
        dummy?.next = head
        var fast: ListNode? = dummy
        var slow: ListNode? = dummy
        var n: Int = n
        while n > 0  {
            fast = fast?.next
            n -= 1
        }
        if fast != nil {
            fast = fast?.next
            while fast != nil {
                fast = fast?.next
                slow = slow?.next
            }
            slow?.next = slow?.next?.next
        }
        return dummy?.next
    }
    
    func swapPairs(_ head: ListNode?) -> ListNode? {
        guard head != nil, head?.next != nil else {
            return head
        }
        let newNote = head?.next
        head?.next = swapPairs(newNote?.next)
        newNote?.next = head
        return newNote
    }
    func removeNote(root: ListNode?,target: Int) ->ListNode? {
       
        var root: ListNode? = root
        let dummy: ListNode = ListNode(0)
        dummy.next = root
        if root?.val == target || root == nil {
            dummy.next = nil
        }
        while root != nil, root?.next != nil {
            if root?.next?.val == target {
                root?.next = root?.next?.next
            } else {
                root = root?.next
            }
        }
        return dummy.next
    }
    
    func gcfa() {
        
        //        var sear = DispatchQueue(label: "abce")
        //        sear.async {
        //            print("1----\(Thread.current)")
        //        }
        //        sear.async {
        //            print("3----\(Thread.current)")
        //        }
        //
        //        let queue = DispatchQueue(label: "queue", attributes: DispatchQueue.Attributes.concurrent)
        //        queue.async {
        //            print("4----\(Thread.current)")
        //        }
        //        queue.async {
        //            print("5----\(Thread.current)")
        //        }
        
        //        DispatchQueue.global().sync {
        //            print("4----\(Thread.current)")
        //            DispatchQueue.main.async {
        //                print("1----\(Thread.current)")
        //                DispatchQueue.main.sync {
        //                    print("3----\(Thread.current)")
        //                }
        //
        //            }
        //            DispatchQueue.global().async {
        //                DispatchQueue.main.async {
        //                    print("5----\(Thread.current)")
        //                    DispatchQueue.main.sync {
        //                        print("6----\(Thread.current)")
        //                    }
        //                }
        //            }
        //
        //        }
        //        print("2")
    }
    
    func printArrayClock()  {
        
        func printArray(nums:[[Int]], start: Int) {
            var result: [Int] = []
//            let endX: Int =  bu
        }
    }
    
    func printCircle()  {
        func printCircle(nums:[[Int]], start: Int) {
            var result: [Int] = []
            // left  -> right
            let endX: Int =  nums[0].count - 1 - start
            let endY: Int =  nums.count - 1 - start
            for i in start...endX {
                let num = nums[start][i]
                result.append(num)
            }
            //  top -> bottom
            if start < endY {
                for i in (start + 1)...endY {
                    let num = nums[i][endX]
                    result.append(num)
                }
            }
            //  right -> left
            if start < endX && start < endY {
                for i in (start...(endX - 1)).reversed() {
                    let num = nums[endY][i]
                    result.append(num)
                }
            }
            //  bottom -> top
            if start < endX && start < endY - 1 {
                for i in ((start + 1)...(endY - 1)).reversed() {
                    let num = nums[i][start]
                    result.append(num)
                }
            }
            print("\(result)\n")
        }
        let n: Int = 4
        let m: Int = 5
        var nums: [[Int]] = Array(repeating: Array(repeating: 0, count: 5), count: 4)
        for i in 0...n - 1 {
            for j in 0...m - 1 {
                let num = i * m  + j + 1
                nums[i][j] = num
            }
        }
        
        nums.forEach { num in
            print("\(num)\n")
        }
        var start: Int = 0
        while start < nums.count / 2 {
            printCircle(nums: nums,start: start)
            start += 1
        }
    }
    

    
    func sortVersion() {
        var aaa = ["1.0","1.1.0","1.2.1","1.0.0","1.11.1"]
        aaa = aaa.sorted(by: <)
        print(aaa)
    }
    
    
    func minSubArrayLen(nums: [Int], target: Int) -> Int {
        var res: Int = Int.max
        var subLength: Int = 0
        var sum: Int = 0
        var i: Int = 0
        for (j,num) in nums.enumerated() {
            sum += num
            if sum >= target {
                subLength = j - i + 1
                res = res < subLength ? res : sum
                i += 1
                sum -= nums[i]
            }
        }
        return res == Int.max ? 0 : res;
    }
    
    func removeDuplicates(nums: inout [Int]) -> Int {
        let n = nums.count
        if n == 0 {
            return 0
        }
        var fast: Int = 1
        var slow: Int = 1
        while fast < n {
            if nums[fast] != nums[fast - 1] {
                nums[slow] = nums[fast]
                slow += 1
            }
            fast += 1
        }
        return slow
    }
    
    func maxArea(heights:[Int]) -> Int {
        var ans: Int = 0
        var left: Int = 0
        var right: Int = heights.count - 1
        while left < right {
            let area = min(heights[left], heights[right]) * (right - left)
            ans = max(area, ans)
            if heights[left] <= heights[right] {
                left += 1
            } else {
                right -= 1
            }
        }
        return ans
    }
    
    func GCDssss() {
        print("0000000")
        DispatchQueue.main.async {
            print("1111111")
            DispatchQueue.main.async {
                print("2222222")
            }
            DispatchQueue.global().sync {
                print("7777777")
                DispatchQueue.main.sync {
                    print("88888888")
                }
            }
        }
        print("33333333")
        DispatchQueue.global().sync {
            print("44444444")
            DispatchQueue.main.sync {
                print("5555555")
            }
        }
        print("66666666")
        
    }
    
    func minWindow(s: String, t: String) -> Int {
        let array: [Character] = Array(s)
        let targets: [Character] = Array(t)
        var cnt: [Character: Int] = [:]
        var org: [Character: Int] = [:]
        
        func check() -> Bool {
            var flag: Bool = true
            org.forEach { (key: Character, value: Int) in
                if let count1 = cnt[key], count1 < value {
                    flag = false
                    return
                }
            }
            return flag
        }
        
        var l: Int = 0
        var r: Int = -1
        var lenght: Int = Int.max
        var anSL: Int = -1
        var ansR: Int = -1 // 全局的右指针
        for ch in targets {
            org[ch, default: 0] += 1
        }
        while r < array.count - 1 {
            r += 1
            let ch: Character = array[r]
            if  let _ = org[ch] {
                cnt[ch, default: 0] += 1
            }
            while check() && l < r {
                if r - l + 1 < lenght {
                    lenght = r - l + 1
                    anSL = l
                }
                let chL = array[l]
                if let _ = org[chL] {
                    cnt[chL, default: 0]  -= 1
                }
                l += 1
            }
            
        }
        return  anSL == -1 ? s.count : lenght
    }
    

    func verifTreeNote(nums: [Int]) -> Bool {
        let rootValue = nums.last ?? 0
        var left: Int = 0
        for (index, num) in nums.enumerated() {
            if num  > rootValue {
                left = index
                break
            }
        }
        for i in left..<nums.count {
            if nums[i] < rootValue {
                return false
            }
        }
        var isleft: Bool = true
        if left > 0 {
            let leftNums: [Int] = Array(nums.prefix(left))
            isleft = verifTreeNote(nums: leftNums)
        }
        var isRight: Bool = true
        let rightNums: [Int] = Array(nums.suffix(nums.count - 1 - left))
        isRight = verifTreeNote(nums: rightNums)
        return isleft && isRight
    }
    
    func rotate(matrix: inout [[Int]]) {
        let n =  matrix.count
        for i in 0..<n / 2 {
            for j in 0..<((n + 1) / 2) {
                let temp = matrix[i][j]
                matrix[i][j] = matrix[n - j - 1][i]
                matrix[n - j - 1][i] = matrix[n-i-1][n - j - 1]
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
                matrix[j][n - i - 1] = temp
            }
        }
    }
    
    func searchNums(nums:[[Int]], target: Int) -> (Int , Int) {
        guard !nums.isEmpty else {
            return (0,0)
        }
        let n = nums.count
        let m = nums[0].count
     
        var row: Int = 0
        var colum: Int = m - 1
        while row < n &&  colum > 0 {
             row = 0
            if nums[(row * n )][colum] == target {
                return (row, colum)
            }
            if target < nums[(row * n )][colum] {
                row += 1
            } else {
                colum -= 1
            }
        }
        return (0, 0)
    }
    
    func searchMid(nums:[[Int]], target: Int) -> (Int , Int) {
        guard !nums.isEmpty else {
            return (0,0)
        }

        return (0, 0)
    }
    
    
    func myPow(_ x: Double, _ n: Int) -> Double {
        let n = n
        return n > 0  ? quickMul(x: x, n: n) :  quickMul(x: x, n: -n)
    }
    
    func quickMul(x: Double, n: Int) -> Double {
        if n == 0 {
            return 1.0
        }
        
        let y = quickMul(x: x, n: n / 2)
        
        return n % 2 == 0 ? y * y  :   1.0 / y * y * x
        
    }
    func abcMinPathSum(grid: [[Int]]) -> Int {
        if grid.isEmpty || grid[0].isEmpty {
            return 0
        }
        var dp: [[Int]] = []
        dp = grid.compactMap({ Array(repeating: 0, count: $0.count) })
        dp[0][0] = grid[0][0]
        let row = grid.count
        let columns = grid[0].count
        
        for i in 0..<row {
            for j in 0..<columns {
                if i == 0 && j == 0{
                    dp[i][j] = grid[i][j]
                } else if i == 0 {
                    dp[0][j] = dp[0][j - 1] + grid[0][j]
                } else if j == 0 {
                    dp[i][0] = dp[i - 1][0] + grid[i][0]
                } else {
                    let a: Int = dp[i - 1][j]
                    let b: Int = dp[i][j - 1]
                    let c: Int = min(a, b)
                    dp[i][j] = c + grid[i][j]
                }
            }
        }
        
        let dd = dp[row - 1][columns - 1]
        return dd
    }
    
    func addDD(n: Int) -> Int {
        if n == 0 {
            return 0
        }
        return addDD(n: n - 1) + n
    }
    
    
    func reorderList(head: ListNode?) {
        var head = head
        if (head == nil) {
            return;
        }
        var list: [ListNode] = []
        while head != nil {
            list.append(head!)
            head = head?.next
        }
        var i: Int = 0
        var j: Int = list.count - 1
        while i < j {
            list[i].next = list[j]
            i += 1
            if i == j {
                break
            }
            list[j].next = list[i]
            j -= 1
        }
        list[i].next = nil
    }
    
    func printZNote(root: TreeNode?) -> [[Int]] {
        guard let root = root else {
            return []
        }
        var leftToRight: Bool = true
        var noteList: [TreeNode] = []
        var ret: [[Int]] = []
        noteList.append(root)
        while !noteList.isEmpty {
            let size = noteList.count
            var temp: [Int] = []
            for _ in 0..<size {
                let top = noteList.first
                if let val = top?.val {
                    temp.append(val)
                }
                if let left = top?.left {
                    noteList.append(left)
                }
                if let right = top?.right {
                    noteList.append(right)
                }
                noteList.removeFirst()
            }
            if !leftToRight {
                temp = temp.reversed()
            }
            leftToRight = !leftToRight
            ret.append(temp)
        }
        return ret
    }
    
    func merge(intervals: [[Int]]) -> [[Int]] {  ///   [[1, 5],  [1, 5],  [3,  7], [9, 10]]
        var intervals = intervals
        var mergeArray: [[Int]] = []
        intervals = intervals.sorted(by: {$0[0] < $1[0]})
        mergeArray.append(intervals[0])
        for (_ , interval) in intervals.enumerated() {
            let L = interval[0]
            let R = interval[1]
            if !mergeArray.isEmpty, let last = mergeArray.last {
                let start: Int = last[0]
                let end: Int = last[1]
                if end < L {
                    mergeArray.append(interval)
                } else {
                    mergeArray.removeLast()
                    mergeArray.append([start, max(end, R)])
                }
            }
        }
        return mergeArray
    }
    
    func longestCommonPrefix(_ strs: [String]) -> String {
        return longestCommonPrefix(strs: strs, start: 0, end: strs.count)
    }
    
    func longestCommonPrefix(strs: [String], start: Int, end: Int) -> String {
        if start == end {
            return strs[start]
        }
        let mid =  (end - start)  / 2
        let left  = longestCommonPrefix(strs: strs, start: start, end: mid)
        let right = longestCommonPrefix(strs: strs, start: mid + 1, end: end)
        return longestCommonPrefix(string1: left, string2: right)
    }
    
    func longestCommonPrefix(string1: String, string2: String) -> String {
        let str1s: [Character] = string1.map({$0})
        let str2s: [Character] = string2.map({$0})
        let minCount = min(string1.count, string2.count)
        var subIndex: Int = 0
        for index in 1...minCount {
            if str1s[index] != str2s[index] {
                subIndex = index
                break
            }
        }
        return String(string1.prefix(subIndex))
    }
    
    func dddfkf() {
        var a: NSNumber = NSNumber(integerLiteral: 0)
        var intA = 0
        let quen = DispatchQueue.global()
        let group = DispatchGroup()
        for _ in 0..<1000 {
            quen.async(group: group, execute: {
                a = NSNumber(integerLiteral: a.intValue + 1)
                intA += 1
            })
        }
        
        for _ in 0..<1000 {
            quen.async(group: group, execute: {
                a = NSNumber(integerLiteral: a.intValue + 1)
                intA += 1
            })
        }
        group.notify(queue: quen) {
            print("--------\(a)-----\(intA)")
        }
        
    }
    
    func longestPalindrome(s: String) -> String {
        guard s.count > 1 else {
            return s
        }
        let longString = s
        let count = s.count
        var dp: [[Bool]] = []
        let characters: [Character] = Array(s)
        var beginIndex: Int = 0
        var maxLenght: Int = 0
        for i in 1...s.count {
            dp[i][i] = true
        }
        for L in 2..<count {
            for i in 0..<count {
                let j = i + L - 1
                if j >= count {
                    break
                }
                if characters[i] != characters[j] {
                    dp[i][j] = false
                } else {
                    if j - i < 3 {
                        dp[i][j] = true
                    } else {
                        dp[i][j] = dp[i + 1][j-1]
                    }
                }
                if dp[i][j] && j - i > maxLenght {
                    maxLenght = j - i
                    beginIndex = i
                }
            }
        }
        return longString
    }
    
    func reverse(_ x: Int) -> Int {
        var x = x
        var revers: Int = 0
        while x != 0 {
            if x > Int.max || x < Int.min {
                return 0
            }
            let digit = x % 10
            x = x / 10
            revers =  revers * 10 + digit
        }
        return revers
    }
    
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var dict = [Int: Int]()
        for (i,num) in nums.enumerated() {
            if let lasindex = dict[target - num] {
                return [lasindex, i]
            }
            dict[num] = i
        }
        fatalError("No valid outputs")
    }
    
    func combinationSum(candidates:[Int], target: Int) -> [[Int]] {
        var res: [[Int]] = []
        var ans: [Int] = []
        combinationSum(candidates: candidates, res: &res, ant: &ans, target: target, index: 0)
        return res
    }
    
    func combinationSum(candidates: [Int], res: inout [[Int]] , ant: inout [Int], target: Int, index: Int) {
        if index == candidates.count {
            return
        }
        if target == 0 {
            res.append(ant)
            return
        }
        combinationSum(candidates: candidates, res: &res, ant: &ant, target: target , index: index + 1 )
        let newTarget = target - candidates[index]
        if newTarget >= 0 {
            ant.append(candidates[index])
            combinationSum(candidates: candidates, res: &res, ant: &ant, target: newTarget, index: index)
            ant.removeLast()
        }
    }
    
    func permute(_ nums: [Int]) -> [[Int]] {
        var ant: [Int] = []
        var res: [[Int]] = []
        var used: [Bool] = []
        used = Array(repeating: false, count: nums.count)
        dfsPermute(nums: nums, res: &res, ant: &ant, used: &used, index: 0)
        return res
    }
    
    func dfsPermute(nums:[Int], res: inout [[Int]], ant: inout [Int], used: inout [Bool], index: Int) {
        if index == nums.count {
            res.append(ant)
            return
        }
        for i in 0...nums.count - 1 {
            if !used[i] {
                ant.append(nums[i])
                used[i] = true
                dfsPermute(nums: nums, res: &res, ant: &ant, used: &used, index: index + 1)
                used[i] = false
                ant.removeLast()
            }
        }
    }
    
    func dfs(nums:[Int],res: inout [[Int]],ant: inout [Int], current: Int) {
        if current == nums.count {
            res.append(ant)
            return
        }
        ant.append(nums[current])
        dfs(nums: nums, res: &res, ant: &ant, current: current + 1)
        ant.removeLast()
        dfs(nums: nums, res: &res, ant: &ant, current: current + 1)
    }
    
    func subsets(nums: [Int]) -> [[Int]] {
        var res: [[Int]] = []
        var ant: [Int] = []
        dfs(nums: nums, res: &res, ant: &ant, current: 0)
        return res
    }
    
    func printTreeNote(treeNote: TreeNode? = nil) {
        var list: [TreeNode] = []
        guard let treeNote = treeNote else {
            return
        }
        list.append(treeNote)
        while !list.isEmpty {
            let count = list.count
            for _ in 1...count {
                let treeNote: TreeNode? = list.first
                list.removeFirst()
                if let left = treeNote?.left {
                    list.append(left)
                }
                if let right = treeNote?.right {
                    list.append(right)
                }
            }
            print("\n")
        }
    }
    
    func maxProfit(nums: [Int]) -> Int {
        var pre: Int = nums[0]
        var res: Int = 0
        nums.forEach { x in
            pre = min(x, pre)
            res = max(res, x - pre)
        }
        return res
    }
    
    func printDsTreeNote(treeNote: TreeNode? = nil) {
        guard let treeNote = treeNote else {
            return
        }
        print("\(treeNote.val)")
        if let left = treeNote.left {
            printDsTreeNote(treeNote: left)
        }
        if let right = treeNote.right {
            printDsTreeNote(treeNote: right)
        }
    }
    
    func reverseKGroup(_ head: ListNode?, _ k: Int) -> ListNode? {
        var header: ListNode? = head
        let dummy: ListNode = ListNode(0)
        dummy.next = head
        var pre: ListNode? = dummy
        while header != nil {
            var tail: ListNode? = pre
            for _ in 0..<k {
                tail = tail?.next
                if tail == nil {
                    return dummy.next
                }
            }
            let next: ListNode? = tail?.next
            let (h1, t1) = reverseKGroup(header, tail)
            pre?.next = h1
            t1?.next = next
            pre = t1
            header = t1?.next
        }
        return dummy
    }
    
    func reverseKGroup(_ head: ListNode?, _ tail: ListNode?) -> (ListNode?, ListNode?){
        var pre = tail?.next
        var node = head
        while pre !== tail {
            let next = node?.next
            node?.next = pre
            pre = node
            node = next
        }
        return (tail, head)
    }
    
    func method1()  {
        var local = NSLock()
        var i = 0
        local.lock()
        i += 1
        print("-------------\(i) current\(Thread.current)")
        local.unlock()
    }
    
    func GCDStack() {
        for _ in  1...200 {
            DispatchQueue.global().async {
                self.method1()
            }
        }
    }

    func twoSum(nums: [Int], target: Int) -> (Int, Int) {
        var dic: [Int : Any] = [:]
        for (index, num) in  nums.enumerated() {
            if let a = dic[target - num] as? Int {
                return (a, index)
            }
            dic[num] = index
        }
        return  (0,0)
    }
    
    func lengthOfLongestSubstring(string: String) -> Int {
        let occ = NSMutableSet()
        let stingCount: Int = string.count
        var k: Int = -1
        var ant = 0
        let strings: [Character] = string.map({$0})
        for index in 0..<stingCount {
            if index != 0 {
                occ.remove(strings[index])
            } else {
                while k + 1 < stingCount && !occ.contains(strings[k + 1]) {
                    occ.add(strings[k + 1])
                    k += 1
                }
            }
            ant = max(ant, k - index + 1)
        }
        return ant
    }
    
    func rootView(view: UIView?, tag: Int) -> UIView? {
        guard let rootView  = view else {
            return nil
        }
        
        if rootView.tag == tag {
            return rootView
        }
        var quene: [UIView] = []
        quene.append(rootView)
        while !quene.isEmpty {
            let viewCount = quene.count
            for _ in  1...viewCount {
                if let topView: UIView = quene.first {
                    if topView.tag == tag {
                        return topView
                    } else {
                        topView.subviews.forEach({quene.append($0)})
                        quene.removeFirst()
                    }
                }
            }
        }
        return nil
    }
    
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var tail = m + n - 1
        var p1  = m - 1
        var p2  = n - 1
        var curr: Int = 0
        while p1 >= 0 && p2 >= 0 {
            if nums1[p1] < nums2[p2] {
                curr = nums2[p2]
                p2 -= 1
            } else {
                curr = nums1[p1]
                p1 -= 1
            }
            nums1[tail] = curr
            tail -= 1
        }
        while p2 >= 0 {
            nums1[tail] = nums2[p2]
            p2 -= 1
            tail -= 1
        }
    }
    
    func feibonaqie(n: Int) -> Int {
        var dp: [Int] = [1,1]
        for index in 2..<n {
            let sum = dp[index - 1] + dp[index - 2]
            dp.append(sum)
        }
        return dp.last ?? 0 as Int
        
    }
    
    func trap(_ height: [Int]) -> Int {
        var stack: [Int] = []
        var res: Int = 0
        for index in 0..<height.count {
            while !stack.isEmpty && height[index] > height[stack.last ?? 0] {
                let top: Int = (stack.last ?? 0) as  Int
                stack.removeLast()
                if stack.isEmpty {
                    break
                }
                let left: Int = stack.last ?? 0
                let currWidth = index - left - 1
                let currHeight = min(height[top],  height[index] - height[top])
                res += currHeight * currWidth
            }
            stack.append(index)
        }
        return res
    }
    
    func search(_ nums: [Int], _ target: Int) -> Int {
        var index: Int = -1
        let length: Int = nums.count
        let first: Int = nums.first ?? 0
        var left: Int = 0
        var right: Int = length - 1
        while left <= right {
            let mid: Int = (left + right) / 2
            let midNum = nums[mid]
            if midNum == target {
                return mid
            }
            if first <= midNum {
                if first <= target &&  target <= midNum {
                    right = mid - 1
                } else {
                    left = mid + 1
                }
            } else {
                if midNum < target && target <= nums[length - 1] {
                    left = mid + 1
                } else {
                    right = mid - 1
                }
                
            }
        }
        return index
    }
    
    func findMedianSortedArrays(_ nums1: [Int], _ nums2: [Int]) -> Double {
        if nums1.count > nums2.count {
            return findMedianSortedArrays(nums1, nums2)
        }
        let n: Int =  nums1.count
        let m: Int =  nums2.count
        var left: Int = 0
        var right: Int = m
        
        var med1: Int = 0 // 前一部分最大
        var med2: Int = 0 // 后一部分最小
        
        while left < right {
            let i: Int = (left + right) / 2
            let j: Int = (m + n + 1) / 2 - i
            let num1_min: Int = i == 0 ? Int.min : nums1[i-1]
            let num1_max: Int = i == m ? Int.max : nums1[i]
            
            let num2_min: Int = j == 0 ? Int.min : nums2[j-1]
            let num2_max: Int = j == n ? Int.max : nums2[j]
            
            if num1_min <= num2_max {
                left = i +  1
                med1 = max(num1_min, num2_min)
                med2 = min(num1_max, num2_max)
            } else {
                right = i - 1
            }
        }
        // num1 [0..i-1]       num2[0...j-1]
        // num1 [i..m-1]       num2[j..n-1]
        if (n + m) % 2 == 0 {
            return Double((med1 + med2)) / 2.0
        }
        return Double(med1)
    }
    
    func maxSubArray(_ nums: [Int]) -> Int {
        var sum: Int = nums[0]
        var pre: Int = 0
        nums.forEach { x in
            pre = max(pre + x, x)
            sum = max(sum, pre)
            
        }
        return sum
    }
    
    func threeSum(_ nums: [Int]) -> [[Int]] {
        guard nums.count >= 3 else {
            return []
        }
        var count: Int = nums.count
        var ret: [[Int]] = []
        for (i, num) in nums.enumerated() {
            var firt = num
            var target = -num
            for j in i..<count - 1 {
                
            }
        }
        return ret
    }
    
    func myAtoi(_ str: String) -> Int {
        //！ 开始录入有效字符的起点
        var start = false
        //! 寻找start
        var returnStr = ""
        //!
        for ch in str {
            if !start {
                if (ch.isNumber || ch == "-" || ch == "+") {
                    start = true
                    returnStr.append(ch)
                } else if ch == " " {
                    continue;
                } else {
                    return 0
                }
                
            } else {
                if ch.isNumber {
                    returnStr.append(ch)
                } else {
                    break
                }
            }
        }
        
        //! 如果没有录入，或者 只录入了符号， 则直接返回
        if start == false || returnStr=="+" || returnStr == "-"{
            return 0
        }
        //! 开始转换
        let finalInt = Int32(returnStr)
        guard finalInt != nil else {
            return returnStr.first == "-" ? Int(Int32.min) : Int(Int32.max)
        }
        return Int(finalInt!)
    }
    
    func longsub(nums: [Int]) -> Int {
        var dp: [Int] = []
        dp = nums.compactMap({ _ in return 0})
        var maxans: Int = 0
        dp [0] = 1
        for i in 0..<nums.count {
            dp [0] = 1
            for j in 0..<nums.count {
                if nums[j] > dp[i] {
                    dp [i] = max(dp[i], dp[j + 1])
                }
            }
            maxans = max(maxans, dp[i])
        }
        return dp.last ?? 0
    }
    
    func lowestCommonAncestor(_ root: TreeNode?, _ p: TreeNode?, _ q: TreeNode?) ->  TreeNode? {
        if root == nil || p === root || root === q  {
            return root
        }
        let left = lowestCommonAncestor(root?.left, p, q)
        let right = lowestCommonAncestor(root?.right, p, q)
        
        if left != nil && right != nil {
            return  root
        }
        if left != nil {
            return right
        }
        if right != nil {
            return left
        }
        return nil
    }
    

    func auoChange(_ s: String) -> Int {
        var ret: Int = 0
        let auto = Automaton()
        for ch in s {
            auto.get(ch)
        }
        if auto.sign == -1 && auto.ans < Int.max {
            return Int(Int32.min)
        } else if auto.sign == 1 && auto.ans > Int.max {
            return  Int(Int32.max)
        }
        ret = auto.sign * auto.ans
        return ret
    }
    
    func postorder(root: TreeNode?, notes: inout [Int])  {
        guard let root = root else {
            return
        }
        postorder(root: root.left, notes: &notes)
        postorder(root: root.right, notes: &notes)
        notes.append(root.val)
    }
    
    func postorderBSF(root: TreeNode?, notes: inout [Int]) {
        var root = root
        if root == nil {
            return
        }
        
        var stack: [TreeNode] = []
        stack.append(root!)
        var pre: TreeNode?
        while !stack.isEmpty, root != nil {
            while root != nil {
                stack.append(root!)
                root = root?.left
            }
            if let top = stack.last {
                if top.right == nil || root?.right === pre   {
                    notes.append(root!.val)
                    pre = root
                } else {
                    stack.append(root!)
                    root = root?.right
                }
                stack.removeLast()
            }
        }
    }
    
    func mergeTwoLists(a: ListNode?,b: ListNode?) -> ListNode? {
        if a == nil {
            return b
        }
        if b == nil {
            return a
        }
        var a = a
        var b = b
        var header: ListNode?
        var tail:ListNode?
        header =  tail
        while a != nil && b != nil {
            if a!.val < b!.val {
                tail?.next = a
                a = a?.next
            } else {
                tail?.next = b
                b = b?.next
            }
            tail = tail?.next
        }
        tail?.next = a != nil ? a : b
        
        return header
    }
    
    func merge(notes:[ListNode], left: Int, right: Int) -> ListNode? {
        if left == right {
            return notes[left]
        }
        if left > right {
            return nil
        }
        let mid = (left + right) / 2
        let leftNote = merge(notes: notes, left: left, right: mid)
        let rightNote = merge(notes: notes, left: mid + 1, right: right)
        return mergeTwoLists(a: leftNote, b: rightNote)
    }
    
    func reverse(x: Int) -> Int {
        var x: Int = x
        var res: Int = 0
        while x != 0 {
            if res > Int.max / 10 || res < Int.min / 10 {
                fatalError("越界了。。。。")
            }
            let digit = x % 10
            x = x / 10
            res = res * 10 + digit
        }
        return res
    }
    
    func swipList(head: ListNode?) -> ListNode? {
        if head == nil  ||  head?.next == nil {
            return head
        }
        let newNote = head?.next
        head?.next = swipList(head:newNote?.next)
        newNote?.next = head
        return newNote
    }
}

class Automaton {
    init() {
    }
    var sign: Int = 1
    var ans: Int = 0
    var state = "start"
    var table: [String: [String]] = ["start": ["start","sign", "number", "end"],
                                     "sign": ["end", "sign","number","end"],
                                     "number" : ["end", "end", "number", "end"],
                                     "end" : ["end","end","end","end"]
    ]
    
    func get(_ ch: Character) {
        let typeIndex: Int = getColum(ch)
        if let stateA: [String] = table[state] {
            let state1 = stateA[typeIndex]
            state = state1
            if state1 == "number" {
                if ans > Int.max || ans < Int.min {
                    state = "end"
                    return
                }
            }
            ans = ans * 10 + (Int(String(ch)) ?? 0)
        } else if state == "sign" {
            sign = ch == "+" ? 1 : -1
        }
    }
    
    func getColum(_ ch: Character) -> Int {
        if ch == " " {
            return 0
        } else if  ch == "-" || ch == "+" {
            return 1
        } else if ch.isNumber {
            return 2
        } else {
            return 3
        }
    }
}

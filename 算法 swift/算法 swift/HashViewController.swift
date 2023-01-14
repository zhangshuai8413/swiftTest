//
//  HashViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/8.
//

import UIKit

class HashViewController: BaseTableViewController {

    enum Constant {
        static let 异位词 = "异位词"
        static let  查找常用字符 = "查找常用字符"
        static let 翻转字符串 = "翻转字符串"
        static let reverse2K = "2K 翻转字符串"
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.textViewCompletionBlock = { [weak self ]text in
            guard let strongSelf = self else { return }
            strongSelf.inputText = text
            
        }
        dataSource =  [Constant.异位词, Constant.查找常用字符,Constant.翻转字符串, Constant.reverse2K]
        self.compleBlock = { [weak self ]title, _ in
            guard let strongSelf = self else { return }
            strongSelf.didSelected(title: title)
        }
      
    }
    
    
    override func didSelected(title: String)  {
        
        switch title {
        case Constant.异位词:
            isAnagram()
        case Constant.查找常用字符:
            commonChars()
        case Constant.翻转字符串:
            reverseStrs()
        case  Constant.reverse2K:
            reverseStringK()
        default:
            break
        }
    }
    
    func reverse(_ s: inout [Character], start: Int, end: Int)  {
        if start >= end {
            return
        }
        var start = start
        var end = end
        while start < end {
            s.swapAt(start, end)
            start += 1
            end -= 1
        }
    }
    
    func reverseStringK() {
        let k: Int = 2
        let str1: String = inputText
        var str1Character: [Character] = Array(str1)
        var i: Int = 0
        let n: Int = str1.count - 1
        while  i < n {
            if (i + k <= n) {
                let end: Int = i + k - 1
                reverse(&str1Character, start: i, end: end)
                i += 2 * k
            } else {
                reverse(&str1Character, start: i, end: n)
            }
            i += 2 * k
        }
        print("str1Character----\(str1Character)")
    }
    
    func reverseStrs() {
        //        编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
        //        不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
        //        你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
        //        示例 1：
        //        输入：["h","e","l","l","o"]
        //        输出：["o","l","l","e","h"]
        //
        //        示例 2：
        //        输入：["H","a","n","n","a","h"]
        //        输出：["h","a","n","n","a","H"]
        var str1 = ["h","e","l","l","o"]
        print("reverseStrs----start------\(str1)")
        var left: Int = 0
        var right: Int = str1.count - 1
        while left < right {
            str1.swapAt(left, right)
            left += 1
            right -= 1
        }
        print("reverseStrs---end----\(str1)")
    }
    
    func commonChars() {
        //        words = ["bella","label","roller"] 输出：["e","l","l"]
        //        示例 2： 输入：words = ["cool","lock","cook"] 输出：["c","o"]
        var res = [String]()
//        let words: [String] = ["bella","label","roller"]
        let words: [String] = ["cppllllldl","llllllock","cooklttllllsso"]
        
        let first: String = words.first ?? ""
        let lettersMaxCount: Int = 26
        var hashArray: [Int] = Array(repeating: 0, count: lettersMaxCount)
        let aUnicodeScalarValue = "a".unicodeScalars.first!.value
        for ch in first.unicodeScalars {
            hashArray[Int(ch.value - aUnicodeScalarValue)] += 1
        }
        for i in (1..<words.count) {
            var otherHash = Array(repeating: 0, count: lettersMaxCount)
            let word: String = words[i]
            for ch in word.unicodeScalars {
                otherHash[Int(ch.value - aUnicodeScalarValue)] += 1
            }
            // 更新hash,保证hash里统计的字母为出现的最小频率
            for k in 0..<lettersMaxCount {
                hashArray[k] = min(hashArray[k], otherHash[k])
            }
        }
        
        for i in 0..<lettersMaxCount {
            while hashArray[i] != 0 {
                print("i---\(i)---\(hashArray[i])\n")
                let currentUnicodeScalarValue: UInt32 = UInt32(i) + aUnicodeScalarValue
                let currentUnicodeScalar: UnicodeScalar = UnicodeScalar(currentUnicodeScalarValue)!
                let outputStr = String(currentUnicodeScalar) // UnicodeScalar -> String
                res.append(outputStr)
                hashArray[i] -= 1
            }
        }
        print("\n----\(res)----")
    }
    
    
    func isAnagram() {
        let s = "abcde"
        let t = "cadbe"
        let isanagram = isAnagram(s, t)
        print("isanagram----\(isanagram)")
    }
    
    func isAnagram(_ s: String, _ t: String) -> Bool {
        if s.count  != t.count {
            return false
        }
        var isAnagram: Bool = true
        var dict1: [Character: Int] = [:]
        for ch in s {
            dict1[ch, default: 0] += 1
        }
        for ch in t {
            dict1[ch, default: 0] -= 1
        }
        for (_, value) in dict1 {
            if value != 0 {
                isAnagram = false
                break
            }
        }
        return isAnagram
    }
}

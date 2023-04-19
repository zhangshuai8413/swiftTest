//
//  StringViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/8.
//

import UIKit

class StringViewController: BaseTableViewController {

    enum Constant {
        static let replaceEmptyString = "替换空格"
        static let reverseString = "翻转文字"
        static let reverseLeftString = "左转文字"
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        dataSource = [Constant.replaceEmptyString, Constant.reverseString, Constant.reverseLeftString]
    }
    
    
    override func didSelected(title: String) {
        switch title {
        case Constant.replaceEmptyString:
            replaceEmptyStringW()
        case Constant.reverseString:
            reverseWords()
        case Constant.reverseLeftString:
            reverseLeftWords()
        default:
            break
        }
    }
    
    func replaceEmptyStringW()  {
//        请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
//        示例 1： 输入：s = "We are happy."
//        输出："We%20are%20happy."
        


    }

    
    func reverseWords() {
        //        给定一个字符串，逐个翻转字符串中的每个单词。
        //
        //        示例 1：
        //        输入: "the sky is blue"
        //        输出: "blue is sky the"
        //
        //        示例 2：
        //        输入: "  hello world!  "
        //        输出: "world! hello"
        print(inputText)
        let ww = reverseWords(words: inputText)
        print(ww?.trimmingCharacters(in: .alphanumerics))
        func reverseWords(words: String?) -> String? {
            guard var  words = words else {
                return nil
            }
            var characters: [Character] = Array(words)
            var left: Int = 0
            var right: Int = words.count - 1
            while left < right {
                characters.swapAt(left, right)
                left += 1
                right -= 1
            }
            var start: Int = 0
            var end: Int = 0
            var entry: Bool = false
            for i in 0..<characters.count  {
                if !entry  {
                    start = i
                    entry = true
                }
                if entry && (characters[i] == " " && characters[i - 1] != " ") {
                    end = i - 1
                    entry = false
                    reverseStrings(&characters, left: start, right: end)
                }
                if entry && (i == characters.count - 1 && characters[i] != " ") {
                    end = i
                    entry = false
                    reverseStrings(&characters, left: start, right: end)
                }
            }
            return String(characters)
        }
    }
    
    func reverseStrings(_ characters: inout [Character], left: Int, right: Int) {
        var left = left
        var right = right
        while left < right {
            characters.swapAt(left, right)
            left += 1
            right -= 1
        }
    }
    
    func reverseLeftWords()  {
        //            输入: s = "abcdefg", k = 2
        //    输出: "cdefgab"
        let input = inputText
        print("input--\(input)")
        let sss = reverseLeftWords(words: input  , k: 2)
  
        print(sss)
        
    }
    
    func reverseLeftWords(words: String, k: Int) -> String {
        var characters: [Character] = Array(words)
        reverseStrings(&characters, left: 0, right: k - 1)
        reverseStrings(&characters, left: k, right:characters.count - 1)
        reverseStrings(&characters, left: 0, right: characters.count - 1)
        
        return String(characters)
    }
    
    func repeatedSubstringPattern(_ s: String) -> Bool {
        if s.count <= 1 { return false }
        var result = s + s;
//        result = String(result[result.index(result.startIndex, offsetBy: 1)..<result.index(result.endIndex, offsetBy: -1)])
//        return result.contains(s)
        result = String(result[result.index(result.startIndex,offsetBy: 1)..<result.index(result.endIndex, offsetBy: -1)])
        return result.contains(s)
    }
    
  
    
    func multiply(_ num1: String, _ num2: String) -> String {
        if num1 == "0" || num2 == "0" {
            return "0"
        }
        let len1: Int = num1.count
        let len2: Int = num2.count
        let nums1: [Int] = num1.compactMap({ Int(String($0))})
        let nums2: [Int] = num2.compactMap({ Int(String($0))})
        var result: String = ""
        var nums: [Int] = [Int](repeating: 0, count: len1 + len2)
        for (i, num1) in nums1.enumerated().reversed() {
            for (j, num2) in nums2.enumerated().reversed() {
                let index: Int =  i + j + 1
                let value: Int = nums[index]
                let sum: Int = num1 * num2 + value
                nums[index] = sum % 10
                nums[index - 1] += sum / 10
            }
        }
        if nums.first == 0 {
            nums.removeFirst()
        }
        result = nums.map({"\(String($0))" }).joined()
        return result
    }
    
    func add(_ num1: String?, _ num2: String?) -> String? {
        if num1 == nil {
            return num2
        }
        if num2 == nil {
            return num1
        }
        var result: String? = ""
        let nums1: [Int] = num1?.compactMap({ Int(String($0))}) ?? []
        let nums2: [Int] = num2?.compactMap({ Int(String($0))}) ?? []

        var len1: Int = nums1.count
        var len2: Int = nums2.count
        
        var nums: [Int] = []
        var carry: Int = 0
        while len2 > 0 || len1 > 0 || carry != 0 {
            let a: Int = (len1 >= 0) ? nums1[len1 - 1] : 0
            let b: Int = (len2 >= 0) ? nums2[len2 - 1] : 0
            let sum: Int = a + b + carry
            carry = sum / 10
            nums.append(sum % 10)
            len2 -= 1
            len1 -= 1
        }
        
        result = nums.reversed().map({"\(String($0))"}).joined()
        return result
    }

}

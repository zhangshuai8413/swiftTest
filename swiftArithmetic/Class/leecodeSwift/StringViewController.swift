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
    
    
    func letterCombinations(_ digits: String) -> [String] {
        let mapping: [String: String] = [
            "1": "a", "2": "b", "3": "c", "4": "d", "5": "e",
            "6": "f", "7": "g", "8": "h", "9": "i", "10": "j",
            "11": "k", "12": "l", "13": "m", "14": "n", "15": "o",
            "16": "p", "17": "q", "18": "r", "19": "s", "20": "t",
            "21": "u", "22": "v", "23": "w", "24": "x", "25": "y", "26": "z"
        ]
        
        var combinations: [String] = []
        
        func generateCombinations(_ currentCombination: String, _ remainingDigits: String) {
            if remainingDigits.isEmpty {
                combinations.append(currentCombination)
                return
            }
            
            let firstDigit = remainingDigits.first!
            let remainingDigitsWithoutFirst = String(remainingDigits.dropFirst())
            
            if let letters = mapping[String(firstDigit)] {
                for letter in letters {
                    generateCombinations(currentCombination + String(letter), remainingDigitsWithoutFirst)
                }
            }
        }
        
        generateCombinations("", digits)
        
        return combinations
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
    
    
    /*
     224. 基本计算器
     困难
     950
     相关企业
     给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

     注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

      

     示例 1：

     输入：s = "1 + 1"
     输出：2
     示例 2：

     输入：s = " 2-1 + 2 "
     输出：3
     示例 3：

     输入：s = "(1+(4+5+2)-3)+(6+8)"
     输出：23
      
     */
    func calculate(_ s: String) -> Int {
        var stack: [Int] = []
        var result = 0
        var num = 0
        var sign = 1

        for char in s {
            if char.isNumber {
                num = num * 10 + Int(String(char))!
            } else if "+-".contains(char) {
                result += sign * num
                num = 0
                sign = char == "+" ? 1 : -1
            } else if char == "(" {
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1
            } else if char == ")" {
                result += sign * num
                num = 0
                result *= stack.popLast()!
                result += stack.popLast()!
            }
        }

        result += sign * num
        return result
    }

}

/*
 
 let number = 1234567
 let formattedNumber = formatNumber(number: number)
 print(formattedNumber) //

 */
func formatNumber(number: Int) -> String {
    let numberFormatter = NumberFormatter()
    numberFormatter.numberStyle = .decimal
    return numberFormatter.string(from: NSNumber(value: number)) ?? ""
}


func formatNumberToThousands(_ number: Int) -> String {
    var numberString = String(number)
    var result = ""
    
    while numberString.count > 3 {
        let index = numberString.index(numberString.endIndex, offsetBy: -3)
        let subString = numberString[index...]
        result = "," + subString + result
        numberString = String(numberString[..<index])
    }
    
    result = numberString + result
    return result
}

/*
 
 let input = "apple banana apple cherry banana apple"
 if let result = findMostFrequentString(input: input) {
     print(result) // 输出：apple
 }
 */

func findMostFrequentString(input: String) -> String? {
    var frequencyDict: [String: Int] = [:]
    var firstOccurrenceDict: [String: Int] = [:]
    
    let words = input.components(separatedBy: " ")
    
    for (index, word) in words.enumerated() {
        frequencyDict[word, default: 0] += 1
        
        if firstOccurrenceDict[word] == nil {
            firstOccurrenceDict[word] = index
        }
    }
    
    let mostFrequentWord = frequencyDict.max { $0.value < $1.value }
    var result: String?
    
    if let word = mostFrequentWord {
        var minIndex = firstOccurrenceDict[word.key] ?? 0
        let maxIndex = firstOccurrenceDict[word.key] ?? 0
        
        for (key, value) in firstOccurrenceDict {
            if frequencyDict[key] == word.value && value < minIndex {
                minIndex = value
                result = key
            }
        }
    }
    
    return result
}

func getString() {
    
}

func getString1() {
    
}

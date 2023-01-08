//
//  HashViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/8.
//

import UIKit

class HashViewController: BaseTableViewController {


    override func viewDidLoad() {
        super.viewDidLoad()
         dataSource = ["异位词","查找常用字符"]
        self.compleBlock = { [weak self ]title, _ in
            guard let strongSelf = self else { return }
            strongSelf.didSelected(title: title)
        }
      
    }
    
    
    func didSelected(title: String)  {
        if title == "异位词" {
            isAnagram()
        } else if title == "查找常用字符" {
            commonChars()
        }
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
        print("isanagram\(isanagram)")
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

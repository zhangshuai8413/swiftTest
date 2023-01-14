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
     
    }
    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        dataSource = [Constant.replaceEmptyString, Constant.reverseString]
 
    }
    
    
    override func didSelected(title: String) {
        switch title {
        case Constant.replaceEmptyString:
            replaceEmptyStringW()
        case Constant.reverseString:
            reverseWords()
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
        print(ww)
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
                if  entry && (characters[i] == " "  && characters[i - 1] != " ") {
                    end = i - 1
                    entry = false
                    reverseStrings(characters: &characters, left: start, right: end)
               
                }
                if entry && (i == characters.count - 1 && characters[i] != " ") {
                    end = i
                    entry = false
                    reverseStrings(characters: &characters, left: start, right: end)
                }
                
            }
            return String(characters)
        }
        
        func reverseStrings(characters: inout [Character], left: Int, right: Int) {
            var left = left
            var right = right
            while left < right {
                characters.swapAt(left, right)
                left += 1
                right -= 1
            }
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

}

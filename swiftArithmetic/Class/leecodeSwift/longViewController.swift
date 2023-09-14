//
//  longViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/2/18.
//

import UIKit

class longViewController: BaseTableViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Do any additional setup after loading the view.
    }
    
    //评测题目:
    //现有一个英文词库，要求给定一个输入，返回词库中与这个输入最相似的词，不要求语义相似。
    //词库：abstract、default、goto、null、switch、boolean、do、if、package、synchronzed、break、double、implements、private、this、byte、else、import、protected、throw、case、extends、instanceof、public、transient、catch、false、int、return、true、char、final、interface、short、try、class、finally、long、static、void、float、native、volatile、continue、for、new、super、while、assert、enum
    //相似：公共子串最长的（按顺序连续匹配最多字符）
    
    //示例输入：swatch
    //示例输出：catch
    
    //示例输入：swtch
    //示例输出：catch, switch
    
    
    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        let strings: String = "abstract、default、goto、null、switch、boolean、do、if、package、synchronzed、break、double、implements、private、this、byte、else、import、protected、throw、case、extends、instanceof、public、transient、catch、false、int、return、true、char、final、interface、short、try、class、finally、long、static、void、float、native、volatile、continue、for、new、super、while、assert、enum"
        let target = "swatch"
        let res: [String] = searchCommonLogetSubstring(target: target, source: strings)
        print("target----\(target)\n res----------\(res)")
        
    }
    
    func searchCommonLogetSubstring(target: String, source: String) -> [String] {
        let words: [String] = source.components(separatedBy: "、")
        guard !words.isEmpty || !target.isEmpty else {
            return []
        }
        return searchCommonPrefix(strs: words, target: target)
    }
    
    func searchCommonPrefix(strs:[String], target: String) -> [String] {
        var res: [String] = []
        // filter // 具备相同的 字符的，没有交集直接过滤掉 减少计算
        let targeSet: NSMutableSet = NSMutableSet(array: Array(target))
        var longest: Int = 0
        let filtterStrs: [String] = strs.filter { str1 in
            let set1: NSMutableSet = NSMutableSet(array: Array(str1))
            set1.intersect(targeSet as! Set<AnyHashable>)
            if set1.count >= longest {
                longest = set1.count
                return true
            }
            return false
        }
        var longestLength: Int = Int.min
        filtterStrs.forEach { str in
            if str.count > longestLength {
                let commonLen = longestCommonSubString(string1: target, string2: str)
                if commonLen > longestLength {
                    res = [str]
                    longestLength = commonLen
                } else if commonLen == longestLength {
                    res.append(str)
                }
            }
        }
        return res
    }
    
    
  private func longestCommonSubString(string1: String, string2: String) -> Int {
        let str1: [Character] = Array(string1)
        let str2: [Character] = Array(string2)
        let m: Int = str1.count
        let n: Int = str2.count
        var maxLenght: Int = 0
        var dp:[[Int]] = [[Int]](repeating: Array(repeating: 0, count: n + 1), count: m + 1)
        for i in 0..<m {
            for j in 0..<n {
                if str1[i] ==  str2[j] {
                    if i >= 1 && j >= 1 {
                        dp[i][j] = dp[i - 1][j - 1] + 1
                    } else {
                        dp[i][j] = 1
                    }
                }
                maxLenght = max(maxLenght, dp[i][j])
            }
        }
        return maxLenght
    }
}



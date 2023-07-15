//
//  DynamicPlanningViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/8.
//

import UIKit

class DynamicPlanningViewController: BaseTableViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    func combinationSum4(nums: [Int], target: Int) -> Int {
        var dp:[Int] = [Int].init(repeating: 0, count: target + 1)

        for (i, tar) in (0...target).enumerated() {
            for(j, num) in nums.enumerated() {
                if tar - num >= 0 && dp[i] < Int.max - dp[i - num]  {
                    dp[i] += dp[i - num]
                }
            }
        }
        return dp[target];
    }
}

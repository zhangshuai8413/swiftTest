//
//  GreedViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/8.
//

import UIKit

class GreedViewController: BaseTableViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()

    }
    
    func maxproxt(prices:[Int]) -> Int {
        let n = prices.count
        var dp:[[Int]] = Array(repeating: Array(repeating: 0, count: 2), count: n)

        dp[0][0] = -prices[0]
        for(i, price)  in prices.enumerated() {
            dp[i][0] = max(dp[i - 1][1], dp[i-1][0] + price)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] - price)
        }
        return max(dp[n - 1][0], dp[n - 1][1 ])
        
    }
}

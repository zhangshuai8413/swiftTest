//
//  ContentView.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/5/21.
//

import SwiftUI


struct ContentView: View {
    var body: some View {
        VStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundColor(.accentColor)
           
            Button("max profit") {
               print("max  profit ")
                
        
            }
        }
        .padding()
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

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

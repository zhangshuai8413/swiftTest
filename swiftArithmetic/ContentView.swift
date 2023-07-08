//
//  ContentView.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/5/21.
//

import SwiftUI

struct Item: Identifiable {
    var id: DynamicProgram
    var title: String
    
}
enum DynamicProgram: Int {
    case weight01 = 1
    case weight01Array1
    case targetSum

}

struct ContentView: View {
    
    var dataSources: [Item] = [Item(id: .weight01, title: "01背包"),
                               Item(id: .weight01Array1, title: "01背包一维数组"),
                               Item(id: .targetSum, title: "sum of target"),
                               
    ]
    var body: some View {
        VStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundColor(.accentColor)
            List(dataSources) { item in
                    HStack{
                        Text(item.title)
                    }.onTapGesture {
                        addOCBrige(index: item.id)
                    }
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
    
    func addOCBrige(index: DynamicProgram) {
        print("addOCBrie  \(index) \n")
        let ocBrige = BrideCPlusManger()
        switch index {
        case .weight01:
            ocBrige.wei_bag_problem1()
        case .weight01Array1:
            ocBrige.test_1_wei_bag_problem()
        case .targetSum:
            ocBrige.targetSum()
        }
    
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}

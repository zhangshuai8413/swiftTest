//
//  FLMe.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/8.
//

import SwiftUI

struct FLMeViewController: View {
     
    var body: some View {
//
        Text("单价").font(.headline)
            .bold()
            .padding(100)
            .italic()
        UIKitView()
    }
}

func test1() {
    
    let concurrentQueue = DispatchQueue(label: "com.example.concurrentQueue", attributes: .concurrent)
    let group = DispatchGroup()

    // 使用DispatchQueue异步执行任务，将任务添加到DispatchGroup
    concurrentQueue.async(group: group, execute: {
        testmethod()
    })
    
    concurrentQueue.async(group: group, execute: {
        testmethod()
    })
    group.notify(queue: concurrentQueue) {
        print("sharedVariable-----\(sharedVariable)")
    }
}

var sharedVariable: Int = 0

func testmethod()  {
    for _ in 0..<10 {
     sharedVariable += 1
    }
}


struct FLMe_Previews: PreviewProvider {
    static var previews: some View {
        FLMeViewController()
    }
}

//
//  Person.swift
//  算法 swift
//
//  Created by 张帅 on 2022/11/17.
//

import SwiftUI

class Person: NSObject {

}

extension Person {
    @objc
    func addName() {
//        print("Person")
        let nums: [Int] = [1,3,5,6,3]
        let sum = nums.reduce(0, {$0 + $1})
    }
}

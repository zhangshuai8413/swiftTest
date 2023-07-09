//
//  CoursePart.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/9.
//

import UIKit
import SwiftUI
class CoursePart: NSObject, Decodable {
    var doneNum: Int = 0
    var id: Int = 0
    var level: Int = 0
    var list:[CourseList] = []
    var title: String = ""
    var planNum: Int = 0
    
}

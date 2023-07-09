//
//  CourseList.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/9.
//

import UIKit
import SwiftUI
 
struct CourseList: Hashable, Decodable,Identifiable {

    var id: Int
    var doneNum: Int
    var level: Int
    var list: [Course]
    var liveTime: Int
    var planNum: Int
    var status: Int
    var title: String
    var subTitle: String
    
    
}

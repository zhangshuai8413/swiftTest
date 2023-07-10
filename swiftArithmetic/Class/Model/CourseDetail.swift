//
//  CourseDetail.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/9.
//

import Foundation
import SwiftUI

struct CourseDetail: Hashable, Decodable, Identifiable {
    var id: Int
    var articleId: Int?
    var title: String
    var url: String?
    
    
}

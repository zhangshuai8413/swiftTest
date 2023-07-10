//
//  Course.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/9.
//

import UIKit
import SwiftUI

struct Course: Hashable, Decodable, Identifiable {
    var articleId: Int?
    var id: Int
    var title: String
    var url: String?
    var type: Int?
    var list:[CourseDetail]? = []
    
}



//{"articleId":15764,"id":3116095,"isDemo":false,"level":3,"liveTime":0,"progressStatus":2,"status":2,"subTitle":"已过期","title":"Day 7文本精讲| How to Be Proactive （做事如何积极主动）","type":8,"url":"https://ke.study.163.com/topic/study/article/index.html?pid=15764&courseId=61213&lessonId=3116095","validTime":1596988800000}

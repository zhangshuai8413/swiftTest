//
//  FLCourseDetailView.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/9.
//

import SwiftUI

struct FLCourseDetailView: View {
    
    var course: Course
    var body: some View {
        List {
            ForEach(course.list ?? [], id: \.id) { courseDetail in
                Text(courseDetail.title)
            }
        }
        
    }
}

//struct FLCourseDetailView_Previews: PreviewProvider {
//    static var previews: some View {
//        
//        let course: Course = Course(from: <#Decoder#>)
//        FLCourseDetailView(course: course)
//    }
//}

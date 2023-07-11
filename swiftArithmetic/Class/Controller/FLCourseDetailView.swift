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
                
                if let url = courseDetail.url {
                    Link(courseDetail.title, destination: URL(string: url)!)
                   
                    HStack {
                        Text(url)
                            .textSelection(.enabled)
                    }
                }
                
                NavigationLink {
                    WebView(url: URL(string: courseDetail.url ?? "https://www.baidu.com/")!)

                } label: {
                    
                    Text(courseDetail.title)
                    
                }

               
            }
            
        }.navigationTitle(course.title)
            .navigationBarTitleDisplayMode(.inline)
        
    }
}

//struct FLCourseDetailView_Previews: PreviewProvider {
//    static var previews: some View {
//        
//        let course: Course = Course(from: <#Decoder#>)
//        FLCourseDetailView(course: course)
//    }
//}

//
//  FLHomeViewController.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/8.
//

import SwiftUI

struct FLHomeViewController: View {
    var body: some View {
        
        NavigationView {
            List {
                ForEach(coursePart, id: \.title) { sectionCourse in
                    Section {
                        HStack {
                            Text(sectionCourse.title)
                            Text(sectionCourse.subTitle)
                        }
                        ForEach(sectionCourse.list) { course in
                            NavigationLink {
                                FLCourseDetailView(course: course)
                            } label: {
                                Label(course.title, systemImage: "folder")
                            }

                            
                        }
                    }
                    
                }
            }.navigationTitle("Youdao 精品课")
            
        }
    }

    
    func jumpWebView(urlString: String?) -> some View {
        let url = (urlString != nil) ? urlString! : ""
        print("jumpWebView url \(url)")
        let webView = WebView(url: URL(string: url) ?? URL(fileURLWithPath: "abc"))
        return webView
    }
}

struct FLHomeViewController_Previews: PreviewProvider {
    static var previews: some View {
        FLHomeViewController()
    }
}

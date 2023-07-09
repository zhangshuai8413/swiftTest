//
//  FLHomeViewController.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/8.
//

import SwiftUI

struct FLHomeViewController: View {
    var body: some View {
        List {
            
            ForEach(coursePart, id: \.title) { sectionCourse in
                Section {
                    HStack {
                        Text(sectionCourse.title)
                        Text(sectionCourse.subTitle)
                    }
                    ForEach(sectionCourse.list) { course in
                        HStack {
                            Text(course.title)
                        }
                    }
                  
                }

            }
        }.navigationTitle("Youdao 精品课")
    }
}

struct FLHomeViewController_Previews: PreviewProvider {
    static var previews: some View {
        FLHomeViewController()
    }
}

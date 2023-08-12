//
//  ContentView.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/5/21.
//

import SwiftUI
import ObjectiveC.runtime

struct Item: Identifiable {
    var id: DynamicProgram
    var title: String
    
}
enum DynamicProgram: Int {
    case weight01 = 1
    case weight01Array1
    case targetSum
    case numberOfIsland
    case quikSort

}

struct LeetCodeListView: View {
    
    var dataSources: [Item] = [Item(id: .weight01, title: "01背包"),
                               Item(id: .weight01Array1, title: "01背包一维数组"),
                               Item(id: .targetSum, title: "sum of target"),
                               Item(id: .numberOfIsland, title: "岛屿数量"),
                               Item(id: .quikSort, title: "快速排序"),
                               
    ]
    var body: some View {
        VStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundColor(.accentColor)
            List(dataSources) { item in
                    HStack{
                        Text(item.title)
                    }.onTapGesture {
                        addOCBrige(index: item.id)
                    }
                }
        }
        .padding()
    }
    
 
    
    func addOCBrige(index: DynamicProgram) {
        
//        print("addOCBrie  \(index) \n")
        let ocBrige = BrideCPlusManger()
  
    
        switch index {
        case .weight01:
            ocBrige.wei_bag_problem1()
        case .weight01Array1:
            ocBrige.test_1_wei_bag_problem()
        case .targetSum:
            ocBrige.targetSum()
        case .numberOfIsland:
            ocBrige.numIslands()
        case .quikSort:
            ocBrige.quickSort()
        }

        
//        print("aa------\(aa)")
        
    }
    
    func getAllSwiftClasses() -> [String] {
        var classes = [String]()
        
        // 获取所有已注册的类
        let classCount = objc_getClassList(nil, 0)
        let classesBuffer = UnsafeMutablePointer<AnyClass>.allocate(capacity: Int(classCount))
        let autoreleasingClasses = AutoreleasingUnsafeMutablePointer<AnyClass>(classesBuffer)
        objc_getClassList(autoreleasingClasses, classCount)
        
        for i in 0..<Int(classCount) {
            // 判断类是否为Swift类
//            if class_isMetaClass(classesBuffer[i]) == true {
                let className = NSStringFromClass(classesBuffer[i])
                if className.hasPrefix("_TtC") { // 判断类名前缀是否为Swift类
                    classes.append(className)
                }
//            }
        }
        
        classesBuffer.deallocate()
        
        return classes
    }
}


struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        LeetCodeListView()
    }
}

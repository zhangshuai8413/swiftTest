//
//  TarBarViewController.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/8.
//

import SwiftUI

struct TarBarViewController: View {
    @State private var selectedTabIndex = 0
    
    var body: some View {
        TabView(selection: $selectedTabIndex) {
          FLHomeViewController()
            .tag(0) // 3
            .tabItem {
                Label("Home", systemImage: "house")
            }

            LeetCodeListView()
            .tag(1)
            
            .tabItem {
                Label("leecode", systemImage: "magnifyingglass")
            }
            
           FLMeViewController()
            .tag(2)
            
            .tabItem {
                Label("me", systemImage: "bell")
            }
            
            FLSettingController()
            .tag(3)
            
            .tabItem {
                Label("Settings", systemImage: "gearshape")
            }
        }
    }
}


func test() {
    var tile = [1,2,3,4,5,6]
}
struct TarBarViewController_Previews: PreviewProvider {
    static var previews: some View {
        TarBarViewController()
    }
}

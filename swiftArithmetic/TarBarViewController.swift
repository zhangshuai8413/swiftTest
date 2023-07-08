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
            
            VStack {
                Text("Search")
                Button("0") {
                    selectedTabIndex = 0
                }
                Button("1") {
                    selectedTabIndex = 1
                }
                Button("2") {
                    selectedTabIndex = 2
                }
                Button("3") {
                    selectedTabIndex = 3
                }
            }
            .tag(1)
            
            .tabItem {
                Label("Search", systemImage: "magnifyingglass")
            }
            
            VStack {
                Text("Notification")
                Button("0") {
                    selectedTabIndex = 0
                }
                Button("1") {
                    selectedTabIndex = 1
                }
                Button("2") {
                    selectedTabIndex = 2
                }
                Button("3") {
                    selectedTabIndex = 3
                }
            }
            .tag(2)
            
            .tabItem {
                Label("Notification", systemImage: "bell")
            }
            
            VStack {
                Text("Settings")
                Button("0") {
                    selectedTabIndex = 0
                }
                Button("1") {
                    selectedTabIndex = 1
                }
                Button("2") {
                    selectedTabIndex = 2
                }
                Button("3") {
                    selectedTabIndex = 3
                }
            }
            .tag(3)
            
            .tabItem {
                Label("Settings", systemImage: "gearshape")
            }
        }
    }
}

struct TarBarViewController_Previews: PreviewProvider {
    static var previews: some View {
        TarBarViewController()
    }
}

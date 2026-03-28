//
//  swiftArithmeticApp.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/5/21.
//

import SwiftUI
#if DEBUG
// InjectionNext：官方推荐的轻量注入客户端（HotReloading 依赖多、国内常拉不动 GitHub）。Debug + Other Linker Flags：-Xlinker -interposable。
// SwiftUI 配合 HotSwiftUI；安装 InjectionNext.app 后用「Launch Xcode」启动 Xcode。勿随 Release 发布保留。
import InjectionNext
#endif

@main
struct swiftArithmeticApp: App {
    var body: some Scene {
        WindowGroup {
            TarBarViewController()
        }
    }
}

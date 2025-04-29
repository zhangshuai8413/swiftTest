//
//  FLSettingController.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/8.
//

import SwiftUI

struct FLSettingController: View {
    @State private var isDarkMode: Bool = false
    @State private var selectedLanguage: String = "zh"
    @State private var cacheSize: String = "128 MB"
    @State private var isNotificationsEnabled: Bool = true
    @State private var isAutoSaveEnabled: Bool = true
    @State private var selectedThreadCount: Int = 4
    @State private var isMemoryOptimizationEnabled: Bool = true
    
    var body: some View {
        NavigationView {
            List {
                // MARK: - 多线程设置
                Section(header: Text("多线程设置").font(.headline)) {
                    SettingRowView(
                        icon: "cpu",
                        title: "线程数量",
                        subtitle: "当前使用 \(selectedThreadCount) 个线程",
                        color: .blue
                    ) {
                        ThreadCountPicker(selectedCount: $selectedThreadCount)
                    }
                    
                    SettingRowView(
                        icon: "arrow.triangle.2.circlepath",
                        title: "并发处理",
                        subtitle: "启用多线程并发处理",
                        color: .green
                    ) {
                        Toggle("", isOn: .constant(true))
                            .disabled(true)
                    }
                    
                    SettingRowView(
                        icon: "timer",
                        title: "任务调度",
                        subtitle: "智能任务调度算法",
                        color: .orange
                    ) {
                        NavigationLink(destination: TaskSchedulingView()) {
                            EmptyView()
                        }
                    }
                    
                    SettingRowView(
                        icon: "lock.shield",
                        title: "线程安全",
                        subtitle: "确保数据访问安全",
                        color: .red
                    ) {
                        NavigationLink(destination: ThreadSafetyView()) {
                            EmptyView()
                        }
                    }
                }
                
                // MARK: - UI组件介绍
                Section(header: Text("UI组件介绍").font(.headline)) {
                    SettingRowView(
                        icon: "rectangle.3.group",
                        title: "SwiftUI组件",
                        subtitle: "现代声明式UI框架",
                        color: .purple
                    ) {
                        NavigationLink(destination: SwiftUIComponentsView()) {
                            EmptyView()
                        }
                    }
                    
                    SettingRowView(
                        icon: "slider.horizontal.3",
                        title: "UIKit组件",
                        subtitle: "传统命令式UI框架",
                        color: .indigo
                    ) {
                        NavigationLink(destination: UIKitComponentsView()) {
                            EmptyView()
                        }
                    }
                    
                    SettingRowView(
                        icon: "paintbrush",
                        title: "自定义组件",
                        subtitle: "可复用的自定义视图",
                        color: .pink
                    ) {
                        NavigationLink(destination: CustomComponentsView()) {
                            EmptyView()
                        }
                    }
                    
                    SettingRowView(
                        icon: "iphone",
                        title: "响应式布局",
                        subtitle: "适配不同屏幕尺寸",
                        color: .teal
                    ) {
                        NavigationLink(destination: ResponsiveLayoutView()) {
                            EmptyView()
                        }
                    }
                }
                
                // MARK: - 内存管理
                Section(header: Text("内存管理").font(.headline)) {
                    SettingRowView(
                        icon: "memorychip",
                        title: "内存优化",
                        subtitle: "当前缓存: \(cacheSize)",
                        color: .cyan
                    ) {
                        Toggle("", isOn: $isMemoryOptimizationEnabled)
                    }
                    
                    SettingRowView(
                        icon: "trash",
                        title: "缓存清理",
                        subtitle: "清理应用缓存数据",
                        color: .brown
                    ) {
                        Button("清理") {
                            clearCache()
                        }
                        .foregroundColor(.red)
                    }
                    
                    SettingRowView(
                        icon: "chart.bar",
                        title: "内存监控",
                        subtitle: "实时内存使用情况",
                        color: .mint
                    ) {
                        NavigationLink(destination: MemoryMonitorView()) {
                            EmptyView()
                        }
                    }
                    
                    SettingRowView(
                        icon: "arrow.clockwise",
                        title: "自动释放",
                        subtitle: "自动释放未使用内存",
                        color: .yellow
                    ) {
                        Toggle("", isOn: $isAutoSaveEnabled)
                    }
                }
                
                // MARK: - 应用设置
                Section(header: Text("应用设置").font(.headline)) {
                    SettingRowView(
                        icon: "moon.fill",
                        title: "深色模式",
                        subtitle: isDarkMode ? "已启用" : "已禁用",
                        color: .gray
                    ) {
                        Toggle("", isOn: $isDarkMode)
                    }
                    
                    SettingRowView(
                        icon: "globe",
                        title: "语言设置",
                        subtitle: selectedLanguage == "zh" ? "中文" : "English",
                        color: .green
                    ) {
                        LanguagePicker(selectedLanguage: $selectedLanguage)
                    }
                    
                    SettingRowView(
                        icon: "bell",
                        title: "通知设置",
                        subtitle: isNotificationsEnabled ? "已启用" : "已禁用",
                        color: .orange
                    ) {
                        Toggle("", isOn: $isNotificationsEnabled)
                    }
                }
            }
            .navigationTitle("设置")
            .navigationBarTitleDisplayMode(.large)
        }
    }
    
    // MARK: - 辅助方法
    private func clearCache() {
        // 模拟清理缓存
        cacheSize = "0 MB"
        // 这里可以添加实际的缓存清理逻辑
    }
}

// MARK: - 设置行视图
struct SettingRowView<Content: View>: View {
    let icon: String
    let title: String
    let subtitle: String
    let color: Color
    let content: () -> Content
    
    var body: some View {
        HStack {
            Image(systemName: icon)
                .foregroundColor(color)
                .frame(width: 24, height: 24)
            
            VStack(alignment: .leading, spacing: 2) {
                Text(title)
                    .font(.body)
                    .fontWeight(.medium)
                
                Text(subtitle)
                    .font(.caption)
                    .foregroundColor(.secondary)
            }
            
            Spacer()
            
            content()
        }
        .padding(.vertical, 4)
    }
}

// MARK: - 线程数量选择器
struct ThreadCountPicker: View {
    @Binding var selectedCount: Int
    let threadCounts = [1, 2, 4, 8, 16]
    
    var body: some View {
        Picker("线程数量", selection: $selectedCount) {
            ForEach(threadCounts, id: \.self) { count in
                Text("\(count) 个")
                    .tag(count)
            }
        }
        .pickerStyle(MenuPickerStyle())
    }
}

// MARK: - 语言选择器
struct LanguagePicker: View {
    @Binding var selectedLanguage: String
    let languages = [
        ("zh", "中文"),
        ("en", "English"),
        ("ja", "日本語"),
        ("ko", "한국어")
    ]
    
    var body: some View {
        Picker("语言", selection: $selectedLanguage) {
            ForEach(languages, id: \.0) { language in
                Text(language.1)
                    .tag(language.0)
            }
        }
        .pickerStyle(MenuPickerStyle())
    }
}

// MARK: - 任务调度视图
struct TaskSchedulingView: View {
    var body: some View {
        VStack(alignment: .leading, spacing: 16) {
            Text("任务调度算法")
                .font(.title2)
                .fontWeight(.bold)
            
            VStack(alignment: .leading, spacing: 8) {
                Text("• 优先级调度：根据任务重要性分配CPU时间")
                Text("• 轮转调度：公平分配CPU时间片")
                Text("• 最短作业优先：优先处理耗时短的任务")
                Text("• 多级反馈队列：动态调整任务优先级")
            }
            .font(.body)
            
            Spacer()
        }
        .padding()
        .navigationTitle("任务调度")
        .navigationBarTitleDisplayMode(.inline)
    }
}

// MARK: - 线程安全视图
struct ThreadSafetyView: View {
    var body: some View {
        VStack(alignment: .leading, spacing: 16) {
            Text("线程安全机制")
                .font(.title2)
                .fontWeight(.bold)
            
            VStack(alignment: .leading, spacing: 8) {
                Text("• 互斥锁：防止多个线程同时访问共享资源")
                Text("• 信号量：控制同时访问资源的线程数量")
                Text("• 原子操作：保证操作的原子性")
                Text("• 读写锁：允许多个读操作，但只允许一个写操作")
            }
            .font(.body)
            
            Spacer()
        }
        .padding()
        .navigationTitle("线程安全")
        .navigationBarTitleDisplayMode(.inline)
    }
}

// MARK: - SwiftUI组件视图
struct SwiftUIComponentsView: View {
    var body: some View {
        VStack(alignment: .leading, spacing: 16) {
            Text("SwiftUI组件")
                .font(.title2)
                .fontWeight(.bold)
            
            VStack(alignment: .leading, spacing: 8) {
                Text("• Text：文本显示组件")
                Text("• Button：按钮交互组件")
                Text("• List：列表展示组件")
                Text("• NavigationView：导航容器组件")
                Text("• @State：状态管理属性包装器")
                Text("• @Binding：双向绑定属性包装器")
            }
            .font(.body)
            
            Spacer()
        }
        .padding()
        .navigationTitle("SwiftUI组件")
        .navigationBarTitleDisplayMode(.inline)
    }
}

// MARK: - UIKit组件视图
struct UIKitComponentsView: View {
    var body: some View {
        VStack(alignment: .leading, spacing: 16) {
            Text("UIKit组件")
                .font(.title2)
                .fontWeight(.bold)
            
            VStack(alignment: .leading, spacing: 8) {
                Text("• UILabel：文本标签组件")
                Text("• UIButton：按钮组件")
                Text("• UITableView：表格视图组件")
                Text("• UINavigationController：导航控制器")
                Text("• UIViewController：视图控制器基类")
                Text("• UIView：视图基类")
            }
            .font(.body)
            
            Spacer()
        }
        .padding()
        .navigationTitle("UIKit组件")
        .navigationBarTitleDisplayMode(.inline)
    }
}

// MARK: - 自定义组件视图
struct CustomComponentsView: View {
    var body: some View {
        VStack(alignment: .leading, spacing: 16) {
            Text("自定义组件")
                .font(.title2)
                .fontWeight(.bold)
            
            VStack(alignment: .leading, spacing: 8) {
                Text("• 可复用性：一次编写，多处使用")
                Text("• 封装性：隐藏内部实现细节")
                Text("• 可配置性：支持参数自定义")
                Text("• 一致性：保持UI风格统一")
                Text("• 可测试性：便于单元测试")
            }
            .font(.body)
            
            Spacer()
        }
        .padding()
        .navigationTitle("自定义组件")
        .navigationBarTitleDisplayMode(.inline)
    }
}

// MARK: - 响应式布局视图
struct ResponsiveLayoutView: View {
    var body: some View {
        VStack(alignment: .leading, spacing: 16) {
            Text("响应式布局")
                .font(.title2)
                .fontWeight(.bold)
            
            VStack(alignment: .leading, spacing: 8) {
                Text("• 自适应布局：根据屏幕尺寸调整")
                Text("• 约束布局：使用Auto Layout")
                Text("• 弹性布局：Flexbox布局方式")
                Text("• 网格布局：Grid布局系统")
                Text("• 断点设计：不同屏幕尺寸的适配")
            }
            .font(.body)
            
            Spacer()
        }
        .padding()
        .navigationTitle("响应式布局")
        .navigationBarTitleDisplayMode(.inline)
    }
}

// MARK: - 内存监控视图
struct MemoryMonitorView: View {
    @State private var memoryUsage: Double = 0.0
    @State private var timer: Timer?
    
    var body: some View {
        VStack(spacing: 20) {
            Text("内存使用情况")
                .font(.title2)
                .fontWeight(.bold)
            
            // 内存使用进度条
            VStack(alignment: .leading, spacing: 8) {
                HStack {
                    Text("内存使用率")
                    Spacer()
                    Text("\(Int(memoryUsage * 100))%")
                }
                
                ProgressView(value: memoryUsage)
                    .progressViewStyle(LinearProgressViewStyle())
                
                HStack {
                    Text("已使用: \(String(format: "%.1f", memoryUsage * 1024)) MB")
                    Spacer()
                    Text("总计: 1024 MB")
                }
                .font(.caption)
                .foregroundColor(.secondary)
            }
            
            // 内存优化建议
            VStack(alignment: .leading, spacing: 8) {
                Text("优化建议")
                    .font(.headline)
                
                if memoryUsage > 0.8 {
                    Text("⚠️ 内存使用率过高，建议清理缓存")
                        .foregroundColor(.red)
                } else if memoryUsage > 0.6 {
                    Text("⚠️ 内存使用率较高，建议优化")
                        .foregroundColor(.orange)
                } else {
                    Text("✅ 内存使用正常")
                        .foregroundColor(.green)
                }
            }
            
            Spacer()
        }
        .padding()
        .navigationTitle("内存监控")
        .navigationBarTitleDisplayMode(.inline)
        .onAppear {
            startMemoryMonitoring()
        }
        .onDisappear {
            stopMemoryMonitoring()
        }
    }
    
    private func startMemoryMonitoring() {
        timer = Timer.scheduledTimer(withTimeInterval: 1.0, repeats: true) { _ in
            // 模拟内存使用率变化
//            memoryUsage = Double.random(in: 0.3...0.9)
        }
    }
    
    private func stopMemoryMonitoring() {
        timer?.invalidate()
        timer = nil
    }
}

struct FLSettingController_Previews: PreviewProvider {
    static var previews: some View {
        FLSettingController()
    }
}

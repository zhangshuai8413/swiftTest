//
//  FLMe.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/8.
//

import SwiftUI

/// 个人中心视图控制器
struct FLMeViewController: View {
    
    // MARK: - 状态变量
    @State private var userName: String = "张帅"
    @State private var userAvatar: String = "person.circle.fill"
    @State private var isDarkMode: Bool = false
    @State private var selectedLanguage: String = "zh"
    
    // MARK: - 菜单项数据
    private let menuItems = [
        MenuItem(id: "menu_profile", icon: "person.fill", title: "个人信息", color: .blue),
        MenuItem(id: "menu_settings", icon: "gear", title: "设置", color: .gray),
        MenuItem(id: "menu_language", icon: "globe", title: "语言设置", color: .green),
        MenuItem(id: "menu_dark_mode", icon: "moon.fill", title: "深色模式", color: .purple),
        MenuItem(id: "menu_help", icon: "questionmark.circle", title: "帮助与反馈", color: .orange),
        MenuItem(id: "menu_about", icon: "info.circle", title: "关于我们", color: .red)
    ]
    
    var body: some View {
        NavigationView {
            ScrollView {
                VStack(spacing: 20) {
                    userInfoCard
                    menuSection
                    statisticsSection
                    quickActionsSection
                }
                .padding()
            }
            .navigationTitle("个人中心")
            .toolbar {
                ToolbarItem(placement: .primaryAction) {
                    NavigationLink(destination: SettingsView(isDarkMode: $isDarkMode, selectedLanguage: $selectedLanguage)) {
                        Image(systemName: "gearshape.fill")
                    }
                    .accessibilityIdentifier("toolbar_settings_button")
                }
            }
        }
    }
    
    // MARK: - 用户信息卡片
    private var userInfoCard: some View {
        VStack(spacing: 16) {
            Image(systemName: userAvatar)
                .font(.system(size: 80))
                .foregroundColor(.blue)
                .background(Circle().fill(Color.blue.opacity(0.1)).frame(width: 100, height: 100))
            
            VStack(spacing: 8) {
                Text(userName).font(.title2).fontWeight(.bold)
                Text("iOS开发者").font(.subheadline).foregroundColor(.secondary)
                Text("专注于算法学习和Swift开发").font(.caption).foregroundColor(.secondary).multilineTextAlignment(.center)
            }
            
            NavigationLink(destination: ProfileDetailView(userName: $userName)) {
                Text("编辑资料")
                    .font(.caption).foregroundColor(.blue)
                    .padding(.horizontal, 16).padding(.vertical, 8)
                    .background(RoundedRectangle(cornerRadius: 16).stroke(Color.blue, lineWidth: 1))
            }
            .accessibilityIdentifier("profile_edit_button")
        }
        .padding()
        .background(CardBackground())
    }
    
    // MARK: - 功能菜单
    private var menuSection: some View {
        VStack(spacing: 12) {
            ForEach(menuItems) { item in
                MenuRowView(item: item) { handleMenuAction(for: item.title) }
                    .accessibilityIdentifier("menu_item_\(item.id)")
            }
        }
        .background(CardBackground())
    }
    
    // MARK: - 统计信息
    private var statisticsSection: some View {
        VStack(alignment: .leading, spacing: 16) {
            HStack {
                Text("学习统计").font(.headline).fontWeight(.bold)
                Spacer()
                NavigationLink(destination: StatisticsDetailView()) {
                    Text("查看详情")
                        .font(.caption).foregroundColor(.blue)
                }
            }
            
            HStack(spacing: 20) {
                StatCard(title: "已学算法", value: "156", icon: "function", color: .blue)
                StatCard(title: "完成题目", value: "89", icon: "checkmark.circle", color: .green)
                StatCard(title: "学习天数", value: "45", icon: "calendar", color: .orange)
            }
        }
        .padding()
        .background(CardBackground())
    }
    
    // MARK: - 快速操作
    private var quickActionsSection: some View {
        VStack(alignment: .leading, spacing: 16) {
            Text("快速操作").font(.headline).fontWeight(.bold)
            
            HStack(spacing: 16) {
                QuickActionButton(title: "开始学习", icon: "play.fill", color: .blue) { }
                QuickActionButton(title: "复习", icon: "arrow.clockwise", color: .green) { }
                QuickActionButton(title: "收藏", icon: "heart.fill", color: .red) { }
            }
            
            NavigationLink(destination: LearningHistoryView()) {
                HStack {
                    Image(systemName: "clock.arrow.circlepath").foregroundColor(.purple)
                    Text("学习历史").foregroundColor(.primary)
                    Spacer()
                    Image(systemName: "chevron.right").foregroundColor(.secondary).font(.caption)
                }
                .padding()
                .background(RoundedRectangle(cornerRadius: 8).fill(Color.purple.opacity(0.1)))
            }
            .buttonStyle(PlainButtonStyle())
        }
        .padding()
        .background(CardBackground())
    }
    
    // MARK: - 菜单操作处理
    private func handleMenuAction(for title: String) {
        switch title {
        case "个人信息":
            // 使用NavigationLink处理，这里不需要额外操作
            break
        case "设置":
            // 使用NavigationLink处理，这里不需要额外操作
            break
        case "语言设置":
            // 使用NavigationLink处理，这里不需要额外操作
            break
        case "深色模式": 
            isDarkMode.toggle()
        case "帮助与反馈":
            // 使用NavigationLink处理，这里不需要额外操作
            break
        case "关于我们":
            // 使用NavigationLink处理，这里不需要额外操作
            break
        default: break
        }
    }
}

// MARK: - 公共组件
struct CardBackground: View {
    var body: some View {
        RoundedRectangle(cornerRadius: 12)
            .fill(Color.primary.opacity(0.05))
            .shadow(color: .black.opacity(0.05), radius: 4, x: 0, y: 2)
    }
}

struct DetailNavigationView<Content: View>: View {
    let title: String
    let content: Content
    @Environment(\.presentationMode) var presentationMode
    
    init(title: String, @ViewBuilder content: () -> Content) {
        self.title = title
        self.content = content()
    }
    
    var body: some View {
        NavigationView {
            content
                .navigationTitle(title)
                .navigationBarTitleDisplayMode(.inline)
                .toolbar {
                    ToolbarItem(placement: .navigationBarTrailing) {
                        Button("完成") { presentationMode.wrappedValue.dismiss() }
                    }
                }
        }
    }
}

// MARK: - 详情页面
struct ProfileDetailView: View {
    @Binding var userName: String
    @Environment(\.presentationMode) var presentationMode
    @State private var tempUserName: String = ""
    @State private var userEmail: String = "zhangshuai@example.com"
    @State private var userPhone: String = "138****8888"
    @State private var userLocation: String = "北京"
    @State private var userBio: String = "专注于iOS开发和算法学习，热爱编程，追求代码的优雅和高效。"
    
    var body: some View {
        DetailNavigationView(title: "个人信息") {
            ScrollView {
                VStack(spacing: 20) {
                    // 头像区域
                    VStack(spacing: 16) {
                        Image(systemName: "person.circle.fill").font(.system(size: 100)).foregroundColor(.blue)
                        Button("更换头像") { }.font(.caption).foregroundColor(.blue)
                    }
                    .padding()
                    .background(RoundedRectangle(cornerRadius: 12).fill(Color.blue.opacity(0.1)))
                    
                    // 基本信息
                    VStack(alignment: .leading, spacing: 16) {
                        Text("基本信息").font(.headline).fontWeight(.bold)
                        VStack(spacing: 12) {
                            InfoRow(title: "用户名", value: $tempUserName, isEditable: true)
                            InfoRow(title: "邮箱", value: $userEmail, isEditable: true)
                            InfoRow(title: "手机号", value: $userPhone, isEditable: true)
                            InfoRow(title: "所在地", value: $userLocation, isEditable: true)
                        }
                    }
                    .padding()
                    .background(CardBackground())
                    
                    // 个人简介
                    VStack(alignment: .leading, spacing: 16) {
                        Text("个人简介").font(.headline).fontWeight(.bold)
                        TextEditor(text: $userBio)
                            .frame(minHeight: 100)
                            .padding(8)
                            .background(RoundedRectangle(cornerRadius: 8).fill(Color.primary.opacity(0.05)))
                    }
                    .padding()
                    .background(CardBackground())
                    
                    // 学习统计
                    VStack(alignment: .leading, spacing: 16) {
                        Text("学习统计").font(.headline).fontWeight(.bold)
                        HStack(spacing: 20) {
                            StatCard(title: "学习天数", value: "45", icon: "calendar", color: .blue)
                            StatCard(title: "完成题目", value: "89", icon: "checkmark.circle", color: .green)
                            StatCard(title: "连续打卡", value: "12", icon: "flame", color: .orange)
                        }
                    }
                    .padding()
                    .background(CardBackground())
                }
                .padding()
            }
            .toolbar {
                ToolbarItem(placement: .navigationBarLeading) {
                    Button("取消") { presentationMode.wrappedValue.dismiss() }
                }
                ToolbarItem(placement: .navigationBarTrailing) {
                    Button("保存") {
                        userName = tempUserName
                        presentationMode.wrappedValue.dismiss()
                    }.fontWeight(.semibold)
                }
            }
            .onAppear { tempUserName = userName }
        }
    }
}

struct LanguageDetailView: View {
    @Binding var selectedLanguage: String
    
    private let languages = [
        LanguageOption(code: "zh", name: "中文", nativeName: "中文", flag: "🇨🇳"),
        LanguageOption(code: "en", name: "English", nativeName: "English", flag: "🇺🇸"),
        LanguageOption(code: "ja", name: "日本語", nativeName: "日本語", flag: "🇯🇵"),
        LanguageOption(code: "ko", name: "한국어", nativeName: "한국어", flag: "🇰🇷"),
        LanguageOption(code: "ar", name: "العربية", nativeName: "العربية", flag: "🇸🇦"),
        LanguageOption(code: "fr", name: "Français", nativeName: "Français", flag: "🇫🇷"),
        LanguageOption(code: "de", name: "Deutsch", nativeName: "Deutsch", flag: "🇩🇪"),
        LanguageOption(code: "es", name: "Español", nativeName: "Español", flag: "🇪🇸"),
        LanguageOption(code: "it", name: "Italiano", nativeName: "Italiano", flag: "🇮🇹"),
        LanguageOption(code: "pt", name: "Português", nativeName: "Português", flag: "🇵🇹")
    ]
    
    var body: some View {
        DetailNavigationView(title: "语言设置") {
            List {
                Section(header: Text("选择语言")) {
                    ForEach(languages, id: \.code) { language in
                        LanguageRowView(language: language, isSelected: selectedLanguage == language.code) {
                            selectedLanguage = language.code
                        }
                    }
                }
                Section(header: Text("说明"), footer: Text("更改语言后，应用将重启以应用新的语言设置。")) {
                    VStack(alignment: .leading, spacing: 8) {
                        Text("• 语言设置会影响整个应用的界面语言")
                        Text("• 部分内容可能仍显示为英文")
                        Text("• 重启应用后设置生效")
                    }.font(.caption).foregroundColor(.secondary)
                }
            }
        }
    }
}

struct LearningHistoryView: View {
    private let learningRecords = [
        LearningRecord(date: "2024-01-15", topic: "数组算法", duration: "45分钟", progress: "已完成"),
        LearningRecord(date: "2024-01-14", topic: "链表操作", duration: "30分钟", progress: "已完成"),
        LearningRecord(date: "2024-01-13", topic: "树结构", duration: "60分钟", progress: "进行中"),
        LearningRecord(date: "2024-01-12", topic: "动态规划", duration: "90分钟", progress: "已完成"),
        LearningRecord(date: "2024-01-11", topic: "贪心算法", duration: "40分钟", progress: "已完成")
    ]
    
    var body: some View {
        DetailNavigationView(title: "学习历史") {
            List {
                Section(header: Text("最近学习记录")) {
                    ForEach(learningRecords, id: \.date) { record in
                        LearningRecordRow(record: record)
                    }
                }
                Section(header: Text("学习统计")) {
                    HStack { Text("总学习时长"); Spacer(); Text("265分钟").foregroundColor(.blue) }
                    HStack { Text("连续学习天数"); Spacer(); Text("12天").foregroundColor(.green) }
                    HStack { Text("完成题目数"); Spacer(); Text("89题").foregroundColor(.orange) }
                }
            }
        }
    }
}

struct StatisticsDetailView: View {
    var body: some View {
        DetailNavigationView(title: "统计详情") {
            ScrollView {
                VStack(spacing: 20) {
                    // 总体统计
                    VStack(alignment: .leading, spacing: 16) {
                        Text("总体统计").font(.headline).fontWeight(.bold)
                        LazyVGrid(columns: Array(repeating: GridItem(.flexible()), count: 2), spacing: 16) {
                            StatCard(title: "总学习时长", value: "265分钟", icon: "clock", color: .blue)
                            StatCard(title: "连续学习", value: "12天", icon: "flame", color: .orange)
                            StatCard(title: "完成题目", value: "89题", icon: "checkmark.circle", color: .green)
                            StatCard(title: "正确率", value: "85%", icon: "percent", color: .purple)
                        }
                    }
                    .padding()
                    .background(CardBackground())
                    
                    // 算法分类统计
                    VStack(alignment: .leading, spacing: 16) {
                        Text("算法分类统计").font(.headline).fontWeight(.bold)
                        VStack(spacing: 12) {
                            AlgorithmProgressRow(name: "数组算法", progress: 0.8, count: 25)
                            AlgorithmProgressRow(name: "链表操作", progress: 0.6, count: 18)
                            AlgorithmProgressRow(name: "树结构", progress: 0.4, count: 12)
                            AlgorithmProgressRow(name: "动态规划", progress: 0.9, count: 30)
                            AlgorithmProgressRow(name: "贪心算法", progress: 0.7, count: 22)
                        }
                    }
                    .padding()
                    .background(CardBackground())
                    
                    // 学习趋势
                    VStack(alignment: .leading, spacing: 16) {
                        Text("学习趋势").font(.headline).fontWeight(.bold)
                        HStack(alignment: .bottom, spacing: 8) {
                            ForEach(0..<7, id: \.self) { index in
                                VStack {
                                    RoundedRectangle(cornerRadius: 4)
                                        .fill(Color.blue)
                                        .frame(width: 30, height: CGFloat(20 + index * 5))
                                    Text("D\(index + 1)").font(.caption2).foregroundColor(.secondary)
                                }
                            }
                        }
                        .frame(height: 100)
                        .padding(.top, 8)
                    }
                    .padding()
                    .background(CardBackground())
                }
                .padding()
            }
        }
    }
}

struct HelpFeedbackView: View {
    @State private var feedbackText: String = ""
    @State private var selectedCategory: String = "功能建议"
    private let categories = ["功能建议", "Bug反馈", "使用问题", "其他"]
    
    var body: some View {
        DetailNavigationView(title: "帮助与反馈") {
            ScrollView {
                VStack(spacing: 20) {
                    // 常见问题
                    VStack(alignment: .leading, spacing: 16) {
                        Text("常见问题").font(.headline).fontWeight(.bold)
                        VStack(spacing: 12) {
                            FAQRow(question: "如何开始学习算法？", answer: "点击首页的'开始学习'按钮，选择你感兴趣的算法类型即可开始学习。")
                            FAQRow(question: "如何查看学习进度？", answer: "在个人中心页面可以查看详细的学习统计和进度信息。")
                            FAQRow(question: "如何切换语言？", answer: "在设置页面选择'语言设置'，然后选择你需要的语言即可。")
                        }
                    }
                    .padding()
                    .background(CardBackground())
                    
                    // 反馈表单
                    VStack(alignment: .leading, spacing: 16) {
                        Text("意见反馈").font(.headline).fontWeight(.bold)
                        VStack(spacing: 12) {
                            Picker("反馈类型", selection: $selectedCategory) {
                                ForEach(categories, id: \.self) { category in
                                    Text(category).tag(category)
                                }
                            }.pickerStyle(MenuPickerStyle())
                            
                            TextEditor(text: $feedbackText)
                                .frame(minHeight: 120)
                                .padding(8)
                                .background(RoundedRectangle(cornerRadius: 8).fill(Color.primary.opacity(0.05)))
                                .overlay(RoundedRectangle(cornerRadius: 8).stroke(Color.secondary.opacity(0.3), lineWidth: 1))
                        }
                        
                        Button("提交反馈") { }
                            .frame(maxWidth: .infinity)
                            .padding()
                            .background(Color.blue)
                            .foregroundColor(.white)
                            .cornerRadius(8)
                    }
                    .padding()
                    .background(CardBackground())
                    
                    // 联系方式
                    VStack(alignment: .leading, spacing: 16) {
                        Text("联系我们").font(.headline).fontWeight(.bold)
                        VStack(spacing: 12) {
                            ContactRow(icon: "envelope", title: "邮箱", value: "support@example.com")
                            ContactRow(icon: "phone", title: "电话", value: "400-123-4567")
                            ContactRow(icon: "message", title: "微信", value: "swift_algorithm")
                        }
                    }
                    .padding()
                    .background(CardBackground())
                }
                .padding()
            }
        }
    }
}

struct AboutUsView: View {
    var body: some View {
        DetailNavigationView(title: "关于我们") {
            ScrollView {
                VStack(spacing: 20) {
                    // 应用信息
                    VStack(spacing: 16) {
                        Image(systemName: "function").font(.system(size: 80)).foregroundColor(.blue)
                        Text("Swift算法学习").font(.title).fontWeight(.bold)
                        Text("版本 1.0.0").font(.subheadline).foregroundColor(.secondary)
                    }
                    .padding()
                    .background(RoundedRectangle(cornerRadius: 12).fill(Color.blue.opacity(0.1)))
                    
                    // 应用介绍
                    VStack(alignment: .leading, spacing: 16) {
                        Text("应用介绍").font(.headline).fontWeight(.bold)
                        Text("Swift算法学习是一款专为iOS开发者设计的算法学习应用。我们致力于提供高质量的算法教程、实践题目和详细解析，帮助开发者提升编程技能和算法思维。")
                            .font(.body).foregroundColor(.secondary)
                    }
                    .padding()
                    .background(CardBackground())
                    
                    // 功能特色
                    VStack(alignment: .leading, spacing: 16) {
                        Text("功能特色").font(.headline).fontWeight(.bold)
                        VStack(spacing: 12) {
                            FeatureRow(icon: "book.fill", title: "系统化学习", description: "从基础到高级，系统化的算法学习路径")
                            FeatureRow(icon: "code", title: "代码实践", description: "提供完整的Swift代码示例和详细注释")
                            FeatureRow(icon: "chart.line.uptrend.xyaxis", title: "进度跟踪", description: "实时跟踪学习进度，可视化学习成果")
                            FeatureRow(icon: "person.2.fill", title: "社区交流", description: "与其他开发者交流学习心得和经验")
                        }
                    }
                    .padding()
                    .background(CardBackground())
                    
                    // 开发团队
                    VStack(alignment: .leading, spacing: 16) {
                        Text("开发团队").font(.headline).fontWeight(.bold)
                        VStack(spacing: 12) {
                            TeamMemberRow(name: "张帅", role: "iOS开发工程师", avatar: "person.circle.fill")
                            TeamMemberRow(name: "算法团队", role: "算法内容策划", avatar: "person.2.circle.fill")
                            TeamMemberRow(name: "设计团队", role: "UI/UX设计", avatar: "paintbrush.circle.fill")
                        }
                    }
                    .padding()
                    .background(CardBackground())
                }
                .padding()
            }
        }
    }
}

// MARK: - 数据模型
struct MenuItem: Identifiable {
    let id: String
    let icon: String
    let title: String
    let color: Color
    
    init(id: String, icon: String, title: String, color: Color) {
        self.id = id
        self.icon = icon
        self.title = title
        self.color = color
    }
}

struct LanguageOption: Identifiable {
    let id: String
    let code: String
    let name: String
    let nativeName: String
    let flag: String
    
    init(code: String, name: String, nativeName: String, flag: String) {
        self.id = "lang_\(code)"
        self.code = code
        self.name = name
        self.nativeName = nativeName
        self.flag = flag
    }
}

struct LearningRecord {
    let date: String
    let topic: String
    let duration: String
    let progress: String
}

// MARK: - 组件
struct InfoRow: View {
    let title: String
    @Binding var value: String
    let isEditable: Bool
    
    var body: some View {
        HStack {
            Text(title).foregroundColor(.primary)
            Spacer()
            if isEditable {
                TextField("请输入\(title)", text: $value).multilineTextAlignment(.trailing).foregroundColor(.secondary)
            } else {
                Text(value).foregroundColor(.secondary)
            }
        }.padding(.vertical, 4)
    }
}

struct LanguageRowView: View {
    let language: LanguageOption
    let isSelected: Bool
    let action: () -> Void
    
    var body: some View {
        Button(action: action) {
            HStack {
                Text(language.flag).font(.title2)
                VStack(alignment: .leading, spacing: 2) {
                    Text(language.name).font(.body).foregroundColor(.primary)
                    Text(language.nativeName).font(.caption).foregroundColor(.secondary)
                }
                Spacer()
                if isSelected {
                    Image(systemName: "checkmark").foregroundColor(.blue).fontWeight(.bold)
                }
            }.padding(.vertical, 4)
        }.buttonStyle(PlainButtonStyle())
    }
}

struct LearningRecordRow: View {
    let record: LearningRecord
    
    var body: some View {
        VStack(alignment: .leading, spacing: 8) {
            HStack {
                Text(record.topic).font(.headline).foregroundColor(.primary)
                Spacer()
                Text(record.date).font(.caption).foregroundColor(.secondary)
            }
            HStack {
                Text(record.duration).font(.caption).foregroundColor(.blue)
                Spacer()
                Text(record.progress).font(.caption).foregroundColor(record.progress == "已完成" ? .green : .orange)
            }
        }.padding(.vertical, 4)
    }
}

struct AlgorithmProgressRow: View {
    let name: String
    let progress: Double
    let count: Int
    
    var body: some View {
        VStack(alignment: .leading, spacing: 8) {
            HStack {
                Text(name).font(.body).foregroundColor(.primary)
                Spacer()
                Text("\(count)题").font(.caption).foregroundColor(.secondary)
            }
            ProgressView(value: progress).progressViewStyle(LinearProgressViewStyle(tint: .blue))
        }
    }
}

struct FAQRow: View {
    let question: String
    let answer: String
    @State private var isExpanded: Bool = false
    
    var body: some View {
        VStack(alignment: .leading, spacing: 8) {
            Button(action: { isExpanded.toggle() }) {
                HStack {
                    Text(question).font(.body).foregroundColor(.primary).multilineTextAlignment(.leading)
                    Spacer()
                    Image(systemName: isExpanded ? "chevron.up" : "chevron.down").foregroundColor(.secondary).font(.caption)
                }
            }.buttonStyle(PlainButtonStyle())
            
            if isExpanded {
                Text(answer).font(.caption).foregroundColor(.secondary).padding(.top, 4)
            }
        }
        .padding()
        .background(RoundedRectangle(cornerRadius: 8).fill(Color.primary.opacity(0.05)))
    }
}

struct ContactRow: View {
    let icon: String
    let title: String
    let value: String
    
    var body: some View {
        HStack {
            Image(systemName: icon).foregroundColor(.blue).frame(width: 20)
            Text(title).foregroundColor(.primary)
            Spacer()
            Text(value).foregroundColor(.secondary)
        }.padding(.vertical, 4)
    }
}

struct FeatureRow: View {
    let icon: String
    let title: String
    let description: String
    
    var body: some View {
        HStack(spacing: 12) {
            Image(systemName: icon).foregroundColor(.blue).font(.title2).frame(width: 30)
            VStack(alignment: .leading, spacing: 4) {
                Text(title).font(.body).fontWeight(.medium).foregroundColor(.primary)
                Text(description).font(.caption).foregroundColor(.secondary)
            }
            Spacer()
        }.padding(.vertical, 4)
    }
}

struct TeamMemberRow: View {
    let name: String
    let role: String
    let avatar: String
    
    var body: some View {
        HStack(spacing: 12) {
            Image(systemName: avatar).foregroundColor(.blue).font(.title2).frame(width: 40, height: 40)
            VStack(alignment: .leading, spacing: 4) {
                Text(name).font(.body).fontWeight(.medium).foregroundColor(.primary)
                Text(role).font(.caption).foregroundColor(.secondary)
            }
            Spacer()
        }.padding(.vertical, 4)
    }
}

struct MenuRowView: View {
    let item: MenuItem
    let action: () -> Void
    
    var body: some View {
        Group {
            switch item.title {
            case "个人信息":
                NavigationLink(destination: ProfileDetailView(userName: .constant("张帅"))) {
                    menuRowContent
                }
            case "设置":
                NavigationLink(destination: SettingsView(isDarkMode: .constant(false), selectedLanguage: .constant("zh"))) {
                    menuRowContent
                }
            case "语言设置":
                NavigationLink(destination: LanguageDetailView(selectedLanguage: .constant("zh"))) {
                    menuRowContent
                }
            case "帮助与反馈":
                NavigationLink(destination: HelpFeedbackView()) {
                    menuRowContent
                }
            case "关于我们":
                NavigationLink(destination: AboutUsView()) {
                    menuRowContent
                }
            default:
                Button(action: action) {
                    menuRowContent
                }
                .buttonStyle(PlainButtonStyle())
            }
        }
        .contentShape(Rectangle()) // 确保整个区域都能响应点击
    }
    
    private var menuRowContent: some View {
        HStack {
            Image(systemName: item.icon).foregroundColor(item.color).frame(width: 24)
            Text(item.title).foregroundColor(.primary)
            Spacer()
            Image(systemName: "chevron.right").foregroundColor(.secondary).font(.caption)
        }
        .padding(.horizontal, 16).padding(.vertical, 12)
        .background(Color.clear) // 确保背景透明，让点击区域更大
    }
}

struct StatCard: View {
    let title: String
    let value: String
    let icon: String
    let color: Color
    
    var body: some View {
        VStack(spacing: 8) {
            Image(systemName: icon).font(.title2).foregroundColor(color)
            Text(value).font(.title2).fontWeight(.bold)
            Text(title).font(.caption).foregroundColor(.secondary)
        }
        .frame(maxWidth: .infinity)
        .padding(.vertical, 12)
        .background(RoundedRectangle(cornerRadius: 8).fill(color.opacity(0.1)))
    }
}

struct QuickActionButton: View {
    let title: String
    let icon: String
    let color: Color
    let action: () -> Void
    
    var body: some View {
        Button(action: action) {
            VStack(spacing: 8) {
                Image(systemName: icon).font(.title2).foregroundColor(color)
                Text(title).font(.caption).foregroundColor(.primary)
            }
            .frame(maxWidth: .infinity)
            .padding(.vertical, 16)
            .background(RoundedRectangle(cornerRadius: 8).fill(color.opacity(0.1)))
        }.buttonStyle(PlainButtonStyle())
    }
}

struct SettingsView: View {
    @Binding var isDarkMode: Bool
    @Binding var selectedLanguage: String
    @Environment(\.presentationMode) var presentationMode
    
    private let languages = [("zh", "中文"), ("en", "English"), ("ja", "日本語"), ("ko", "한국어")]
    
    var body: some View {
        DetailNavigationView(title: "设置") {
            Form {
                Section(header: Text("外观")) {
                    Toggle("深色模式", isOn: $isDarkMode)
                }
                Section(header: Text("语言")) {
                    Picker("语言", selection: $selectedLanguage) {
                        ForEach(languages, id: \.0) { language in
                            Text(language.1).tag(language.0)
                        }
                    }.pickerStyle(MenuPickerStyle())
                }
                Section(header: Text("其他")) {
                    Button("清除缓存") { }
                    Button("检查更新") { }
                }
            }
        }
    }
}

struct ProfileView: View {
    @Binding var userName: String
    @Environment(\.presentationMode) var presentationMode
    @State private var tempUserName: String = ""
    
    var body: some View {
        DetailNavigationView(title: "个人资料") {
            Form {
                Section(header: Text("基本信息")) {
                    HStack {
                        Text("用户名")
                        Spacer()
                        TextField("请输入用户名", text: $tempUserName).multilineTextAlignment(.trailing)
                    }
                }
                Section(header: Text("其他信息")) {
                    HStack {
                        Text("邮箱")
                        Spacer()
                        Text("zhangshuai@example.com").foregroundColor(.secondary)
                    }
                    HStack {
                        Text("注册时间")
                        Spacer()
                        Text("2023年7月8日").foregroundColor(.secondary)
                    }
                }
            }
            .toolbar {
                ToolbarItem(placement: .navigationBarLeading) {
                    Button("取消") { presentationMode.wrappedValue.dismiss() }
                }
                ToolbarItem(placement: .navigationBarTrailing) {
                    Button("保存") {
                        userName = tempUserName
                        presentationMode.wrappedValue.dismiss()
                    }
                }
            }
            .onAppear { tempUserName = userName }
        }
    }
}

// MARK: - 测试函数
func test1() {
    let concurrentQueue = DispatchQueue(label: "com.example.concurrentQueue", attributes: .concurrent)
    let group = DispatchGroup()
    concurrentQueue.async(group: group, execute: { testmethod() })
    concurrentQueue.async(group: group, execute: { testmethod() })
    group.notify(queue: concurrentQueue) { print("sharedVariable-----\(sharedVariable)") }
}

nonisolated(unsafe) var sharedVariable: Int = 0

func testmethod() {
    for _ in 0..<10 { sharedVariable += 1 }
}

struct FLMe_Previews: PreviewProvider {
    static var previews: some View {
        FLMeViewController()
    }
}


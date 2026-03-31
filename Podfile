source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/volcengine/volcengine-specs.git'
source 'https://github.com/byteplus-sdk/byteplus-specs.git'
source 'https://github.com/adjoeio/PlaytimeSpecExternal.git' # Playtime repository

platform :ios, '16.0'

use_frameworks!
# 第三方 Pod 统一以动态 Framework 链接（默认 static 时多为 .a 静态链入）。
# 个别 Pod 若仅提供静态库，仍可能以静态方式打进产物，以厂商 podspec 为准。
use_frameworks! :linkage => :dynamic

# -----------------------------------------------------------------------------
# RangersAPM、AliPlayerSDK_iOS 等为「仅真机」预编译库：模拟器 arm64 下可能链到真机 slice 报错
#   building for iOS-simulator, but linking in object file built for iOS
#
# CocoaPods 只在 `pod install` 时解析依赖，无法根据 Xcode 里选的模拟器/真机自动切换。
# 因此用环境变量决定「本次安装是否带上这些 Pod」。
#
# 【要在模拟器上编译、运行】必须**不安装**上述仅真机 Pod（当前含 RangersAPM、AliPlayerSDK_iOS），任选其一：
#   ./podsim                    （推荐，不会和系统 pod 搞混）
#   ./podsim --repo-update
#   ./pod install -sim          （注意必须是 ./pod，不能写 pod）
#   ./pod install - sim
#   EXCLUDE_DEVICE_ONLY_PODS=1 pod install
#   SIMULATOR_BUILD=YES pod install
#
# 【常见错误】在终端执行 pod install -sim
#   → 用的是系统 pod，会报 Unknown command: -sim。请改用 ./podsim 或 ./pod install -sim。
# 【常见错误】./pod 或 ./podsim 报 permission denied
#   → 在项目根目录执行: chmod +x pod podsim
#
# 【错误示例】SIMULATOR_BUILD=NO pod install
#   → 与不加环境变量一样，会**安装**仅真机 Pod → 模拟器链接仍可能失败。
#
# 【真机调试 / Archive / 需要完整 APM】与平时一致：
#   pod install
#   （或未设置 EXCLUDE_DEVICE_ONLY_PODS、且不要用 SIMULATOR_BUILD=YES）
#
# 切换方式后务必重新 pod install，并 Clean Build Folder。
# -----------------------------------------------------------------------------

omit_device_only_pods = (ENV['EXCLUDE_DEVICE_ONLY_PODS'] == '1') || (ENV['SIMULATOR_BUILD'] == 'YES')

target 'swiftArithmetic' do
  pod 'SDWebImage'
  pod 'ReactiveObjC'
  pod 'FingerprintJS', '1.4.1'
  
#  
#  pod 'QMUIKit/QMUIComponents/QMUIButton',:git => 'https://github.com/bxxmwys/QMUI_iOS.git'
#  pod 'QMUIKit/QMUIComponents/QMUILabel',:git => 'https://github.com/bxxmwys/QMUI_iOS.git'
#  pod 'QMUIKit/QMUIComponents/QMUIPopupMenuView',:git => 'https://github.com/bxxmwys/QMUI_iOS.git'
#  pod 'QMUIKit/QMUIComponents/QMUITextField',:git => 'https://github.com/bxxmwys/QMUI_iOS.git'
#  pod 'QMUIKit/QMUIComponents/QMUITextView',:git => 'https://github.com/bxxmwys/QMUI_iOS.git'


  # 仅当「不排除真机专用 Pod」时才安装下列库（模拟器用 ./podsim 安装时不包含它们）。
  # 业务代码若引用：用 #if canImport(...) / #if !targetEnvironment(simulator) 包住 import。
  unless omit_device_only_pods
    pod 'AliPlayerSDK_iOS'

    pod 'RangersAPM', '4.0.0', :subspecs => [
      'Crash',
      'WatchDog',
      'OOM',
      'LAG',
      'UserException',
      'Monitors',
      'UITrackers',
      'HybridPro',
      'MemoryGraph',
      'NetworkPro',
      'EventMonitor',
      'SessionTracker',
      'APMLog',
      'CrashProtector',
      'CPUException',
      'Zombie',
      'BootingProtect',
      'MetricKit',
      'Disk',
      'GWPASan',
      'Coredump',
      'CloudCommand',
      'CN' # 必须引入
    ]
  end
end

# 仅统一 Pods 的 deployment target，不修改 CocoaPods 生成的 xcconfig / 脚本内容。
post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '16.0'
    end
  end
end

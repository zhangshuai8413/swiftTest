source 'https://github.com/CocoaPods/Specs.git'
source 'https://github.com/volcengine/volcengine-specs.git'
source 'https://github.com/byteplus-sdk/byteplus-specs.git'
source 'https://github.com/adjoeio/PlaytimeSpecExternal.git' # Playtime repository

platform :ios, '16.0'

use_frameworks!

target 'swiftArithmetic' do
  pod 'SDWebImage'
  pod 'ReactiveObjC'
  pod 'FingerprintJS', '1.4.1'
#  pod 'Firebase/Crashlytics', '12.8.0'
#  pod 'Firebase/Analytics', '12.8.0'
#  pod 'Firebase/Messaging', '12.8.0'
#  pod 'RSDesignToken',
#    :git => 'https://gitlab.stardustgod.com/RSPodSpec/RSDesignToken.git',
#    :commit => '292532dc6ad84da8253388d5190f2f30bb2cec90',
#    :modular_headers => true
#    
#  pod 'FBSDKLoginKit', '18.0.2'
#  pod 'TikTokOpenSDKCore', '2.5.0'
#  pod 'TikTokOpenAuthSDK', '2.5.0'
#  pod 'TikTokOpenShareSDK', '2.5.0'
#  pod 'RangersAPM', '4.0.0', :subspecs => [
#      'Crash',
#      'WatchDog',
#      'OOM',
#      'LAG',
#      'UserException',
#      'Monitors',
#      'UITrackers',
#      'HybridPro',
#      'MemoryGraph',
#      'NetworkPro',
#      'EventMonitor',
#      'SessionTracker',
#      'APMLog',
#      'CrashProtector',
#      'CPUException',
#      'Zombie',
#      'BootingProtect',
#      'MetricKit',
#      'Disk',
#      'GWPASan',
#      'Coredump',
#      'CloudCommand',
#      'CN'  #必须引入
#  ]
end

post_install do |installer|
  # Xcode 26 默认不再提供低版本部署目标所需的 libarclite_iphoneos.a
  # 这里强制把所有 Pods target 的 iOS deployment target 提到当前工程一致的版本。
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      config.build_settings['IPHONEOS_DEPLOYMENT_TARGET'] = '16.0'
    end
  end

end


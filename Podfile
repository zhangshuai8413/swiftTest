platform :ios, '16.0'

use_frameworks!

target 'swiftArithmetic' do
  pod 'SDWebImage'
  pod 'ReactiveObjC'
  pod 'FingerprintJS', '1.4.1'
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


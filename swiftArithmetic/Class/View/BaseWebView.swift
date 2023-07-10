//
//  BaseWebView.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/9.
//

import SwiftUI
import SafariServices

struct WebView: UIViewControllerRepresentable {

    var url: URL {
        didSet {
            print("url-----\(url)")
        }
    }

    func makeUIViewController(context: UIViewControllerRepresentableContext<WebView>) -> SFSafariViewController {
        return SFSafariViewController(url: url)
    }

    func updateUIViewController(_ uiViewController: SFSafariViewController, context: UIViewControllerRepresentableContext<WebView>) {}
}

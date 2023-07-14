//
//  BaseWebView.swift
//  swiftArithmetic
//
//  Created by 张帅 on 2023/7/9.
//

import SwiftUI
import SafariServices
import WebKit
struct WebView: UIViewRepresentable {
    let url: URL

    func makeUIView(context: Context) -> WKWebView {
        let webView = WKWebView()
        return webView
    }

    func updateUIView(_ uiView: WKWebView, context: Context) {
        let request = URLRequest(url: url)
        uiView.load(request)
    }
}

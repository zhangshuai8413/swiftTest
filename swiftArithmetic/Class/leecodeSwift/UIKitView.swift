//
//  UIKitView.swift
//  swiftArithmetic
//
//  Created by zhangshuai on 2024/4/20.
//

import SwiftUI
import UIKit


struct UIKitView: UIViewRepresentable {
    func makeUIView(context: Context) -> UIView {
        let view = ListNoteViewController()
        view.view.backgroundColor = .red
        return view.view
    }

    func updateUIView(_ uiView: UIView, context: Context) {
        
    }
}


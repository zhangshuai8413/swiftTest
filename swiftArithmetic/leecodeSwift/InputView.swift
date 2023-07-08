//
//  InputView.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/8.
//

import UIKit

class InputView: UIView, UITextFieldDelegate {
    
    var completionBlock:((_ text: String)-> Void)?
    
    lazy var textField: UITextField = {
        let inputView = UITextField()
        inputView.placeholder = "请输入"
        inputView.textColor = .black
        inputView.font = .systemFont(ofSize: 14)
        inputView.delegate = self
        return inputView
    }()
   
    func becomeFirstResponder() {
        textField.becomeFirstResponder()
    }
    override init(frame: CGRect) {
        super.init(frame: frame)
        commonInit()
    }
    
    func commonInit() {
        addSubview(textField)
        textField.frame = CGRect(x: 10, y: 5, width: 150, height: 80)
    }
    required init?(coder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        if let  text = textField.text {
            completionBlock?(text)
        }
    }
    
    func textFieldDidChangeSelection(_ textField: UITextField) {
        if let  text = textField.text {
            completionBlock?(text)
        }
    }
    func textFieldDidBeginEditing(_ textField: UITextField) {
        if let  text = textField.text {
            completionBlock?(text)
        }
    }
    
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        return true
    }
}

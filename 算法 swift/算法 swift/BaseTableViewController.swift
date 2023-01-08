//
//  BaseTableViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/7.
//

import UIKit

class BaseTableViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    var compleBlock:((_ title: String, IndexPath )-> Void)?
    var textViewCompletionBlock:((_ text: String) ->Void)?
    var inputText: String = ""
    lazy var textView: InputView = {
        let view = InputView()
        view.backgroundColor = UIColor.blue.withAlphaComponent(0.3)
        view.completionBlock = {[weak self] text in
            guard let strongSelf = self else { return }
            strongSelf.textViewCompletionBlock?(text)

        }
        return view
    }()
    
    private let cellIdentifier = "BaseTableViewControllerReusedid"
    
    var dataSource: [String] = []
    
    lazy var tableView: UITableView = {
        let tableView = UITableView(frame: .zero, style: .plain)
        tableView.delegate  = self
        tableView.dataSource = self
        return tableView
    }()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        view.addSubview(tableView)
        tableView.frame = self.view.bounds
        tableView.register(UITableViewCell.self, forCellReuseIdentifier: cellIdentifier)
        view.addSubview(textView)
        textView.frame = CGRect(x: view.frame.width - 200, y: 100, width: 150, height: 80)
        textView.layer.zPosition = 10000
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return dataSource.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard  let cell: UITableViewCell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier) else {return UITableViewCell()}
        cell.textLabel?.text = dataSource[indexPath.row]
        return cell
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        let title = dataSource[indexPath.row]
        compleBlock?(title, indexPath)
        inputView?.becomeFirstResponder()
        
    }
}

//
//  ListNoteViewController.swift
//  算法 swift
//
//  Created by 张帅 on 2023/1/7.
//

import UIKit

class ListNoteViewController: BaseTableViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        title = "二叉链表"
        dataSource = ["移除列表"]
        tableView.reloadData()
 
    }
}

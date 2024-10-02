package com.example.demo;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;

public class ListController {
    public int itemNumber = 0;

    @FXML
    private ListView<String> listView;

    private ObservableList<String> list;

    @FXML
    public void initialize() {
        // Инициализируем список
        list = FXCollections.observableArrayList();
        listView.setItems(list);
    }

    @FXML
    public void handleAddItem() {
        // Добавляем новый элемент в список
        list.add("new item " + itemNumber++);
    }
}
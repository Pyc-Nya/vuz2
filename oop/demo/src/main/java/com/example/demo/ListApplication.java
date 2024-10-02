package com.example.demo;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class ListApplication extends Application {

    @Override
    public void start(Stage stage) throws IOException {
        // Загрузка FXML файла, который соответствует новому интерфейсу списка
        FXMLLoader fxmlLoader = new FXMLLoader(ListApplication.class.getResource("list-view.fxml"));

        // Создаем сцену и загружаем разметку
        Scene scene = new Scene(fxmlLoader.load(), 320, 600); // Увеличил высоту, чтобы соответствовало твоему стилю

        // Подключаем CSS файл
        scene.getStylesheets().add(ListApplication.class.getResource("style.css").toExternalForm());

        // Устанавливаем заголовок окна
        stage.setTitle("To-Do List");

        // Устанавливаем сцену для окна
        stage.setScene(scene);

        // Отображаем окно
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}

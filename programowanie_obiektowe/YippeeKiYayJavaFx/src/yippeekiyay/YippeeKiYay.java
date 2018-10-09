/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package yippeekiyay;

import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.stage.Stage;

/**
 *
 * @author Dabrze
 */
public class YippeeKiYay extends Application {

    /**
     * Obrazek Johna. W projekcie zaliczeniowym lepiej oczywiście trzymać obrazki
     * w jednym z folderów projektu.
     */
    Image bruce;

    /**
     * Współrzędna Johna McClane'a.
     */
    private int x = 0;

    /**
     * ...
     */
    private Canvas map;
    
    @Override
    public void start(Stage stage) throws Exception {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("FXMLDocument.fxml"));
        Parent root = (Parent)loader.load();
        FXMLDocumentController controller = (FXMLDocumentController)loader.getController();
        
        Scene scene = new Scene(root);
        this.map = controller.getMap();
        final GraphicsContext context = this.map.getGraphicsContext2D();
        this.bruce = new Image("http://storage.canoe.ca/v1/dynamic_resize/sws_path/suns-prod-images/1322778266171_ORIGINAL.jpg?quality=80&size=420x");

        stage.setTitle("Wieżowiec");
        stage.setScene(scene);
        stage.show();

        
        Thread renderer = new Thread(){
        
            @Override
            public void run(){
                while (true) {
                    try {
                        Thread.sleep(40);
                    } catch (InterruptedException ex) {
                    }

                    Platform.runLater(new Runnable() {
                        @Override
                        public void run() {
                            context.clearRect(0, 0, context.getCanvas().getWidth(), context.getCanvas().getHeight());
                            context.drawImage(bruce, (x += 2) % 800, 0);
                        }
                    });
                }
            }
        };
        
        renderer.setDaemon(true);
        renderer.start();
    }

    /**
     * The main() method is ignored in correctly deployed JavaFX application.
     * main() serves only as fallback in case the application can not be
     * launched through deployment artifacts, e.g., in IDEs with limited FX
     * support. NetBeans ignores main().
     *
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }

}

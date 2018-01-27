/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxcounter;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;

/**
 *
 * @author wojtekreg
 */
public class FXMLDocumentController implements Initializable {
    
    @FXML
    private Label counterLabel;
    private Button countButton;
    
    @FXML
    private void handleButtonAction(ActionEvent event) {
        counterLabel.setText(Integer.toString(Integer.parseInt(counterLabel.getText())+1));
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}

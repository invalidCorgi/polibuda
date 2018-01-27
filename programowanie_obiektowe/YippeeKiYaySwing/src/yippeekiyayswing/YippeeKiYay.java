package yippeekiyayswing;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;

import javax.imageio.ImageIO;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * Klasa prezentująca jak rysować na JPanelu. Prezentowany sposób korzysta z
 * bibliotek Swinga, gdzie należy przesłonić metodę paintComponent().
 * Korzystając z tej metody korzysta się z tzw. Double Buffering i nie powinno
 * być problemów z "mruganiem" obrazu.
 * 
 * Jeżeli ktoś woli korzystać z elementów zawartych w (starszej) bibliotece AWT
 * to powinien przesłaniać metodę update().
 * 
 * @author Dariusz Brzeziński
 * 
 */
public class YippeeKiYay extends JPanel {

	/**
	 * No comment.
	 */
	private BufferedImage bruce;
	
	/**
	 * Współrzędna Johna McClane'a.
	 */
	private int x = 0;
	
	/**
	 * Metoda główna programu.
	 * 
	 * @param args
	 *            paprametry wejściowe (nieużywane)
	 */
	public static void main(String[] args) throws InterruptedException,
			IOException {
		JFrame window = new JFrame("Wieżowiec");
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		YippeeKiYay m = new YippeeKiYay();
		window.add(m);
		window.setSize(800, 600);
		window.setVisible(true);

		while (true) {
			Thread.sleep(40);
			m.repaint();
		}
	}

	/**
	 * Przesłonięta metoda paintComponent().
	 * To ta metoda rysuje komponenet, w tym przypadku
	 * JPanel.
	 */
	@Override
	public void paintComponent(Graphics g) {
		g.clearRect(0, 0, this.getWidth(), this.getHeight());
		g.drawImage(bruce, (x += 2) % 800, 0, null);
	}

	/**
	 * Konstruktor.
	 * Pobiera z Internetu rysunek do wyświetlania.
	 * Do projektu lepiej oczywiście trzymać obrazki
	 * w jednym z folderów projektu.
	 * @throws IOException klauzula throws mówi, że może
	 * pojawić się wyjątek. Wyjątek dotyczy otwierania pliku,
	 * podczas którego może pojawić się wiele problemów 
	 * (np. brak pliku, plik zablokowany). Na następnych zajęciach
	 * omówimy dokładniej mechanizm rzucania i łapania wyjątków.
	 */
	public YippeeKiYay() throws IOException {
		bruce = ImageIO.read(new URL("http://storage.canoe.ca/v1/dynamic_resize/sws_path/suns-prod-images/1322778266171_ORIGINAL.jpg?quality=80&size=420x"));
	}
}

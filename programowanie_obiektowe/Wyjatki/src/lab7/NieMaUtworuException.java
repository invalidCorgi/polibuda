package lab7;

/**
 * Klasa reprezentująca wyjątek występujący, gdy na wybranej 
 * w szafie grającej płycie nie ma utworu.
 */
public class NieMaUtworuException extends RuntimeException {
	
	/**
	 * Konstruktor wyjątku.
	 */
	public NieMaUtworuException(){
		super();
	}
	
	/**
	 * Konstruktor wyjątku.
	 * @param message opis błędu 
	 */
	public NieMaUtworuException(String message){
		super(message);
	}
	
	/**
	 * Konstruktor wyjątku.
	 * @param message opis błędu 
	 * @param cause wyjątek będący przyczyną błędu
	 */
	public NieMaUtworuException(String message, Exception cause){
		super(message, cause);
	}
}

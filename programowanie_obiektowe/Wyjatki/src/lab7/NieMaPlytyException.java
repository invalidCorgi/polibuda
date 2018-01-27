package lab7;

/**
 * Klasa reprezentująca wyjątek występujący, gdy
 * w szafie grającej nie ma wskazanej płyty.
 */
public class NieMaPlytyException extends Exception {

	/**
	 * Konstruktor wyjątku.
	 */
	public NieMaPlytyException(){
		super();
	}
	
	/**
	 * Konstruktor wyjątku.
	 * @param message opis błędu 
	 */
	public NieMaPlytyException(String message){
		super(message);
	}
	
	/**
	 * Konstruktor wyjątku.
	 * @param message opis błędu 
	 * @param cause wyjątek będący przyczyną błędu
	 */
	public NieMaPlytyException(String message, Exception cause){
		super(message, cause);
	}
}

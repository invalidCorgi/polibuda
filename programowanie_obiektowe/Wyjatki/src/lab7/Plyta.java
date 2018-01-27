package lab7;

import java.util.ArrayList;
import java.util.List;

/**
 * Klasa reprezentująca płytę w szafie grającej.
 */
public class Plyta {
	private String nazwa;
	private ArrayList<String> utwory;
	
	/**
	 * Konstruktor.
	 * @param nazwaPlyty nazwa tworzonej płyty
	 * @param utwory utwory znajdujące się na tworzonej płycie
	 */
	public Plyta(String nazwaPlyty, List<String> utwory){
		this.nazwa = nazwaPlyty;
		this.utwory = new ArrayList<String>(utwory);
	}
	
	/**
	 * Zwraca tytuł płyty.
	 * @return tytuł płyty
	 */
	public String getNazwa() {
		return this.nazwa;
	}
	
	/**
	 * Zwraca listę utworów znajdujących sie na płycie.
	 * @return listę utworów znajdujących sie na płycie
	 */
	public ArrayList<String> getUtwory() {
		return this.utwory;
	}
	
	@Override
	public String toString(){
		return this.nazwa;
	}
}

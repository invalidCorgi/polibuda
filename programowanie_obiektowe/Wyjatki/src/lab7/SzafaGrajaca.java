package lab7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class SzafaGrajaca {

    /**
     * Szafa: słownik o kluczu będącym nazwą płyty i wartości będącej Płytą.
     */
    private HashMap<String, Plyta> plyty;

    /**
     * Konstruktor szafy grającej. Uzupełnia szafę grającą płytami.
     */
    public SzafaGrajaca() {
        this.plyty = new HashMap<String, Plyta>();

        // // Pierwsza płyta
        ArrayList<String> satchUtwory = new ArrayList<String>();
        satchUtwory.add("Gnaahh");
        satchUtwory.add("Up in Flames");
        satchUtwory.add("Hands in the Air");
        satchUtwory.add("Lifestyle");
        satchUtwory.add("Is There Love in Space?");
        satchUtwory.add("If I Could Fly");
        satchUtwory.add("The Souls of Distortion");
        satchUtwory.add("Just Look Up");
        satchUtwory.add("I Like the Rain");
        satchUtwory.add("Searching");
        satchUtwory.add("Bamboo");

        // // Druga płyta
        ArrayList<String> andyUtwory = new ArrayList<String>();
        andyUtwory.add("All Is Forgiven");
        andyUtwory.add("Happening '68");
        andyUtwory.add("The Princess");
        andyUtwory.add("Nowhere");
        andyUtwory.add("For God and Country");
        andyUtwory.add("Don't Bring Me Down");
        andyUtwory.add("Astral Fishing");
        andyUtwory.add("Duende");
        andyUtwory.add("The Spoken and Unspoken");
        andyUtwory.add("Olivia's Song");

        Plyta loveInSpace = new Plyta("Is There Love in Space?", satchUtwory);
        Plyta spokenAndUnspoken = new Plyta("The Spoken and Unspoken", andyUtwory);

        this.plyty.put(loveInSpace.getNazwa(), loveInSpace);
        this.plyty.put(spokenAndUnspoken.getNazwa(), spokenAndUnspoken);
    }

    public static void main(String[] args) throws IOException, InterruptedException {
        SzafaGrajaca szafa = new SzafaGrajaca();
        szafa.graj();
    }

    public void graj() throws IOException, InterruptedException {
        //// Obiekt potrzebny do czytania z konsoli
        BufferedReader stin = new BufferedReader(new InputStreamReader(System.in));
        String nazwaUtworu = null;

        System.out.println("Witaj w programie Szafa Grająca!");

        while (true) {
            Plyta wybranaPlyta = null;
            do {

                try {
                    wybranaPlyta = wybierzPlyte(stin);
                } catch (NieMaPlytyException ex) {
                    System.out.println("Wybrana płyta nie istnieje");
                }
            } while (wybranaPlyta == null);

            System.out.println("Świetny wybór!");
            do {
                try {
                    nazwaUtworu = wybierzUtwor(stin, wybranaPlyta);
                    Random rand = new Random();
                    if (rand.nextBoolean()) {
                        throw new PlytaPorysowanaException();
                    }
                    
                } catch (IndexOutOfBoundsException ex) {
                    System.out.println("Nie ma tylu utworów na tej płycie");
                } catch (NumberFormatException ex) {
                    System.out.println("Prosimy wpisać liczbę");
                } catch (PlytaPorysowanaException ex) {
                    System.out.println("Płyta porysowana");
                }
            } while (!wybranaPlyta.getUtwory().contains(nazwaUtworu));
            break;
        }

        System.out.println("Z płyty \"" + wybranaPlyta + "\" specjalnie dla Was utwór \"" + nazwaUtworu + "\"");
        System.out.println("Siala lala...");
        Thread.sleep(1500);

        System.out.println("Dziękujemy za korzystanie z programu Szafa Grająca!");

    }

    public Plyta wybierzPlyte(BufferedReader stin) throws IOException, NieMaPlytyException {
        String nazwaPlyty;
        System.out.print("Podaj nazwę płyty, którą chcesz odtworzyć: ");
        //// Czytamy to co wpisze użytkownik
        nazwaPlyty = stin.readLine();

        Plyta wybranaPlyta = this.plyty.get(nazwaPlyty);

        if (wybranaPlyta == null) {
            throw new NieMaPlytyException();
        }

        return wybranaPlyta;
    }

    public String wybierzUtwor(BufferedReader stin, Plyta wybranaPlyta)
            throws IOException {
        String nazwaUtworu;
        int nrUtworu;
        System.out.print("Podaj numer utworu, który chcesz odtworzyć: ");
        nrUtworu = Integer.parseInt(stin.readLine());

        nazwaUtworu = wybranaPlyta.getUtwory().get(nrUtworu - 1);
        return nazwaUtworu;
    }
}

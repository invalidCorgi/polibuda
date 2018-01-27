// Materiały zaczerpnięte z 'Thinking in Java, 3rd ed.' (c)
// Bruce Eckel 2002 www.BruceEckel.com.

/**
 * KLasa pokazująca możliwe konsekwencje dostępu
 * do zmiennej z wielu wątków.
 */
public class AlwaysEven {

    /**
     * Zmienna przechowująca zmienną o wartości parzystej.
     */
    private int i;

    private final Object o = new Object();

    /**
     * Metoda zwraca kolejne liczby parzyste.
     */
    public void next() {
        synchronized (o) {
            i++;
            i++;
        }
        //i+=2;
    }

    /**
     * Pobiera wartość zmiennej i.
     *
     * @return wartość parzystą?
     */
    public int getValue() {
        synchronized (o) {
            return i;
        }
    }

    /**
     * Głowna metoda programu.
     *
     * @param args
     */
    public static void main(String[] args) {
        final AlwaysEven ae = new AlwaysEven();

        //Wątek sprawdzający kolejne liczby parzyste
        new Thread("Watcher") {

            public void run() {
                while (true) {
                    int val = ae.getValue();
                    if (val % 2 != 0) {
                        System.out.println("wrong: " + val);
                        System.exit(0);
                    }
                }
            }
        }.start();

        // pętla generująca kolejne liczby parzyste
        while (true) {
            ae.next();
        }
    }
}

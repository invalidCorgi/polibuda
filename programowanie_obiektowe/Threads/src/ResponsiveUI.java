// Materiały zaczerpnięte z 'Thinking in Java, 3rd ed.' (c)
// Bruce Eckel 2002 www.BruceEckel.com.

class UnresponsiveUI {

    private volatile double d = 1;

    public UnresponsiveUI() throws Exception {
        while (d > 0) {
            d = d + (Math.PI + Math.E) / d;
        }
        System.in.read(); // Kod nigdy tu nie dojdzie
    }
}

public class ResponsiveUI extends Thread {

    private static volatile double d = 1;

    public ResponsiveUI() {
        setDaemon(true);
        start();
    }

    public void run() {
        while (true) {
            d = d + (Math.PI + Math.E) / d;
        }
    }

    public static void main(String[] args) throws Exception {
        //! new UnresponsiveUI(); // Jeśli ta linia zostanie odkomentowana, program będzie trzeba zabić ręcznie
        new ResponsiveUI();
        Thread.sleep(300);
        System.in.read();
        System.out.println(d);
    }
}


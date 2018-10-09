package lab7;

public class ObslugiwanyWyjatek {
	  void głębiej(String s) throws Exception {
	    System.out.println("początek głębiej");
	    if (s == null) throw new Exception();
	    System.out.println("koniec głębiej");
	  }

	  void głęboko(String s) {
	    try {
	      System.out.println("początek głęboko");
	      głębiej(s);
	      System.out.println("koniec głęboko");
	    } catch (Exception e) {
	      System.out.println("obsługa wyjątku");
	      e.printStackTrace(System.out);
	    }
	    System.out.println("po obsłużeniu wyjątku");
	  }

	  public static void main(String[] args) {
		ObslugiwanyWyjatek ep = new ObslugiwanyWyjatek();
	    System.out.println("przed głęboko");
	    ep.głęboko(null);
	    System.out.println("po głęboko");
	  }
	}

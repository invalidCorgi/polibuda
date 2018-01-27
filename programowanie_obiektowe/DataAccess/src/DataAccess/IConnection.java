/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package DataAccess;

/**
 * Interfejs połączenia z bazą danych
 * @author Maciej Piernik
 */
public interface IConnection
{
    /**
     * Otwiera połączenie z bazą danych
     * @return Czy udało sie nawiązać połączenie
     */
    boolean Open();

    /**
     * Zamyka połączenie z bazą danych
     * @return Czy udało się zamknąć połączenie
     */
    boolean Close();

    /**
     * Informacja o statusie połączenia. True - otwarte, false - zamknięte.
     * @return Status połączenia
     */
    boolean IsOpen();

    /**
     * Zwraca informację o nazwie użytkownika
     * @return Nazwa użytkownika
     */
    String getUsername();

    /**
     * Zwraca informację o haśle użytkownika
     * @return Hasło
     */
    String getPassword();

    /**
     * Baza danych, z którą nawiązane jest połączenie.
     * @return Baza danych
     */
    Database getDatabase();
}

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package DataAccess;

import java.util.List;
import java.util.Map;

/**
 * Interfejs dostępu do bazy danych
 * @author Maciej Piernik
 */
public interface IDatabase
{
    /**
     * Tworzy nowy obiekt połączenia z bazą danych.
     * @param userName Nazwa użytkownika
     * @param password Hasło
     * @return Nowe połączenie do bazy danych
     */
    IConnection GetNewConnection(String userName, String password);

    /**
     * Pobiera dane z bazy
     * @param connection Połączenie z bazą danych
     * @return Dane
     * Dane przedstawione są w formie listy dziesięciu słowników. Każdy zawiera trzy klucze: pesel, imie, nazwisko.
     * Wartości dla kolejnych kluczy to:
     * - pesel (int): kolejne numery od 0 do 9
     * - imie (String): Imie_0, Imie_1, ..., Imie_9
     * - nazwisko (String): Nazwisko_0, Nazwisko_1, ..., Nazwisko_9
     * Jeśli nie można pobrać danych, bo połączenie nie zostało nawiązane, zwraca null.
     */
    List<Map<String, Object>> GetData(IConnection connection);

    /**
     * Zwraca nazwę bazy danych
     * @return Nazwa bazy danych
     */
    String getDatabaseName();
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package gieldasymulator2k18;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author wojtekreg
 */
public class Aktywa {

    protected String nazwa;
    protected LocalDateTime dataPierwszejWyceny;
    protected Double kursOtwarcia;
    protected Double kursMinimalny;
    protected Double kursMaksymalny;
    protected Double kursAktualny;
    protected Double wolumen;
    protected Double obroty;
    protected List<WpisHistorii> historiaKursu;
    protected Long liczbaKupujacych;
    protected Long liczbaSprzedajacych;

    public Aktywa() {
        
    }
    
    

    /**
     * @return the nazwa
     */
    public String getNazwa() {
        return nazwa;
    }

    /**
     * @param nazwa the nazwa to set
     */
    public void setNazwa(String nazwa) {
        this.nazwa = nazwa;
    }

    /**
     * @return the dataPierwszejWyceny
     */
    public LocalDateTime getDataPierwszejWyceny() {
        return dataPierwszejWyceny;
    }

    /**
     * @param dataPierwszejWyceny the dataPierwszejWyceny to set
     */
    public void setDataPierwszejWyceny(LocalDateTime dataPierwszejWyceny) {
        this.dataPierwszejWyceny = dataPierwszejWyceny;
    }

    /**
     * @return the kursOtwarcia
     */
    public Double getKursOtwarcia() {
        return kursOtwarcia;
    }

    /**
     * @param kursOtwarcia the kursOtwarcia to set
     */
    public void setKursOtwarcia(Double kursOtwarcia) {
        this.kursOtwarcia = kursOtwarcia;
    }

    /**
     * @return the kursMinimalny
     */
    public Double getKursMinimalny() {
        return kursMinimalny;
    }

    /**
     * @param kursMinimalny the kursMinimalny to set
     */
    public void setKursMinimalny(Double kursMinimalny) {
        this.kursMinimalny = kursMinimalny;
    }

    /**
     * @return the kursMaksymalny
     */
    public Double getKursMaksymalny() {
        return kursMaksymalny;
    }

    /**
     * @param kursMaksymalny the kursMaksymalny to set
     */
    public void setKursMaksymalny(Double kursMaksymalny) {
        this.kursMaksymalny = kursMaksymalny;
    }

    /**
     * @return the kursAktualny
     */
    public Double getKursAktualny() {
        return kursAktualny;
    }

    /**
     * @param kursAktualny the kursAktualny to set
     */
    public void setKursAktualny(Double kursAktualny) {
        this.kursAktualny = kursAktualny;
    }

    /**
     * @return the wolumen
     */
    public Double getWolumen() {
        return wolumen;
    }

    /**
     * @param wolumen the wolumen to set
     */
    public void setWolumen(Double wolumen) {
        this.wolumen = wolumen;
    }

    /**
     * @return the obroty
     */
    public Double getObroty() {
        return obroty;
    }

    /**
     * @param obroty the obroty to set
     */
    public void setObroty(Double obroty) {
        this.obroty = obroty;
    }

    /**
     * @return the historiaKursu
     */
    public List<WpisHistorii> getHistoriaKursu() {
        return historiaKursu;
    }

    /**
     * @param historiaKursu the historiaKursu to set
     */
    public void setHistoriaKursu(List<WpisHistorii> historiaKursu) {
        this.historiaKursu = historiaKursu;
    }

    /**
     * @return the liczbaKupujacych
     */
    public Long getLiczbaKupujacych() {
        return liczbaKupujacych;
    }

    /**
     * @param liczbaKupujacych the liczbaKupujacych to set
     */
    public void setLiczbaKupujacych(Long liczbaKupujacych) {
        this.liczbaKupujacych = liczbaKupujacych;
    }

    /**
     * @return the liczbaSprzedajacych
     */
    public Long getLiczbaSprzedajacych() {
        return liczbaSprzedajacych;
    }

    /**
     * @param liczbaSprzedajacych the liczbaSprzedajacych to set
     */
    public void setLiczbaSprzedajacych(Long liczbaSprzedajacych) {
        this.liczbaSprzedajacych = liczbaSprzedajacych;
    }
}

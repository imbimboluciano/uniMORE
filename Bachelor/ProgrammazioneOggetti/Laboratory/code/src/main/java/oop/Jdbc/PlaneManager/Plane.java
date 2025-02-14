package oop.Jdbc.PlaneManager;

import java.util.Objects;

public class Plane {

    String nomeAereo;
    String compagnia;
    double width;
    double height;
    double wingSpan;
    String idCode;

    public Plane(String nomeAereo, String compagnia, double width, double height, double wingSpan, String idCode) {
        this.nomeAereo = nomeAereo;
        this.compagnia = compagnia;
        this.width = width;
        this.height = height;
        this.wingSpan = wingSpan;
        this.idCode = idCode;
    }

    public String getNomeAereo() {
        return nomeAereo;
    }

    public void setNomeAereo(String nomeAereo) {
        this.nomeAereo = nomeAereo;
    }

    public String getCompagnia() {
        return compagnia;
    }

    public void setCompagnia(String compagnia) {
        compagnia = compagnia;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getWingSpan() {
        return wingSpan;
    }

    public void setWingSpan(double wingSpan) {
        this.wingSpan = wingSpan;
    }

    public String getIdCode() {
        return idCode;
    }

    public void setIdCode(String idCode) {
        this.idCode = idCode;
    }

    public String toCSV(){
        return nomeAereo + ';' + compagnia +  ';' +  width +  ';' +  height + ';' + wingSpan + ';' + idCode;
    }

    @Override
    public String toString() {
        return "Plane{" +
                "nomeAereo='" + nomeAereo + '\'' +
                ", Compagnia='" + compagnia + '\'' +
                ", width=" + width +
                ", height=" + height +
                ", wingSpan=" + wingSpan +
                ", idCode='" + idCode + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Plane plane = (Plane) o;
        return Double.compare(plane.width, width) == 0 && Double.compare(plane.height, height) == 0 && Double.compare(plane.wingSpan, wingSpan) == 0 && Objects.equals(nomeAereo, plane.nomeAereo) && Objects.equals(compagnia, plane.compagnia) && Objects.equals(idCode, plane.idCode);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nomeAereo, compagnia, width, height, wingSpan, idCode);
    }
}

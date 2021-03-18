package kz.aues.lab12a;

import android.graphics.Bitmap;
import android.os.Parcel;
import android.os.Parcelable;

public class Сountry implements Parcelable {
    private Bitmap picture;
    private String info;
    private String title;
    private String capital;
    private int area;
    private int population;
    private String continent;


    public Сountry(Bitmap picture, String info) {
        this.picture = picture;
        this.info = info;
    }
    public Сountry(String str){
        String[] w = str.split("-");
        this.title=w[0];
        this.capital=w[1];
        this.area=Integer.valueOf(w[2]);
        this.population=Integer.valueOf(w[3]);
        this.continent = w[4];
    }

    public Сountry() {}

    protected Сountry(Parcel in) {
        picture = in.readParcelable(Bitmap.class.getClassLoader());
        info = in.readString();
        title = in.readString();
        capital = in.readString();
        area = in.readInt();
        population = in.readInt();
        continent = in.readString();
    }

    public static final Creator<Сountry> CREATOR = new Creator<Сountry>() {
        @Override
        public Сountry createFromParcel(Parcel in) {
            return new Сountry(in);
        }

        @Override
        public Сountry[] newArray(int size) {
            return new Сountry[size];
        }
    };

    public Bitmap getPicture() {
        return picture;
    }

    public void setPicture(Bitmap picture) {
        this.picture = picture;
    }

    public String getInfo() {
        return info;
    }

    public void setInfo(String info) {
        this.info = info;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getCapital() {
        return capital;
    }

    public void setCapital(String capital) {
        this.capital = capital;
    }

    public int getArea() {
        return area;
    }

    public void setArea(int area) {
        this.area = area;
    }

    public int getPopulation() {
        return population;
    }

    public void setPopulation(int population) {
        this.population = population;
    }

    public String getContinent() {
        return continent;
    }

    public void setContinent(String continent) {
        this.continent = continent;
    }

    public void setInformation(String str){
        String[] w = str.split("-");
        this.title=w[0];
        this.capital=w[1];
        this.area=Integer.valueOf(w[2]);
        this.population=Integer.valueOf(w[3]);
        this.continent = w[4];
    }

    @Override
    public String toString() {
        return "Страна: " + title + '\n' +
                "Столица: " + capital + '\n' +
                "Площадь: " + area + '\n' +
                "Население: " + population + '\n' +
                "Континент: " + continent;
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeParcelable(picture, flags);
        dest.writeString(info);
        dest.writeString(title);
        dest.writeString(capital);
        dest.writeInt(area);
        dest.writeInt(population);
        dest.writeString(continent);
    }
}

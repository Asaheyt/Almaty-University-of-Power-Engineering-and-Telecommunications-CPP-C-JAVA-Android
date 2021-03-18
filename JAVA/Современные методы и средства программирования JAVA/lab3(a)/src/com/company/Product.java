package com.company;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

/**
 * Created by Adil on 03.10.2018.
 */
public class Product {

    private String name;
    private MyDate date;
    private int shelf_life;
    private double price;
    private int id;

    public Product(){}
    public Product(String n, MyDate d, int sl, double p, int i){
        this.name=n;
        this.date=d;
        this.shelf_life=sl;
        this.price=p;
        this.id=i;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public MyDate getDate() {
        return date;
    }

    public void setDate(MyDate date) {
        this.date = date;
    }

    public int getShelf_life() {
        return shelf_life;
    }

    public void setShelf_life(int shelf_life) {
        this.shelf_life = shelf_life;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
    public void show(){
        System.out.println("|Наименование: "+name+"\t |Дата производства "+ date+"\t\t |Срок годности "+shelf_life+" |Цена "+price+" \t |№ серии "+id);
    }
}

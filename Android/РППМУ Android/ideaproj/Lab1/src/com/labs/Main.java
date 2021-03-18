package com.labs;

public class Main {

    public static void main(String[] args) {
        Magistracy m = new Magistracy();
        Undergraduate p =new Undergraduate("Petr", 21, "Almaty", "VT", 2020, 2022);
        m.fill(5);
        m.show();
        m.sortbyBegin();
        System.out.println();
        m.show();
        m.add(p);
        System.out.println();
        m.show();
        m.delLast();
        System.out.println();
        m.show();




    }
}

package com.company;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        List<Numeric_object> numbers=new ArrayList<>();
        numbers.add(new Real_number(-5));
        numbers.add(new Complex_number(5,10));
        numbers.add(new Real_number(7));
        numbers.add(new Complex_number(7,-11));
        numbers.add(new Real_number(8));
        numbers.add(new Complex_number(8,12));
        numbers.add(new Real_number(-3));
        numbers.add(new Complex_number(3,7));
        numbers.add(new Real_number(2));
        numbers.add(new Complex_number(2,1));
        for (Numeric_object r: numbers) {
            System.out.println("Модуль: " + r.module());
        }
        System.out.println();

        List<INumericObject> numbers1=new ArrayList<>();
        numbers1.add(new Real_number(-5));
        numbers1.add(new Complex_number(5,10));
        numbers1.add(new Real_number(7));
        numbers1.add(new Complex_number(7,-11));
        numbers1.add(new Real_number(8));
        numbers1.add(new Complex_number(8,12));
        numbers1.add(new Real_number(-3));
        numbers1.add(new Complex_number(3,7));
        numbers1.add(new Real_number(2));
        numbers1.add(new Complex_number(2,1));
        for (INumericObject r: numbers1) {
            System.out.println("Модуль: " + r.module1());
        }


    }
}

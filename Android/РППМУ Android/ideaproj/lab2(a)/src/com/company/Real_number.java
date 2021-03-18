package com.company;

public class Real_number extends Numeric_object implements INumericObject {

    private double number;

    public Real_number() {}

    public Real_number(double number) {
        this.number = number;
    }

    public double getNumber() {
        return number;
    }

    public void setNumber(double number) {
        this.number = number;
    }

    @Override
    public String toString() {
        return "Действительное число: " + number;
    }

    @Override
    public double module() {
        return Math.abs(number);
    }

    public void showModule(){
        System.out.println("Модуль: "+this.module());
    }

    @Override
    public double module1() {
        return Math.abs(number);
    }
}

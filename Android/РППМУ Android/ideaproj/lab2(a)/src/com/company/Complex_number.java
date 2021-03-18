package com.company;

public class Complex_number extends Numeric_object implements INumericObject {

    private double real;
    private double imaginary;

    public Complex_number() {}

    public Complex_number(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public double getReal() {
        return real;
    }

    public void setReal(double real) {
        this.real = real;
    }

    public double getImaginary() {
        return imaginary;
    }

    public void setImaginary(double imaginary) {
        this.imaginary = imaginary;
    }

    @Override
    public String toString() {
        return "Комплексное число: " + real + "+i" + imaginary;
    }

    @Override
    public double module() {
        return Math.sqrt(real * real + imaginary * imaginary);
    }

    public void showModule(){
        System.out.println("Модуль: "+this.module());
    }

    @Override
    public double module1() {
        return Math.sqrt(real * real + imaginary * imaginary);
    }
}

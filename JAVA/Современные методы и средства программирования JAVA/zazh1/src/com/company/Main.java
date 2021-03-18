package com.company;

import com.sun.javafx.scene.layout.region.Margins;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here

        int n;
        double r,v=0;
        Scanner in=new Scanner(System.in);
        System.out.println("Введите количество шаров");
        n= in.nextInt();
        System.out.println("Введите радиус");
        r=in.nextDouble();
        for (int i=0;i<n;i++){
            v+=4*3.14*r*r*r/3;
            r+=0.2;
        }
        v=v/n;
        System.out.println("Средний объем шаров = " + v);



    }
}

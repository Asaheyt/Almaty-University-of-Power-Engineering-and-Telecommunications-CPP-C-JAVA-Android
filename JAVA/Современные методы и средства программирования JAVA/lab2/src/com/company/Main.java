package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here


        double x,y,z=0,min=2;
        for(x=1;x<=5;x+=0.5){
            y=Math.cos(x)+x*x/10;
            System.out.println(x);
            System.out.println(y);
            if(min>y){
                min=y;
            }
            if(y<0){
                z+=y;
            }
        }
        System.out.println("Минимальный элемент = " + min);
        System.out.println("Сумма отрицательных элементов = " + z);




        /*
        double x=1,y,z=0,min=2;
        while(x<=5){
            y=Math.cos(x)+x*x/10;
            //System.out.println(x);
            //System.out.println(y);
            x+=0.5;
            if(min>y){
                min=y;
            }
            if(y<0){
                z+=y;
            }
        }
        System.out.println("Минимальный элемент = " + min);
        System.out.println("Сумма отрицательных элементов = " + z);
        */



        /*
        double x=1,y,z=0,min=2;
        do{
            y=Math.cos(x)+x*x/10;
            //System.out.println(x);
            //System.out.println(y);
            x+=0.5;
            if(min>y){
                min=y;
            }
            if(y<0){
                z+=y;
            }
        }
        while(x<=5);
        System.out.println("Минимальный элемент = " + min);
        System.out.println("Сумма отрицательных элементов = " + z);
        */






    }
}

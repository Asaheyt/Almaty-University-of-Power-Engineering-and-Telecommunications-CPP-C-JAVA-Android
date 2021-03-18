package com.company;

import java.util.Random;

public class Main {

    public static void main(String[] args) {
	// write your code here

/*
        int [] x=new int [12];
        Random rnd=new Random();
        for(int i=0;i<12;i++)
        {
            x[i]=rnd.nextInt(20)-10;
            System.out.print(x[i]+"\t");
        }
        for(int i=0;i<12;i++){
            if(x[i]<0){
                x[i]=0;
            }
            if(x[i]>0){
                x[i]=1;
            }
        }
        System.out.println();
        for(int i=0;i<12;i++)
        {
            System.out.print(x[i]+"   ");
        }
*/


/*
        int [] a=new int [4];
        int [] c=new int [6];
        int [] x=new int[10];
        int a1=0,c1=0,x1=0;
        Random rnd=new Random();
        for(int i=0;i<a.length;i++)
        {
            a[i]=rnd.nextInt(20)-10;
            System.out.print(a[i]+"\t");
            if(a[i]>0){
                a1+=a[i];
                x[x1]=a[i];
                x1++;
            }
        }
        System.out.println("\n Сумма положительных элементоа массива А = "+a1);
        for(int i=0;i<c.length;i++)
        {
            c[i]=rnd.nextInt(20)-10;
            System.out.print(c[i]+"\t");
            if(c[i]>0){
                c1+=c[i];
                x[x1]=c[i];
                x1++;
            }
        }
        System.out.println("\n Сумма положительных элементоа массива C = "+c1);
        for(int i=0;i<x1;i++)
        {
            System.out.print(x[i]+"\t");
        }
        System.out.println();
        int min=1000;
        for(int i=0;i<x1;i++)
        {
            if(min>x[i]){
                min=x[i];
            }
        }
        System.out.println("Наименьший элемент = " + min);
*/

/*
        int [][] x=new int[5][5];
        Random rnd =new Random();
        for(int i=0;i<5;i++)
        {
            for (int j=0;j<5;j++){
                x[i][j]=rnd.nextInt(20)-10;
                System.out.print(x[i][j]+"\t");
            }
            System.out.println();
        }
        int x1=1;
        for(int i=0;i<5;i++)
        {
            if(x[i][i]>0){
                x1*=x[i][i];
            }
        }
        System.out.println("Произведение положительных элементов главной диагонали " + x1);
*/



        int [][] a=new int[5][5];
        Random rnd =new Random();
        for(int i=0;i<5;i++)
        {
            for (int j=0;j<5;j++){
                a[i][j]=rnd.nextInt(20)-10;
                System.out.print(a[i][j]+"\t");
            }
            System.out.println();
        }
        System.out.println("\n\n");
        int k=1;
        for(int i=0;i<5;i++)
        {
            a[i][k]=a[k][i];
        }
        for(int i=0;i<5;i++)
        {
            for (int j=0;j<5;j++){
                System.out.print(a[i][j]+"\t");
            }
            System.out.println();
        }






    }
}

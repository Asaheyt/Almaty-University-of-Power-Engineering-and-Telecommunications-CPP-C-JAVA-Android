package com.company;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Random;

/**
 * Created by Adil on 03.10.2018.
 */
public class Market {
    private Product[] products;
    private int size;
    public Market(){}
    final String [] names={"Севен  ","Привет","Добрый","Джуйс  ","Спрайт","Фанта ","Сочный","Кола  ","Фьюзти","Нектар"};
    Random rnd=new Random();
    MyDate d;
    public void RandomFilling(int s){
        this.size=s;
        products=new Product[s];
        for(int i=0;i<s;i++){
            this.products[i]=new Product();
            this.products[i].setName(names[rnd.nextInt(10)]);
            d=new MyDate();
            d.setDate(rnd.nextInt(30)+1,rnd.nextInt(11)+1,rnd.nextInt(4)+2014);
            this.products[i].setDate(d);
            this.products[i].setShelf_life(rnd.nextInt(2)+1);
            this.products[i].setPrice(rnd.nextInt(300)+1);
            this.products[i].setId(rnd.nextInt(100)+1);
        }
    }
    public void ShowFullInf(){
        for(int i=0;i<size;i++){
            products[i].show();
        }
    }
    public void ShowCertain()
    {
        for(int i=0;i<size;i++){
            System.out.println("Наименование: "+products[i].getName()+"\t |Годен до: "+products[i].getDate().getMonth()+"."+products[i].getDate().getDay()+"."+(products[i].getDate().getYear()+products[i].getShelf_life()));
        }
    }

}

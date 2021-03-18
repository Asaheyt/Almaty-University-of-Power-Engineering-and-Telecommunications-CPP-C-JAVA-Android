package com.company;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class Theater {
    private String name;
    private List<Actor> actors =new ArrayList<Actor>();

    public Theater(String name) {
        this.name = name;
    }

    public Theater(){}

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void show () {
        for (Actor r:actors) {
            System.out.println(r.toString());
        }
        System.out.println();
    }

    public void add (Actor r) {
        actors.add(r);
    }

    public void delLast () {
        actors.remove(actors.size()-1);
    }

    public void fill(int num) {
        Random rnd = new Random();
        String[] names = {"Александр", "Абылай", "Джон", "Матс", "Томас", "Джульетта", "Алексис", "Лара", "Лео", "Хамес"};
        String[] types = {"злодей", "герой", "учитель", "родитель", "друг", "наставник", "лидер", "весельчак", "умник"};
        for (int i = 0; i < num; i++) {
            Actor x = new Actor();
            x.setName(names[rnd.nextInt(9)]);
            x.setExperience(1+rnd.nextInt(20));
            x.setType(types[(rnd.nextInt(8))]);
            x.setSalary(1000+rnd.nextInt(4000));
            x.setNumber_of_roles(5+rnd.nextInt(19));
            actors.add(x);
        }
    }

    public void sortbyName ()
    {
        Collections.sort(actors, ((o1, o2) -> {
            return o1.getName().compareTo(o2.getName());
        }));
    }

    public void sortbyType ()
    {
        Collections.sort(actors, ((o1, o2) -> {
            return o1.getType().compareTo(o2.getType());
        }));
    }

    public void sortbySalary() {
        Collections.sort(actors, ((o1, o2) -> {
            return o1.getSalary()-o2.getSalary();
        }));
    }

    public void sortbyNumberOfRoles() {
        Collections.sort(actors, ((o1, o2) -> {
            return o1.getNumber_of_roles()-o2.getNumber_of_roles();
        }));
    }

    public void sortbyExperience() {
        Collections.sort(actors, ((o1, o2) -> {
            return o1.getExperience()-o2.getExperience();
        }));
    }
}

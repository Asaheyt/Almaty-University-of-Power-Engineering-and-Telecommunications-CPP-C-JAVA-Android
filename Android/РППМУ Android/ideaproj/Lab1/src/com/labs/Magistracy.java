package com.labs;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import  java.util.Comparator;

public class Magistracy {
    private List<Undergraduate> magistranty = new ArrayList<>();
    int count=0;
    public void fill(int num) {
        Random rnd = new Random();
        String[] names = {"Чех", "Терри", "Мюллер", "Хуммельс", "Санчес", "Бэйл", "Модрич", "Сильва", "Рональдо", "Месси"};
        String[] study_places = {"США", "Германия", "Италия", "Испания", "Россия", "Англия", "Ирландия", "Бельгия", "Исландия"};
        String[] specs = {"ВТ", "АУ", "ИС", "ИНФ"};
        for (int i = 0; i < num; i++) {
            Undergraduate x = new Undergraduate();
           x.setName(names[rnd.nextInt(9)]);
                   x.setAge(18+rnd.nextInt(5));
                   x.setStudy_place(study_places[(rnd.nextInt(8))]);
                   x.setSpec(specs[rnd.nextInt(3)]);
                   x.setBegin(2016+rnd.nextInt(5));
                   x.setEnd(x.getBegin()+2);
           magistranty.add(x);
           count++;
        }
    }
    public void show () {
        for (Undergraduate r:magistranty) {
            r.show1();
        }
       // System.out.println();
    }
    public void add (Undergraduate r) {
        magistranty.add(r);
        count++;
    }
    public void delLast () {
        magistranty.remove(count-1);
    }
    public void sortbyName ()
    {
        Collections.sort(magistranty, ((o1, o2) -> {
            return o1.getName().compareTo(o2.getName());
        }));
    }
    public void sortbyPlace ()
    {
        Collections.sort(magistranty, ((o1, o2) -> {
            return o1.getStudy_place().compareTo(o2.getStudy_place());
        }));
    }
    public void sortbySpec ()
    {
        Collections.sort(magistranty, ((o1, o2) -> {
            return o1.getSpec().compareTo(o2.getSpec());
        }));
    }
    public void sortbyAge() {
        Collections.sort(magistranty, ((o1, o2) -> {
            return o1.getAge()-o2.getAge();
        }));
    }
    public void sortbyBegin() {
        Collections.sort(magistranty, ((o1, o2) -> {
            return o1.getBegin()-o2.getBegin();
        }));
    }
    public void sortbyEnd() {
        Collections.sort(magistranty, ((o1, o2) -> {
            return o1.getEnd()-o2.getEnd();
        }));
    }
}

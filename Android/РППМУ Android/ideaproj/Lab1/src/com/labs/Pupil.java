package com.labs;

public class Pupil {
    private String name;
    private int age;
    private String study_place;
//Конструкторы
    public Pupil(String name, int age, String study_place) {
        this.name = name;
        this.age = age;
        this.study_place = study_place;
    }

    public Pupil() {}
//Методы set
    public void setName(String name) {
        this.name = name;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setStudy_place(String study_place) {
        this.study_place = study_place;
    }
//Методы get
    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getStudy_place() {
        return study_place;
    }

    public void show() {
        System.out.print("Имя: " +name + " Возраст: " + age + " Место учебы: " + study_place);
    }
}

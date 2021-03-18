package com.company;

import java.io.Serializable;

public class Employee implements Serializable {
    private String name;
    private int experience;
    private int salary;

    public Employee(String name, int experience, int salary) {
        this.name = name;
        this.experience = experience;
        this.salary = salary;
    }

    public Employee(){}

    public String getName() {
        return name;
    }

    public int getExperience() {
        return experience;
    }

    public int getSalary() {
        return salary;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setExperience(int experience) {
        this.experience = experience;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Имя: " + name + ", стаж: " + experience + ", зарплата: " + salary;
    }
}

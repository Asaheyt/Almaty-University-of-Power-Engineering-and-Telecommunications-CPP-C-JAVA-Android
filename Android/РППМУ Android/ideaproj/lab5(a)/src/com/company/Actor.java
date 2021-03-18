package com.company;

import java.io.Serializable;

public class Actor extends Employee implements Serializable {
    private int number_of_roles;
    private String type;

    public Actor(String name, int experience, int salary, int number_of_roles, String type) {
        super(name, experience, salary);
        this.number_of_roles = number_of_roles;
        this.type = type;
    }

    public Actor(){}

    public int getNumber_of_roles() {
        return number_of_roles;
    }

    public String getType() {
        return type;
    }

    public void setNumber_of_roles(int number_of_roles) {
        this.number_of_roles = number_of_roles;
    }

    public void setType(String type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return super.toString()+ ", количество ролей: " + number_of_roles + ", типаж: " + type;
    }
}

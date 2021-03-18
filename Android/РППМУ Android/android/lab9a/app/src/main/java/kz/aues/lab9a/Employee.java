package kz.aues.lab9a;

import android.os.Parcel;
import android.os.Parcelable;

import java.io.Serializable;

public class Employee implements Serializable, Parcelable {
    private String name;
    private int experience;
    private int salary;

    public Employee(String name, int experience, int salary) {
        this.name = name;
        this.experience = experience;
        this.salary = salary;
    }

    public Employee(){}

    protected Employee(Parcel in) {
        name = in.readString();
        experience = in.readInt();
        salary = in.readInt();
    }

    public static final Creator<Employee> CREATOR = new Creator<Employee>() {
        @Override
        public Employee createFromParcel(Parcel in) {
            return new Employee(in);
        }

        @Override
        public Employee[] newArray(int size) {
            return new Employee[size];
        }
    };

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

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(name);
        dest.writeInt(experience);
        dest.writeInt(salary);
    }
}

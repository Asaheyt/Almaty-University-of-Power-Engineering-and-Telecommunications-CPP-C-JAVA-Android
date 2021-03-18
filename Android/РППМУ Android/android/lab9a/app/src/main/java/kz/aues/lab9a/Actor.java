package kz.aues.lab9a;

import android.os.Parcel;
import android.os.Parcelable;

import java.io.Serializable;

public class Actor extends Employee implements Serializable, Parcelable {
    private int number_of_roles;
    private String type;

    public Actor(String name, int experience, int salary, int number_of_roles, String type) {
        super(name, experience, salary);
        this.number_of_roles = number_of_roles;
        this.type = type;
    }
    public Actor(String str){
        String[] w = str.split("-");
        this.setName(w[0]);
        this.setExperience(Integer.valueOf(w[1]));
        this.setSalary(Integer.valueOf(w[2]));
        this.number_of_roles=Integer.valueOf(w[3]);
        this.type = w[4];
    }
    protected Actor(Parcel in) {
        super(in);
        number_of_roles = in.readInt();
        type = in.readString();
    }

    public static final Creator<Actor> CREATOR = new Creator<Actor>() {
        @Override
        public Actor createFromParcel(Parcel in) {
            return new Actor(in);
        }

        @Override
        public Actor[] newArray(int size) {
            return new Actor[size];
        }
    };

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
    public String toString1() {
        return super.getName() + "-"+super.getExperience() + "-"+super.getSalary() + "-" + number_of_roles + "-" + type;
    }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        super.writeToParcel(dest,flags);
        dest.writeInt(number_of_roles);
        dest.writeString(type);
    }
}

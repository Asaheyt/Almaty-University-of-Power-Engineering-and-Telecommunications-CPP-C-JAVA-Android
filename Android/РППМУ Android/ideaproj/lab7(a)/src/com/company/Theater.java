package com.company;

import org.yaml.snakeyaml.Yaml;

import javax.swing.*;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class Theater implements Serializable {
    private String name;
    private List<Actor> actors =new ArrayList<Actor>();
    public static boolean OK =false;

    public Theater(String name) {
        this.name = name;
    }

    public Theater(){}

    public String getName() {
        return name;
    }

    public int getSize(){
        return actors.size();
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<Actor> getActors(){
        return actors;
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
    public void clear () {
        actors.clear();
    }

    public void fill(int num) {
        Random rnd = new Random();
        String[] names = {"Александр", "Абылай", "Джон", "Матс", "Томас", "Джульетта", "Алексис", "Лара", "Лео", "Хамес"};
        String[] names1 = {"Alexandr", "Abilay", "John", "Mats", "Tomas", "Julietta", "Alexis", "Lara", "Leo", "James"};
        String[] types = {"злодей", "герой", "учитель", "родитель", "друг", "наставник", "лидер", "весельчак", "умник"};
        String[] types1 = {"evil", "hero", "teacher", "parents", "friend", "Sensei", "Leader", "FunnyMan", "Megamind"};
        for (int i = 0; i < num; i++) {
            Actor x = new Actor();
            x.setName(names1[rnd.nextInt(9)]);
            x.setExperience(1+rnd.nextInt(20));
            x.setType(types1[(rnd.nextInt(8))]);
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
    public String exist(String s){
        File f =new File(s);
        if(f.exists()){
            s=s.substring(0,s.length()-4)+"1.fbd";
            Theater.OK=false;
        }
        else{ Theater.OK =true; }
        return s;
    }
    public String exist1(String s){
        File f =new File(s);
        if(f.exists()){
            s=s.substring(0,s.length()-5)+"1.yaml";
            Theater.OK=false;
        }
        else{ Theater.OK =true; }
        return s;
    }

    public void saveToFile(File f){
        try {
            String s = f.getAbsolutePath();
            s= s.substring(0,s.length())+ "\\" + this.name+ ".fbd";
            //System.out.println(s);
            Theater.OK =false;
            while(!Theater.OK){
                s=exist(s);
            }
            FileOutputStream fos = new FileOutputStream(s);
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(actors);
            oos.flush();
            oos.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
    public void saveToFile1(File f){///////////
        try {
            String s = f.getAbsolutePath();
            s= s.substring(0,s.length())+ "\\" + this.name+ ".yaml";
            //System.out.println(s);
            Theater.OK =false;
            while(!Theater.OK){
                s=exist1(s);
            }
            Yaml yaml =new Yaml();
            FileWriter fw=new FileWriter(s);
            fw.write(yaml.dump(actors));
            fw.flush();
            fw.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
    public void readFromFile(File f){
        try {
            String s = f.getAbsolutePath();
            s= s.substring(0,s.length());
            FileInputStream fis = new FileInputStream(s);
            ObjectInputStream ois = new ObjectInputStream(fis);
            actors=(ArrayList<Actor>)ois.readObject();
        }
        catch(Exception ex){
            System.out.println(ex.getMessage());
        }
    }
    public void readFromFile1(File f){
        try {
            String s = f.getAbsolutePath();
            s= s.substring(0,s.length());
            FileInputStream fis = new FileInputStream(s);
            Yaml yaml = new Yaml();
            actors=(ArrayList<Actor>)yaml.load(fis);
        }
        catch(Exception ex){
            System.out.println(ex.getMessage());
        }
    }

}

package com.labs;

public class Undergraduate extends Pupil {
    private String spec;
    private int begin;
    private int end;
    public Undergraduate () {}

    public Undergraduate(String name, int age, String study_place, String spec, int begin, int end) {
        super(name, age, study_place);
        this.spec = spec;
        this.begin = begin;
        this.end = end;
    }

    public void setSpec(String spec) {
        this.spec = spec;
    }

    public void setBegin(int begin) {
        this.begin = begin;
    }

    public void setEnd(int end) {
        this.end = end;
    }

    public String getSpec() {
        return spec;
    }

    public int getBegin() {
        return begin;
    }

    public int getEnd() {
        return end;
    }
    public void show1 ()
    {
        show();
        System.out.println(" Специальность: "+spec + " Год поступления: " + begin+ " Год окончания: "+ end);
    }

}

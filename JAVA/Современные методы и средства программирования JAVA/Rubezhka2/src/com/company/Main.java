package com.company;

import java.io.*;
import java.util.Scanner;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
	// write your code here

        File myfile=new File("C:\\Users\\нео\\Documents\\IdeaProjects\\Rubezhka2\\src\\com\\company\\RK2.txt");
        Scanner fout=new Scanner(myfile);
        String s;
        int count=0;
        while(fout.hasNext()){
            s=fout.nextLine();
            //System.out.println(s);
            if (s.length()==0) {
                count++;
                s=fout.nextLine();
                while (s.length()==0){
                    s=fout.nextLine();
                }
            }
        }
        System.out.println("Количество абзацев равно "+(count+1));


    }
}

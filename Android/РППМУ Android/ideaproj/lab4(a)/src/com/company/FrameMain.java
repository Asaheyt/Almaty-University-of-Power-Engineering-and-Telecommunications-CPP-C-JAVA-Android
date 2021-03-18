package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FrameMain extends JFrame {
    private JButton button1;
    private JButton button2;
    private JButton button3;
    private JButton button4;
    private JButton button5;
    private JButton button6;
    private JButton button7;
    private JButton button8;
    private JButton button9;
    private Theater theater=new Theater();

    public FrameMain (){
        createGUI();
    }

    private void createGUI() {
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(100,100,250,330);
        button1 = new JButton("Рандомное заполнение"); button1.setBounds(20,20,200,20); this.add(button1);
        button2 = new JButton("Вывести на консоль"); button2.setBounds(20,50,200,20); this.add(button2);
        button3 = new JButton("Добавление элемента"); button3.setBounds(20,80,200,20); this.add(button3);
        button4 = new JButton("Удаление элемента"); button4.setBounds(20,110,200,20); this.add(button4);
        button5 = new JButton("Сортировка по имени"); button5.setBounds(20,140,200,20); this.add(button5);
        button6 = new JButton("Сортировка по стажу"); button6.setBounds(20,170,200,20); this.add(button6);
        button7 = new JButton("Сортировка по зарплате"); button7.setBounds(20,200,200,20); this.add(button7);
        button8 = new JButton("Сортировка по кол. ролей"); button8.setBounds(20,230,200,20); this.add(button8);
        button9 = new JButton("Сортировка по типажу"); button9.setBounds(20,260,200,20); this.add(button9);

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                theater.fill(5);
            }
        });
        button2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0)
                theater.show();
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button3.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                setVisible(false);
                Add();
            }

        });
        button4.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0)
                    theater.delLast();
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0)
                    theater.sortbyName();
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button6.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0)
                    theater.sortbyExperience();
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button7.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0)
                    theater.sortbySalary();
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button8.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0)
                    theater.sortbyNumberOfRoles();
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button9.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0)
                    theater.sortbyType();
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        this.setVisible(true);
    }
    public void Add(){
        Actor x = new Actor();
        FrameAdd add = new FrameAdd(this, x);
        theater.add(x);
    }
}

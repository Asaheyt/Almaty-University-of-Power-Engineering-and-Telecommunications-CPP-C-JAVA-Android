package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


public class Main {

    public static void main(String[] args) {


        JFrame.setDefaultLookAndFeelDecorated(true);
        JFrame frame = new JFrame("Лабораторная работа №5");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JButton northButton = new JButton("Вверх");
        frame.add(northButton, BorderLayout.NORTH);

        JButton southButton = new JButton("Вниз");
        frame.add(southButton, BorderLayout.SOUTH);

        JButton eastButton = new JButton("Вправо");
        frame.add(eastButton, BorderLayout.EAST);

        JButton westButton = new JButton("Влево");
        frame.add(westButton, BorderLayout.WEST);

        JButton line=new JButton();
        line.setSize(50,1);
        frame.add(line);
        line.setLocation(150,150);

        JPanel panel = new JPanel(){
            Graphics2D g2;

            protected void paintComponent(Graphics g){
                super.paintComponent(g);
                g2=(Graphics2D)g;
                g2.setColor(Color.BLACK);
                g2.drawRect(22,22,300,275);
            }

        };

        frame.add(panel);
        frame.setPreferredSize(new Dimension(500, 400));

        int step=10;
        northButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                if(line.getY()-step<53){
                    line.setLocation(line.getX(),320);
                }
                else{
                    line.setLocation(line.getX(),line.getY()-step);
                }
            }
        });

        westButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                if(line.getX()-step<93){
                    line.setLocation(343,line.getY());
                }
                else{
                    line.setLocation(line.getX()-step,line.getY());
                }
            }
        });

        eastButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                if(line.getX()+step>322){
                    line.setLocation(93,line.getY());
                }
                else{
                line.setLocation(line.getX()+step,line.getY());
                }
            }
        });

        southButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e){
                if(line.getY()+1+step>320){
                    line.setLocation(line.getX(),53);
                }
                else{
                    line.setLocation(line.getX(),line.getY()+step);
                }
            }
        });

        frame.pack();
        frame.setVisible(true);
        frame.setLocationRelativeTo(null);
        frame.setResizable(false);





    }
}

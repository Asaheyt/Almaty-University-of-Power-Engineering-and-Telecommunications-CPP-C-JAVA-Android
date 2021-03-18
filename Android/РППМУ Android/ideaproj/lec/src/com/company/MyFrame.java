package com.company;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyFrame extends JFrame {
    private JButton button;
    private JTextField t1;
    private JTextField t2;
    private JTextField t3;
    public MyFrame() {
        createGUI();
    }

    public void createGUI(){
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(100,100,500,500);
        button = new JButton("OK");
        button.setBounds(300,50,100,100);
        this.add(button);
        t1 = new JTextField(); t1.setBounds(50,50,100,50); this.add(t1);
        t2 = new JTextField(); t2.setBounds(50,150,100,50);this.add(t2);
        t3 = new JTextField(); t3.setBounds(50,250,100,50);this.add(t3);
        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int a, b, c;
                a = Integer.parseInt(t1.getText());
                b = Integer.parseInt(t2.getText());
                c=a+b;
                t3.setText(String.valueOf(c));
            }
        });
        this.setVisible(true);
    }
}

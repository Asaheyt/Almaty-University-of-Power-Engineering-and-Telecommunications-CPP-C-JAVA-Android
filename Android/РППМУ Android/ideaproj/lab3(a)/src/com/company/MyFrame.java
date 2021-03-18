package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MyFrame extends JFrame {
    private JButton button1;
    private JTextField t1;
    private JTextField t2;
    private JTextField t3;
    private JLabel l1;
    private JLabel l2;
    private JLabel l3;
    private JLabel l4;
    private JComboBox c1;
    double x, y1, y2;
    public MyFrame() {
        createGUI();
    }

    public void createGUI(){
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(100,100,500,500);
        button1 = new JButton("OK");
        button1.setBounds(300,150,100,30);
        this.add(button1);
        l1 = new JLabel("Введите x"); l1.setBounds(50,20,150,30); this.add(l1);
        t1 = new JTextField(); t1.setBounds(50,50,150,30); this.add(t1);
        l2 = new JLabel("Встроенная функция"); l2.setBounds(50,120,150,30); this.add(l2);
        t2 = new JTextField(); t2.setBounds(50,150,150,30); t2.setEditable(false);this.add(t2);
        l3 = new JLabel("Собственная функция"); l3.setBounds(50,220,150,30); this.add(l3);
        t3 = new JTextField(); t3.setBounds(50,250,150,30); t3.setEditable(false);this.add(t3);
        l4 = new JLabel(); l4.setBounds(50,300,300,30); this.add(l4);
        c1 = new JComboBox(); c1.setBounds(300,50,100,30);this.add(c1);
        t1.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                char c = e.getKeyChar();
                if((c<'0'|| c>'9')&& c!=KeyEvent.VK_BACK_SPACE){
                    e.consume();
                }
            }
        });
        c1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (c1.getSelectedItem() == "Пример 1") {
                    l4.setText("(3^tan(x))*asin(7*x^4)");
                } else if (c1.getSelectedItem() == "Пример 2") {
                    l4.setText("((x-4)^5)*arcctn(3*x^2)");
                } else if (c1.getSelectedItem() == "Пример 3") {
                    l4.setText("(atan(x)^4)*cos(7*x^4)");
                }
            }
        });
        c1.addItem("Пример 1");c1.addItem("Пример 2");c1.addItem("Пример 3");
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    x = Double.parseDouble(t1.getText());
                    if (c1.getSelectedItem() == "Пример 1") {
                        if(x>-0.614788&&x<0.614788) {
                            y1 = Math.pow(3, Math.tan(x)) * Math.asin(7 * Math.pow(x, 4));
                            y2 = Math1.Pow_Dou(3, Math1.Tan_Dou(x)) * Math1.Arcsin_Dou(7 * Math1.Pow_Dou(x, 4));
                            t2.setText(String.valueOf(y1));
                            t3.setText(String.valueOf(y2));
                        }
                        else JOptionPane.showMessageDialog(null,"Error: -0.614788<x<0.614788");
                    } else if (c1.getSelectedItem() == "Пример 2") {
                        y1 = Math.pow(x - 4, 5) * (Math.PI / 2 - Math.atan(3 * Math.pow(x, 2)));
                        y2 = Math1.Pow_Dou(x - 4, 5) * Math1.Arcctg_Dou(3 * Math1.Pow_Dou(x, 2));
                        t2.setText(String.valueOf(y1));
                        t3.setText(String.valueOf(y2));
                    } else if (c1.getSelectedItem() == "Пример 3") {
                        y1 = Math.pow(Math.atan(x), 4) * (Math.cos(7 * Math.pow(x, 4)));
                        y2 = Math1.Pow_Dou(Math1.Arctg_Dou(x), 4) * (Math1.Cos_Dou(7 * Math1.Pow_Dou(x, 4)));
                        t2.setText(String.valueOf(y1));
                        t3.setText(String.valueOf(y2));
                    }
                }
                catch (Exception e1){
                    JOptionPane.showMessageDialog(null,"Error");
                }
            }
        });
        this.setVisible(true);
    }
}

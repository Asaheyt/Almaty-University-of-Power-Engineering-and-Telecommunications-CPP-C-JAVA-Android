package com.company;

import javax.swing.*;
import java.awt.event.*;

public class FrameAdd extends JFrame {
    private JTextField t1, t2, t3, t4, t5;
    private JLabel l1, l2, l3, l4, l5;
    private JButton button1;
    Actor x1;
    FrameMain a1;
    public FrameAdd (FrameMain a, Theater x){
        //x1=x;
        a1=a;
        createGUI(a, x);
    }

    private void createGUI(FrameMain a, Theater x) {
        this.setLayout(null);
        //this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(100,100,475,225);
        l1 = new JLabel("Имя"); l1.setBounds(50,20,150,30); this.add(l1);
        l2 = new JLabel("Стаж"); l2.setBounds(50,50,150,30); this.add(l2);
        l3 = new JLabel("Зарплата"); l3.setBounds(50,80,150,30); this.add(l3);
        l4 = new JLabel("Кол-во ролей"); l4.setBounds(50,110,150,30); this.add(l4);
        l5 = new JLabel("Типаж"); l5.setBounds(50,140,150,30); this.add(l5);
        t1 = new JTextField(); t1.setBounds(150,20,150,30); this.add(t1);
        t2 = new JTextField(); t2.setBounds(150,50,150,30); this.add(t2);
        t3 = new JTextField(); t3.setBounds(150,80,150,30); this.add(t3);
        t4 = new JTextField(); t4.setBounds(150,110,150,30); this.add(t4);
        t5 = new JTextField(); t5.setBounds(150,140,150,30); this.add(t5);
        button1 = new JButton("ОК"); button1.setBounds(320,140,100,30); this.add(button1);
        t1.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                char c = e.getKeyChar();
                if((!Character.isLetter(c))&& c!=KeyEvent.VK_BACK_SPACE){
                    e.consume();
                }
            }
        });
        t2.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                char c = e.getKeyChar();
                if((c<'0'|| c>'9')&& c!=KeyEvent.VK_BACK_SPACE){
                    e.consume();
                }
            }
        });
        t3.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                char c = e.getKeyChar();
                if((c<'0'|| c>'9')&& c!=KeyEvent.VK_BACK_SPACE){
                    e.consume();
                }
            }
        });
        t4.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                char c = e.getKeyChar();
                if((c<'0'|| c>'9')&& c!=KeyEvent.VK_BACK_SPACE){
                    e.consume();
                }
            }
        });
        t5.addKeyListener(new KeyAdapter() {
            @Override
            public void keyTyped(KeyEvent e) {
                char c = e.getKeyChar();
                if((!Character.isLetter(c))&& c!=KeyEvent.VK_BACK_SPACE){
                    e.consume();
                }
            }
        });
        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(t1.getText().equals("")==false && t2.getText().equals("")==false && t3.getText().equals("")==false && t4.getText().equals("")==false && t5.getText().equals("")==false) {
                    Actor x2 =new Actor();
                    x2.setName(t1.getText());
                    x2.setExperience(Integer.parseInt(t2.getText()));
                    x2.setSalary(Integer.parseInt(t3.getText()));
                    x2.setNumber_of_roles(Integer.parseInt(t4.getText()));
                    x2.setType(t5.getText());
                    x.add(x2);
                    setVisible(false);
                    a.setVisible(true);
                    dispose();
                }
                else JOptionPane.showMessageDialog(null,"Заполните все поля","Ошибка",1);
            }
        });
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                setVisible(false);
                a1.setVisible(true);
//                x1=null;
//                x=x1;
                dispose();
            }
        });
        this.setVisible(true);
    }

}

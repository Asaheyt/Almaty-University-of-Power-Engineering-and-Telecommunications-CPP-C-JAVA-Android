package com.company;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.sql.*;

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
    private JButton button10;
    private JButton button11;
    private JButton button12;
    private JButton button13;
    private JButton button14;
    private JTable jtbl1;
    private TableModel tm1;
    private Connection connection;
    private Statement statement;
    private ResultSet resultSet;

    private Theater theater=new Theater("Theater");


    public FrameMain (){
        createGUI();
    }

    private void createGUI() {
        this.setLayout(null);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setBounds(100,100,900,400);
        button1 = new JButton("Рандомное заполнение"); button1.setBounds(20,20,200,20); this.add(button1);
        button2 = new JButton("Вывести на консоль"); button2.setBounds(20,50,200,20); this.add(button2);
        button3 = new JButton("Добавление элемента"); button3.setBounds(20,80,200,20); this.add(button3);
        button4 = new JButton("Очистить"); button4.setBounds(20,110,200,20); this.add(button4);

        button5 = new JButton("Сортировка по имени"); button5.setBounds(20,140,200,20); //this.add(button5);
        button6 = new JButton("Сортировка по стажу"); button6.setBounds(20,170,200,20); //this.add(button6);
        button7 = new JButton("Сортировка по зарплате"); button7.setBounds(20,200,200,20); //this.add(button7);
        button8 = new JButton("Сортировка по кол. ролей"); button8.setBounds(20,230,200,20); //this.add(button8);
        button9 = new JButton("Сортировка по типажу"); button9.setBounds(20,260,200,20); //this.add(button9);

        button10 = new JButton("Сохранение в файл"); button10.setBounds(20,140,200,20); this.add(button10);
        button11 = new JButton("Считывание с файла"); button11.setBounds(20,170,200,20); this.add(button11);
        button12 = new JButton("Считывание с SqlLite"); button12.setBounds(20,200,200,20); this.add(button12);
        button13 = new JButton("Запись в SqlLite"); button13.setBounds(20,230,200,20); this.add(button13);
        button14 = new JButton("Удалить выбранную строку"); button14.setBounds(20,260,200,20); this.add(button14);

        tm1=new TableModel(theater); jtbl1=new JTable(tm1);jtbl1.setAutoCreateRowSorter( true );
        JScrollPane jscrlp = new JScrollPane(jtbl1); jscrlp.setBounds(230,20,600,300);
        this.add(jscrlp);

        button1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                theater.fill(5);
                tm1.fireTableDataChanged();
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
                if(theater.getSize()>0){
                    theater.clear();
                    tm1.fireTableDataChanged();
                    //tm1.fireTableRowsDeleted(0,theater.getSize());
                }
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button5.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0){
                    theater.sortbyName();
                tm1.fireTableDataChanged();}
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button6.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0){
                    theater.sortbyExperience();tm1.fireTableDataChanged();}
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button7.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0){
                    theater.sortbySalary();tm1.fireTableDataChanged();}
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button8.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0){
                    theater.sortbyNumberOfRoles();tm1.fireTableDataChanged();}
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button9.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0){
                    theater.sortbyType();tm1.fireTableDataChanged();}
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button10.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0) {
                    JFileChooser fc = new JFileChooser();
                    fc.setFileSelectionMode(JFileChooser.DIRECTORIES_ONLY);
                    fc.showOpenDialog(null);
                    File f1 = fc.getSelectedFile();
                    theater.saveToFile1(f1);
                }
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });
        button11.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()==0) {
                    JFileChooser fc = new JFileChooser();
                    fc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
                    FileNameExtensionFilter filter = new FileNameExtensionFilter("YAML FILES", "yaml", "yaml");
                    fc.setFileFilter(filter);
                    fc.showOpenDialog(null);
                    File f1 = fc.getSelectedFile();
                    if(f1!=null){
                    theater.readFromFile1(f1);
                    tm1.fireTableDataChanged();}
                }
                else JOptionPane.showMessageDialog(null,"Уже имеются данные","Ошибка",1);
            }
        });
        button12.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()==0) {
                    try {
                        Class.forName("org.sqlite.JDBC");
                        connection = DriverManager.getConnection("jdbc:sqlite:C://Users//Adil//Documents//Files//lab7(a).s3db");
                        statement = connection.createStatement();
                        resultSet = statement.executeQuery("SELECT * FROM actor");
                        while(resultSet.next())
                        {
                            Actor x =new Actor();
                            x.setName(resultSet.getString("Name"));
                            x.setSalary(resultSet.getInt("Salary"));
                            x.setExperience(resultSet.getInt("Experience"));
                            x.setNumber_of_roles(resultSet.getInt("Number_of_roles"));
                            x.setType(resultSet.getString("Type"));
                            theater.add(x);
                        }
                        resultSet.close();
                        statement.close();
                        connection.close();
                    } catch (SQLException e1) {
                        e1.printStackTrace();
                    } catch (ClassNotFoundException e1) {
                        e1.printStackTrace();
                    }
                    tm1.fireTableDataChanged();
                }
                else JOptionPane.showMessageDialog(null,"Уже имеются данные","Ошибка",1);
            }
        });
        button13.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()!=0) {
                    try {
                        Class.forName("org.sqlite.JDBC");
                        connection = DriverManager.getConnection("jdbc:sqlite:C://Users//Adil//Documents//Files//lab7(a).s3db");
                        statement = connection.createStatement();
                        for (Actor x:theater.getActors()) {
                            statement.execute("INSERT INTO 'actor' ('Name', 'Salary', 'Experience', 'Number_of_roles', 'Type') VALUES ('"+x.getName()+"', '"+x.getSalary()+"', '"+x.getExperience()+"', '"+x.getNumber_of_roles()+"', '"+x.getType()+"'); ");
                        }
                        statement.close();
                        connection.close();
                    } catch (SQLException e1) {
                        e1.printStackTrace();
                    } catch (ClassNotFoundException e1) {
                        e1.printStackTrace();
                    }
                }
                else JOptionPane.showMessageDialog(null,"Нет данных","Ошибка",1);
            }
        });

        button14.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if(theater.getSize()>0){
                    theater.getActors().remove(jtbl1.getSelectedRow());
                    tm1.fireTableDataChanged();
                }
                else JOptionPane.showMessageDialog(null,"Пусто","Ошибка",1);
            }
        });




        this.setVisible(true);
    }
    public void Add(){
//        Actor x=new Actor();
        FrameAdd add = new FrameAdd(this, theater);
        tm1.fireTableDataChanged();

//        if (x!=null){
//            theater.add(x);
//            tm1.fireTableDataChanged();
//        }
    }

}

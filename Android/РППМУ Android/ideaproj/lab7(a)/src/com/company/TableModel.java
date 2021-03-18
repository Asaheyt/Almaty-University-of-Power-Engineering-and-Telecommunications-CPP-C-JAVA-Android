package com.company;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.AbstractTableModel;
import java.awt.event.ActionEvent;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.List;

public class TableModel extends AbstractTableModel {
    private String [] headers = {"Имя","Стаж","Зарплата","Кол. ролей","Типаж"};
    private Theater theater ;//=new Theater();

    public TableModel(Theater theater) {
        this.theater = theater;
    }



    public TableModel() {
    }

    @Override
    public int getRowCount() {
        return theater.getSize();
    }

    @Override
    public int getColumnCount() {
        return headers.length;
    }

    @Override
    public String getColumnName(int c) {
        switch (c) {
            case 0:
                return headers[0];
            case 1:
                return headers[1];
            case 2:
                return headers[2];
            case 3:
                return headers[3];
            case 4:
                return headers[4];
            default:
                return "Other Column";
        }
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        String tString = headers[columnIndex];
        if (tString == "Стаж") {
            return theater.getActors().get(rowIndex).getExperience();
        } else if (tString == "Имя") {
            return theater.getActors().get(rowIndex).getName();
        } else if (tString == "Зарплата") {
            return theater.getActors().get(rowIndex).getSalary();
        } else if (tString == "Кол. ролей") {
            return theater.getActors().get(rowIndex).getNumber_of_roles();
        } else if (tString == "Типаж") {
            return theater.getActors().get(rowIndex).getType();
        }else return null;
    }
    @Override
    public boolean isCellEditable(int row, int column) {
        return true;
    }

    @Override
    public void setValueAt(Object a, int rowIndex, int columnIndex){
        String tString = headers[columnIndex];
        if (tString == "Стаж") {
            theater.getActors().get(rowIndex).setExperience((Integer)a);
        } else if (tString == "Имя") {
            theater.getActors().get(rowIndex).setName((String) a);
        } else if (tString == "Зарплата") {
            theater.getActors().get(rowIndex).setSalary((Integer)a);
        } else if (tString == "Кол. ролей") {
            theater.getActors().get(rowIndex).setNumber_of_roles((Integer)a);
        } else if (tString == "Типаж") {
            theater.getActors().get(rowIndex).setType((String) a);
        }
    }

    @Override
    public Class getColumnClass(int c) {
        if(theater.getSize()!=0){
        return getValueAt(0, c).getClass();}
        else return Object.class;

    }

    //-------------
////
////    public void actionPerformed(ActionEvent e) {
////        final Object[] valueAt = new Object[1];
////        //ListSelectionListener - слушатель реагирующий на выбор елемента List
////
////        ListSelectionModel selectionModel = table_pogoda.getSelectionModel(); //Следит за тем , какую строку выделяют в таблице
////        selectionModel.addListSelectionListener(new ListSelectionListener() {
////            //Метод вызывающийся у слушателя при выделении строки
////            @Override
////            public void valueChanged(ListSelectionEvent e) {
////
////                if (table_pogoda.getSelectedRows().length != 1) //getSelectedRows() - возвращает массив индексов выделенных строк
////                {
////                    return;
////                }
////                int viewRowIndex = table_pogoda.getSelectedRows()[0];
////                int rowIndex = table_pogoda.convertRowIndexToModel(viewRowIndex);//Приобразование индексов строк в исходные (если есть сортировка)
////                valueAt[0] = model_table.getValueAt(rowIndex, 0);
////                SwingUtilities.invokeLater(new Runnable()
////                {
////                    @Override
////                    public void run() {
////                        // удалить данные
////                        dellRow(String.valueOf(valueAt[0]));
////                        // перерисовать
////                        model_table.fireTableDataChanged();
////                    }
////                });
////
////            }
////        });
//
//    }
}

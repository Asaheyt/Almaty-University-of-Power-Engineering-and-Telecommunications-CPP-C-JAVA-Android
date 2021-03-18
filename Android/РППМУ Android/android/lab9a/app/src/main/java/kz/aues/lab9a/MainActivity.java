package kz.aues.lab9a;

import android.Manifest;
import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Environment;
import android.os.Parcelable;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Theater theater = new Theater();
    private ListView listView;
    private My_adapter my_adapter;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        try {
            Bundle data = getIntent().getExtras();
            theater = (Theater) data.getParcelable("Theater");
        }
        catch (Exception e) {
        }
            super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        listView = (ListView) findViewById(R.id.listview);

        //theater.fill(10);

        my_adapter = new My_adapter(this,theater.getActors());

        listView.setAdapter(my_adapter);

    }

    public void fill_List(View view) {
        theater.fill(10);
        //my_adapter = new My_adapter(this,theater.getActors());
        my_adapter.setList(theater.getActors());
    }

    public void show_List(View view) {
        if(theater.getSize()>0) {
            listView.setAdapter(my_adapter);
        }
        else {
            AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
            builder.setTitle("Внимание!")
                    .setMessage("Лист пуст!")
                    .setCancelable(false)
                    .setNegativeButton("ОК",
                            new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {
                                    dialog.cancel();
                                }
                            });
            AlertDialog alert = builder.create();
            alert.show();
        }
    }

    public void clear_List(View view) {
        if(theater.getSize()>0) {
            theater.clear();
            //my_adapter = new My_adapter(this, theater.getActors());
            my_adapter.setList(theater.getActors());
            listView.setAdapter(my_adapter);
        }
        else {
            AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
            builder.setTitle("Внимание!")
                    .setMessage("Лист пуст!")
                    .setCancelable(false)
                    .setNegativeButton("ОК",
                            new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {
                                    dialog.cancel();
                                }
                            });
            AlertDialog alert = builder.create();
            alert.show();
        }
    }

    public void sort_by_Name(View view) {
        if(theater.getSize()>0) {
            theater.sortbyName();
            //my_adapter = new My_adapter(this, theater.getActors());
            my_adapter.setList(theater.getActors());
            listView.setAdapter(my_adapter);
        }
        else {
            AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
            builder.setTitle("Внимание!")
                    .setMessage("Лист пуст!")
                    .setCancelable(false)
                    .setNegativeButton("ОК",
                            new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {
                                    dialog.cancel();
                                }
                            });
            AlertDialog alert = builder.create();
            alert.show();
        }
    }

    public void add_List(View view) {
        Intent intent = new Intent(MainActivity.this, Add_Activity.class);
        intent.putExtra("Theater", (Parcelable) theater);
        startActivity(intent);
    }

    public void del_dubl(View view) {
        if(theater.getSize()>0) {

           for(int i = 0;i<theater.getSize()-1;i++){
               for (int j =i+1;j<theater.getSize();j++){
                   if(theater.getActors().get(i).getName().equals(theater.getActors().get(j).getName())){
                        theater.del_index(j);j--;
                       Toast.makeText(this, "Deleted", Toast.LENGTH_SHORT).show();
                   }
               }
           }
            my_adapter.setList(theater.getActors());
            listView.setAdapter(my_adapter);
        }
        else {
            AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
            builder.setTitle("Внимание!")
                    .setMessage("Лист пуст!")
                    .setCancelable(false)
                    .setNegativeButton("ОК",
                            new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {
                                    dialog.cancel();
                                }
                            });
            AlertDialog alert = builder.create();
            alert.show();
        }
    }

    public void save_list(View view) {
        /*FileOutputStream fos = null;
        try {
            fos = openFileOutput("MYPGM.txt", MODE_PRIVATE);
            fos.write(theater.toString().getBytes());
            Toast.makeText(this, "Файл сохранен", Toast.LENGTH_SHORT).show();
        }
        catch(IOException ex) {

            Toast.makeText(this, ex.getMessage(), Toast.LENGTH_SHORT).show();
        }
        finally{
            try{
                if(fos!=null)
                    fos.close();
            }
            catch(IOException ex){

                Toast.makeText(this, ex.getMessage(), Toast.LENGTH_SHORT).show();
            }
        }*/
        if(theater.getSize()>0) {
        try {
            OutputStreamWriter outputStreamWriter = new OutputStreamWriter(openFileOutput("MyPGM.txt", MODE_PRIVATE));
            BufferedWriter bw = new BufferedWriter(outputStreamWriter);
            for (Actor r: theater.getActors()) {
                bw.write(r.toString1());
                bw.newLine();
            }
            bw.close();
            System.out.println("MyPGM: File saved");
            Toast.makeText(this, "Файл сохранен", Toast.LENGTH_SHORT).show();
        // writer.write();
        } catch (IOException e) {
            System.out.println("MyPGM: "+ e.toString());
            System.out.println("MyPGM: Error File");
            e.printStackTrace();
        }
        }else {
            AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
            builder.setTitle("Внимание!")
                    .setMessage("Лист пуст!")
                    .setCancelable(false)
                    .setNegativeButton("ОК",
                            new DialogInterface.OnClickListener() {
                                public void onClick(DialogInterface dialog, int id) {
                                    dialog.cancel();
                                }
                            });
            AlertDialog alert = builder.create();
            alert.show();
        }
        /*// проверяем доступность SD
        if (!Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED)) {
            System.out.println("MyPGM: SD-карта не доступна: " + Environment.getExternalStorageState());
            return;
        }
        // получаем путь к SD
        File sdPath = Environment.getExternalStorageDirectory();
        // добавляем свой каталог к пути
        sdPath = new File(sdPath.getAbsolutePath());
        // создаем каталог
        sdPath.mkdirs();
        // формируем объект File, который содержит путь к файлу
        File sdFile = new File(sdPath, "MyFile.txt");
        try {
            // открываем поток для записи
            BufferedWriter bw = new BufferedWriter(new FileWriter(sdFile));
            // пишем данные
            for (Actor r: theater.getActors()) {
                bw.write(r.toString1());
            }
            // закрываем поток
            bw.close();
            System.out.println("MyPGM: Файл записан на SD: " + sdFile.getAbsolutePath());
        } catch (IOException e) {
            System.out.println("MyPGM: "+ e.toString());
            System.out.println("MyPGM: Error File");
            e.printStackTrace();
        }*/
    }

    public void read_list(View view) {
        /*FileInputStream fin = null;
        try {
            fin = openFileInput("MyPGM.txt");
            byte[] bytes = new byte[fin.available()];
            fin.read(bytes);
            String text = new String (bytes);
            Toast.makeText(this, text, Toast.LENGTH_SHORT).show();
            //theater.=text.;
        }
        catch(IOException ex) {

            Toast.makeText(this, ex.getMessage(), Toast.LENGTH_SHORT).show();
        }
        finally{

            try{
                if(fin!=null)
                    fin.close();
            }
            catch(IOException ex){

                Toast.makeText(this, ex.getMessage(), Toast.LENGTH_SHORT).show();
            }
        }*/
       try {
            BufferedReader br = new BufferedReader(new InputStreamReader(openFileInput("MyPGM.txt")));
            String str;
            while ( (str = br.readLine()) != null){
                Actor x =new Actor(str);
                theater.add(x);
                //System.out.println("MyPGM: "+str);
                //Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
            }
        } catch (FileNotFoundException e) {
            System.out.println("MyPGM: "+ e.toString());
            System.out.println("MyPGM: Error File");
            e.printStackTrace();
        } catch (Exception e){
            System.out.println("MyPGM: "+ e.toString());
            System.out.println("MyPGM: Error File");
        }
        /*// проверяем доступность SD
        if (!Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED)) {
            System.out.println("MyPGM: SD-карта не доступна: " + Environment.getExternalStorageState());
            return;
        }
        // получаем путь к SD
        File sdPath = Environment.getExternalStorageDirectory();
        // добавляем свой каталог к пути
        sdPath = new File(sdPath.getAbsolutePath());
        // формируем объект File, который содержит путь к файлу
        File sdFile = new File(sdPath, "MyFile.txt");
        try {
            // открываем поток для чтения
            BufferedReader br = new BufferedReader(new FileReader(sdFile));
            String str = "";
            // читаем содержимое
            while ((str = br.readLine()) != null) {
                theater.add(new Actor(str));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }*/
    }
   /* private static final int REQUEST_EXTERNAL_STORAGE = 1;
    private static String[] PERMISSIONS_STORAGE = {
            Manifest.permission.READ_EXTERNAL_STORAGE,
            Manifest.permission.WRITE_EXTERNAL_STORAGE
    };

    /**
     * Checks if the app has permission to write to device storage
     *
     * If the app does not has permission then the user will be prompted to grant permissions
     *
     * @param activity
     */
    /*public static void verifyStoragePermissions(Activity activity) {
        // Check if we have write permission
        int permission = ActivityCompat.checkSelfPermission(activity, Manifest.permission.WRITE_EXTERNAL_STORAGE);

        if (permission != PackageManager.PERMISSION_GRANTED) {
            // We don't have permission so prompt the user
            ActivityCompat.requestPermissions(
                    activity,
                    PERMISSIONS_STORAGE,
                    REQUEST_EXTERNAL_STORAGE
            );
        }
    }*/
}

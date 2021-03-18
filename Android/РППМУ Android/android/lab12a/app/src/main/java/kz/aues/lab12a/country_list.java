package kz.aues.lab12a;


import android.content.Intent;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Parcelable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.Spinner;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class country_list extends AppCompatActivity {
    private final static String TAG = "MainActivity";
    private ImageView imageView;
    private ImageView img, imageViewbyCode;
    private LinearLayout myLayout;
    private AssetManager assetManager;
    private ListView listView;
    private CustomAdapter adapter1;
    private Сountry test;
    private ArrayList<Сountry> list = new ArrayList<>();
    private String[] types1 = {"Стране", "Столице", "Площади", "Населению", "Континенту"};
    private String selected;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_country_list);
        assetManager = getAssets();
        listView = (ListView) findViewById(R.id.listview);
        this.listAllImages(this);
        Bundle data = getIntent().getExtras();
        if(data!=null){
            list.clear();
            list = (ArrayList)data.get("List");
        }
        adapter1 = new CustomAdapter(this, list);
        listView.setAdapter(adapter1);
        final ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item, types1);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        Spinner spinner = (Spinner) findViewById(R.id.spinner);
        spinner.setAdapter(adapter);
        // заголовок
        spinner.setPrompt("Type");
        // выделяем элемент
        spinner.setSelection(0);
        AdapterView.OnItemSelectedListener itemSelectedListener = new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                // Получаем выбранный объект
                selected = (String)parent.getItemAtPosition(position);
                if(selected=="Стране"){sortbyTitle();adapter1.setCountryList(list);adapter1.notifyDataSetChanged();}
                if(selected=="Столице"){sortbyCapital();adapter1.setCountryList(list);adapter1.notifyDataSetChanged();}
                if(selected=="Площади"){sortbyArea();adapter1.setCountryList(list);adapter1.notifyDataSetChanged();}
                if(selected=="Населению"){sortbyPopulation();adapter1.setCountryList(list);adapter1.notifyDataSetChanged();}
                if(selected=="Континенту"){sortbyContinent();adapter1.setCountryList(list);adapter1.notifyDataSetChanged();}
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        };
        spinner.setOnItemSelectedListener(itemSelectedListener);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent = new Intent(country_list.this, Current_country_info.class);
                intent.putExtra("Position", (Parcelable) list.get(position));
                intent.putExtra("List", list);
                intent.putExtra("ActivityName","country_list");
                startActivity(intent);
            }
        });
    }
    public void listAllImages(country_list v) {
        // image.setImage(currentWriter.getPicture());
        //String text = filename;
        try {
            String[] imgPath = assetManager.list("64");
            String[] imgPath1 = assetManager.list("information");
            assert imgPath != null;
            assert imgPath1 != null;
            for(int i =0; i<imgPath.length-1;i++){
                for(int j =i; j<imgPath.length;j++){
                    if(Double.valueOf(imgPath[i].substring(0,imgPath[i].length()-4))>Double.valueOf(imgPath[j].substring(0,imgPath[j].length()-4))){
                        String imgpath=imgPath[j];
                        imgPath[j]=imgPath[i];
                        imgPath[i]=imgpath;
                    }
                }
            }
            int n=0;
            for (int i = 0; i < 10/*imgPath.length*/; i++) {

                test = new Сountry();
                InputStream is = assetManager.open("64/" + imgPath[i]);
                InputStream  is1 = assetManager.open("information/info.txt");
                Log.d(TAG, imgPath[i]);
                Bitmap bitmap = BitmapFactory.decodeStream(is);

                imageViewbyCode = new ImageView(this);
                imageViewbyCode.setImageBitmap(bitmap);


                String mline = StreamToString(is1,n);
                n++;
                is1.close();
                test.setInformation(mline);
                //System.out.println("MyLOG "+mline);

                test.setPicture(bitmap);
                list.add(test);

            }
        } catch (IOException e) {
            Log.e(TAG, e.getMessage());
        }

    }

    public void listAllInfo(MainActivity v) {

    }

    public static String StreamToString(InputStream in,int l) throws IOException {
        if (in == null) {
            return "";
        }
        Writer writer = new StringWriter();
        char[] buffer = new char[1024];
        try {
            Reader reader = new BufferedReader(new InputStreamReader(in, "UTF-8"));
            int n;
            /*while ((n = reader.read(buffer)) != -1) {
                writer.write(buffer, 0, n);
            }*/
            String str;
            for(int i=0;i<10/*197*/;i++){
                str=((BufferedReader) reader).readLine();
                if(i==l){
                    writer.write(str);
                }
            }
            /*while ((str=((BufferedReader) reader).readLine())!=null){
                writer.write(str);
            }*/
        } finally {
        }
        return writer.toString();
    }

    public void BackToMain(View view) {
        Intent intent = new Intent(country_list.this, MainActivity.class);
        startActivity(intent);
    }
    public void sortbyTitle ()
    {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getTitle().compareTo(o2.getTitle());
            }
        }));
    }
    public void sortbyCapital ()
    {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getCapital().compareTo(o2.getCapital());
            }
        }));
    }
    public void sortbyArea ()
    {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getArea()-o2.getArea();
            }
        }));
    }
    public void sortbyPopulation ()
    {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getPopulation()-o2.getPopulation();
            }
        }));
    }
    public void sortbyContinent ()
    {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getContinent().compareTo(o2.getContinent());
            }
        }));
    }
}

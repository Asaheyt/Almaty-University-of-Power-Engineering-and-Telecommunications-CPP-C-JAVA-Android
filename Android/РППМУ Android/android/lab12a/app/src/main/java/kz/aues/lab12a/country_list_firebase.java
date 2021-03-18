package kz.aues.lab12a;


import android.content.Intent;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Parcelable;
import android.support.annotation.NonNull;
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
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.OnFailureListener;
import com.google.android.gms.tasks.OnSuccessListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.FirebaseApp;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;
import com.google.firebase.auth.FirebaseUser;
import com.google.firebase.storage.FileDownloadTask;
import com.google.firebase.storage.FirebaseStorage;
import com.google.firebase.storage.StorageReference;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class country_list_firebase extends AppCompatActivity {
    private final static String TAG = "MyLOG";
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
    private FirebaseStorage storage;
    private StorageReference rootRef;
    private StorageReference myRef;
    private StorageReference myRef1;
    private FirebaseAuth mAuth = FirebaseAuth.getInstance();
    private int t=0;
    private Bitmap[] bitmap=new Bitmap[10];
    private String[] strings=new String[10];

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        //String email="Sarzhigitov.adil@gmail.com",password="123456789adil";
        //signin(email,password);
        FirebaseApp.initializeApp(this);
        storage = FirebaseStorage.getInstance();
        rootRef = storage.getReferenceFromUrl("gs://lab12a.appspot.com");

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_country_list_firebase);
        assetManager = getAssets();
        listView = (ListView) findViewById(R.id.listview);


        Bundle data = getIntent().getExtras();
        if (data != null) {
            list.clear();
            list = (ArrayList) data.get("List");
        }
        adapter1 = new CustomAdapter(this, list);
        adapter1.notifyDataSetChanged();
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
                selected = (String) parent.getItemAtPosition(position);
                if (selected == "Стране") {
                    sortbyTitle();
                    adapter1.setCountryList(list);
                    adapter1.notifyDataSetChanged();
                }
                if (selected == "Столице") {
                    sortbyCapital();
                    adapter1.setCountryList(list);
                    adapter1.notifyDataSetChanged();
                }
                if (selected == "Площади") {
                    sortbyArea();
                    adapter1.setCountryList(list);
                    adapter1.notifyDataSetChanged();
                }
                if (selected == "Населению") {
                    sortbyPopulation();
                    adapter1.setCountryList(list);
                    adapter1.notifyDataSetChanged();
                }
                if (selected == "Континенту") {
                    sortbyContinent();
                    adapter1.setCountryList(list);
                    adapter1.notifyDataSetChanged();
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        };
        spinner.setOnItemSelectedListener(itemSelectedListener);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent = new Intent(country_list_firebase.this, Current_country_info.class);
                intent.putExtra("Position", (Parcelable) list.get(position));
                intent.putExtra("List", list);
                intent.putExtra("ActivityName","country_list_firebase");
                startActivity(intent);
            }
        });
        //---------

    }
    @Override
    protected void onStart() {
        super.onStart();
        try {
            this.listAllImages(this);
        } catch (IOException e) {
            e.printStackTrace();
        }
        /*try {
            this.ListALLFlags(this);
        } catch (IOException e) {
            e.printStackTrace();
        }*/
    }
    @Override
    protected void onResume() {
        super.onResume();
        //this.fill();
        adapter1.setCountryList(list);
        adapter1.notifyDataSetChanged();
    }

    public void listAllImages(country_list_firebase v) throws IOException {
            myRef1 = rootRef.child("Firebase_FIles/information/info.txt");
            final File localFile1 = File.createTempFile("info", "txt");
            myRef1.getFile(localFile1).addOnSuccessListener(new OnSuccessListener<FileDownloadTask.TaskSnapshot>() {
                @Override
                public void onSuccess(FileDownloadTask.TaskSnapshot taskSnapshot) {
                    try {
                        FileReader fileReader = new FileReader(localFile1.getAbsoluteFile());
                        BufferedReader br = new BufferedReader(fileReader);
                        String str;int i=0;
                        while ( (str = br.readLine()) != null){
                            //if(i==10)break;
                            strings[i]=str;
                            System.out.println("MyLOG "+ strings[i]);
                            i++;
                            /*test=new Сountry();
                            test.setInformation(str);
                            list.add(test);*/
                        }
                    } catch (FileNotFoundException e) {
                        e.printStackTrace();
                    } catch (Exception e){ }
                }
            }).addOnFailureListener(new OnFailureListener() {
                @Override
                public void onFailure(@NonNull Exception exception) {
                }
            });


    }
    public void ListALLFlags(country_list_firebase v)throws IOException {
        for(int i=0;i<10;i++) {
            t=i;
            myRef = rootRef.child("Firebase_FIles/64/" + (i + 1) + ".png");
            final File localFile = File.createTempFile("img", "png");
            myRef.getFile(localFile).addOnSuccessListener(new OnSuccessListener<FileDownloadTask.TaskSnapshot>() {
                @Override
                public void onSuccess(FileDownloadTask.TaskSnapshot taskSnapshot) {
                    bitmap[t] = BitmapFactory.decodeFile(localFile.getAbsolutePath());
                    //list.get(t).setPicture(bitmap[t]);
                }
            }).addOnFailureListener(new OnFailureListener() {
                @Override
                public void onFailure(@NonNull Exception exception) {
                }
            });
        }
    }

    public void fill(){
        for(int i = 0;i<10;i++){
            test=new Сountry();
            test.setInformation(strings[i]);
            //test.setPicture(bitmap[i]);
            list.add(test);
        }
    }

    public void BackToMain(View view) {
        Intent intent = new Intent(country_list_firebase.this, MainActivity.class);
        startActivity(intent);
    }

    public void sortbyTitle() {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getTitle().compareTo(o2.getTitle());
            }
        }));
    }

    public void sortbyCapital() {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getCapital().compareTo(o2.getCapital());
            }
        }));
    }

    public void sortbyArea() {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getArea() - o2.getArea();
            }
        }));
    }

    public void sortbyPopulation() {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getPopulation() - o2.getPopulation();
            }
        }));
    }

    public void sortbyContinent() {
        Collections.sort(list, (new Comparator<Сountry>() {
            @Override
            public int compare(Сountry o1, Сountry o2) {
                return o1.getContinent().compareTo(o2.getContinent());
            }
        }));
    }

    public void signin(String email , String password)
    {
        mAuth.signInWithEmailAndPassword(email,password).addOnCompleteListener(this, new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if(task.isSuccessful()) {
                    Toast.makeText(country_list_firebase.this, "Aвторизация успешна", Toast.LENGTH_SHORT).show();
                }else
                    Toast.makeText(country_list_firebase.this, "Aвторизация провалена", Toast.LENGTH_SHORT).show();

            }
        });
    }

    public void FILLB(View view) {
        if(list.size()==0){
        fill();
        adapter1.setCountryList(list);
        adapter1.notifyDataSetChanged();}
        else Toast.makeText(country_list_firebase.this, "Список заполнен", Toast.LENGTH_SHORT).show();
    }
}
package kz.aues.lab9a;

import android.content.DialogInterface;
import android.content.Intent;
import android.os.Parcelable;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

public class Add_Activity extends AppCompatActivity {
    String[] types1 = {"Evil", "Hero", "Teacher", "Parents", "Friend", "Sensei", "Leader", "FunnyMan", "Megamind"};
    String selected;

    private Theater theater;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Bundle data = getIntent().getExtras();
        theater = (Theater)data.getParcelable("Theater");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_);
        // адаптер
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, android.R.layout.simple_spinner_item, types1);
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
            }
            @Override
            public void onNothingSelected(AdapterView<?> parent) {
            }
        };
        spinner.setOnItemSelectedListener(itemSelectedListener);
    }

    public void back(View view) {
        Intent intent = new Intent(Add_Activity.this, MainActivity.class);
        intent.putExtra("Theater", (Parcelable) theater);
        startActivity(intent);
    }
    private boolean isEmpty(EditText etText) {
        return etText.getText().toString().trim().length() == 0;
    }

    public void add(View view) {
        EditText t1,t2,t3,t4;//,t5;
        t1 = (EditText) findViewById(R.id.editText4);
        t2 = (EditText) findViewById(R.id.editText3);
        t3 = (EditText) findViewById(R.id.editText2);
        t4 = (EditText) findViewById(R.id.editText);
        //t5 = (EditText) findViewById(R.id.editText5);
        for (int i =0;i<theater.getSize();i++){
            if(theater.getActors().get(i).getName().equals(t1.getText().toString())){
                Toast.makeText(this, "Такое имя уже существует", Toast.LENGTH_SHORT).show();
                return;
            }
        }
        if(!isEmpty(t1) && !isEmpty(t2) && !isEmpty(t3) && !isEmpty(t4)&& Integer.valueOf(t2.getText().toString())<50 && Integer.valueOf(t3.getText().toString())<1000500 && Integer.valueOf(t4.getText().toString())<40 ) {
            Actor x = new Actor(t1.getText().toString(), Integer.valueOf(t2.getText().toString()), Integer.valueOf(t3.getText().toString()), Integer.valueOf(t4.getText().toString()), selected);
            theater.add(x);
            AlertDialog.Builder builder = new AlertDialog.Builder(Add_Activity.this);
            builder.setTitle("Внимание!")
                    .setMessage("Актер добавлен в список!")
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
        else {
            AlertDialog.Builder builder = new AlertDialog.Builder(Add_Activity.this);
            builder.setTitle("Ошибка!")
                    .setMessage("Заполните все поля верно!")
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
}

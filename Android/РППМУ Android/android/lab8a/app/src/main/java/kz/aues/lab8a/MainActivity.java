package kz.aues.lab8a;

import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.InputFilter;
import android.text.InputType;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    EditText t1, t2, t3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        t1=(EditText)findViewById(R.id.editText1);
        t1.setFilters(new InputFilter[]{new NegativeDecimalInputFilter()});
        t2=(EditText) findViewById(R.id.editText2);
        t3=(EditText) findViewById(R.id.editText3);
    }

    public void calculate(View view) {

        double x;
        x=Double.parseDouble(String.valueOf(t1.getText()));
        if(x>-0.614788&&x<0.614788) {
            double b;
            double c;
            b = Math.pow(3, Math.tan(x)) * Math.asin(7 * Math.pow(x, 4));
            c = Math1.Pow_Dou(3, Math1.Tan_Dou(x)) * Math1.Arcsin_Dou(7 * Math1.Pow_Dou(x, 4));
            t2.setText(String.valueOf(b));
            t3.setText(String.valueOf(c));
        }
        else {
            AlertDialog.Builder builder = new AlertDialog.Builder(MainActivity.this);
            builder.setTitle("Ошибка!")
                    .setMessage("Не соответсвует диапазону (x>-0.614788&&x<0.614788)!")
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

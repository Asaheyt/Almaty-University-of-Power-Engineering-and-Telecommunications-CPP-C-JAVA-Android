package kz.aues.lec;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import java.util.StringJoiner;

public class MainActivity extends AppCompatActivity {
    public String TAG ="MyLog";
    EditText t, t2, t3;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.i(TAG, "HElp");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        t=(EditText)findViewById(R.id.editText);
        t2=(EditText) findViewById(R.id.editText2);
        t3=(EditText) findViewById(R.id.editText3);
    }

    public void cal(View view) {
        int a;
        a=Integer.parseInt(String.valueOf(t.getText()));
        int b;
        b=Integer.parseInt(String.valueOf(t2.getText()));
        int c;
        c=a+b;
        t3.setText(String.valueOf(c));

    }
}

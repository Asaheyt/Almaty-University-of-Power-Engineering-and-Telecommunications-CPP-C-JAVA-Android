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
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.FirebaseApp;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

import org.springframework.http.converter.StringHttpMessageConverter;
import org.springframework.web.client.RestTemplate;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private ImageView imageView;
    private AssetManager assetManager;
    private FirebaseAuth mAuth = FirebaseAuth.getInstance();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        String email="Sarzhigitov.adil@gmail.com",password="123456789adil";
        signin(email,password);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);




        assetManager = getAssets();
        imageView=(ImageView) findViewById(R.id.imageView2);
        try {
            InputStream is = assetManager.open("map_world.png");
            Bitmap bitmap = BitmapFactory.decodeStream(is);
            imageView.setImageBitmap(bitmap);
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void Next(View view) {
        Intent intent = new Intent(MainActivity.this, country_list.class);
        startActivity(intent);
    }

    public void Next1(View view) {
        Intent intent = new Intent(MainActivity.this, country_list_firebase.class);
        startActivity(intent);
    }
    public void signin(String email , String password)
    {
        mAuth.signInWithEmailAndPassword(email,password).addOnCompleteListener(this, new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if(task.isSuccessful()) {
                    Toast.makeText(MainActivity.this, "Aвторизация успешна", Toast.LENGTH_SHORT).show();
                }else
                    Toast.makeText(MainActivity.this, "Aвторизация провалена", Toast.LENGTH_SHORT).show();

            }
        });
    }

    public void Next2(View view) {
        Intent intent = new Intent(MainActivity.this, country_list_spring.class);
        startActivity(intent);
    }
}

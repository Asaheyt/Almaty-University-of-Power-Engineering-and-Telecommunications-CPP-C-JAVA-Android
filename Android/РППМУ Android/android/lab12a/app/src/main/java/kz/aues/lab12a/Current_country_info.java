package kz.aues.lab12a;

import android.content.Intent;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Parcelable;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.Reader;
import java.io.StringWriter;
import java.io.Writer;
import java.util.ArrayList;

public class Current_country_info extends AppCompatActivity {
    private int position=0;
    private TextView textView;
    private Сountry country;
    private ArrayList<Сountry> list;
    private AssetManager assetManager;
    private ImageView imageView;
    private Bitmap [] bitmap = new Bitmap[3];
    private int count=0;
    private String activityName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Bundle data = getIntent().getExtras();
        country = (Сountry) data.getParcelable("Position");
        list = (ArrayList) data.get("List");
        activityName=(String) data.get("ActivityName");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_current_country_info);
        textView = (TextView)findViewById(R.id.textView3);
        textView.setMovementMethod(new ScrollingMovementMethod());
        assetManager = getAssets();
        imageView=(ImageView)findViewById(R.id.imageView3);
        String[] imgPath = new String[0];
        try {
            imgPath = assetManager.list("information/" + country.getTitle()+"/image");
        } catch (IOException e) {
            e.printStackTrace();
        }
        assert imgPath != null;
        for (int i = 0;i<3;i++){


            InputStream is1 = null;
            try {
                is1 = assetManager.open("information/" + country.getTitle()+"/image/" + imgPath[i]);
            } catch (IOException e) {
                e.printStackTrace();
            }
            bitmap[i] = BitmapFactory.decodeStream(is1);
        }
        try {

            imageView.setImageBitmap(bitmap[0]);
            InputStream is = assetManager.open("information/" + country.getTitle()+"/information.txt");
            String mline = StreamToString(is);
            textView.setText(mline);
        } catch (IOException e) {
            e.printStackTrace();
        }
        //textView.setText(country.toString());
    }

    public void BackToList(View view) {
        if (activityName.equals("country_list")) {
            Intent intent = new Intent(Current_country_info.this, country_list.class);
            intent.putExtra("List", list);
            startActivity(intent);
        } else if (activityName.equals("country_list_firebase")) {
            Intent intent = new Intent(Current_country_info.this, country_list_firebase.class);
            intent.putExtra("List", list);
            startActivity(intent);
        } else if (activityName.equals("country_list_spring")) {
            Intent intent = new Intent(Current_country_info.this, country_list_spring.class);
            intent.putExtra("List", list);
            startActivity(intent);

        }
    }

    public static String StreamToString(InputStream in) throws IOException {
        if (in == null) {
            return "";
        }
        Writer writer = new StringWriter();
        char[] buffer = new char[1024];
        try {
            Reader reader = new BufferedReader(new InputStreamReader(in, "UTF-8"));
            int n;
            while ((n = reader.read(buffer)) != -1) {
                writer.write(buffer, 0, n);
            }
            String str;
            while ((str=((BufferedReader) reader).readLine())!=null){
                writer.write(str);
            }
        } finally {
        }
        return writer.toString();
    }


    public void NextPic(View view) {
        if(count==0){
            imageView.setImageBitmap(bitmap[1]);count=1;}
        else if(count==1){
            imageView.setImageBitmap(bitmap[2]);count=2;}
        else if(count==2){
            imageView.setImageBitmap(bitmap[0]);count=0;}

    }

    public void PreviousPic(View view) {
        if(count==0){
            imageView.setImageBitmap(bitmap[2]);count=2;}
        else if(count==1){
            imageView.setImageBitmap(bitmap[0]);count=0;}
        else if(count==2){
            imageView.setImageBitmap(bitmap[1]);count=1;}
    }
}

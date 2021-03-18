package kz.aues.lab12a;

import android.os.AsyncTask;
import android.os.Build;
import android.support.annotation.RequiresApi;
import android.util.Log;

import org.springframework.http.converter.json.MappingJackson2HttpMessageConverter;
import org.springframework.web.client.RestTemplate;

//@RequiresApi(api = Build.VERSION_CODES.CUPCAKE)
public class HttpRequestTask extends AsyncTask<Void, Void, CuntryClient[]> {
    public static CuntryClient[] country;
    @Override
    protected CuntryClient[] doInBackground(Void... params) {
        try {
            final String url = "http://192.168.108.92:8080/country";
            RestTemplate restTemplate = new RestTemplate();
            restTemplate.getMessageConverters().add(new MappingJackson2HttpMessageConverter());
            country = restTemplate.getForObject(url, CuntryClient[].class);
            System.out.println("MyLOG ");
            System.out.println("MyLOG "+country[0].getInformation());
            country_list_spring.country=country;
            return country;
        } catch (Exception e) {
            Log.e("MyLOG", e.getMessage(), e);
        }

        return null;
    }
}

package kz.aues.lab12a;

import android.annotation.SuppressLint;
import android.content.Context;
import android.support.annotation.LayoutRes;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;

public class CustomAdapter extends ArrayAdapter<Сountry> {
    private Context mContext;
    private List<Сountry> countryList = new ArrayList<>();

    public CustomAdapter(@NonNull Context context, @SuppressLint("SupportAnnotationUsage") @LayoutRes ArrayList<Сountry> list) {
        super(context, 0 , list);
        mContext = context;
        countryList = list;
    }

    public void setCountryList(List<Сountry> countryList) {
        this.countryList = countryList;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        View listItem = convertView;
        if(listItem == null)
            listItem = LayoutInflater.from(mContext).inflate(R.layout.list_item,parent,false);
        Сountry currentСountry = countryList.get(position);

        ImageView image = (ImageView)listItem.findViewById(R.id.imageView);
        image.setImageBitmap(currentСountry.getPicture());
        // image.setImage(currentWriter.getPicture());


        TextView name = (TextView) listItem.findViewById(R.id.textView_end);
        name.setText(currentСountry.toString());

        return listItem;
    }
}
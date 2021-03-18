package kz.aues.lab9a;

import android.content.Context;
import android.support.annotation.LayoutRes;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.List;

public class My_adapter extends ArrayAdapter<Actor> {

    private Context mContext;
    private List<Actor> actors = new ArrayList<>();


    public My_adapter(@NonNull Context context, @LayoutRes List<Actor> list) {
            super(context, 0 , list);
            mContext = context;
            actors = list;
    }
    public void setList(@LayoutRes List<Actor> list){
        actors = list;
    }



    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
            View listItem = convertView;
            if(listItem == null)
            listItem = LayoutInflater.from(mContext).inflate(R.layout.list_item,parent,false);

            Actor currentActor = actors.get(position);

            TextView name = (TextView) listItem.findViewById(R.id.textView_Single);
            name.setText(currentActor.toString());

            return listItem;
    }
}
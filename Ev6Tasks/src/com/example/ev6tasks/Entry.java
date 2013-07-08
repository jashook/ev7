package com.example.ev6tasks;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class Entry extends Activity 
{

    @Override
    protected void onCreate(Bundle _SavedInstanceState) 
    {
       
        super.onCreate(_SavedInstanceState);
        
        setContentView(R.layout.activity_entry);
   
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) 
    {
       
        getMenuInflater().inflate(R.menu.entry, menu);
        
        return true;
        
    }
    
}

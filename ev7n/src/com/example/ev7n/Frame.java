package com.example.ev7n;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class Frame extends Activity 
{

   @Override
   protected void onCreate(Bundle savedInstanceState) 
   {
      super.onCreate(savedInstanceState);
      
      setContentView(R.layout.activity_frame);
	
	}

   @Override
   public boolean onCreateOptionsMenu(Menu menu) 
   {
      // Inflate the menu; this adds items to the action bar if it is present.
      getMenuInflater().inflate(R.menu.frame, menu);
  
      return true;
	
	}

}

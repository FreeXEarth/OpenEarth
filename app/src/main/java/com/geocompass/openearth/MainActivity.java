package com.geocompass.openearth;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

import com.geocompass.openearth.sdk.earth.Earth;
import com.geocompass.openearth.sdk.earth.EarthView;
import com.geocompass.openearth.sdk.earth.geometry.LatLng;
import com.geocompass.openearth.sdk.http.HttpRequest;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private EarthView mEarthView;
    private Earth mEarth;
//    float x = 0;
//    float x1;
//    float y = 0;
//    float y1;
//
//    float preX = 0;
//    float preY = 0;

    @SuppressLint("ClickableViewAccessibility")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mEarthView = findViewById(R.id.earth_view);

        mEarth = mEarthView.getEarth();
        findViewById(R.id.btn_zoom_in).setOnClickListener(this);
        findViewById(R.id.btn_zoom_out).setOnClickListener(this);
        findViewById(R.id.btn_look_up).setOnClickListener(this);
        findViewById(R.id.btn_look_down).setOnClickListener(this);
        findViewById(R.id.btn_set_center).setOnClickListener(this);
        HttpRequest request = new HttpRequest("http://t1.tianditu.com/DataServer?T=vec_w&x=1682&y=776&l=11");
    }


    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_zoom_in:
                mEarth.zoomIn();
                return;
            case R.id.btn_zoom_out:
                mEarth.zoomOut();
                return;
            case R.id.btn_look_up:
                mEarth.lookUp();
                return;
            case R.id.btn_look_down:
                mEarth.lookDown();
                return;
            case R.id.btn_set_center:
                mEarth.setCenter(new LatLng(40,116));
                return;
        }
    }


}

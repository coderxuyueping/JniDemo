package com.baidu.yuepingxu.jnidemo;

import android.view.View;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void helloJni(View view) {
        JniUtil jniUtil = new JniUtil();
        jniUtil.helloJni();
    }

    public void helloJni2(View view) {
        JniUtil jniUtil = new JniUtil();
        int result = jniUtil.helloJni2("hello");
        Toast.makeText(this, "jni返回的参数:" + result, Toast.LENGTH_SHORT).show();
    }

    public void helloJni3(View view) {
        JniUtil jniUtil = new JniUtil();
        jniUtil.helloJni3();
    }

    public void helloJni4(View view) {
        JniUtil jniUtil = new JniUtil();
        jniUtil.helloJni4();
    }

    public void helloJni5(View view) {
        JniUtil jniUtil = new JniUtil();
        jniUtil.helloJni5();
    }
}

package com.baidu.yuepingxu.jnidemo;

import android.util.Log;

/**
 * @author xuyueping
 * @date 2020-03-06
 * @describe 编译生成的so在 app/build/intermediates/cmake/debug/obj
 *
 */
public class JniUtil {
    static {
        System.loadLibrary("jniUtil");
    }
    public native void helloJni();

    // 有行参和返回值
    public native int helloJni2(String str);

    // 这个方法回调java方法
    public native void helloJni3();

    // 这个方法回调static方法
    public native void helloJni4();

    // 这个方法回调另外一个对象的方法
    public native void helloJni5();

    // jni回调java方法
    public void callbackFromNative(String str){
        Log.d("xuyueping_jni", "callbackFromNative 接受jni返回的参数=" + str);
    }

    public static int callbackFromNativeStatic(int a){
        Log.d("xuyueping_jni", "callbackFromNativeStatic 接受jni返回的参数=" + a);
        return 0;
    }
}

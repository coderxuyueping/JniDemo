#include <jni.h>
#include <stdlib.h>
#include <android/log.h>

// define 宏定义
#define LOG_TAG  "xuyueping_jni"
// _VA_ARGS_是可变参数的意思
#define LogD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)


// jni方法Java_包名_类名
// env是一个二级指针 需要*找到一级指针再进行调用
// thiz是调用jni的对象
JNIEXPORT void JNICALL
Java_com_baidu_yuepingxu_jnidemo_JniUtil_helloJni(JNIEnv *env, jobject thiz) {
    char* ch = "hello jni";
    LogD("hello jni");
}

JNIEXPORT jint JNICALL
Java_com_baidu_yuepingxu_jnidemo_JniUtil_helloJni2(JNIEnv *env, jobject thiz, jstring str) {
    int lenght = (*env)->GetStringLength(env, str);
    LogD("字符串长度是%d", lenght);
    return lenght;
}

JNIEXPORT void JNICALL
Java_com_baidu_yuepingxu_jnidemo_JniUtil_helloJni3(JNIEnv *env, jobject thiz) {
    // 通过反射回调java方法,如果是thiz是当前调用jni方法的对象就不需要创建对象
    // 找到class文件
    char * className = "com/baidu/yuepingxu/jnidemo/JniUtil";
    jclass class = (*env)->FindClass(env, className);
    // 找到方法 最后一个参数是反射方法的参数签名
    char * methodSign = "(Ljava/lang/String;)V";
    jmethodID jmethodId = (*env)->GetMethodID(env, class, "callbackFromNative", methodSign);

    // 在c中字符串是char * ，java中是string，所以需要把char*转换为java中的string，也就是jstring
    jstring str = (*env)->NewStringUTF(env, "jni回调java方法");
    (*env)->CallVoidMethod(env, thiz, jmethodId, str);
}

JNIEXPORT void JNICALL
Java_com_baidu_yuepingxu_jnidemo_JniUtil_helloJni4(JNIEnv *env, jobject thiz) {
    // 找到class文件
    char * ch = "com/baidu/yuepingxu/jnidemo/JniUtil";
    jclass class = (*env)->FindClass(env, ch);
    // 找到方法
    char * methodSign = "(I)I";
    jmethodID jmethodId = (*env)->GetStaticMethodID(env, class, "callbackFromNativeStatic",
            methodSign);
    // 因为是静态方法，只需要class调用就行，不需要类对象
    int result = (*env)->CallStaticIntMethod(env, class, jmethodId, 1);
    LogD("jni调用java静态方法得到的返回值%d", result);
}

JNIEXPORT void JNICALL
Java_com_baidu_yuepingxu_jnidemo_JniUtil_helloJni5(JNIEnv *env, jobject thiz) {
    char * ch = "com/baidu/yuepingxu/jnidemo/Test";
    jclass class = (*env)->FindClass(env, ch);
    char * methodSign = "(Ljava/lang/String;)V";
    jmethodID jmethodId = (*env)->GetMethodID(env, class, "fun", methodSign);
    // 创建对象
    jobject object = (*env)->AllocObject(env, class);
    jstring  str = (*env)->NewStringUTF(env, "我是从jni返回的参数");
    (*env)->CallVoidMethod(env, object, jmethodId, str);
    (*env)->DeleteLocalRef(env, object);
}
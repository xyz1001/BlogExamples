package com.example.jmi;

public class Calculator {
    private long mInstance = 0;

    public Calculator() {
        mInstance = createNativeObject();
    }
    public native long createNativeObject();

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        if (mInstance != 0) {
            releaseNativeObject();
            mInstance = 0;
        }
    }
    public native void releaseNativeObject();

    public native void plus(int a);
    public native void minus(int a);
    public native void multi(int a);
    public native void divide(int a);
    public native int getResult();
}

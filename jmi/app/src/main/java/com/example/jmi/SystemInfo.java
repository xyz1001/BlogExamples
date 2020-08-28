package com.example.jmi;

import android.os.Build;

public class SystemInfo {
    private String mOsVersion;
    private int mApiLevel = -1;

    String getOsVersion() {
        if(mOsVersion == null) {
            mOsVersion = Build.VERSION.RELEASE;
        }
        return mOsVersion;
    }

    int getApiLevel() {
        if(mApiLevel == -1) {
            mApiLevel = Build.VERSION.SDK_INT;
        }
        return mApiLevel;
    }
}

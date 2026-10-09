package com.shadow.granny;

import android.app.Activity;
import android.graphics.Color;
import android.graphics.Typeface;
import android.os.Bundle;
import android.view.Gravity;
import android.widget.LinearLayout;
import android.widget.ScrollView;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
    private final int bg = Color.rgb(12, 10, 18);
    private final int purple = Color.rgb(165, 90, 255);
    private final int muted = Color.rgb(190, 180, 205);

    @Override
    protected void onCreate(Bundle state) {
        super.onCreate(state);

        ScrollView scroll = new ScrollView(this);
        LinearLayout page = new LinearLayout(this);
        page.setOrientation(LinearLayout.VERTICAL);
        page.setPadding(24, 32, 24, 32);
        page.setBackgroundColor(bg);
        scroll.addView(page);

        TextView title = new TextView(this);
        title.setText("SHADOW  /  GRANNY");
        title.setTextColor(purple);
        title.setTextSize(24);
        title.setTypeface(Typeface.DEFAULT, Typeface.BOLD);
        title.setGravity(Gravity.CENTER);
        page.addView(title);

        TextView status = new TextView(this);
        status.setText("ARM64 • protótipo JNI • controles demonstrativos");
        status.setTextColor(muted);
        status.setTextSize(12);
        status.setGravity(Gravity.CENTER);
        status.setPadding(0, 8, 0, 24);
        page.addView(status);

        try {
            addToggle(page, "Freeze Granny", NativeBridge.nativeGetFreeze(),
                checked -> NativeBridge.nativeSetFreeze(checked));
            addToggle(page, "God Mode", NativeBridge.nativeGetGodMode(),
                checked -> NativeBridge.nativeSetGodMode(checked));
            addToggle(page, "Speed", NativeBridge.nativeGetSpeedEnabled(),
                checked -> NativeBridge.nativeSetSpeedEnabled(checked));

            TextView version = new TextView(this);
            version.setText(NativeBridge.nativeGetVersion());
            version.setTextColor(muted);
            version.setPadding(0, 24, 0, 0);
            page.addView(version);
        } catch (UnsatisfiedLinkError e) {
            Toast.makeText(this, "A biblioteca libshadow.so ainda não foi compilada/instalada.", Toast.LENGTH_LONG).show();
        }

        setContentView(scroll);
    }

    private interface ToggleAction { void run(boolean checked); }

    private void addToggle(LinearLayout page, String label, boolean initial, ToggleAction action) {
        Switch toggle = new Switch(this);
        toggle.setText(label);
        toggle.setTextColor(Color.WHITE);
        toggle.setTextSize(16);
        toggle.setPadding(0, 18, 0, 18);
        toggle.setChecked(initial);
        toggle.setOnCheckedChangeListener((button, checked) -> {
            action.run(checked);
            Toast.makeText(this, label + (checked ? " ON" : " OFF") +
                " — estado demonstrativo", Toast.LENGTH_SHORT).show();
        });
        page.addView(toggle);
    }
}

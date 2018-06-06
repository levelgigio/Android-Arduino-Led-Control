package com.led.led;

/**
 * Created by Giovanni on 5/21/2018.
 */

public class Led {
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    private String name;

    public int getPin() {
        return pin;
    }

    public void setPin(int pin) {
        this.pin = pin;
    }

    private int pin;

    Led(String cname, int cpin) {
        this.name = cname;
        this.pin = cpin;
    }

    @Override
    public String toString() {
        return name;
    }
}

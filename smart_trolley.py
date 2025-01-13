from machine import Pin, I2C
from time import sleep
from lcd_api import LcdApi
from pico_i2c_lcd import I2cLcd	

i2c = I2C(0, scl=Pin(1), sda=Pin(0), freq=400000)
lcd = I2cLcd(i2c, 0x27, 2, 16)

input = bytearray(12)
count = 0

a_pin = Pin(1, Pin.IN, Pin.PULL_UP)
led1_pin = Pin(4, Pin.OUT)  // green
led2_pin = Pin(5, Pin.OUT)  // red
buzz = Pin(6, Pin.OUT)  // buzzer

total = 0
p1 = 0
p2 = 0

def main():
    global total, p1, p2

    lcd.clear()
    lcd.putstr(" AUTOMATIC BILL\n")
    lcd.putstr(" SHOPPING CART ")
    sleep(2)
    lcd.clear()
    lcd.putstr(" CSBS\n")
    lcd.putstr("SUPER MARKET")
    sleep(2)
    lcd.clear()
    lcd.putstr("Plz Add iTem :- ")

    while True:
        global input, count
        input = 0 * 12
        count = 0
        
        while count < 12:
            input[count] = uart.read(1)[0]
            count += 1
            sleep(0.005)

        a = a_pin.value()

        if input.decode() == "4900C623339F" and a == 1:
            lcd.clear()
            lcd.putstr("Cheese Added       ")
            led1_pin.value(1)
            buzz.value(1)
            sleep(1)
            led1_pin.value(0)
            buzz.value(0)
            lcd.clear()
            lcd.putstr("Total Price :-")
            total += 100.00
            lcd.putstr(str(total))
            p1 += 1
        elif input.decode() == "4900C623339F" and a == 0:
            if p1 > 0:
                lcd.clear()
                lcd.putstr("Cheese Removed!!!        ")
                led2_pin.value(1)
                buzz.value(1)
                sleep(1)
                lcd.clear()
                led2_pin.value(0)
                buzz.value(0)
                lcd.clear()
                lcd.putstr("Total Price :-")
                total -= 100.00
                lcd.putstr(str(total))
                p1 -= 1
            else:
                lcd.clear()
                lcd.putstr("Not in cart!!!        ")
                led2_pin.value(1)
                buzz.value(1)
                sleep(1)
                led2_pin.value(0)
                buzz.value(0)
                lcd.clear()
                lcd.putstr("Total Price :-")
                lcd.putstr(str(total))

        if input.decode() == "090064BBCE18" and a == 1:
            lcd.clear()
            lcd.putstr("Milk Added       ")
            led1_pin.value(1)
            buzz.value(1)
            sleep(1)
            led1_pin.value(0)
            buzz.value(0)
            lcd.clear()
            lcd.putstr("Total Price :-")
            total += 70.00
            lcd.putstr(str(total))
            p2 += 1
        elif input.decode() == "090064BBCE18" and a == 0:
            if p2 > 0:
                lcd.clear()
                lcd.putstr("Milk Removed!!!        ")
                led2_pin.value(1)
                buzz.value(1)
                sleep(1)
                lcd.clear()
                led2_pin.value(0)
                buzz.value(0)
                lcd.clear()
                lcd.putstr("Total Price :-")
                total -= 70.00
                lcd.putstr(str(total))
                p2 -= 1
            else:
                lcd.clear()
                lcd.putstr("Not in cart!!!        ")
                led2_pin.value(1)
                buzz.value(1)
                sleep(1)
                led2_pin.value(0)
                buzz.value(0)
                lcd.clear()
                lcd.putstr("Total Price :-")
                lcd.putstr(str(total))
            
        if input.decode() == "09001EA3C470" and a == 1:
            lcd.clear()
            lcd.putstr("Milk Added       ")
            led1_pin.value(1)
            buzz.value(1)
            sleep(1)
            led1_pin.value(0)
            buzz.value(0)
            lcd.clear()
            lcd.putstr("Total Price :-")
            total += 70.00
            lcd.putstr(str(total))
            p2 += 1
        elif input.decode() == "09001EA3C470" and a == 0:
            if p2 > 0:
                lcd.clear()
                lcd.putstr("Milk Removed!!!        ")
                led2_pin.value(1)
                buzz.value(1)
                sleep(1)
                lcd.clear()
                led2_pin.value(0)
                buzz.value(0)
                lcd.clear()
                lcd.putstr("Total Price :-")
                total -= 70.00
                lcd.putstr(str(total))
                p2 -= 1
            else:
                lcd.clear()
                lcd.putstr("Not in cart!!!        ")
                led2_pin.value(1)
                buzz.value(1)
                sleep(1)
                led2_pin.value(0)
                buzz.value(0)
                lcd.clear()
                lcd.putstr("Total Price :-")
                lcd.putstr(str(total))

if __name__ == "__main__":
    main()


# ESP32 BT Controller – Android Connection Guide

This guide will walk you through connecting your Android phone to the ESP32 Bluetooth Controller step by step.  
No prior technical knowledge is required.

---

## What You Will Need

| Item | Details |
|------|---------|
| ESP32 development board | Flashed with this firmware |
| Power source | USB cable or battery connected to the ESP32 |
| Android smartphone or tablet | Android 6.0 (Marshmallow) or newer |
| The companion Android app | Installed on your phone |

---

## Step 1 – Power On the ESP32

1. Connect the ESP32 board to a power source (USB or battery).
2. The onboard LED may blink briefly while the board initializes.
3. After a few seconds the board is ready and **broadcasting its Bluetooth signal** under the name **`ESP32-BT`**.

> **Tip:** You do not need a computer connected – any 5 V USB charger works.

---

## Step 2 – Enable Bluetooth on Your Android Device

1. Open the **Settings** app on your phone.
2. Tap **Connections** (or **Connected devices**, depending on your Android version).
3. Tap **Bluetooth** and make sure the toggle is turned **ON**.

---

## Step 3 – Pair the ESP32 with Your Phone

> You only need to do this pairing once. After the first time, your phone will remember the device.

1. In the Bluetooth settings screen, tap **Scan** or **Search for devices** (the button label varies by phone).
2. Wait a few seconds. You will see a list of nearby Bluetooth devices.
3. Tap **`ESP32-BT`** in the list.
4. If a PIN dialog appears, enter **`1234`** and confirm.
5. The status next to `ESP32-BT` should change to **Paired**.

---

## Step 4 – Connect Using the Android App

1. Open the **companion Android app** on your phone.
2. Look for a **Connect** button or a Bluetooth device picker in the app.
3. Select **`ESP32-BT`** from the list of paired devices.
4. The app will show a **Connected** status indicator once the link is established.

> **Note:** The ESP32 automatically sends its configuration to the app the moment a connection is detected, so the controls and display labels will populate on their own.

---

## Controls Overview

Once connected, the app provides the following controls:

| Control | What It Does |
|---------|-------------|
| **Left Stick – Horizontal (X)** | Steering (left / right) |
| **Left Stick – Vertical (Y)** | Left motor speed |
| **Right Stick – Horizontal (X)** | Camera pan (left / right) |
| **Right Stick – Vertical (Y)** | Right motor speed |
| **Left Knob** | LED brightness (0 = off, full = maximum brightness) |
| **Right Knob** | Buzzer intensity (0 = silent, full = maximum) |
| **Switches 1 – 6** | Toggle digital outputs on or off |
| **Event Buttons** | Send a short pulse to a switch output |

---

## Telemetry Displayed in the App

While connected, the ESP32 sends real-time data back to the app:

| Display Element | Data Shown |
|----------------|-----------|
| **Left Panel** | Left-side sensor value |
| **Right Panel** | Right-side sensor value |
| **Throttle Indicator** | Current throttle level (analog bar) |
| **Battery Indicator** | Remaining battery level |
| **Volts Plot** | Voltage reading (live graph, updated 20× per second) |
| **Amps Plot** | Current draw reading (live graph) |
| **RPMs Plot** | Motor speed reading (live graph) |

---

## Troubleshooting

| Problem | Solution |
|---------|---------|
| `ESP32-BT` does not appear in the scan | Make sure the ESP32 is powered on and within ~10 m of your phone. Try scanning again. |
| Pairing fails or asks for a PIN you do not know | Try the PIN `1234` or `0000`. |
| The app says "Connection failed" | Unpair `ESP32-BT` in Android Bluetooth settings, then repeat Step 3 and Step 4. |
| Controls have no effect | Confirm the status in the app shows **Connected**, not just **Paired**. |
| The app connects but no telemetry appears | Wait 2–3 seconds after connecting. The ESP32 sends the configuration automatically on first connect. |
| Bluetooth keeps disconnecting | Keep the phone within 10 m of the ESP32. Walls and metal objects can reduce range. |

---

## Project Modes

The firmware can be built in different modes. Each mode enables a different set of features:

| Mode | Description |
|------|-------------|
| `MODE_FULL_RC_MCP` *(default)* | Full RC control with GPIO expander (MCP23017) |
| `MODE_FULL_RC` | Full RC control using the ESP32 built-in pins |
| `MODE_BASIC_RC` | Simplified RC control with basic telemetry |
| `MODE_SENSOR_NODE` | Sensor-only mode (I2C sensors, no RC outputs) |
| `MODE_MINIMAL` | Minimal operation – panels and indicators only |

The active mode is set in [`user_config.h`](user_config.h) before flashing the firmware.

---

## Quick Reference

```
Bluetooth device name : ESP32-BT
Default pairing PIN   : 1234
Bluetooth profile     : SPP (Serial Port Profile)
Telemetry rate        : 20 Hz (plots), 2 Hz (indicators)
```

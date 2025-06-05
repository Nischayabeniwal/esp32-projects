# DotFocus-Pomodoro
# ⏱️ ESP32 Pomodoro Timer with Web Interface, LED Progress, and Buzzer Ticks

A smart Pomodoro timer built on the **ESP32** with the following features:

- 🌐 **Web-based control panel** (synchronous web server)
- 🔟 **LED progress bar** for visual session tracking
- 🔊 **Buzzer ticking** sound in final 20 seconds
- 🕹️ **Start/Stop/Resume** session control
- 🧠 **Automatic break management**
- 📈 **Session completion counter**

---

## 🚀 Features

| Feature            | Description |
|--------------------|-------------|
| WiFi Control       | Web interface accessible over local WiFi |
| LED Progress       | 10 LEDs represent Pomodoro progress |
| Ticking Buzzer     | Activates in last 20s of session for urgency |
| Web Interface      | Auto-refreshing HTML dashboard |
| Break Automation   | Automatically enters 5-min break after work session |
| Session Counter    | Tracks completed Pomodoro cycles |

---

## 🔌 Hardware Requirements

| Component       | Quantity | Description                   |
|------------------|----------|-------------------------------|
| ESP32 Dev Board  | 1        | Main microcontroller          |
| LEDs             | 10       | For session progress display  |
| Resistors        | 10       | ~220Ω for LEDs                |
| Buzzer (active)  | 1        | For ticking sound             |
| Breadboard + Wires| As needed | For connections              |

### GPIO Pin Mapping

| Function     | GPIO Pins              |
|--------------|------------------------|
| LED Pins     | 2, 4, 5, 18, 19, 21, 22, 23, 13, 25 |
| Buzzer       | 15                     |

---

## 📲 Web Interface

The ESP32 hosts a basic control panel.

---

### Interface Actions

- 🟢 **Start** — Begins a 25-minute work session
- 🔴 **Stop** — Ends current session/break
- 🟡 **Resume** — Resumes after break

The page updates every 5 seconds and displays:

- **Session Time**
- **Status** (Working or On Break)
- **Remaining Time**
- **Master Time** (Total running time)
- **Sessions Completed**

---

## 📡 WiFi Configuration

Update your SSID and password in the code:

```cpp
const char* ssid = "JARVIS";
const char* password = "WAKEJARVIS@3000";

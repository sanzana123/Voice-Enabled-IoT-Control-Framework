Assistive LED Communicator for Non-Verbal Patients
An affordable and accessible assistive system designed for patients who are non-verbal, bedridden, or have speech/hearing impairments. This system allows patients to communicate basic needs—such as requesting food or medication—through a simple web interface. Upon selecting an option, an LED lights up as an alert signal, and the browser uses speech synthesis to vocalize the request.

🛠️ Tech Stack
🔧 Hardware
ESP32 microcontroller

LEDs (Red, Blue, etc.) for signaling

Breadboard & Jumper Wires

💻 Software
Arduino (C++) for microcontroller logic

ESP32 WebServer to serve the user interface

HTML/CSS/JavaScript for the front-end

Web Speech API (Google) for browser-based text-to-speech

✅ Features
Touch-friendly web interface for patients

Real-time LED activation based on request type

Text-to-speech functionality without external modules

Fully wireless, no mobile app required

📌 How It Works
The ESP32 hosts a local web server accessible via any browser.

Patients interact with buttons like "Need Food" or "Need Help".

Selecting a button:

Lights up a corresponding LED for visual signaling.

Triggers the browser to speak the selected message aloud.

💡 Use Case
This system is designed to enhance communication between non-verbal patients and caregivers in hospitals, elderly care centers, or at home.

📚 What I Learned
Hosting web pages directly from ESP32

Using Web Speech API for real-time TTS

Interfacing HTML front-end with Arduino-based GPIO control

Designing accessible, hardware-integrated web applications

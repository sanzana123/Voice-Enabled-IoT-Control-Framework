// #include <WiFi.h>
// #include <WebServer.h>

// // Wi-Fi credentials
// const char* ssid = "my wifi";   // Change this to your Wi-Fi SSID
// const char* password = "my password";          // Change this to your Wi-Fi password

// // Create a web server object on port 80
// WebServer server(80);

// // Motor driver pins (adjust as per your connection)
// const int IN1 = 14;   // Left Motor Forward
// const int IN2 = 27;   // Left Motor Backward
// const int IN3 = 26;   // Right Motor Forward
// const int IN4 = 25;   // Right Motor Backward

// // Motor control functions
// void moveForward() {
//   digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
//   digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
//   server.send(200, "text/plain", "Moving Forward");
// }

// void moveBackward() {
//   digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
//   server.send(200, "text/plain", "Moving Backward");
// }

// void turnLeft() {
//   digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
//   server.send(200, "text/plain", "Turning Left");
// }

// void turnRight() {
//   digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
//   server.send(200, "text/plain", "Turning Right");
// }

// void stopMotors() {
//   digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
//   server.send(200, "text/plain", "Stopped");
// }

// // HTML page with buttons
// void handleRoot() {
//   server.send(200, "text/html",
//     "<!DOCTYPE html><html>"
//     "<head>"
//     "<title>ESP32 Robot Controller</title>"
//     "<meta name='viewport' content='width=device-width, initial-scale=1'>"
//     "<style>"
//     "body { font-family: Arial; text-align: center; padding: 20px; background: linear-gradient(to bottom right, #fff700, #ffd700); }"
//     "h1 { color: #333; }"
//     ".btn {"
//     "  display: inline-block;"
//     "  margin: 10px;"
//     "  padding: 15px 30px;"
//     "  font-size: 20px;"
//     "  background-color: #2196F3;"
//     "  color: white;"
//     "  border: none;"
//     "  border-radius: 8px;"
//     "  text-decoration: none;"
//     "}"
//     ".btn:hover { background-color: #0b7dda; }"
//     "</style>"
//     "</head>"
//     "<body>"
//     "<h1>ESP32 Robot Controller</h1>"
//     "<a class='btn' href='/forward'>Forward</a><br>"
//     "<a class='btn' href='/left'>Left</a>"
//     "<a class='btn' href='/stop'>Stop</a>"
//     "<a class='btn' href='/right'>Right</a><br>"
//     "<a class='btn' href='/backward'>Backward</a>"
//     "</body></html>"
//   );
// }

// void setup() {
//   Serial.begin(115200);

//   // Setup motor pins
//   pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
//   pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
//   stopMotors(); // Ensure motors are off at startup

//   // Connect to Wi-Fi
//   Serial.print("Connecting to Wi-Fi");
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("\nConnected to Wi-Fi!");
//   Serial.print("IP address: ");
//   Serial.println(WiFi.localIP());

//   // Define URL handlers
//   server.on("/", handleRoot);
//   server.on("/forward", moveForward);
//   server.on("/backward", moveBackward);
//   server.on("/left", turnLeft);
//   server.on("/right", turnRight);
//   server.on("/stop", stopMotors);

//   // Start the server
//   server.begin();
//   Serial.println("HTTP server started");
// }

// void loop() {
//   server.handleClient();  // Handle incoming client requests
// }

////////////////////////////////////////////////////////////////////////////////////////////

// #include <WiFi.h>
// #include <WebServer.h>

// // Replace with your network credentials
// const char* ssid = "No Network";
// const char* password = "4699392931";

// WebServer server(80);

// String storedUsername = "admin";
// String storedPassword = "1234";

// bool isAuthenticated = false;

// // Motor pins
// const int motorPin1 = 14;
// const int motorPin2 = 27;

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(ssid, password);
//   Serial.println("Connecting to WiFi...");

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.print(".");
//   }

//   Serial.println("");
//   Serial.print("Connected! IP address: ");
//   Serial.println(WiFi.localIP());

//   pinMode(motorPin1, OUTPUT);
//   pinMode(motorPin2, OUTPUT);

//   server.on("/", HTTP_GET, handleRoot);
//   server.on("/login", HTTP_POST, handleLogin);
//   server.on("/control", HTTP_GET, handleControl);
//   server.on("/move", HTTP_POST, handleMove);

//   server.begin();
// }

// void loop() {
//   server.handleClient();
// }

// // Landing page with login
// void handleRoot() {
//   String html = R"rawliteral(
//     <!DOCTYPE html>
//     <html>
//     <head>
//       <title>Login</title>
//       <style>
//         body {
//           background-color: yellow;
//           font-family: Arial, sans-serif;
//           display: flex;
//           flex-direction: column;
//           align-items: center;
//           justify-content: center;
//           height: 100vh;
//         }
//         h1 {
//           color: green;
//           font-weight: bold;
//         }
//         input, button {
//           margin: 10px;
//           padding: 10px;
//           font-size: 16px;
//         }
//       </style>
//     </head>
//     <body>
//       <h1>Assistive Robotic Navigator</h1>
//       <form action="/login" method="POST">
//         <input type="text" name="username" placeholder="Username"><br>
//         <input type="password" name="password" placeholder="Password"><br>
//         <button type="submit">Login</button>
//       </form>
//     </body>
//     </html>
//   )rawliteral";

//   server.send(200, "text/html", html);
// }

// // Handle login logic
// void handleLogin() {
//   if (!server.hasArg("username") || !server.hasArg("password")) {
//     server.send(400, "text/plain", "Bad Request");
//     return;
//   }

//   String username = server.arg("username");
//   String password = server.arg("password");

//   if (username == storedUsername && password == storedPassword) {
//     isAuthenticated = true;
//     server.sendHeader("Location", "/control");
//     server.send(303);
//   } else {
//     server.send(200, "text/html", "<h1 style='color:red;'>Login Failed</h1><a href='/'>Try Again</a>");
//   }
// }

// // Control UI
// void handleControl() {
//   if (!isAuthenticated) {
//     server.sendHeader("Location", "/");
//     server.send(303);
//     return;
//   }

//   String html = R"rawliteral(
//     <!DOCTYPE html>
//     <html>
//     <head>
//       <title>Control Robot</title>
//       <style>
//         body {
//           background-color: yellow;
//           font-family: Arial, sans-serif;
//           display: flex;
//           flex-direction: column;
//           align-items: center;
//           justify-content: center;
//           height: 100vh;
//         }
//         h1 {
//           color: green;
//           font-weight: bold;
//         }
//         button {
//           margin: 10px;
//           padding: 15px 30px;
//           font-size: 20px;
//           font-weight: bold;
//           background-color: white;
//           border: 2px solid green;
//           color: green;
//           cursor: pointer;
//         }
//         button:hover {
//           background-color: lightgreen;
//         }
//       </style>
//     </head>
//     <body>
//       <h1>Assistive Robotic Navigator</h1>
//       <form action="/move" method="POST">
//         <button name="dir" value="forward">Forward</button><br>
//         <button name="dir" value="left">Left</button>
//         <button name="dir" value="right">Right</button><br>
//         <button name="dir" value="backward">Backward</button><br>
//         <button name="dir" value="stop">Stop</button>
//       </form>
//     </body>
//     </html>
//   )rawliteral";

//   server.send(200, "text/html", html);
// }

// // Handle motor movement
// void handleMove() {
//   if (!isAuthenticated) {
//     server.sendHeader("Location", "/");
//     server.send(303);
//     return;
//   }

//   String direction = server.arg("dir");
//   Serial.print("Command: ");
//   Serial.println(direction);

//   if (direction == "forward") {
//     digitalWrite(motorPin1, HIGH);
//     digitalWrite(motorPin2, LOW);
//   } else if (direction == "backward") {
//     digitalWrite(motorPin1, LOW);
//     digitalWrite(motorPin2, HIGH);
//   } else {
//     digitalWrite(motorPin1, LOW);
//     digitalWrite(motorPin2, LOW);  // Stop by default
//   }

//   server.sendHeader("Location", "/control");
//   server.send(303);
// }

/////////////////////////////////////////////////////////////////////////////////////
#include <WiFi.h>
#include <WebServer.h>

// Wi-Fi credentials
const char* ssid = "No Network";
const char* password = "4699392931";

// Login credentials
String storedUsername = "admin";
String storedPassword = "2004";

// LED pins
const int redLED = 13;
const int blueLED = 12;
const int greenLED = 14;
const int whiteLED = 27;

WebServer server(80);

// Login page
String loginPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>Assistive LED Communicator</title>
  <style>
    body {
      background-color: yellow;
      font-family: Arial, sans-serif;
      text-align: center;
    }
    h1 {
      color: green;
      font-size: 2em;
      font-weight: bold;
    }
    input, button {
      padding: 12px;
      font-size: 16px;
      margin: 10px;
    }
  </style>
</head>
<body>
  <h1>Assistive LED Communicator for Non-Verbal Patients</h1>
  <form action="/login" method="POST">
    <input type="text" name="username" placeholder="Username" required><br>
    <input type="password" name="password" placeholder="Password" required><br>
    <button type="submit">Login</button>
  </form>
</body>
</html>
)rawliteral";

// Control page with speech
String controlPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>LED Control</title>
  <style>
    body {
      background-color: yellow;
      font-family: Arial, sans-serif;
      text-align: center;
    }
    h2 {
      color: green;
      font-size: 2em;
      font-weight: bold;
    }
    button {
      padding: 14px 28px;
      margin: 12px;
      font-size: 18px;
      border: none;
      cursor: pointer;
      border-radius: 8px;
    }
    .red { background-color: red; color: white; }
    .blue { background-color: blue; color: white; }
    .green { background-color: green; color: white; }
    .white { background-color: white; color: black; border: 1px solid black; }
  </style>
  <script>
    function speak(text) {
      const msg = new SpeechSynthesisUtterance(text);
      msg.lang = "en-US";
      window.speechSynthesis.speak(msg);
    }
  </script>
</head>
<body>
  <h2>Assistive LED Communicator for Non-Verbal Patients</h2>
  <form action="/led" method="POST">
    <button name="action" value="medications" class="red" onclick="speak('I need medications')">I need medications</button><br>
    <button name="action" value="food" class="blue" onclick="speak('I need food')">I need food</button><br>
    <button name="action" value="water" class="green" onclick="speak('I need water')">I need water</button><br>
    <button name="action" value="help" class="white" onclick="speak('I need help')">I need help</button>
  </form>
</body>
</html>
)rawliteral";

// Serve login page
void handleRoot() {
  server.send(200, "text/html", loginPage);
}

// Handle login
void handleLogin() {
  if (server.method() == HTTP_POST) {
    String username = server.arg("username");
    String password = server.arg("password");
    if (username == storedUsername && password == storedPassword) {
      server.send(200, "text/html", controlPage);
    } else {
      server.send(200, "text/html", "<h2>Invalid login. <a href='/'>Try again</a></h2>");
    }
  }
}

// Handle LED actions
void handleLED() {
  String action = server.arg("action");

  // Reset all LEDs
  digitalWrite(redLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(whiteLED, LOW);

  if (action == "medications") {
    for(int i=0; i<10; i++)
    {
      digitalWrite(redLED, HIGH);
      delay(500);
      digitalWrite(redLED, LOW);
      delay(500);
    }
  } 
  else if (action == "food") {
    for(int i=0; i<10; i++)
    {
      digitalWrite(blueLED, HIGH);
      delay(500);
      digitalWrite(blueLED, LOW);
      delay(500);
    }
  } 
  else if (action == "water") {
    for(int i=0; i<10; i++)
    {
      digitalWrite(greenLED, HIGH);
      delay(500);
      digitalWrite(greenLED, LOW);
      delay(500);
    }
  } 
  else if (action == "help") {
    for(int i=0; i<10; i++)
    {
      digitalWrite(whiteLED, HIGH);
      digitalWrite(whiteLED, LOW);
    }
  }

  server.send(200, "text/html", controlPage);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected to WiFi.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Setup LED pins
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);

  // Route handlers
  server.on("/", handleRoot);
  server.on("/login", handleLogin);
  server.on("/led", handleLED);

  server.begin();
}

void loop() {
  server.handleClient();
}

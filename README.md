# Reverse Shell - Arduino Digispark
For this to work you will need to download [ngrok](https://ngrok.com/download) and [netcat](https://pkgs.org/download/netcat).

### Installation ngrok
- Linux
```bash
curl -s https://ngrok-agent.s3.amazonaws.com/ngrok.asc | sudo tee /etc/apt/trusted.gpg.d/ngrok.asc >/dev/null && echo "deb https://ngrok-agent.s3.amazonaws.com buster main" | sudo tee /etc/apt/sources.list.d/ngrok.list && sudo apt update && sudo apt install ngrok
```
_NOTE: Netcat is already installed on Linux systems._

- Windows
### Installing Chocolatey
Open ```Powershell``` and run as administrator, then run the command below:
```bash
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```
### Installing ngrok

```powershell
> choco install ngrok
```
* NOTE: unlike Linux, Windows does not come with Netcat installed, so you can install it [here](https://eternallybored.org/misc/netcat/).

1. Extract `netcat-win32-1.12.zip` and move the extracted files to the directory on Windows: `C:/Windows/System32`
2. installations on the respective systems are done, now let's create the reverse shell

### Creating Reverse Shell

- Creating data tunnel to receive TCP packets

```bash
ngrok tcp 44444
```
![Captura de tela de 2023-04-30 21-23-24](https://user-images.githubusercontent.com/91799009/235383253-a2e9f8ad-f8b8-45e6-9ca9-36a48dfc6f54.png)

The print shows some ngrok connection information, you can see that there is a parameter called ```Forwarding```, when located, take the address `0.tcp.sa.ngrok.io` and port `16832` set and save it in some text editor, you will need it later.

- Now create a bridge to ngrok by setting the same port

```bash
nc -lnvp 44444
```

![Captura de tela de 2023-04-30 21-22-02](https://user-images.githubusercontent.com/91799009/235383207-a46c9b84-b7e6-4565-a9bf-d96a0301d75e.png)

- When configuring everything, go back to the [shell.ino](https://github.com/Vinnybrunn00/reverse_shell/blob/main/shell.ino) code, on line `27`, change `YOUR_NGROK_ADDRESS` to your ngrok address and `PORT_NGROK` for your ngrok port

Okay, now it's time to compile and run your tests :)








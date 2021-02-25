import websocket
import time
import json

dic = {
    "ssid":"Galaxy A71CA30",
    "password":"mzlw4323"
}
 
ws = websocket.WebSocket()
ws.connect("ws://192.168.4.1/")

ws.send(json.dumps(dic))

result = ws.recv()
print(result)

ws.close()

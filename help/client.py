import websocket
import time
import json

dic = {
    "ssid":"2.4g Adalberto",
    "password":"qi2001to500"
}
 
ws = websocket.WebSocket()
ws.connect("ws://192.168.4.1/")

ws.send(json.dumps(dic))

result = ws.recv()
print(result)

ws.close()

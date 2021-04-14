import requests
import time
import json

url = 'http://192.168.4.1/post?'
dic = {
    "ssid":"2.4g Adalberto",
    "password":"qi2001to500"
}
 
x = requests.post(url, json.dumps(dic))

print(x.text)


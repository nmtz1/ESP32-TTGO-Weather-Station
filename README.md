# ESP32-TTGO-Weather-Station
Creating a weather station with TTGO ESP32 T1 + SDS011 + BME280.

Plan is to create compact, enclosed and functional weather station for personal use to monitor following:
1. Particulate matter (PM2.5 & PM10)
2. Temperature
3. Humidity
4. Barometric pressure
5. Altitude

Idea is to use ESP32, for now with 1.12 inch display. However, I can already see it is pretty small and to fit all data in nice form and fonts and icons wont be readable so I will
move over to ESP32 with 2,8 or larger screen.

Parts:
1. Particulate matter sensor - Nova SDS011 - https://amzn.to/3koxxTt
2. Temperature, humidity, pressure sensor - Bosh BME280 - https://amzn.to/2O64QON
3. ESP32 - https://amzn.to/3stYwj9

As I said my first step was to put together esp32 with 1.14 inch display I already had like this https://amzn.to/3qXJ66h with SDS011 sensor.
That is the file in repository called SDS011.ino

Here is how it looks like on display

<img src="https://github.com/nmtz1/ESP32-TTGO-Weather-Station/blob/main/Images/SDS011%20ESP32%20PM_data.jpg" width="200" height="100">



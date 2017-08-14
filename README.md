# Doorbell-via-Wemos

Doorbell project to determine if the doorbell was pressed.

Version 1 was presented at the DomoticaGrunn Meetup #2. Slides can be found on [SpeakerDeck](https://speakerdeck.com/domoticagrunn/domoticagrunn-meetup-number-2).

It all started with the question "How to determine someone pressed the doorbell without interfering with the existing doorbell installation?".

My main requirements was that I did not want to mess with the existing setup or be dependant on extra components. I have seen several solutions, but sofar none of them met this requirement. ELMO

My doorbell installation is a standard Dutch doorbell installation:
![Dutch standard doorbell installation](img/standard_doorbell_installation.png)

Once the doorbell-button is pressed, the "signal" is send to the Wemos. The Wemos is connected to MQTT via the local Wi-Fi.
Home Assistant picks up the signal from MQTT. From there it's up to your imagination what you want to do with the input. 
For now I send a message to Slack-bot to notify me.

![From button press to HA via MQTT](img/from_button_to_HA_via_MQTT.png)

## Hardware v1.0
For the initial setup a colleague helped me out with the initial design and with some components he had lying around:
- Bridge Rectifier, B80 1500R
- Voltage regulator, 3.3V

![Hardware setup v1.0](img/hardware_setup_v1.0.png)

The initial setup worked, the measured voltage on the Wemos was between 1 and 2V. This was the setup presented at the DomoticaGrunn Meetup.

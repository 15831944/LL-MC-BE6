#pragma once
#define ADDRESS     "tcp://broker.emqx.io:1883"
#define USERNAME    "emqx"
#define PASSWORD    "public"
#define CLIENTID    "c-client"
#define QOS         0
#define TIMEOUT     10000L
void publish(MQTTClient client,const char* topic,string payload);
void pubchat(MQTTClient client, const char* topic, string _payload);
void subscribe(MQTTClient client, const char* TOPIC);
MQTTClient MqttInit(const char* TOPIC);
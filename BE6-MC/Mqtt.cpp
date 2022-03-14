#include "pch.h"
#include "res.h"
#include "Mqtt.h"
#include "stdlib.h"
#include "string.h"
#include <MQTTClient.h>
#include <MC/Level.hpp>
#include <LLAPI.h>
vector<string> msg;
void publish(MQTTClient client,const char* topic,string _payload) {
    string str = _payload;
    int len = str.size();
    char* payload = new char[len + 1];
    memset(payload, 0, len + 1);
    strncpy(payload, str.c_str(), str.size());
    MQTTClient_message message = MQTTClient_message_initializer;
    message.payload = payload;
    message.payloadlen = strlen(payload);
    message.qos = QOS;
    message.retained = 0;
    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, topic, &message, &token);
    MQTTClient_waitForCompletion(client, token, TIMEOUT);
    delete(payload);
}
void pubchat(MQTTClient client, const char* topic, string _payload) {
    string str = _payload;
    msg.push_back(str);
    publish(client, topic, str);
}
void subscribe(MQTTClient client,const char* TOPIC) {
    MQTTClient_subscribe(client, TOPIC, QOS);
}
int on_message(void* context, char* topicName, int topicLen, MQTTClient_message* message) {
    string payload= std::string((char*)message->payload, message->payloadlen);
    string topic = topicName;
    if (WorldChat && topic == "BE6MC/WorldChat" && !count(msg.begin(), msg.end(), payload)) {

        std::wstring result = Wordtrie.replaceSensitive(SBCConvert::s2ws(payload));
        payload = SBCConvert::ws2s(result);
        logger.info("[世界聊天] {}",payload);
        Level::broadcastText("§9<WorldChat>§b" + payload, TextType::RAW);  
    }
    else if (count(msg.begin(), msg.end(), payload))
    {
        msg.erase(remove(msg.begin(), msg.end(), payload));
    }else{
        if (msg.size()>30) msg.erase(msg.begin(), msg.end());
    }
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

MQTTClient MqttInit(const char *TOPIC) {
    MQTTClient client;
    MQTTClient_create(&client, ADDRESS, CLIENTID, 0, NULL);
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    conn_opts.username = USERNAME;
    conn_opts.password = PASSWORD;
    MQTTClient_setCallbacks(client, NULL, NULL, on_message, NULL);
    if ((MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS) {
        logger.error<<"连接服务器失败!"<<logger.endl;
    }
    else {
        logger.info << "连接服务器成功!" << logger.endl;
    }
    // subscribe topic
    MQTTClient_subscribe(client, TOPIC, QOS);
    return client;
}
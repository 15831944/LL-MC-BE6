#include "pch.h"
#include "Mqtt.h"
#include "stdlib.h"
#include "string.h"
#include <MQTTClient.h>
void publish(MQTTClient client, char* topic, char* payload) {
    MQTTClient_message message = MQTTClient_message_initializer;
    message.payload = payload;
    message.payloadlen = strlen(payload);
    message.qos = QOS;
    message.retained = 0;
    MQTTClient_deliveryToken token;
    MQTTClient_publishMessage(client, topic, &message, &token);
    MQTTClient_waitForCompletion(client, token, TIMEOUT);
    logger.info("发送消息 {} 到 {}" , payload,topic);
}
int on_message(void* context, char* topicName, int topicLen, MQTTClient_message* message) {
    string payload= (char*)message->payload;
    logger.info("收到来自 {} 的 {}", topicName,payload);
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
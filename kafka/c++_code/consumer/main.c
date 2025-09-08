#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <librdkafka/rdkafka.h>

static int run = 1;

static void stop(int sig) {
    run = 0;
}

int main() {
    const char *brokers = "192.168.198.131:9092";
    const char *topic = "test";
    const char *group_id = "c_consumer_group";

    char errstr[512];

    // 注册信号处理（Ctrl+C 退出）
    signal(SIGINT, stop);

    // 创建配置
    rd_kafka_conf_t *conf = rd_kafka_conf_new();
    rd_kafka_conf_set(conf, "bootstrap.servers", brokers, errstr, sizeof(errstr));
    rd_kafka_conf_set(conf, "group.id", group_id, errstr, sizeof(errstr));
    rd_kafka_conf_set(conf, "auto.offset.reset", "earliest", errstr, sizeof(errstr));

    // 创建消费者实例
    rd_kafka_t *rk = rd_kafka_new(RD_KAFKA_CONSUMER, conf, errstr, sizeof(errstr));
    if (!rk) {
        fprintf(stderr, "%% Failed to create consumer: %s\n", errstr);
        return 1;
    }

    // 订阅 topic
    rd_kafka_topic_partition_list_t *topics = rd_kafka_topic_partition_list_new(1);
    rd_kafka_topic_partition_list_add(topics, topic, -1);

    if (rd_kafka_subscribe(rk, topics)) {
        fprintf(stderr, "%% Failed to subscribe to topic\n");
        return 1;
    }

    rd_kafka_topic_partition_list_destroy(topics);

    // 消费循环
    while (run) {
        rd_kafka_message_t *msg = rd_kafka_consumer_poll(rk, 1000);
        if (!msg) continue;

        if (msg->err) {
            if (msg->err == RD_KAFKA_RESP_ERR__PARTITION_EOF) {
                // 分区消费完毕，不是错误
            } else {
                fprintf(stderr, "%% Error: %s\n", rd_kafka_message_errstr(msg));
                run = 0;
            }
        } else {
            printf("%% Received message: %.*s\n", (int)msg->len, (char *)msg->payload);
        }

        rd_kafka_message_destroy(msg);
    }

    // 关闭消费者
    rd_kafka_consumer_close(rk);
    rd_kafka_destroy(rk);

    return 0;
}

   

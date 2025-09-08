
import org.apache.kafka.clients.consumer.*;
import org.apache.kafka.common.PartitionInfo;
import org.apache.kafka.common.TopicPartition;
import org.apache.kafka.common.record.Record;
import org.apache.kafka.common.serialization.StringDeserializer;

import java.time.Duration;
import java.util.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ConsumerExample {
    public static void main(String[] args) {
        String topic = "test";

        Properties props = new Properties();
        props.put(ConsumerConfig.BOOTSTRAP_SERVERS_CONFIG, "192.168.198.131:9092");
        props.put(ConsumerConfig.GROUP_ID_CONFIG, "c_consumer_group");
        props.put(ConsumerConfig.KEY_DESERIALIZER_CLASS_CONFIG, StringDeserializer.class.getName());
        props.put(ConsumerConfig.VALUE_DESERIALIZER_CLASS_CONFIG, StringDeserializer.class.getName());
        props.put(ConsumerConfig.ENABLE_AUTO_COMMIT_CONFIG, "true");

        KafkaConsumer<String, String> consumer = new KafkaConsumer<String, String>(props);
        List<PartitionInfo> PartitionInfos = consumer.partitionsFor(topic);

        ExecutorService executorService = Executors.newFixedThreadPool(PartitionInfos.size());

        for (PartitionInfo partitionInfo : PartitionInfos) {
            executorService.submit(() -> {
                while (true) {
                    KafkaConsumer<String, String> partitionConsumer = new KafkaConsumer<String, String>(props);

                    partitionConsumer.assign(Collections.singleton(new TopicPartition(topic, partitionInfo.partition())));

                    ConsumerRecords<String, String> consumerRecords = partitionConsumer.poll(Duration.ofMillis(100));
                    for (ConsumerRecord<String, String> record : consumerRecords) {
                        System.out.printf("con =%s =%s =%s =%s\n", record.value(), record.partition(), record.offset(), record.topic());
                    }
                    partitionConsumer.commitSync();
                }
            });
        }


    }
}


import org.apache.kafka.clients.producer.*;
import org.apache.kafka.common.serialization.StringSerializer;

import java.util.Properties;

public class ProducerExample {
    public static void main(String[] args) {
        String topic = "orders";
        Properties props = new Properties();
        props.put(ProducerConfig.BOOTSTRAP_SERVERS_CONFIG, "192.168.198.131:9092");
        props.put(ProducerConfig.KEY_SERIALIZER_CLASS_CONFIG, StringSerializer.class.getName());
        props.put(ProducerConfig.VALUE_SERIALIZER_CLASS_CONFIG, StringSerializer.class.getName());
        props.put(ProducerConfig.ACKS_CONFIG, "all");

        try (KafkaProducer<String, String> producer = new KafkaProducer<>(props)) {

            for (int i = 1; i <= 10; i++) {
                String orderId = "order-" + (i % 3); 
                String message = "Event " + i + " for " + orderId;

                ProducerRecord<String, String> record = new ProducerRecord<>(topic, orderId, message);

                producer.send(record, new Callback() {
                    @Override
                    public void onCompletion(RecordMetadata metadata, Exception exception) {
                        if (exception == null) {
                            System.out.printf("Sent to partition %d with offset %d: %s%n",
                                    metadata.partition(), metadata.offset(), message);
                        } else {
                            exception.printStackTrace();
                        }
                    }
                });
            }
        }
    }
}
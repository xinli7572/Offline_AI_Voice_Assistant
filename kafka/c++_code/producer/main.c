
#include <iostream>
#include <librdkafka/rdkafkacpp.h>

int main() {
    std::string brokers = "localhost:9092";
    std::string topic = "test";

    std::string errstr;

    RdKafka::Conf *conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    conf->set("bootstrap.servers", brokers, errstr);

    RdKafka::Producer *producer = RdKafka::Producer::create(conf, errstr);
    if (!producer) {
        std::cerr << "Failed to create producer: " << errstr << std::endl;
        return 1;
    }

    std::string message = "Hello, Kafka from C++!";



	RdKafka::ErrorCode resp = producer->produce(
	    topic,                                  // topic name
	    RdKafka::Topic::PARTITION_UA,          // use automatic partition
	    RdKafka::Producer::RK_MSG_COPY,        // message flag
	    const_cast<char *>(message.c_str()),   // payload
	    message.size(),                         // payload length
	    nullptr, 0,                             // no key
	    0,                                      // default timestamp
	    nullptr                                 // opaque pointer
	);


    if (resp != RdKafka::ERR_NO_ERROR)
        std::cerr << "Produce failed: " << RdKafka::err2str(resp) << std::endl;
    else
        std::cout << "Message sent: " << message << std::endl;

    producer->flush(5000);  

    delete producer;
    delete conf;

    return 0;
}


# Producer-Consumer Problem and Thread Management in Java

This README provides an explanation and code snippets for implementing the Producer-Consumer problem in Java and understanding key thread management concepts such as thread priority, join, and daemon threads.

---

## Assignment: Implement Producer-Consumer Problem

### Problem Description
Two threads, a producer and a consumer, share a common, fixed-size buffer as a queue:
- The producer's job is to generate data and put it into the buffer.
- The consumer's job is to consume the data from the buffer.

The problem is to ensure:
- The producer doesn't produce data if the buffer is full.
- The consumer doesn't consume data if the buffer is empty.

---

### Code Implementation

#### Shared Resource Class
The `SharedResource` class manages the buffer and provides synchronized methods for producing and consuming data.

```java
import java.util.Queue;
import java.util.LinkedList;

public class SharedResource {
    private Queue<Integer> sharedBuffer;
    private int bufferSize;

    public SharedResource(int bufferSize) {
        this.sharedBuffer = new LinkedList<>();
        this.bufferSize = bufferSize;
    }

    // Producer thread logic
    public synchronized void produce(int item) throws Exception {
        // Wait if the buffer is full
        while (sharedBuffer.size() == bufferSize) {
            System.out.println("Buffer is full, Producer is waiting for consumer");
            wait();
        }
        sharedBuffer.add(item);
        System.out.println("Produced: " + item);
        // Notify the consumer thread
        notify();
    }

    // Consumer thread logic
    public synchronized int consume() throws Exception {
        // Wait if the buffer is empty
        while (sharedBuffer.isEmpty()) {
            System.out.println("Buffer is empty, Consumer is waiting for producer");
            wait();
        }
        int item = sharedBuffer.poll();
        System.out.println("Consumed: " + item);
        // Notify the producer thread
        notify();
        return item;
    }
}
```

#### Producer and Consumer Threads
These threads use the `SharedResource` class to produce and consume data.

```java
public class ProducerConsumerLearning {
    public static void main(String[] args) {
        SharedResource sharedBuffer = new SharedResource(5);

        // Creating producer thread
        Thread producerThread = new Thread(() -> {
            try {
                for (int i = 1; i <= 10; i++) {
                    sharedBuffer.produce(i);
                }
            } catch (Exception e) {
                // Handle exception
            }
        });

        // Creating consumer thread
        Thread consumerThread = new Thread(() -> {
            try {
                for (int i = 1; i <= 10; i++) {
                    sharedBuffer.consume();
                }
            } catch (Exception e) {
                // Handle exception
            }
        });

        producerThread.start();
        consumerThread.start();
    }
}
```

#### Example Output
```
Produced: 1
Produced: 2
Produced: 3
Produced: 4
Produced: 5
Buffer is full, Producer is waiting for consumer
Consumed: 1
Consumed: 2
Consumed: 3
Consumed: 4
Consumed: 5
Buffer is empty, Consumer is waiting for producer
Produced: 6
Produced: 7
Produced: 8
Produced: 9
Produced: 10
Consumed: 6
Consumed: 7
Consumed: 8
Consumed: 9
Consumed: 10
```

---

## Why Stop, Resume, and Suspend Methods are Deprecated?

### Key Points
1. **Stop**: Abruptly terminates the thread without releasing resources or cleaning up.
2. **Suspend**: Temporarily puts the thread on hold but locks resources leading to potential deadlocks.
3. **Resume**: Resumes the execution of a suspended thread; however, can lead to deadlock issues.

---

## Thread Management in Java

### `Join` Method
- When the `join()` method is invoked on a thread object, the current thread will be blocked until the specified thread completes.
- Useful for coordinating between threads.

#### Example
```java
Thread t1 = new Thread(() -> {
    System.out.println("Thread 1 executing");
});

Thread t2 = new Thread(() -> {
    try {
        t1.join(); // Waits for thread t1 to finish
        System.out.println("Thread 2 executing after Thread 1");
    } catch (InterruptedException e) {
        e.printStackTrace();
    }
});

t1.start();
t2.start();
```

---

### Thread Priority
- Priorities range from 1 (lowest) to 10 (highest).
- Thread priority is a hint to the scheduler and does not guarantee execution order.

#### Example
```java
Thread t1 = new Thread(() -> {
    System.out.println("Thread 1 executing");
});
t1.setPriority(Thread.MAX_PRIORITY); // Priority 10
t1.start();
```

---

### Daemon Thread
- Daemon threads run in the background and do not prevent the JVM from exiting.
- Use the `setDaemon(true)` method to mark a thread as a daemon.

#### Example
```java
Thread daemonThread = new Thread(() -> {
    while (true) {
        System.out.println("Daemon thread running in background");
    }
});
daemonThread.setDaemon(true);
daemonThread.start();
```

---

### Visual Explanation

**Producer-Consumer Buffer Diagram**

![image1](image1)

**Thread Priority and Join Mechanism**

![image2](image2)

---

### Conclusion
Understanding the Producer-Consumer problem and thread management concepts are essential for robust multithreading and concurrency handling in Java. Use these code snippets and diagrams to implement and grasp these concepts effectively.
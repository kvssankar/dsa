# Concurrency in Java

Concurrency in Java can be achieved using two broad mechanisms: **Lock-based Mechanisms** and **Lock-free Mechanisms**. This document explains these mechanisms with code examples and comments.

---

## 1. Lock-based Mechanism

Lock-based mechanisms rely on explicit locking to ensure thread safety. Common types of locks include:
- Synchronized blocks
- Reentrant locks
- Stamped locks
- ReadWrite locks
- Semaphores

### Example: Using `synchronized` for thread safety

```java
// SharedResource demonstrating synchronized locking
public class SharedResource {
    // Counter shared by multiple threads
    private int counter;

    // Synchronized method ensures only one thread can access at a time
    public synchronized void increment() {
        counter++;
    }

    // Method to retrieve the counter value
    public int get() {
        return counter;
    }
}

// Main class demonstrating thread safety
public class Main {
    public static void main(String[] args) throws InterruptedException {
        SharedResource resource = new SharedResource();

        // Create two threads that increment the counter
        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 200; i++) {
                resource.increment();
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 200; i++) {
                resource.increment();
            }
        });

        t1.start();
        t2.start();

        // Wait for both threads to finish execution
        t1.join();
        t2.join();

        // Prints the correct counter value (400)
        System.out.println("Counter value: " + resource.get());
    }
}
```

---

## 2. Lock-free Mechanism

Lock-free mechanisms use **CAS (Compare-and-Swap)** operations to achieve thread safety without explicit locks. This is more efficient in scenarios with high contention.

### Example: Using `AtomicInteger` for lock-free thread safety

```java
// SharedResource demonstrating lock-free mechanism using AtomicInteger
import java.util.concurrent.atomic.AtomicInteger;

public class SharedResource {
    // AtomicInteger ensures thread-safe increment without locks
    private final AtomicInteger counter = new AtomicInteger(0);

    // Increment the counter atomically
    public void increment() {
        counter.incrementAndGet();
    }

    // Method to retrieve the counter value
    public int get() {
        return counter.get();
    }
}

// Main class demonstrating lock-free thread safety
public class Main {
    public static void main(String[] args) throws InterruptedException {
        SharedResource resource = new SharedResource();

        // Create two threads that increment the counter
        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 200; i++) {
                resource.increment();
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 200; i++) {
                resource.increment();
            }
        });

        t1.start();
        t2.start();

        // Wait for both threads to finish execution
        t1.join();
        t2.join();

        // Prints the correct counter value (400)
        System.out.println("Counter value: " + resource.get());
    }
}
```

---

## 3. Atomic Variables

Atomic variables, such as `AtomicInteger`, `AtomicBoolean`, and `AtomicReference`, operate atomically to ensure thread safety. They rely on low-level CAS operations.

### Key Features of Atomic Variables:
- **Atomicity**: Guarantees operations are indivisible.
- **Efficient**: Avoids the overhead of locks.

---

## 4. Concurrent Collections

Java provides thread-safe collections for managing concurrent access to data structures.

### Common Concurrent Collections:
| Collection          | Concurrent Alternative      | Lock Mechanism          |
|----------------------|-----------------------------|-------------------------|
| `PriorityQueue`     | `PriorityBlockingQueue`     | ReentrantLock           |
| `LinkedList`        | `ConcurrentLinkedDeque`     | Compare-and-Swap        |
| `HashMap`           | `ConcurrentHashMap`         | Compare-and-Swap        |
| `TreeSet`           | `Collections.synchronizedSortedSet` | Synchronized |

### Example: Using `ConcurrentHashMap`

```java
import java.util.concurrent.ConcurrentHashMap;

public class ConcurrentCollectionExample {
    public static void main(String[] args) {
        // Thread-safe map
        ConcurrentHashMap<String, Integer> map = new ConcurrentHashMap<>();

        // Add data to the map
        map.put("A", 1);
        map.put("B", 2);

        // Retrieve values safely
        System.out.println("Value for A: " + map.get("A"));
    }
}
```

---

## Summary

Concurrency is critical for building efficient multi-threaded applications. While **Lock-based mechanisms** offer simplicity, **Lock-free mechanisms** provide better performance under high contention. Additionally, **Atomic variables** and **Concurrent collections** simplify thread-safe programming in modern Java applications.

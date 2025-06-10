# Java Lock Mechanisms

This document provides an overview of various lock mechanisms in Java: `ReentrantLock`, `ReadWriteLock`, `StampedLock`, and `Semaphore`. Each section is accompanied by code snippets with detailed comments to explain the functionality.

---

## 1. ReentrantLock

`ReentrantLock` is a lock with the same basic behavior as the implicit monitor lock accessed using `synchronized`. It provides additional features like fairness and explicit unlocking.

### Code Example
```java name=ReentrantLockExample.java
import java.util.concurrent.locks.ReentrantLock;

public class SharedResource {
    boolean isAvailable = false;
    ReentrantLock lock = new ReentrantLock();

    public void producer() {
        try {
            lock.lock(); // Acquiring the lock
            System.out.println("Lock acquired by: " + Thread.currentThread().getName());
            isAvailable = true;
            Thread.sleep(4000); // Simulating work
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            lock.unlock(); // Releasing the lock
            System.out.println("Lock released by: " + Thread.currentThread().getName());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        Thread th1 = new Thread(resource::producer);
        Thread th2 = new Thread(resource::producer);

        th1.start();
        th2.start();
    }
}
```

---

## 2. ReadWriteLock

`ReadWriteLock` allows multiple readers or one writer at a time, making it suitable for scenarios with a high ratio of read operations to write operations.

### Code Example
```java name=ReadWriteLockExample.java
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class SharedResource {
    boolean isAvailable = false;
    ReentrantReadWriteLock lock = new ReentrantReadWriteLock();

    public void producer() {
        try {
            lock.readLock().lock(); // Acquiring the read lock
            System.out.println("Read Lock acquired by: " + Thread.currentThread().getName());
            isAvailable = true;
            Thread.sleep(8000); // Simulating work
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            lock.readLock().unlock(); // Releasing the read lock
            System.out.println("Read Lock released by: " + Thread.currentThread().getName());
        }
    }

    public void consumer() {
        try {
            lock.writeLock().lock(); // Acquiring the write lock
            System.out.println("Write Lock acquired by: " + Thread.currentThread().getName());
            isAvailable = false;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            lock.writeLock().unlock(); // Releasing the write lock
            System.out.println("Write Lock released by: " + Thread.currentThread().getName());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        Thread th1 = new Thread(resource::producer);
        Thread th2 = new Thread(resource::consumer);

        th1.start();
        th2.start();
    }
}
```

---

## 3. StampedLock

`StampedLock` is an advanced lock mechanism introduced in Java 8. It supports optimistic locking in addition to read/write locks.

### Code Example
#### Read/Write Lock Functionality
```java name=StampedLockExample.java
import java.util.concurrent.locks.StampedLock;

public class SharedResource {
    boolean isAvailable = false;
    StampedLock lock = new StampedLock();

    public void producer() {
        long stamp = lock.readLock(); // Acquiring the read lock
        try {
            System.out.println("Read Lock acquired by: " + Thread.currentThread().getName());
            isAvailable = true;
            Thread.sleep(6000); // Simulating work
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            lock.unlockRead(stamp); // Releasing the read lock
            System.out.println("Read Lock released by: " + Thread.currentThread().getName());
        }
    }

    public void consumer() {
        long stamp = lock.writeLock(); // Acquiring the write lock
        try {
            System.out.println("Write Lock acquired by: " + Thread.currentThread().getName());
            isAvailable = false;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            lock.unlockWrite(stamp); // Releasing the write lock
            System.out.println("Write Lock released by: " + Thread.currentThread().getName());
        }
    }
}
```

#### Optimistic Lock Functionality
```java name=StampedLockOptimisticExample.java
import java.util.concurrent.locks.StampedLock;

public class SharedResource {
    int a = 10;
    StampedLock lock = new StampedLock();

    public void producer() {
        long stamp = lock.tryOptimisticRead(); // Acquiring optimistic read lock
        try {
            System.out.println("Taken optimistic lock");
            Thread.sleep(6000); // Simulating work
            if (lock.validate(stamp)) { // Validating the lock
                System.out.println("Updated a value successfully");
            } else {
                System.out.println("Rollback of work");
                a = 10; // Rollback
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void consumer() {
        long stamp = lock.writeLock(); // Acquiring the write lock
        try {
            System.out.println("Write lock acquired by: " + Thread.currentThread().getName());
            a = 9; // Performing work
        } finally {
            lock.unlockWrite(stamp); // Releasing the write lock
            System.out.println("Write lock released by: " + Thread.currentThread().getName());
        }
    }
}
```

---

## 4. Semaphore Lock

`Semaphore` controls access to a resource by maintaining a set number of permits. Threads acquire permits before accessing the resource and release them afterward.

### Code Example
```java name=SemaphoreLockExample.java
import java.util.concurrent.Semaphore;

public class SharedResource {
    boolean isAvailable = false;
    Semaphore lock = new Semaphore(2); // Allowing 2 threads to acquire the lock

    public void producer() {
        try {
            lock.acquire(); // Acquiring the semaphore lock
            System.out.println("Lock acquired by: " + Thread.currentThread().getName());
            isAvailable = true;
            Thread.sleep(4000); // Simulating work
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            lock.release(); // Releasing the semaphore lock
            System.out.println("Lock released by: " + Thread.currentThread().getName());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        Thread th1 = new Thread(resource::producer);
        Thread th2 = new Thread(resource::producer);
        Thread th3 = new Thread(resource::producer);
        Thread th4 = new Thread(resource::producer);

        th1.start();
        th2.start();
        th3.start();
        th4.start();
    }
}
```

---

## 5. Condition

`Condition` provides advanced coordination features, such as signaling threads, and is used in conjunction with `Lock`.

### Code Example
```java name=ConditionExample.java
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class SharedResource {
    ReentrantLock lock = new ReentrantLock();
    Condition condition = lock.newCondition();

    public void awaitCondition() {
        try {
            lock.lock(); // Acquiring the lock
            System.out.println("Thread waiting: " + Thread.currentThread().getName());
            condition.await(); // Waiting for signal
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            lock.unlock(); // Releasing the lock
        }
    }

    public void signalCondition() {
        try {
            lock.lock(); // Acquiring the lock
            System.out.println("Thread signaling: " + Thread.currentThread().getName());
            condition.signal(); // Sending signal
        } finally {
            lock.unlock(); // Releasing the lock
        }
    }
}
```

---

### Conclusion
These lock mechanisms provide powerful means for thread synchronization and resource sharing. Choose the appropriate mechanism depending on the use case:
- **ReentrantLock**: For simple locking scenarios.
- **ReadWriteLock**: For scenarios with frequent read operations.
- **StampedLock**: For performance-critical applications needing optimistic locking.
- **Semaphore**: For managing access to limited resources.
- **Condition**: For advanced thread coordination.
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 6675
// Hash 8139
// Hash 5192
// Hash 8525
// Hash 8317
// Hash 7353
// Hash 2737
// Hash 9822
// Hash 8999
// Hash 9312
// Hash 7059
// Hash 8385
// Hash 3904
// Hash 6149
// Hash 1857
// Hash 1030
// Hash 7656
// Hash 4398
// Hash 6441
// Hash 2001
// Hash 3462
// Hash 6182
// Hash 3084
// Hash 9871
// Hash 7952
// Hash 1686
// Hash 1975
// Hash 9244
// Hash 7528
// Hash 7551
// Hash 6607
// Hash 9072
// Hash 1356
// Hash 1258
// Hash 2048
// Hash 4842
// Hash 1368
// Hash 8045
// Hash 5201
// Hash 8731
// Hash 3479
// Hash 5417
// Hash 7989
// Hash 7004
// Hash 9811
// Hash 4595
// Hash 4046
// Hash 4161
// Hash 4103
// Hash 7776
// Hash 1405
// Hash 4560
// Hash 8101
// Hash 7371
// Hash 4578
// Hash 1065
// Hash 9109
// Hash 1584
// Hash 3401
// Hash 9634
// Hash 8369
// Hash 5870
// Hash 5768
// Hash 2638
// Hash 5186
// Hash 4211
// Hash 3014
// Hash 6267
// Hash 3359
// Hash 7659
// Hash 5394
// Hash 6109
// Hash 2120
// Hash 9362
// Hash 1562
// Hash 4438
// Hash 6651
// Hash 5968
// Hash 1556
// Hash 6318
// Hash 8899
// Hash 2074
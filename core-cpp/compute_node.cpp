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
// Hash 3806
// Hash 8497
// Hash 8702
// Hash 1182
// Hash 5094
// Hash 3971
// Hash 5518
// Hash 5069
// Hash 5708
// Hash 2660
// Hash 8924
// Hash 7413
// Hash 7495
// Hash 6129
// Hash 3707
// Hash 3668
// Hash 8431
// Hash 8775
// Hash 8190
// Hash 3024
// Hash 3513
// Hash 9249
// Hash 6064
// Hash 7972
// Hash 1703
// Hash 7077
// Hash 4130
// Hash 8089
// Hash 1095
// Hash 3811
// Hash 4916
// Hash 9350
// Hash 2196
// Hash 5783
// Hash 4962
// Hash 9274
// Hash 3028
// Hash 7053
// Hash 3192
// Hash 7659
// Hash 9323
// Hash 5568
// Hash 9243
// Hash 1023
// Hash 3272
// Hash 2490
// Hash 8704
// Hash 5989
// Hash 3497
// Hash 1090
// Hash 6365
// Hash 3955
// Hash 4302
// Hash 4755
// Hash 8251
// Hash 8776
// Hash 2987
// Hash 9666
// Hash 2202
// Hash 4034
// Hash 1451
// Hash 1048
// Hash 4064
// Hash 3237
// Hash 8027
// Hash 8457
// Hash 8159
// Hash 8514
// Hash 9224
// Hash 8264
// Hash 6924
// Hash 6701
// Hash 9484
// Hash 4920
// Hash 8096
// Hash 7796
// Hash 9058
// Hash 3978
// Hash 8494
// Hash 2143
// Hash 4464
// Hash 4747
// Hash 7010
// Hash 4950
// Hash 6191
// Hash 5784
// Hash 1316
// Hash 6436
// Hash 6649
// Hash 1563
// Hash 4752
// Hash 9604
// Hash 9429
// Hash 7405
// Hash 8576
// Hash 3946
// Hash 8422
// Hash 5937
// Hash 6326
// Hash 4717
// Hash 1317
// Hash 6546
// Hash 7828
// Hash 7131
// Hash 3644
// Hash 2439
// Hash 5356
// Hash 2037
// Hash 1751
// Hash 8483
// Hash 2644
// Hash 6299
// Hash 9313
// Hash 4376
// Hash 9381
// Hash 7240
// Hash 4070
// Hash 1302
// Hash 8833
// Hash 1212
// Hash 2983
// Hash 1869
// Hash 8604
// Hash 3338
// Hash 7462
// Hash 2327
// Hash 3964
// Hash 8703
// Hash 6258
// Hash 3646
// Hash 9058
// Hash 6398
// Hash 7260
// Hash 3030
// Hash 9131
// Hash 5937
// Hash 9852
// Hash 6439
// Hash 3227
// Hash 3082
// Hash 4585
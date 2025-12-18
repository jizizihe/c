#include <iostream>
#include <cstdint>

/* =====================
 * 1. 定义回调类型（C 风格）
 * ===================== */
typedef void (*camera_notify_callback)(int msg, int ext1, int ext2, void *user);
typedef void (*camera_data_callback)(const void *data, size_t size, void *user);
typedef void (*camera_data_timestamp_callback)(const void *data,
                                               size_t size,
                                               int64_t timestamp,
                                               void *user);

/* =====================
 * 2. CallbackNotifier 类
 * ===================== */
class CallbackNotifier {
public:
    void setCallbacks(camera_notify_callback notify_cb,
                      camera_data_callback data_cb,
                      camera_data_timestamp_callback data_cb_timestamp,
                      void *user)
    {
        mNotifyCb = notify_cb;
        mDataCb = data_cb;
        mDataTsCb = data_cb_timestamp;
        mUser = user;
    }

    /* 模拟触发事件 */
    void simulateNotify()
    {
        if (mNotifyCb) {
            mNotifyCb(100, 1, 2, mUser);
        }
    }

    void simulateFrame()
    {
        const char dummy[] = "frame_data";
        if (mDataCb) {
            mDataCb(dummy, sizeof(dummy), mUser);
        }
    }

    void simulateFrameWithTs()
    {
        const char dummy[] = "frame_data_ts";
        if (mDataTsCb) {
            mDataTsCb(dummy, sizeof(dummy), 123456789, mUser);
        }
    }

private:
    camera_notify_callback mNotifyCb = nullptr;
    camera_data_callback mDataCb = nullptr;
    camera_data_timestamp_callback mDataTsCb = nullptr;
    void *mUser = nullptr;
};

/* =====================
 * 3. 使用回调的 C++ 类
 * ===================== */
class CameraApp {
public:
    /* static 回调函数 */
    static void notifyCallback(int msg, int ext1, int ext2, void *user)
    {
        auto *self = static_cast<CameraApp *>(user);
        self->onNotify(msg, ext1, ext2);
    }

    static void dataCallback(const void *data, size_t size, void *user)
    {
        auto *self = static_cast<CameraApp *>(user);
        self->onData(data, size);
    }

    static void dataTsCallback(const void *data,
                               size_t size,
                               int64_t ts,
                               void *user)
    {
        auto *self = static_cast<CameraApp *>(user);
        self->onDataTs(data, size, ts);
    }

private:
    void onNotify(int msg, int ext1, int ext2)
    {
        std::cout << "[Notify] msg=" << msg
                  << " ext1=" << ext1
                  << " ext2=" << ext2 << std::endl;
    }

    void onData(const void *data, size_t size)
    {
        std::cout << "[Data] size=" << size
                  << " content=" << static_cast<const char *>(data)
                  << std::endl;
    }

    void onDataTs(const void *data, size_t size, int64_t ts)
    {
        std::cout << "[DataTs] size=" << size
                  << " ts=" << ts
                  << " content=" << static_cast<const char *>(data)
                  << std::endl;
    }
};

/* =====================
 * 4. main 函数
 * ===================== */
int main()
{
    CallbackNotifier notifier;
    CameraApp app;

    notifier.setCallbacks(
        CameraApp::notifyCallback,
        CameraApp::dataCallback,
        CameraApp::dataTsCallback,
        &app
    );

    notifier.simulateNotify();
    notifier.simulateFrame();
    notifier.simulateFrameWithTs();

    return 0;
}


#include <stdio.h>
#include <stdint.h>

/* =====================
 * 1. 回调类型定义（C）
 * ===================== */
typedef void (*camera_notify_callback)(int msg, int ext1, int ext2, void *user);
typedef void (*camera_data_callback)(const void *data, size_t size, void *user);
typedef void (*camera_data_timestamp_callback)(const void *data,
                                               size_t size,
                                               int64_t timestamp,
                                               void *user);

/* =====================
 * 2. Notifier（类似 C++ 类）
 * ===================== */
struct callback_notifier {
    camera_notify_callback notify_cb;
    camera_data_callback data_cb;
    camera_data_timestamp_callback data_ts_cb;
    void *user;
};

void notifier_set_callbacks(struct callback_notifier *n,
                            camera_notify_callback notify_cb,
                            camera_data_callback data_cb,
                            camera_data_timestamp_callback data_ts_cb,
                            void *user)
{
    n->notify_cb = notify_cb;
    n->data_cb = data_cb;
    n->data_ts_cb = data_ts_cb;
    n->user = user;
}

/* 模拟触发 */
void notifier_notify(struct callback_notifier *n)
{
    if (n->notify_cb) {
        n->notify_cb(100, 1, 2, n->user);
    }
}

void notifier_frame(struct callback_notifier *n)
{
    const char data[] = "frame_data";
    if (n->data_cb) {
        n->data_cb(data, sizeof(data), n->user);
    }
}

void notifier_frame_ts(struct callback_notifier *n)
{
    const char data[] = "frame_data_ts";
    if (n->data_ts_cb) {
        n->data_ts_cb(data, sizeof(data), 123456789, n->user);
    }
}

/* =====================
 * 3. 应用层上下文（重点）
 * ===================== */
struct app_ctx {
    int camera_id;
};

/* =====================
 * 4. 回调函数（C）
 * ===================== */
void notify_callback(int msg, int ext1, int ext2, void *user)
{
    struct app_ctx *ctx = (struct app_ctx *)user;
    printf("[Notify] cam=%d msg=%d ext1=%d ext2=%d\n",
           ctx->camera_id, msg, ext1, ext2);
}

void data_callback(const void *data, size_t size, void *user)
{
    struct app_ctx *ctx = (struct app_ctx *)user;
    printf("[Data] cam=%d size=%zu content=%s\n",
           ctx->camera_id, size, (const char *)data);
}

void data_ts_callback(const void *data, size_t size, int64_t ts, void *user)
{
    struct app_ctx *ctx = (struct app_ctx *)user;
    printf("[DataTs] cam=%d size=%zu ts=%lld content=%s\n",
           ctx->camera_id, size, (long long)ts, (const char *)data);
}

/* =====================
 * 5. main
 * ===================== */
int main(void)
{
    struct callback_notifier notifier = {0};
    struct app_ctx app = {
        .camera_id = 0,
    };

    notifier_set_callbacks(&notifier,
                           notify_callback,
                           data_callback,
                           data_ts_callback,
                           &app);

    notifier_notify(&notifier);
    notifier_frame(&notifier);
    notifier_frame_ts(&notifier);

    return 0;
}


#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "FRUIT_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🍎 เริ่มต้นคำนวณราคาผลไม้ 🛒");
    ESP_LOGI(TAG, "==============================");

    // จำนวนและราคาต่อหน่วย
    int apple_qty = 6;
    int apple_price = 15;
    int banana_qty = 12;
    int banana_price = 8;
    int orange_qty = 8;
    int orange_price = 12;

    // คำนวณราคาสินค้าแต่ละชนิด
    int apple_total = apple_qty * apple_price;
    int banana_total = banana_qty * banana_price;
    int orange_total = orange_qty * orange_price;

    // รวมราคาทั้งหมด
    int total = apple_total + banana_total + orange_total;

    // ส่วนลด
    int discount = 20;
    int total_after_discount = total - discount;

    // หาร 3 คน
    float per_person = total_after_discount / 3.0;

    // แสดงการคิดทีละขั้น
    ESP_LOGI(TAG, "📦 การคำนวณราคาผลไม้");
    ESP_LOGI(TAG, "  แอปเปิ้ล: %d × %d = %d บาท", apple_qty, apple_price, apple_total);
    ESP_LOGI(TAG, "  กล้วย:   %d × %d = %d บาท", banana_qty, banana_price, banana_total);
    ESP_LOGI(TAG, "  ส้ม:      %d × %d = %d บาท", orange_qty, orange_price, orange_total);
    ESP_LOGI(TAG, "  รวมทั้งหมด: %d + %d + %d = %d บาท", 
             apple_total, banana_total, orange_total, total);
    ESP_LOGI(TAG, "  หักส่วนลด: %d - %d = %d บาท", total, discount, total_after_discount);
    ESP_LOGI(TAG, "  แบ่งจ่าย 3 คน: %.2f บาท/คน", per_person);

    // สรุป
    ESP_LOGI(TAG, "==============================");
    ESP_LOGI(TAG, "✅ สรุป:");
    ESP_LOGI(TAG, "   ราคาก่อนลด: %d บาท", total);
    ESP_LOGI(TAG, "   หลังหักส่วนลด: %d บาท", total_after_discount);
    ESP_LOGI(TAG, "   จ่ายคนละ: %.2f บาท", per_person);
    ESP_LOGI(TAG, "==============================");

    // รอเพื่อให้ log แสดงครบ
    vTaskDelay(5000 / portTICK_PERIOD_MS);
}
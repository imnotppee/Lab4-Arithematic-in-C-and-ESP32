#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "TOYS_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🧸 เริ่มต้นโปรแกรมนับของเล่นของน้อง 🧸");
    ESP_LOGI(TAG, "=========================================");

    // ประกาศตัวแปร
    int toys_have = 15;        // ของเล่นที่น้องมีอยู่
    int toys_give_away = 7;    // แจกไปแล้ว
    int dolls = 5;             // ตุ๊กตา
    int robots = 2;            // หุ่นยนต์
    int toys_remaining = 0;    // ของเล่นที่เหลือ
    int total_toys = 0;        // รวมของเล่นทุกประเภท

    // แสดงโจทย์
    ESP_LOGI(TAG, "📖 โจทย์:");
    ESP_LOGI(TAG, "   น้องมีของเล่น: %d ชิ้น", toys_have);
    ESP_LOGI(TAG, "   เอาไปแจกให้เพื่อน: %d ชิ้น", toys_give_away);
    ESP_LOGI(TAG, "   ❓ น้องเหลือของเล่นกี่ชิ้น?");
    ESP_LOGI(TAG, "");

    vTaskDelay(2000 / portTICK_PERIOD_MS);

    // ตรวจสอบว่าของเล่นพอแจกไหม
    if (toys_give_away > toys_have) {
        ESP_LOGW(TAG, "⚠️  คำเตือน: ของเล่นที่จะแจก (%d) มากกว่าที่มีอยู่ (%d)!", 
                 toys_give_away, toys_have);
        ESP_LOGI(TAG, "   จะแจกได้เฉพาะ %d ชิ้น (ทั้งหมดที่มี)", toys_have);
        toys_give_away = toys_have;
    } else {
        ESP_LOGI(TAG, "✅ ของเล่นพอแจก");
    }

    // คำนวณ
    toys_remaining = toys_have - toys_give_away;
    total_toys = toys_have + dolls + robots;

    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   ของเล่นที่มี - ของเล่นที่แจก = %d - %d = %d", 
             toys_have, toys_give_away, toys_remaining);
    ESP_LOGI(TAG, "");

    // คำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   น้องเหลือของเล่น %d ชิ้น", toys_remaining);
    ESP_LOGI(TAG, "");

    // ภาพประกอบ
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   ของเล่นเดิม: 🧸🚗🎲🧩🎮🧸🚁🎯 (%d ชิ้น)", toys_have);
    ESP_LOGI(TAG, "   แจกให้เพื่อน: 🧸🚗🎲 (%d ชิ้น)", toys_give_away);
    ESP_LOGI(TAG, "   เหลืออยู่:   🧩🎮🧸 (%d ชิ้น)", toys_remaining);
    ESP_LOGI(TAG, "");

    // รายการของเล่นประเภทอื่น
    ESP_LOGI(TAG, "🪆 ตุ๊กตา: %d ตัว", dolls);
    ESP_LOGI(TAG, "🤖 หุ่นยนต์: %d ตัว", robots);
    ESP_LOGI(TAG, "🎯 ของเล่นรวมทั้งหมด (ทุกประเภท): %d ชิ้น", total_toys);
    ESP_LOGI(TAG, "");

    // แบบฝึกหัดที่ 4: แจกให้เพื่อน
    int friends = 10;
    int toys_per_friend = 2;
    int required_toys = friends * toys_per_friend;

    ESP_LOGI(TAG, "❓ ถ้าน้องอยากแจกของเล่นให้เพื่อน %d คน คนละ %d ชิ้น", 
             friends, toys_per_friend);
    ESP_LOGI(TAG, "   ต้องใช้ของเล่นทั้งหมด: %d ชิ้น", required_toys);

    if (total_toys >= required_toys) {
        ESP_LOGI(TAG, "🎉 ของเล่นเพียงพอสำหรับแจกให้เพื่อนทุกคน!");
    } else {
        int shortage = required_toys - total_toys;
        ESP_LOGI(TAG, "⚠️ ของเล่นไม่พอ! ขาดอีก %d ชิ้น", shortage);
    }

    // สรุป
    ESP_LOGI(TAG, "==============================");
    ESP_LOGI(TAG, "✅ สรุป:");
    ESP_LOGI(TAG, "   ของเล่นเริ่มต้น: %d ชิ้น", toys_have);
    ESP_LOGI(TAG, "   แจกไปแล้ว: %d ชิ้น", toys_give_away);
    ESP_LOGI(TAG, "   เหลืออยู่: %d ชิ้น", toys_remaining);
    ESP_LOGI(TAG, "   รวมของเล่นทั้งหมด (ทุกประเภท): %d ชิ้น", total_toys);
    ESP_LOGI(TAG, "==============================");

    // หน่วงเวลาเพื่อให้ log แสดงผลครบ
    vTaskDelay(3000 / portTICK_PERIOD_MS);
}

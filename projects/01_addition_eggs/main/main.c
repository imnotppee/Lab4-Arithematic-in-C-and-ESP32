#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// กำหนดชื่อสำหรับแสดงใน log
static const char *TAG = "EGGS_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🥚 เริ่มต้นโปรแกรมนับไข่ไก่ของแม่ 🥚");
    ESP_LOGI(TAG, "=====================================");
    
    // ประกาศตัวแปรเก็บจำนวนไข่
    int eggs_already_have = 8;    // ไข่ไก่ที่แม่มีอยู่แล้ว
    int eggs_new_today = 3;       // ไข่ไก่ที่ไก่ออกวันนี้
    int total_eggs;               // ไข่ไก่ทั้งหมด
    int duck_eggs = 3;          // ไข่เป็ด
    int total_all_eggs;          // ไข่ไก่และไข่เป็ดรวมกัน
    
    // แสดงข้อมูลเริ่มต้น
    ESP_LOGI(TAG, "📖 โจทย์:");
    ESP_LOGI(TAG, "   แม่มีไข่ไก่อยู่แล้ว: %d ฟอง", eggs_already_have);
    ESP_LOGI(TAG, "   เมื่อเช้าไก่ออกไข่เพิ่ม: %d ฟอง", eggs_new_today);
    ESP_LOGI(TAG, "   ❓ วันนี้แม่มีไข่ไก่รวมกี่ฟอง?");
    ESP_LOGI(TAG, "");
    
    // รอสักครู่เพื่อให้อ่านโจทย์
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    
    // คำนวณผลรวม (การบวก)
    total_eggs = eggs_already_have + eggs_new_today;
    total_all_eggs = total_eggs + duck_eggs; // รวมไข่ไก่และไข่เป็ด
    
    // แสดงผลลัพธ์
    ESP_LOGI(TAG, "🦆 และแม่มีไข่เป็ด: %d ฟอง", duck_eggs);
    ESP_LOGI(TAG, "🥚 ไข่ทั้งหมด (ไก่+เป็ด): %d ฟอง", total_all_eggs);

    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   ไข่ไก่ที่มีอยู่ + ไข่ไก่ที่ออกใหม่");
    ESP_LOGI(TAG, "   = %d + %d", eggs_already_have, eggs_new_today);
    ESP_LOGI(TAG, "   = %d ฟอง", total_eggs);
    ESP_LOGI(TAG, "");
    
    // แสดงคำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   วันนี้แม่มีไข่ไก่ทั้งหมด %d ฟอง", total_eggs);
    ESP_LOGI(TAG, "");
    
    // แสดงภาพประกอบ (ASCII Art)
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   ไข่เดิม: 🥚🥚🥚🥚 (%d ฟอง)", eggs_already_have);
    ESP_LOGI(TAG, "   ไข่ใหม่: 🥚🥚 (%d ฟอง)", eggs_new_today);
    ESP_LOGI(TAG, "   รวม:   🥚🥚🥚🥚🥚🥚 (%d ฟอง)", total_eggs);
    ESP_LOGI(TAG, "");
    
    // ตัวอย่างเพิ่มเติม
    ESP_LOGI(TAG, "💡 ตัวอย่างเพิ่มเติม:");
    
    // ตัวอย่างที่ 1
    int example1_old = 7;
    int example1_new = 3;
    int example1_total = example1_old + example1_new;
    ESP_LOGI(TAG, "   ถ้าแม่มีไข่ %d ฟอง และไก่ออกไข่ %d ฟอง", example1_old, example1_new);
    ESP_LOGI(TAG, "   จะได้ไข่ทั้งหมด %d + %d = %d ฟอง", example1_old, example1_new, example1_total);
    ESP_LOGI(TAG, "");
    
    // ตัวอย่างที่ 2
    int example2_old = 10;
    int example2_new = 5;
    int example2_total = example2_old + example2_new;
    ESP_LOGI(TAG, "   ถ้าแม่มีไข่ %d ฟอง และไก่ออกไข่ %d ฟอง", example2_old, example2_new);
    ESP_LOGI(TAG, "   จะได้ไข่ทั้งหมด %d + %d = %d ฟอง", example2_old, example2_new, example2_total);
    ESP_LOGI(TAG, "");
    
    // สรุปการเรียนรู้
    ESP_LOGI(TAG, "📚 สิ่งที่เรียนรู้:");
    ESP_LOGI(TAG, "   1. การบวกเลข (Addition): a + b = c");
    ESP_LOGI(TAG, "   2. การใช้ตัวแปร (Variables) เก็บค่า");
    ESP_LOGI(TAG, "   3. การแสดงผลด้วย ESP_LOGI");
    ESP_LOGI(TAG, "   4. การแก้โจทย์แบบมีขั้นตอน");
    ESP_LOGI(TAG, "");
    
    ESP_LOGI(TAG, "🎉 จบโปรแกรมนับไข่ไก่ของแม่!");
    ESP_LOGI(TAG, "📖 อ่านต่อในโปรเจคถัดไป: 02_subtraction_toys");

    ESP_LOGI(TAG, "=== ไข่ไก่ของแม่ ===");
    ESP_LOGI(TAG, "🥚 ไข่ไก่ที่แม่มีอยู่แล้ว: %d ฟอง", eggs_already_have);
    ESP_LOGI(TAG, "🥚 ไข่ไก่ที่ไก่ออกวันนี้: %d ฟอง", eggs_new_today);
    ESP_LOGI(TAG, "🥚 ไข่เป็ดที่แม่มี: %d ฟอง", duck_eggs);
    ESP_LOGI(TAG, "🥚 ไข่ไก่ทั้งหมด (ไก่ + เป็ด): %d ฟอง", total_all_eggs);
    ESP_LOGI(TAG, "===========================");

    int cars_existing = 15;       // รถที่จอดอยู่แล้ว
    int cars_new_arrived = 7;     // รถที่เข้ามาใหม่
    int motorcycles = 12;         // มอเตอร์ไซค์ที่จอดอยู่
    int total_cars = cars_existing + cars_new_arrived;
    int total_vehicles = total_cars + motorcycles;

    ESP_LOGI(TAG, "=== รถยนต์และมอเตอร์ไซค์ ===");
    ESP_LOGI(TAG, "🚗 รถยนต์ที่จอดอยู่แล้ว: %d คัน", cars_existing);
    ESP_LOGI(TAG, "🚗 รถยนต์ที่เข้ามาใหม่: %d คัน", cars_new_arrived);
    ESP_LOGI(TAG, "🏍️ มอเตอร์ไซค์ที่จอดอยู่: %d คัน", motorcycles);
    ESP_LOGI(TAG, "🚗 รถยนต์ทั้งหมด (จอด + ใหม่): %d คัน", total_cars);
    ESP_LOGI(TAG, "🚗🚲 ยานพาหนะทั้งหมด (รถยนต์ + มอเตอร์ไซค์): %d คัน", total_vehicles);
    ESP_LOGI(TAG, "===========================");
    
    // รอสักครู่ก่อนจบโปรแกรม
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}

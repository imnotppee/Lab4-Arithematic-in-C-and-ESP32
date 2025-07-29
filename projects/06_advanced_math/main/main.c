#include <stdio.h>
#include <math.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// 🏷️ Tag สำหรับ Log
static const char *TAG = "ADVANCED_MATH";

// 🔢 ค่าคงที่ทางคณิตศาสตร์
#define PI 3.14159265359
#define SQUARE_METERS_TO_RAI 1600.0  // 1 ไร่ = 1,600 ตร.ม.

// 📐 โครงสร้างข้อมูลรูปทรง
typedef struct {
    char name[50];
    double length;      // ความยาว/รัศมี
    double width;       // ความกว้าง
    double height;      // ความสูง/ความลึก
} shape_t;

// 🏟️ คำนวณพื้นที่สี่เหลี่ยม
void calculate_rectangle(shape_t shape) {
    double area = shape.length * shape.width;
    double perimeter = 2 * (shape.length + shape.width);
    double area_in_rai = area / SQUARE_METERS_TO_RAI;
    
    ESP_LOGI(TAG, "╔══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║          %s           ║", shape.name);
    ESP_LOGI(TAG, "╠══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 ความยาว: %.2f เมตร", shape.length);
    ESP_LOGI(TAG, "║ 📏 ความกว้าง: %.2f เมตร", shape.width);
    ESP_LOGI(TAG, "║ 📐 พื้นที่: %.2f × %.2f = %.2f ตร.ม.", shape.length, shape.width, area);
    ESP_LOGI(TAG, "║ 🔄 ปริเมตร: 2×(%.0f+%.0f) = %.2f ม.", shape.length, shape.width, perimeter);
    ESP_LOGI(TAG, "║ 🌾 เท่ากับ: %.4f ไร่", area_in_rai);
    ESP_LOGI(TAG, "╚══════════════════════════════════════╝");
}

// 🏊‍♀️ คำนวณวงกลม (ทรงกระบอก)
void calculate_circle(shape_t shape) {
    double radius = shape.length;
    double surface_area = PI * radius * radius;
    double circumference = 2 * PI * radius;
    double volume = surface_area * shape.height;

    ESP_LOGI(TAG, "╔══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║          %s            ║", shape.name);
    ESP_LOGI(TAG, "╠══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 รัศมี: %.2f เมตร", radius);
    ESP_LOGI(TAG, "║ 📏 ความลึก: %.2f เมตร", shape.height);
    ESP_LOGI(TAG, "║ 🌊 พื้นที่ผิวน้ำ: π × %.0f² = %.2f ตร.ม.", radius, surface_area);
    ESP_LOGI(TAG, "║ ⭕ เส้นรอบวง: 2π × %.0f = %.2f ม.", radius, circumference);
    ESP_LOGI(TAG, "║ 💧 ปริมาตรน้ำ: %.2f × %.2f = %.2f ลบ.ม.", surface_area, shape.height, volume);
    ESP_LOGI(TAG, "╚══════════════════════════════════════╝");
}

// 🎁 คำนวณกล่อง
void calculate_box(shape_t shape) {
    double volume = shape.length * shape.width * shape.height;
    double surface_area = 2 * (shape.length * shape.width +
                               shape.width * shape.height +
                               shape.length * shape.height);
    
    ESP_LOGI(TAG, "╔══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║          %s          ║", shape.name);
    ESP_LOGI(TAG, "╠══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 ความยาว: %.2f ซม.", shape.length);
    ESP_LOGI(TAG, "║ 📏 ความกว้าง: %.2f ซม.", shape.width);
    ESP_LOGI(TAG, "║ 📏 ความสูง: %.2f ซม.", shape.height);
    ESP_LOGI(TAG, "║ 📦 ปริมาตร: %.0f×%.0f×%.0f = %.2f ลบ.ซม.", shape.length, shape.width, shape.height, volume);
    ESP_LOGI(TAG, "║ 🎀 พื้นที่ผิว: %.2f ตร.ซม.", surface_area);
    ESP_LOGI(TAG, "║ 📐 เท่ากับ: %.6f ลิตร", volume / 1000.0);
    ESP_LOGI(TAG, "╚══════════════════════════════════════╝");
}

// 📊 เปรียบเทียบผลลัพธ์
void compare_results(void) {
    ESP_LOGI(TAG, "\n🔍 การเปรียบเทียบผลลัพธ์:");
    ESP_LOGI(TAG, "╔════════════════════════════════════╗");
    ESP_LOGI(TAG, "║  สนามฟุตบอล vs สระน้ำ vs กล่อง    ║");
    ESP_LOGI(TAG, "╠════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 🏟️ สนาม: ใหญ่ที่สุด (6,000 ตร.ม.)  ║");
    ESP_LOGI(TAG, "║ 🏊‍♀️ สระ: กลาง (78.54 ตร.ม.)       ║");
    ESP_LOGI(TAG, "║ 🎁 กล่อง: เล็กที่สุด (300 ลบ.ซม.)  ║");
    ESP_LOGI(TAG, "╚════════════════════════════════════╝");
}

// 📚 ความรู้เพิ่มเติม
void show_math_facts(void) {
    ESP_LOGI(TAG, "\n📚 ความรู้ทางคณิตศาสตร์:");
    ESP_LOGI(TAG, "╔═══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║           สูตรคณิตศาสตร์             ║");
    ESP_LOGI(TAG, "╠═══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📐 สี่เหลี่ยม: พื้นที่ = ยาว × กว้าง   ║");
    ESP_LOGI(TAG, "║ ⭕ วงกลม: พื้นที่ = π × r²           ║");
    ESP_LOGI(TAG, "║ 📦 ทรงผีเสื้อ: ปริมาตร = ย×ก×ส       ║");
    ESP_LOGI(TAG, "║ 💡 π (pi) ≈ 3.14159                  ║");
    ESP_LOGI(TAG, "║ 🌾 1 ไร่ = 1,600 ตารางเมตร          ║");
    ESP_LOGI(TAG, "╚═══════════════════════════════════════╝");
}

// 🎯 ฟังก์ชันท้าทาย - คำนวณสามเหลี่ยม
void calculate_triangle_bonus(void) {
    double base = 10.0;
    double height = 8.0;
    double side1 = 10.0;
    double side2 = 8.0;
    double side3 = 6.0;

    double area = 0.5 * base * height;
    double perimeter = side1 + side2 + side3;

    ESP_LOGI(TAG, "\n🎯 โบนัส: สามเหลี่ยม");
    ESP_LOGI(TAG, "╔═══════════════════════════════════════╗");
    ESP_LOGI(TAG, "║         สามเหลี่ยมมุมฉาก             ║");
    ESP_LOGI(TAG, "╠═══════════════════════════════════════╣");
    ESP_LOGI(TAG, "║ 📏 ฐาน: %.2f ซม.", base);
    ESP_LOGI(TAG, "║ 📏 สูง: %.2f ซม.", height);
    ESP_LOGI(TAG, "║ 📐 พื้นที่: ½×%.0f×%.0f = %.2f ตร.ซม.", base, height, area);
    ESP_LOGI(TAG, "║ 🔄 ปริเมตร: %.0f+%.0f+%.0f = %.2f ซม.", side1, side2, side3, perimeter);
    ESP_LOGI(TAG, "╚═══════════════════════════════════════╝");
}

// 🚀 main function
void app_main(void) {
    ESP_LOGI(TAG, "🚀 เริ่มต้นโปรแกรมคณิตศาสตร์ขั้นสูง!");
    ESP_LOGI(TAG, "📐 การคำนวณพื้นที่และปริมาตร\n");
    vTaskDelay(pdMS_TO_TICKS(1000));

    shape_t football_field = {"สนามฟุตบอล", 100.0, 60.0, 0.0};
    shape_t swimming_pool  = {"สระน้ำกลม", 5.0, 0.0, 2.0};
    shape_t gift_box       = {"กล่องของขวัญ", 20.0, 15.0, 10.0};

    ESP_LOGI(TAG, "   🏟️     🏊‍♀️     🎁");
    ESP_LOGI(TAG, " ┌─────┐  ╭─────╮  ┌─────┐");
    ESP_LOGI(TAG, " │ ⚽  │  │ 💧💧 │  │ 🎀  │");
    ESP_LOGI(TAG, " │     │  │     │  │     │");
    ESP_LOGI(TAG, " └─────┘  ╰─────╯  └─────┘\n");

    calculate_rectangle(football_field);  vTaskDelay(pdMS_TO_TICKS(2000));
    calculate_circle(swimming_pool);      vTaskDelay(pdMS_TO_TICKS(2000));
    calculate_box(gift_box);              vTaskDelay(pdMS_TO_TICKS(2000));
    compare_results();                    vTaskDelay(pdMS_TO_TICKS(2000));
    show_math_facts();                    vTaskDelay(pdMS_TO_TICKS(2000));
    calculate_triangle_bonus();
    
}

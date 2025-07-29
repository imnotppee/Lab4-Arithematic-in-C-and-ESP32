#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "COOKIES_MATH";

void app_main(void)
{
    ESP_LOGI(TAG, "🍪 เริ่มต้นโปรแกรมแบ่งคุกกี้ 🍪");
    ESP_LOGI(TAG, "================================");

    // 📝 แบบฝึกหัดที่ 1: เปลี่ยนจำนวนคุกกี้และเพื่อน
    int total_cookies = 24;        // คุกกี้ทั้งหมด
    int number_of_friends = 6;     // จำนวนเพื่อน
    int cookies_per_person;        // คุกกี้ต่อคน
    int remaining_cookies;         // คุกกี้ที่เหลือ

    ESP_LOGI(TAG, "📖 โจทย์:");
    ESP_LOGI(TAG, "   มีคุกกี้: %d ชิ้น", total_cookies);
    ESP_LOGI(TAG, "   จะแบ่งให้เพื่อน: %d คน", number_of_friends);
    ESP_LOGI(TAG, "   ❓ แต่ละคนได้คุกกี้กี่ชิ้น?");
    ESP_LOGI(TAG, "");

    vTaskDelay(3000 / portTICK_PERIOD_MS);

    if (number_of_friends == 0) {
        ESP_LOGE(TAG, "❌ ข้อผิดพลาด: ไม่สามารถหารด้วยศูนย์ได้!");
        ESP_LOGI(TAG, "   ไม่มีเพื่อนมาแบ่ง คุกกี้เหลือทั้งหมด %d ชิ้น", total_cookies);
        return;
    }

    cookies_per_person = total_cookies / number_of_friends;
    remaining_cookies = total_cookies % number_of_friends;

    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   คุกกี้ทั้งหมด ÷ จำนวนเพื่อน");
    ESP_LOGI(TAG, "   = %d ÷ %d", total_cookies, number_of_friends);
    ESP_LOGI(TAG, "   = %d ชิ้นต่อคน", cookies_per_person);
    if (remaining_cookies > 0) {
        ESP_LOGI(TAG, "   เศษที่เหลือ = %d ชิ้น", remaining_cookies);
    }
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   แต่ละคนได้คุกกี้ %d ชิ้น", cookies_per_person);
    if (remaining_cookies > 0) {
        ESP_LOGI(TAG, "   มีคุกกี้เหลือ %d ชิ้น (ไม่สามารถแบ่งได้เท่าๆ กัน)", remaining_cookies);
    } else {
        ESP_LOGI(TAG, "   แบ่งได้พอดี ไม่มีเหลือ");
    }
    ESP_LOGI(TAG, "");

    // 📝 แบบฝึกหัดที่ 2: ตรวจสอบหารลงตัว
    if (remaining_cookies == 0) {
        ESP_LOGI(TAG, "✅ หารลงตัว! ทุกคนได้เท่ากัน");
    } else {
        ESP_LOGI(TAG, "⚠️ หารไม่ลงตัว! เหลือ %d ชิ้น", remaining_cookies);
    }
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🎨 ภาพประกอบการแบ่ง:");
    ESP_LOGI(TAG, "   คุกกี้ทั้งหมด: ");
    for (int i = 0; i < total_cookies; i++) {
        printf("🍪");
    }
    printf(" (%d ชิ้น)\n\n", total_cookies);

    for (int person = 1; person <= number_of_friends; person++) {
        ESP_LOGI(TAG, "   เพื่อนคนที่ %d: ", person);
        for (int i = 0; i < cookies_per_person; i++) {
            printf("🍪");
        }
        printf(" (%d ชิ้น)\n", cookies_per_person);
    }

    if (remaining_cookies > 0) {
        ESP_LOGI(TAG, "   เหลือ:");
        for (int i = 0; i < remaining_cookies; i++) {
            printf("🍪");
        }
        printf(" (%d ชิ้น)\n", remaining_cookies);
    }

    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "💡 ตัวอย่างเพิ่มเติม:");

    // ตัวอย่างที่ 1: หารลงตัว
    int ex1_cookies = 15;
    int ex1_friends = 3;
    ESP_LOGI(TAG, "   %d ชิ้น ÷ %d คน = %d ชิ้นต่อคน, เหลือ %d ชิ้น",
             ex1_cookies, ex1_friends,
             ex1_cookies / ex1_friends,
             ex1_cookies % ex1_friends);

    // ตัวอย่างที่ 2: หารไม่ลงตัว
    int ex2_cookies = 13;
    int ex2_friends = 4;
    ESP_LOGI(TAG, "   %d ชิ้น ÷ %d คน = %d ชิ้นต่อคน, เหลือ %d ชิ้น",
             ex2_cookies, ex2_friends,
             ex2_cookies / ex2_friends,
             ex2_cookies % ex2_friends);

    // ตัวอย่างที่ 3: หารด้วยศูนย์
    ESP_LOGI(TAG, "⚠️  กรณีพิเศษ: หารด้วย 0");
    ESP_LOGI(TAG, "   คุกกี้ 10 ชิ้น ÷ 0 คน = ❌ ไม่สามารถทำได้");

    ESP_LOGI(TAG, "");

    // ความสัมพันธ์กับการคูณ
    ESP_LOGI(TAG, "🔄 ความสัมพันธ์กับการคูณ:");
    ESP_LOGI(TAG, "   %d ÷ %d = %d", total_cookies, number_of_friends, cookies_per_person);
    ESP_LOGI(TAG, "   %d × %d = %d", cookies_per_person, number_of_friends, cookies_per_person * number_of_friends);
    if (remaining_cookies > 0) {
        ESP_LOGI(TAG, "   บวกเศษ: %d + %d = %d", cookies_per_person * number_of_friends, remaining_cookies, total_cookies);
    }

    ESP_LOGI(TAG, "");

    // 📝 แบบฝึกหัดที่ 3: หาจำนวนเพื่อนที่เหมาะสม
    int cookies = 30;
    ESP_LOGI(TAG, "🔍 แบบฝึกหัดเพิ่มเติม:");
    ESP_LOGI(TAG, "   คุกกี้ %d ชิ้น หารลงตัวกับ:", cookies);
    for (int people = 1; people <= 10; people++) {
        if (cookies % people == 0) {
            ESP_LOGI(TAG, "   ✅ %d คน → คนละ %d ชิ้น",
                     people, cookies / people);
        }
    }
}
